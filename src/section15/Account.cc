#include "Account.h"

#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

std::shared_ptr<IdGenerator> Account::idg_;
std::shared_ptr<std::unordered_set<std::string>> Account::m_uids;

Account::Account() : Account::Account("Unnamed Account", 0.0) {}

Account::Account(const std::string &name) : Account::Account(name, 0.0) {}

Account::Account(const std::string &name, const double &balance)
    : m_name{name}, m_balance{balance} {
  if (!idg_) idg_ = std::make_shared<IdGenerator>();

#ifdef FIXED_SEED
  // static_assert(true, "FIXED_SEED is defined");
  std::cout << "FS" << std::endl;
  m_uid = idg_->generate(ID_SIZE, 1);
#else
  // static_assert(false, "FIXED_SEED is not defined");
  std::cout << "NFS" << std::endl;
  m_uid = idg_->generate(ID_SIZE);
#endif
  // Creating a shared pointer between all instances to check if the ID is
  // already in use in any of the instances.
  if (!m_uids) m_uids = std::make_shared<std::unordered_set<std::string>>();
  // Check if the ID is already existing, since e.g. fixed seeds may lead to the
  // fact that the ID is already existing.
  if (m_uids->find(m_uid) == m_uids->end()) {
    m_uids->insert(m_uid);
    return;
  } else {
// Error that key already exists, but only in non-testing mode.
#ifndef FIXED_SEED
    throw std::invalid_argument("ID already existing: " + m_uid);
#endif
  }
}

bool Account::deposit(const double &amount) {
  if (amount < 0) {
    return false;
  } else {
    m_balance += amount;
    return true;
  }
}

bool Account::withdraw(const double &amount) {
  if (m_balance - amount >= 0) {
    m_balance -= amount;
    return true;
  } else {
    return false;
  }
}

double Account::get_balance() const { return m_balance; }

std::ostream &operator<<(std::ostream &os, const Account &account) {
  os << "[Account: " << account.m_name << ": " << account.m_balance << "]";
  return os;
}

std::string Account::get_name() const { return m_name; }

std::string Account::get_uid() const { return m_uid; }

// Account::~Account() { delete idg_; }
