#include "FinanceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

FinanceManager::FinanceManager() : savingGoal(0) {}

bool FinanceManager::authenticateUser(const std::string& username) {
    currentUser = loadData("Data/" + username + ".csv");
    return (currentUser.username == username);
}

bool FinanceManager::checkPassword(const std::string& password) {
    return (currentUser.password == password);
}

void FinanceManager::registerUser(const std::string& username, const std::string& password) {
    currentUser.username = username;
    currentUser.password = password;
    saveData(currentUser, "Data/" + username + ".csv");
}

void FinanceManager::saveData(const User& user, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << user.username << "," << user.password << "," << user.savingGoal << "\n";
        for (const auto& transaction : user.transactions) {
            outFile << transaction.date << ","
                << transaction.category << ","
                << transaction.amount << ","
                << transaction.type << ","
                << transaction.description << "\n";
        }
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}

User FinanceManager::loadData(const std::string& filename) {
    User user;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        std::getline(inFile, line);
        std::istringstream ss(line);
        std::getline(ss, user.username, ',');
        std::getline(ss, user.password, ',');
        ss >> user.savingGoal;

        while (std::getline(inFile, line)) {
            Transaction transaction;
            std::istringstream ss(line);
            std::getline(ss, transaction.date, ',');
            std::getline(ss, transaction.category, ',');
            ss >> transaction.amount;
            ss.ignore();
            std::getline(ss, transaction.type, ',');
            std::getline(ss, transaction.description);
            user.transactions.push_back(transaction);
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to open file for reading\n";
    }
    return user;
}

void FinanceManager::addTransaction(User& user, const Transaction& transaction) {
    if (transaction.type == "expense" && (user.getTotalBalance() - transaction.amount) < 0) {
        if (!confirmNegativeBalance()) {
            return;
        }
    }
    user.transactions.push_back(transaction);
    checkSavingGoal(user);
    saveData(user, "Data/" + user.username + ".csv");
}

void FinanceManager::setSavingGoal(User& user, double goal) {
    user.savingGoal = goal;
}

double FinanceManager::getSavingGoal(const User& user) const {
    return user.savingGoal;
}

bool FinanceManager::confirmNegativeBalance() {
    std::cout << "Warning: This transaction will result in a negative balance. Do you want to proceed? (yes/no): ";
    std::string response;
    std::cin >> response;
    return (response == "yes");
}

void FinanceManager::checkSavingGoal(User& user) {
    if (user.getTotalBalance() >= user.savingGoal && user.savingGoal > 0) {
        std::cout << "\nCongratulations! You have reached your saving goal of " << user.savingGoal << "!\n\n";
        user.savingGoal = 0;
        saveData(user, "data/" + user.username + ".csv");
    }
}

void FinanceManager::printLastTransactions(const User& user, int count) {
    int start = std::max(0, (int)user.transactions.size() - count);
    std::cout << "Last " << std::min(count, (int)user.transactions.size()) << " transactions:\n";
    for (int i = start; i < user.transactions.size(); ++i) {
        const auto& transaction = user.transactions[i];
        std::cout << transaction.date << " | "
            << transaction.category << " | "
            << std::fixed << std::setprecision(2) << transaction.amount << " | "
            << transaction.type << " | "
            << transaction.description << "\n";
    }
}