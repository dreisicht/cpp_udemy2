#include <iostream>

int main() {
#ifdef ASDF
  std::cout << "YES" << std::endl;
#else
  std::cout << "NO" << std::endl;
#endif
  return 0;
}
