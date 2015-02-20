#include "KGMeshDeformer.hh"

#include "KGDeformed.hh"

#include "KGMeshRectangle.hh"
#include "KGMeshTriangle.hh"
#include "KGMeshWire.hh"

#define EPSILON 1.e-9

namespace KGeoBag
{
  void KGMeshDeformer::VisitExtendedSpace(KGExtendedSpace<KGDeformed>* deformedSpace)
  {
    if (deformedSpace->HasExtension<KGDeformed>())
    {
      // collect all of the boundaries and surfaces held by the space, and 
      // affix the deformation to them (if they don't have one already).

      for (vector<KGSurface*>::const_iterator it=deformedSpace->AsBase()->GetBoundaries()->begin();it!=deformedSpace->AsBase()->GetBoundaries()->end();++it)
      {
	if (!((*it)->HasExtension<KGDeformed>()))
	{
	  (*it)->MakeExtension<KGDeformed>();
	  (*it)->AsExtension<KGDeformed>()->SetDeformation(deformedSpace->AsExtension<KGDeformed>()->GetDeformation());
	}
      }

      for (vector<KGSurface*>::const_iterator it=deformedSpace->AsBase()->GetChildSurfaces()->begin();it!=deformedSpace->AsBase()->GetChildSurfaces()->end();++it)
      {
	if (!((*it)->HasExtension<KGDeformed>()))
	{
	  (*it)->MakeExtension<KGDeformed>();
	  (*it)->AsExtension<KGDeformed>()->SetDeformation(deformedSpace->AsExtension<KGDeformed>()->GetDeformation());
	}
      }
    }
  }

  void KGMeshDeformer::VisitExtendedSurface(KGExtendedSurface<KGMesh>* meshSurface)
  {
    if (meshSurface->HasExtension<KGDeformed>())
    {
      // first, fill container vector with deformed mesh elements (and delete
      // the old mesh elements as we go)
      fDeformation = meshSurface->AsExtension<KGDeformed>()->GetDeformation();

      KGMeshElementIt it;
      for (it=meshSurface->Elements()->begin();it!=meshSurface->Elements()->end();++it)
      {
	AddDeformed(*it);
	delete *it;
      }

      // then, add the deformed mesh elements to the surface
      meshSurface->Elements()->clear();
      for (it=fDeformedVector.begin();it!=fDeformedVector.end();++it)
	meshSurface->Elements()->push_back(*it);

      fDeformedVector.clear();
    }
  }

  void KGMeshDeformer::AddDeformed(KGMeshElement* e)
  {
    if (KGMeshRectangle* r = dynamic_cast<KGMeshRectangle*>(e))
      AddDeformed(r);
    else if (KGMeshTriangle* t = dynamic_cast<KGMeshTriangle*>(e))
      AddDeformed(t);
    else if (KGMeshWire* w = dynamic_cast<KGMeshWire*>(e))
      AddDeformed(w);
  }

  void KGMeshDeformer::AddDeformed(KGMeshRectangle* r)
  {
    KThreeVector p0 = r->GetP0();
    KThreeVector p1 = r->GetP0() + r->GetA()*r->GetN1();
    KThreeVector p2 = p1 + r->GetB()*r->GetN2();
    KThreeVector p3 = r->GetP0() + r->GetB()*r->GetN2();

    fDeformation->Apply(p0);
    fDeformation->Apply(p1);
    fDeformation->Apply(p2);
    fDeformation->Apply(p3);

    KThreeVector n10 = (p1-p0).Unit();
    KThreeVector n30 = (p3-p0).Unit();
    KThreeVector n12 = (p1-p2).Unit();
    KThreeVector n32 = (p3-p2).Unit();

    bool isRectangle = true;
    // first, we determine if the four points are still coplanar
    if (fabs(n30.Dot(n10.Cross(n32)))>EPSILON)
      isRectangle = false;
    // then, we determine if the interior angles are still 90 degrees
    if (isRectangle)
    {
      if (n10.Dot(n30)>EPSILON || n12.Dot(n32)>EPSILON ||
	  n10.Dot(n12)>EPSILON || n30.Dot(n32)>EPSILON)
	isRectangle = false;
    }

    if (isRectangle)
    {
      fDeformedVector.push_back(new KGMeshRectangle(p0,p1,p2,p3));
    }
    else
    {
      KGMeshTriangle* t1;
      KGMeshTriangle* t2;
      if ((p2-p0).Magnitude() > (p1-p3).Magnitude())
      {
	t1 = new KGMeshTriangle(p0,p1,p2);
	t2 = new KGMeshTriangle(p0,p3,p2);
      }
      else
      {
	t1 = new KGMeshTriangle(p0,p1,p3);
	t2 = new KGMeshTriangle(p2,p1,p3);
      }

      fDeformedVector.push_back(t1);
      fDeformedVector.push_back(t2);
    }
  }

  void KGMeshDeformer::AddDeformed(KGMeshTriangle* t)
  {
    KThreeVector p0 = t->GetP0();
    KThreeVector p1 = t->GetP0() + t->GetA()*t->GetN1();
    KThreeVector p2 = t->GetP0() + t->GetB()*t->GetN2();
    fDeformation->Apply(p0);
    fDeformation->Apply(p1);
    fDeformation->Apply(p2);

    fDeformedVector.push_back(new KGMeshTriangle(p0,p1,p2));
  }

  void KGMeshDeformer::AddDeformed(KGMeshWire* w)
  {
    KThreeVector p0 = w->GetP0();
    KThreeVector p1 = w->GetP1();
    fDeformation->Apply(p0);
    fDeformation->Apply(p1);

    fDeformedVector.push_back(new KGMeshWire(p0,p1,w->GetDiameter()));
  }
}