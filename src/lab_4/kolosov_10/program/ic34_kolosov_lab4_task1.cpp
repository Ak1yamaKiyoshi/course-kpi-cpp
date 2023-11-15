#include <iostream>
#include <cmath>
#include <iomanip>

#define open(mod, x) mod*(mod-x)

float formula(int a, int x, int lim_k) {
  float upper = pow(x, lim_k);
  for (int k = 1; k < lim_k; k+=1, upper *= open(a, k));
  return 1 + upper/tgamma(lim_k+1);
}


int digits(double num) {
  std::stringstream out;
  out << num;
  std::string s = out.str();
  return s.substr(s.find(".")+1).length();
}

int main() {
  int a, x, lim_k;
  std::cout << "Enter a, x, lim_k: ";
  std::cin >> a >> x >> lim_k;

  double result = 1;
  for (int k = 1, precision = 1; precision < 5; k++, precision = digits(result)) {
    result = formula(a, x, k);
    std::cout << " f(k) = " << result << " \n";
  }
}