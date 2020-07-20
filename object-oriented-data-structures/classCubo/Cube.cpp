/* Implementation the class Cube 
    Should be in files.cpp
*/
#include "Cube.h"

//Aqui tambien lo hacemos para nuestro namespace
namespace uiuc {
    double Cube::getVolume(){
        return length_*length_*length_;
    }

    double Cube::getSurfaceArea(){
        return 6 * length_ * length_;
    }

    void Cube::setLength(double length){
        length_ = length;
    }
}
