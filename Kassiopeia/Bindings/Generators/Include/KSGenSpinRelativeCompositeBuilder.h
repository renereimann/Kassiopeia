#ifndef Kassiopeia_KSGenSpinRelativeCompositeBuilder_h_
#define Kassiopeia_KSGenSpinRelativeCompositeBuilder_h_

#include "KComplexElement.hh"
#include "KSGenSpinRelativeComposite.h"
#include "KToolbox.h"
#include "KGCore.hh"

using namespace Kassiopeia;
using namespace KGeoBag;
namespace katrin
{

    typedef KComplexElement< KSGenSpinRelativeComposite > KSGenSpinRelativeCompositeBuilder;

    template< >
    inline bool KSGenSpinRelativeCompositeBuilder::AddAttribute( KContainer* aContainer )
    {
        if( aContainer->GetName() == "name" )
        {
            aContainer->CopyTo( fObject, &KNamed::SetName );
            return true;
        }
        if( aContainer->GetName() == "theta" )
        {
            fObject->SetThetaValue( KToolbox::GetInstance().Get< KSGenValue >( aContainer->AsReference< std::string >() ) );
            return true;
        }
        if( aContainer->GetName() == "phi" )
        {
            fObject->SetPhiValue( KToolbox::GetInstance().Get< KSGenValue >( aContainer->AsReference< std::string >() ) );
            return true;
        }
        return false;
    }

    template< >
    inline bool KSGenSpinRelativeCompositeBuilder::AddElement( KContainer* aContainer )
    {
        if( aContainer->GetName().substr( 0, 5 ) == "theta" )
        {
            aContainer->ReleaseTo( fObject, &KSGenSpinRelativeComposite::SetThetaValue );
            return true;
        }
        if( aContainer->GetName().substr( 0, 3 ) == "phi" )
        {
            aContainer->ReleaseTo( fObject, &KSGenSpinRelativeComposite::SetPhiValue );
            return true;
        }
        return false;
    }

}

#endif