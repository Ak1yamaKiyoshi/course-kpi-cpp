#include <iostream>
#include <math.h>

int main() {
    float x;
    float result;

    auto function = [](float x) -> float { return pow(x, 5) + (pow(x, 4) / tan(x)) + 1; };

    std::cout << " > Enter x: \n x: ";
    std::cin >> x;

    result = function(x);
    
    std::cout  << " - Result: ";
    if (isnan(result)) {
        std::cout << " Wrong x, try another value. is nan.  ";
    }
    else {
        std::cout << result;
    }
    std::cout << "\n";

    return 0;
}
