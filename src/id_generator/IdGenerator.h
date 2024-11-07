#pragma once

#include <cstddef>
#include <random>
#include <string>

class IdGenerator {
  // Character set for the random string
 private:
  static const constexpr char* m_characters{
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "0123456789"};
  static const constexpr size_t m_n_chars{26 + 10};

 public:
  std::string generate(const size_t& length);
  std::string generate(const size_t& length, const int& seed);
  std::string generate(const size_t& length,
                       std::mt19937& generator);  // NOLINT(runtime/references)
};
