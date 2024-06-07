#include "User.h"

double User::getTotalBalance() const {
    return getTotalIncome() - getTotalExpenses();
}

double User::getTotalIncome() const {
    double total = 0;
    for (const auto& transaction : transactions) {
        if (transaction.type == "income") {
            total += transaction.amount;
        }
    }
    return total;
}

double User::getTotalExpenses() const {
    double total = 0;
    for (const auto& transaction : transactions) {
        if (transaction.type == "expense") {
            total += transaction.amount;
        }
    }
    return total;
}