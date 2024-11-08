// Copyright

#include <iostream>
#include <vector>

#include <gtest/gtest.h>

#include "fibonacci.h"
#include "gtest/gtest.h"

TEST(SimpleTest, BasicAssertions) {
  std::vector<int> actual = ::fibonacci(100);
  std::vector<int> expected = {1, 2, 4};
  for (long unsigned int i = 0; i < expected.size(); i++) {
    std::cout << actual[i] << " " << expected[i];
    EXPECT_EQ(actual[i], expected[i]);
  }
}

int main(int argc, char **argv) {
  // optional, but recommended for flag parsing
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
