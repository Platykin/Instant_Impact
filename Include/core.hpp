#include "precision.hpp"
using namespace InstantImpact;

namespace InstantImpact {
    
    class vector3{
    public:
        real x, y, z;
        vector3() 
            : x(0), y(0), z(0){}

        vector3(const real x_arg, const real y_arg, const real z_arg) 
            : x(x_arg), y(y_arg), z(z_arg){}

        void invert(){
            x = -x;
            y = -y;
            z = -y;
        }

        real magnitude() const{return real_sqrt(x*x+y*y+z*z);}

        real squared_magnitude() const {return x*x + y*y + z*z;}

        void normalize(){
            real l = magnitude();
            real arg_x, arg_y, arg_z;
            if (l > 0){
                //I think of overloading the operator *= for this object intead of using vec3->arg in the future
                this->x *= 1/l;
                this->y *= 1/l;
                this->z *= 1/l;
            }
        }
    private:
        /*four floating-point values sit more cleanly in memory than
        three (memory is optimized for sets of four words), so noticeable speed-ups
        can be achieved by adding this padding.       
        */
        real pad;
    };
}