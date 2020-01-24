#ifndef Kassiopeia_KSIntSpinRotateYPulse_h_
#define Kassiopeia_KSIntSpinRotateYPulse_h_

#include "KSSpaceInteraction.h"

#include <vector>
using std::vector;

namespace Kassiopeia
{

    class KSIntSpinRotateYPulse :
        public KSComponentTemplate< KSIntSpinRotateYPulse, KSSpaceInteraction >
    {
        public:
            KSIntSpinRotateYPulse();
            KSIntSpinRotateYPulse( const KSIntSpinRotateYPulse& aCopy );
            KSIntSpinRotateYPulse* Clone() const;
            virtual ~KSIntSpinRotateYPulse();

        public:
            void CalculateInteraction(
                    const KSTrajectory& aTrajectory,
                    const KSParticle& aTrajectoryInitialParticle,
                    const KSParticle& aTrajectoryFinalParticle,
                    const KThreeVector& aTrajectoryCenter,
                    const double& aTrajectoryRadius,
                    const double& aTrajectoryTimeStep,
                    KSParticle& anInteractionParticle,
                    double& aTimeStep,
                    bool& aFlag
            );

            void ExecuteInteraction(
                    const KSParticle& anInteractionParticle,
                    KSParticle& aFinalParticle,
                    KSParticleQueue& aSecondaries
            ) const;

            //***********
            //composition
            //***********

        public:
            void SetTime( const double& aTime );
            void SetAngle( const double& anAngle );
            void SetIsAdiabatic( const bool& anIsAdiabatic );

        private:
            mutable bool fDone;
            double fTime;
            double fAngle;
            bool fIsAdiabatic;

            //**************
            //initialization
            //**************

        // protected:
        //     virtual void PushUpdateComponent();
        //     virtual void PushDeupdateComponent();
    };

}

#endif