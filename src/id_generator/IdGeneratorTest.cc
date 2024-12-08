// Copyright

#include <cstddef>

#include <gtest/gtest.h>

#include "IdGenerator.h"

TEST(IdGeneratorTest, Generate) {
  IdGenerator idg;
  size_t len = 5;
#ifdef _WIN64
  EXPECT_EQ(idg.generate(len, 2), "QGA8U");
  EXPECT_EQ(idg.generate(len).length(), len);
#endif
#ifdef __APPLE__
  EXPECT_EQ(idg.generate(len, 2), "PIWSL");
  EXPECT_EQ(idg.generate(len).length(), len);
#endif
}

int main(int argc, char **argv) {
  // optional, but recommended for flag parsing
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
