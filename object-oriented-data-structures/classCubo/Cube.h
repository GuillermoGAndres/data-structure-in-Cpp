#pragma once   // Compile once 

/*Other opcion
#ifndef CUBE_H
#define CUBE_H
*/
/* Deficion de una clase en C++
should be in file.h 
Interface of Cube class 
@see: https://google.github.io/styleguide/cppguide.html
*/

/* Aqui creamos un nuevo espacio de nombre (namespace) para nuestro Cubo class
para que pertenezca a este namespace
Encapsulamos al cubo */
namespace uiuc {
    class Cube{
        public:
        double getVolume();
        double getSurfaceArea();
        void setLength(double length);

        private:
        double length_;  // Variables_private_ google style c++ 
    }; //End with semicolon(;)
}
//#endif