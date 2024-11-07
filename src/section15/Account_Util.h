// Copyright

#pragma once

#include <vector>

#include "Account.h"
#include "Savings_Account.h"

namespace account_util {

// Utility helper functions for Account class

void display(const std::vector<Account> &accounts);
void deposit(const std::vector<Account> &accounts, double amount);
void withdraw(const std::vector<Account> &accounts, double amount);

// Utility helper functions for Savings Account class

void display(const std::vector<Savings_Account> &accounts);
void deposit(const std::vector<Savings_Account> &accounts, double amount);
void withdraw(const std::vector<Savings_Account> &accounts, double amount);
}  // namespace account_util
