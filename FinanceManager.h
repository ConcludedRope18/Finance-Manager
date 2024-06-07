#pragma once
#include "User.h"
#include <string>
#include <iomanip>

class FinanceManager {
public:
    FinanceManager();

    bool authenticateUser(const std::string& username);
    bool checkPassword(const std::string& password);
    void registerUser(const std::string& username, const std::string& password);
    void saveData(const User& user, const std::string& filename);
    User loadData(const std::string& filename);
    void addTransaction(User& user, const Transaction& transaction);
    void setSavingGoal(User& user, double goal);
    double getSavingGoal(const User& user) const;
    bool confirmNegativeBalance();
    void checkSavingGoal(User& user);
    void printLastTransactions(const User& user, int count = 10);

private:
    User currentUser;
    double savingGoal;
};