#include <iostream>

// #include "Account_Util.h"
// #include "Savings_Account.h"
// #include "src/id_generator/IdGenerator.h"

#include "src/section15/Account.h"

int main() {
  // std::cout.precision(2);
  // std::cout << std::fixed;
  Account acc{};
  std::cout << acc.idg_->generate(10, 0) << std::endl;

  // Accounts
  // std::vector<Account> accounts;
  // accounts.push_back(Account{});
  // accounts.push_back(Account{"Larry"});
  // accounts.push_back(Account{"Moe", 2000});
  // accounts.push_back(Account{"Curly", 5000});

  // account_util::display(accounts);
  // account_util::deposit(accounts, 1000);
  // account_util::withdraw(accounts, 2000);

  // // Savings

  // std::vector<Savings_Account> sav_accounts;
  // sav_accounts.push_back(Savings_Account{});
  // sav_accounts.push_back(Savings_Account{"Superman"});
  // sav_accounts.push_back(Savings_Account{"Batman", 2000});
  // sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

  // account_util::display(sav_accounts);
  // account_util::deposit(sav_accounts, 1000);
  // account_util::withdraw(sav_accounts, 2000);

  return 0;
}
