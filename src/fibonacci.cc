// Copyright
#include "fibonacci.h"

#include <vector>

std::vector<int> fibonacci(int limiter) {
  int x = 0;
  int y = 1;
  std::vector<int> result;  // Create an empty vector

  while (x < limiter) {
    result.push_back(y);
    x = y;
    y = x + y;
  }

  return result;
}
