#ifndef _PARTICLE_HPP_
#define _PARTICLE_HPP_

#include "core.hpp"
#include "precision.hpp"

class Particle{

public:
    //Properties
    InstantImpact::Vector3 position;
    InstantImpact::Vector3 velocity;
    InstantImpact::Vector3 acceleration;
    //this "damping" property is used as a simple drag force for now 
    real damping;
    //end Properties

    //Methods
    real getInverseMass(){
        return inverseMass;
    }

    void setInverseMass(real value){
        inverseMass = value;
    }

    void integrate(real time);

    //end Methods



protected:
    /*Inverse mass is literally 1/mass. Why not use mass instead then? for two reasons:
    Efficiency. Internally, expressions like something / (1/massA + 1/massB + ... + 1/massN) are extremely common 
    and happen literally tens of thousands of times each frame. By storing inverse masses instead of masses, 
    we can skip all the divisions. This takes pressure off the ALU, reducing the amount of processor cycles used
    to calculate things, making the engine faster.
    Intuitiveness. Unlike mass, inverse mass is directly proportional to how sensitive a particle is to forces.
    Setting inverse mass to zero, is equivalent to giving a particle infinite mass (minus having to deal with the
    ugly and risky infinity/NaN values explicitly). This causes the particle to be impervious to forces.
    Setting it to a high value makes the particle very sensitive to forces.
    31-03-2020, 09:49 AM (This post was last modified: 31-03-2020, 10:41 AM by josemendez.)*/
    real inverseMass;

};
#endif