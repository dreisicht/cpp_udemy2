// Copyright

#include <gtest/gtest.h>

#include "src/section15/Account.h"

TEST(SimpleTest, NoArgs) {
  Account acc{};
  EXPECT_EQ(acc.get_name(), "Unnamed Account");
  EXPECT_EQ(acc.get_balance(), 0.0);
  EXPECT_EQ(acc.get_uid(), "MI");
}
TEST(SimpleTest, NameArg) {
  Account acc{"Larry", false};
  EXPECT_EQ(acc.get_name(), "Larry");
  EXPECT_EQ(acc.get_balance(), 0.0);
  EXPECT_EQ(acc.get_uid(), "MI");
}
TEST(SimpleTest, NameArg2) {
  Account acc{"Moe", 2000};
  EXPECT_EQ(acc.get_name(), "Moe");
  EXPECT_EQ(acc.get_balance(), 2000.0);
  EXPECT_EQ(acc.get_uid(), "MI");
}
TEST(SimpleTest, NameArg3) {
  Account acc{"Curly", 5000};
  EXPECT_EQ(acc.get_name(), "Curly");
  EXPECT_EQ(acc.get_balance(), 5000.0);
  EXPECT_EQ(acc.get_uid(), "MI");
}

int main(int argc, char **argv) {
  // optional, but recommended for flag parsing
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
