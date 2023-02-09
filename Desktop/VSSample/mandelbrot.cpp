#include <iostream>
#include <complex>
#include <cmath>

const int WIDTH = 80;
const int HEIGHT = 40;
const int MAX_ITER = 100;

int main() {
  std::complex<double> z, c;

  for (int y = HEIGHT - 1; y >= 0; --y) {
    for (int x = 0; x < WIDTH; ++x) {
      z = c = std::complex<double>(
        (4.0 * x / WIDTH - 2),
        (2.0 * y / HEIGHT - 1)
      );

      int iterations = 0;
      while (std::abs(z) < 2 && iterations < MAX_ITER) {
        z = std::pow(z, 2) + c;
        ++iterations;
      }

      std::cout << (iterations == MAX_ITER ? "*" : " ");
    }
    std::cout << std::endl;
  }

  return 0;
}
