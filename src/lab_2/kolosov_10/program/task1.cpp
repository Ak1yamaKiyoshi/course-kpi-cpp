#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>


float evaluate_y(float x, float *a) {
    float result;
    if (x >= 1) {
        result = log(x);
        *a = 1.8;
    } else if (-1 < x && x < 1) {
        result = sqrt(pow(x, 2) + pow(*a, 3));
    } else if ( x <= 1) {
        result = *a;
    } else { // will never be executed
        result = pow(M_E, x);
    }
    return result;
}
/*
int main() {
    float x, *a = new float;

    std::cout << " > Enter x and a value ( separate with spaces ) \n enter x a:  ";
    std::cin >> x; 
    std::cout << " - result:  " << evaluate_y(x, a);

    delete a;

    return 0;
}
*/


// Це не код, це просто коментарі :)
void autotestForLab() {
    float a; 
    float test[] = {2, 0.5, -1.5, 2555};
    srand(time(NULL));
    for (auto x: test) {
        a = (rand() % 200) / 10;
        std::cout << "\n\nPS C:\\Users\\avoqu\\Documents\\Git\\course-kpi-cpp\\src\\lab_2\\kolosov_10\\program>" 
        << "cd \"c:\\Users\\avoqu\\Documents\\Git\\course-kpi-cpp\\src\\lab_2\\kolosov_10\\program\\\" && g++ task2.cpp -o task2 && \"c:\\Users\\avoqu\\Documents\\Git\\course-kpi-cpp\\src\\lab_2\\kolosov_10\\program\"task2";
        std::cout << " \n    > Enter x and a value ( separate with spaces ) \n    enter x a:  ";
        std::cout << x << " " << a ; 
        std::cout << "\n    - result:  " << evaluate_y(x, &a);
    }
}



void manualTestForLab() {
    float x, a;
    std::cout << " > Enter x and a value ( separate with spaces ) \n enter x a:  ";
    std::cin >> x; 
    std::cout << " - result:  " << evaluate_y(x, &a);
}


int main() {

    autotestForLab();
    //manualTestForLab();

    return 0;
}
