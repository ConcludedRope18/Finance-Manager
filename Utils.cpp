#include "Utils.h"
#include <filesystem>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace fs = std::filesystem;

void checkDataDir() {
    const std::string dataDir = "Data";
    if (!fs::exists(dataDir)) {
        fs::create_directory(dataDir);
        std::cout << "Created 'Data' directory.\n";
    }
}

void handleLogin(FinanceManager& manager, User& user) {
    std::string username, password;
    while (true) {
        std::cout << "Enter username: ";
        std::cin >> username;

        if (!manager.authenticateUser(username)) {
            std::cout << "User not found. Registering new user...\n";
            std::cout << "Enter password: ";
            std::cin >> password;
            manager.registerUser(username, password);
            user = manager.loadData("data/" + username + ".csv");
            break;
        }
        else {
            std::cout << "Enter password: ";
            std::cin >> password;

            if (manager.checkPassword(password)) {
                user = manager.loadData("data/" + username + ".csv");
                break;
            }
            else {
                while (true) {
                    std::cout << "Incorrect password. Would you like to try again? (yes/no): ";
                    std::string response;
                    std::cin >> response;
                    if (response == "yes") {
                        std::cout << "Enter password: ";
                        std::cin >> password;
                        if (manager.checkPassword(password)) {
                            user = manager.loadData("data/" + username + ".csv");
                            break;
                        }
                    }
                    else if (response == "no") {
                        break;
                    }
                    else {
                        std::cout << "Invalid response. Please enter 'yes' or 'no'.\n";
                    }
                }
                if (user.username.empty()) {
                    continue;
                }
                else {
                    break;
                }
            }
        }
    }
}

void displayMenu() {
    std::cout << "1. Add Transaction\n";
    std::cout << "2. View Balance\n";
    std::cout << "3. Set Saving Goal\n";
    std::cout << "4. View Saving Goal\n";
    std::cout << "5. List Last 10 Transactions\n";
    std::cout << "6. List All Transactions\n";
    std::cout << "7. Exit\n";
    std::cout << "Choose an option: ";
}

void addTransaction(FinanceManager& manager, User& user) {
    Transaction transaction;
    std::cout << "Enter date (DD-MM-YYYY): ";
    std::cin >> transaction.date;
    std::cout << "Enter category: ";
    std::cin >> transaction.category;
    std::cout << "Enter amount: ";
    std::cin >> transaction.amount;
    std::cout << "Enter type (income/expense): ";
    std::cin >> transaction.type;
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, transaction.description);
    manager.addTransaction(user, transaction);
    std::cout << "Transaction added successfully.\n";
}

void viewBalance(const User& user) {
    std::cout << "Total Balance: " << std::fixed << std::setprecision(2) << user.getTotalBalance() << "\n";
}

void setSavingGoal(FinanceManager& manager, User& user) {
    double goal;
    std::cout << "Enter saving goal: ";
    std::cin >> goal;
    manager.setSavingGoal(user, goal);
    manager.saveData(user, "Data/" + user.username + ".csv");
    std::cout << "Saving goal set to " << std::fixed << std::setprecision(2) << goal << "\n";
}

void viewSavingGoal(const FinanceManager& manager, const User& user) {
    std::cout << "Saving Goal: " << std::fixed << std::setprecision(2) << manager.getSavingGoal(user) << "\n";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void delay(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}