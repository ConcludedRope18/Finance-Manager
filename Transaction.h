#pragma once
#include <string>

struct Transaction {
    std::string date; // DD-MM-YYYY
    std::string category; // fun or subscription or food or w/e
    double amount;
    std::string type; // income or expense
    std::string description;
};