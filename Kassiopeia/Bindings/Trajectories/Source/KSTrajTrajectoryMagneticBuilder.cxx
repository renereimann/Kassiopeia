#include "KSTrajTrajectoryMagneticBuilder.h"
#include "KSTrajIntegratorRK54Builder.h"
#include "KSTrajIntegratorRK65Builder.h"
#include "KSTrajIntegratorRK86Builder.h"
#include "KSTrajIntegratorRK87Builder.h"
#include "KSTrajIntegratorRK8Builder.h"
#include "KSTrajInterpolatorFastBuilder.h"
#include "KSTrajTermPropagationBuilder.h"
#include "KSTrajControlTimeBuilder.h"
#include "KSTrajControlLengthBuilder.h"
#include "KSTrajControlEnergyBuilder.h"
#include "KSTrajControlCyclotronBuilder.h"
#include "KSRootBuilder.h"

using namespace Kassiopeia;
namespace katrin
{

    template< >
    KSTrajTrajectoryMagneticBuilder::~KComplexElement()
    {
    }

    static int sKSTrajTrajectoryMagneticStructure =
        KSTrajTrajectoryMagneticBuilder::Attribute< string >( "name" ) +
        KSTrajTrajectoryMagneticBuilder::Attribute< bool >( "reverse" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajIntegratorRK54 >( "integrator_rk54" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajIntegratorRK65 >( "integrator_rk65" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajIntegratorRK86 >( "integrator_rk86" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajIntegratorRK87 >( "integrator_rk87" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajIntegratorRK8 >( "integrator_rk8" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajInterpolatorFast >( "interpolator_fast" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajTermPropagation >( "term_propagation" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajControlTime >( "control_time" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajControlLength >( "control_length" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajControlEnergy >( "control_energy" ) +
        KSTrajTrajectoryMagneticBuilder::ComplexElement< KSTrajControlCyclotron >( "control_cyclotron" );

    static int sToolboxKSTrajTrajectoryMagnetic =
        KSRootBuilder::ComplexElement< KSTrajTrajectoryMagnetic >( "kstraj_trajectory_magnetic" );

}