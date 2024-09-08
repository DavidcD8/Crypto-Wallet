 #include "Vec3D.h"
#include <cmath>


int Vec3D::getLenght(){

    return std::sqrt(x * x + y*y + z*z);
}
 