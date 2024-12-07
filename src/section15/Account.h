// Copyright

#pragma once
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

#include "src/id_generator/IdGenerator.h"

static constexpr size_t ID_SIZE{2};

class Account {
  friend std::ostream &operator<<(std::ostream &os, const Account &account);

 private:
  const std::string m_name;
  std::string m_uid;

 protected:
  double m_balance;

 public:
  // Constructors
  Account();
  explicit Account(const std::string &name);
  explicit Account(const std::string &name, const double &balance);
  static std::shared_ptr<std::unordered_set<std::string>> m_uids;

  static std::shared_ptr<IdGenerator> idg_;

  bool use_fixed_seed;

  // Member function definitions.
  bool deposit(const double &amount);
  bool withdraw(const double &amount);
  double get_balance() const;
  std::string get_name() const;
  std::string get_uid() const;
};
