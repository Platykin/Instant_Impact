#include "precision.hpp"
using namespace InstantImpact;

namespace InstantImpact {
    
    class Vector3{
    public:
        real x, y, z;
        Vector3() 
            : x(0), y(0), z(0){}

        Vector3(const real x_arg, const real y_arg, const real z_arg) 
            : x(x_arg), y(y_arg), z(z_arg){}

        //Overloads
        Vector3 operator*=(const real value){
            x *= value;
            y *= value;
            z *= value;
        }

        void operator+=(const Vector3 &v3){
            x += v3.x;
            y += v3.y;
            z += v3.z;
        }

        void invert(){
            x, y, z *= -1;
        }

        real magnitude() const{return real_sqrt(x*x+y*y+z*z);}

        real squared_magnitude() const {return x*x + y*y + z*z;}

        void normalize(){
            real l = magnitude();
            real arg_x, arg_y, arg_z;
            if (l > 0){
                (*this) *= l;
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