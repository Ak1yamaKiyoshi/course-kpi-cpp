#include <iostream>
#include <cmath>

typedef double ( *sinT )(double x);

double sinTaylor(double x) {
    double sum = 0, tempValue = 1;
    for (int i = 0; fabs(tempValue) > 0.001; i++, sum+=tempValue) 
        tempValue = pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2*i+1);
    return sum;
}

double function(sinT sinus,  double x) {
    double y = -1;
    if (0 < x && x <= 1)       y = pow(sinus(x), 2) - sinus(x); 
    else if (-2 < x && x <= 0) y = pow(sinus(x), 3) - sinus(2*x);
    return y;
}

int main() {
    double *res = new double;
    const float LOWER_BOUND = -2, UPPER_BOUND = 2, STEP = 0.5; 
    for (double i = LOWER_BOUND; i <= UPPER_BOUND; i += STEP) {
        // ВИКОРИСТАНО ВКАЗІВНИКИ НА ФУНКЦІЇ 
        double fTailor = function(sinTaylor, i);
        double fOrigin = function(sin, i);
        std::cout 
        << " <iteration: " << UPPER_BOUND - LOWER_BOUND / STEP 
        << "; x: " << i << ">\n" 
        << " > fTailor: " << fTailor << "\n"
        << " > fOrigin: " << fOrigin << "\n" 
        << " > error: " << fabs(fTailor - fOrigin) << "\n";
    }
    return 0;
}
