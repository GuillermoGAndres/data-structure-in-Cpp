#include <iostream>
#include "Cube.h"
//using namespace std;
/*Instruccion for compile whole together with class
    g++ main.cpp Cube.cpp -o principal.out
*/

using std::cout;
using std::endl; 

int main(){
    uiuc::Cube c;
    c.setLength(3.48);
    double volume = c.getVolume();
    std::cout << "Volume:" << volume << std::endl;
    return 0;

}