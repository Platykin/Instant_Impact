#ifndef _PRECISION_HPP_
#define _PRECISION_HPP_
#include <math.h>

namespace InstantImpact {
    // If we need to switch type float to type double, we can change here (DONT'T FORGET TO CHANGE SQRTF TO SQRT)
   typedef float real;
   #define real_sqrt sqrtf
   #define real_pow powf
   
}
#endif