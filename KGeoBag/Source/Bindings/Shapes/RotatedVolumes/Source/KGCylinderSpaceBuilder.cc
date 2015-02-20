#include "KGCylinderSpaceBuilder.hh"
#include "KGInterfaceBuilder.hh"

namespace katrin
{

    static const int sKGCylinderSpaceBuilder =
        KGInterfaceBuilder::ComplexElement< KGCylinderSpace >( "cylinder_space" );

    static const int sKGCylinderSpaceBuilderStructure =
        KGCylinderSpaceBuilder::Attribute< string >( "name" ) +
        KGCylinderSpaceBuilder::Attribute< double >( "z1" ) +
        KGCylinderSpaceBuilder::Attribute< double >( "z2" ) +
        KGCylinderSpaceBuilder::Attribute< double >( "length" ) +
        KGCylinderSpaceBuilder::Attribute< double >( "r" ) +
        KGCylinderSpaceBuilder::Attribute< unsigned int >( "longitudinal_mesh_count" ) +
        KGCylinderSpaceBuilder::Attribute< double >( "longitudinal_mesh_power" ) +
        KGCylinderSpaceBuilder::Attribute< unsigned int >( "radial_mesh_count" ) +
        KGCylinderSpaceBuilder::Attribute< double >( "radial_mesh_power" ) +
        KGCylinderSpaceBuilder::Attribute< unsigned int >( "axial_mesh_count" );

}