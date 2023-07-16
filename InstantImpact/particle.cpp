#include "core.hpp"
#include "particle.hpp"
#include "precision.hpp"
#include "assert.h"

void Particle::integrate(real time){
    assert(time > 0.0);

    Particle::position.addScaledVector(Particle::velocity, time);

}