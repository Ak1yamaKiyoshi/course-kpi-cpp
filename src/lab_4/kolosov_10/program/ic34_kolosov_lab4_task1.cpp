#include <iostream>
#include <cmath>
#include <iomanip>

#define open(mod, x) mod*(mod-x)


float formula(int a, int x, int lim_k) {
  float upper = pow(x, lim_k);
  for (int k = 1; k < lim_k; k+=1, upper *= open(a, k));
  return 1 + upper/tgamma(lim_k+1);
}

int main() {
  int a, x, lim_k;
  std::cout << "Enter a, x, lim_k: ";
  std::cin >> a >> x >> lim_k;

  for (int k = 1; k < lim_k+1; k++) 
    std::cout << " f(k) = " << formula(a, x, k) << " \n";

}