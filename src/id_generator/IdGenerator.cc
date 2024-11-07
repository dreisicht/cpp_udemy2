//  Copyright

#include "IdGenerator.h"

#include <cstddef>
#include <random>
#include <string>

std::string IdGenerator::generate(const size_t& length) {
  // random_device is used instead of a seed to be fully random.
  std::random_device device{};
  std::mt19937 generator(device());
  return IdGenerator::generate(length, generator);
}

std::string IdGenerator::generate(const size_t& length, const int& seed) {
  std::mt19937 generator(seed);
  return IdGenerator::generate(length, generator);
}

std::string IdGenerator::generate(const size_t& length,
                                  std::mt19937& generator) {
  std::string m_random_string(length, 0);
  std::uniform_int_distribution<int> dist(0, m_n_chars - 1);

  for (size_t i = 0; i < length; ++i)
    m_random_string[i] = m_characters[dist(generator)];

  return m_random_string;
}
