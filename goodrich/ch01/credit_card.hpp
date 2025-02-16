#pragma once

#include <iostream>
#include <string>

class CreditCard {
public:
  CreditCard(const std::string &num, const std::string &name, int limit, double balance=0, double interest=0.01);
  CreditCard(const CreditCard &other);
  ~CreditCard(void);

  CreditCard &operator=(const CreditCard &other);

  std::string getNumber(void) const;
  std::string getName(void) const;
  double getBalance(void) const;
  int getLimit(void) const;

  bool chargeIt(double price);
  void makePayment(double payment);

private:
  CreditCard(void);
  std::string _number;
  std::string _name;
  int _limit;
  double _balance;
  double _interest;
};

std::ostream &operator<<(std::ostream &o, const CreditCard &c);
