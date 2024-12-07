// Copyright

#include <iostream>
#include <stdexcept>

#include <gtest/gtest.h>

#include "src/section15/Account.h"

TEST(SimpleTest, duplicateID) {
  std::function<void()> exc_lambda = []() {
    // Assuming, that if we generate as many accounts, as there are
    // combinations, that we are going to run into the issue.
    for (int i = 0; i < 36 * 36; i++) {
      std::cout << "Building account.." << std::endl;
      Account acc{"name1", 1000};

      // Print list of UIDs.
      std::cout << "UIDs: ";
      for (auto& uid : *acc.m_uids) std::cout << uid << " ";
      std::cout << std::endl;
    }
  };
  EXPECT_THROW(exc_lambda(), std::invalid_argument);
}

int main(int argc, char** argv) {
  // optional, but recommended for flag parsing
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
