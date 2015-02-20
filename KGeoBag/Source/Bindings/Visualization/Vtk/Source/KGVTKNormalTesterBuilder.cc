#include "KGVTKNormalTesterBuilder.hh"
#include "KVTKWindow.h"

using namespace KGeoBag;
namespace katrin
{

    static const int sKGVTKNormalTesterStructure =
        KGVTKNormalTesterBuilder::Attribute< string >( "name" ) +
        KGVTKNormalTesterBuilder::Attribute< string >( "surfaces" ) +
        KGVTKNormalTesterBuilder::Attribute< string >( "spaces" ) +
        KGVTKNormalTesterBuilder::Attribute< KThreeVector >( "sample_disk_origin" ) +
        KGVTKNormalTesterBuilder::Attribute< KThreeVector >( "sample_disk_normal" ) +
        KGVTKNormalTesterBuilder::Attribute< double >( "sample_disk_radius" ) +
        KGVTKNormalTesterBuilder::Attribute< unsigned int >( "sample_count" ) +
        KGVTKNormalTesterBuilder::Attribute< KGRGBColor >( "sample_color" ) +
        KGVTKNormalTesterBuilder::Attribute< KGRGBColor >( "point_color" ) +
        KGVTKNormalTesterBuilder::Attribute< KGRGBColor >( "normal_color" ) +
        KGVTKNormalTesterBuilder::Attribute< double >( "normal_length" ) +
        KGVTKNormalTesterBuilder::Attribute< double >( "vertex_size" ) +
        KGVTKNormalTesterBuilder::Attribute< double >( "line_size" );

    static const int sKGVTKNormalTesterWindow =
        KVTKWindowBuilder::ComplexElement< KGVTKNormalTester >( "vtk_normal_tester" );

}