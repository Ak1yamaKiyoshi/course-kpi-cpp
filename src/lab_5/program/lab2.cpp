#include <iostream>
#include <math.h>

typedef double ( *func )(double x);

double chord(func f, double x0, double x1) {
    double x2 = x1 - (x1 - x0) * (f(x1) - f(2 * x1)) / (f(x1) - f(2 * x1) - f(x0) + f(2 * x0));
    if (fabs(x2 - x1) < 0.001) return x2;
    return chord(f, x1, x2);
}

double chord_p(func f, double *x0, double *x1) {
    double x2 = *x1 - (*x1 - *x0) * (f(*x1) - f(2 * (*x1))) / (f(*x1) - f(2 * (*x1)) - f(*x0) + f(2 * *x0));
    if (fabs(x2 - *x1) < 0.001) return x2;
    return chord_p(f, x1, &x2);
}

double function(double x) {
    return 3 * pow(exp(1.0), -3*x);
} 

int main() {
    double limA, limB;
    std::cout << " <Enter lower and upper bounds of the interval>\n" << " - Enter a, b: ";
    std::cin >> limA >> limB;
    for (double i = limA; i < limB; i += 0.1) {
        double j = i + 0.1;
        double x = chord_p(function, &i, &j);
        std::cout << " > x: " << x << "\n";
    }
    
    return 0;
}