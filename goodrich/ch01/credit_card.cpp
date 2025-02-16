#include "credit_card.hpp"

CreditCard::CreditCard(const std::string &num, const std::string &name,
                       int limit, double balance, double interest)
    : _number(num), _name(name), _limit(limit), _balance(balance), _interest(interest) {}

CreditCard::CreditCard(const CreditCard &other)
    : _number(other._number), _name(other._name), _limit(other._limit),
      _balance(other._balance), _interest(other._interest) {}

CreditCard::~CreditCard(void) {}

CreditCard &CreditCard::operator=(const CreditCard &other) {
  if (this == &other) {
    return *this;
  }

  _number = other._number;
  _name = other._name;
  _limit = other._limit;
  _balance = other._balance;
  _interest = other._interest;

  return *this;
}

std::string CreditCard::getNumber(void) const { return _number; }

std::string CreditCard::getName(void) const { return _name; }

double CreditCard::getBalance(void) const { return _balance; }

int CreditCard::getLimit(void) const { return _limit; }

bool CreditCard::chargeIt(double price) {
  if (price <= 0.0) {
    return false;
  }
  if (price + _balance > double(_limit)) {
    return false;
  }

  _balance += price;

  return true;
}

void CreditCard::makePayment(double payment) { _balance -= payment; }

CreditCard::CreditCard(void)
    : _number("0"), _name("none"), _limit(0), _balance(0.0) {}

std::ostream &operator<<(std::ostream &o, const CreditCard &c) {
  o << "Number: " << c.getNumber() << '\n'
    << "Name: " << c.getName() << '\n'
    << "Balance: " << c.getBalance() << '\n'
    << "Limit: " << c.getLimit() << '\n'
  return o;
}
