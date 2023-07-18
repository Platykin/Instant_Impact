#include "core.hpp"
#include "particle.hpp"
#include "precision.hpp"
#include "assert.h"

void Particle::integrate(real time){
    assert(time > 0.0);

    position.addScaledVector(velocity, time);

    InstantImpact::Vector3 resultAcc = acceleration;
    resultAcc.addScaledVector(forceAccum, inverseMass);

    velocity.addScaledVector(resultAcc, time);




}