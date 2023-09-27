#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>

struct Cylinder {
    float height_cm;
    float baseRadius_cm;
};

/**
 @brief calculates cylinder volume using base radius 
 in centimeters and height of cylinder in centimeters 
 π x r² x h
 @param baseRadius_cm float radius of cylinder base 
 @param height_cm float height of cylinder 
 @return volume in cm^3 */
float cylinderVolume_cm3(Cylinder *cylinder) {
    return M_PI * cylinder->baseRadius_cm * cylinder->baseRadius_cm * cylinder->height_cm; 
} 

int main() {

    Cylinder *cyl1 = new Cylinder;
    
    std::cout << "\n > Enter height of cylinder in centimeters: \n height: ";
    std::cin >> cyl1->height_cm;
    std::cout << " > Enter base radius of cylinder in centimeters: \n radius: ";
    std::cin >> cyl1->baseRadius_cm;
    std::cout << " x Cylinder volume in cm^3: " << cylinderVolume_cm3(cyl1);;

    delete cyl1;

    return 0;
}