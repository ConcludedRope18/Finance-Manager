#pragma once
#include <string>
#include <vector>
#include "Transaction.h"

class User {
public:
    std::string username;
    std::string password;
    std::vector<Transaction> transactions;
    double savingGoal;

    User() : savingGoal(0) {}

    double getTotalBalance() const;
    double getTotalIncome() const;
    double getTotalExpenses() const;
};