#pragma once
#include "FinanceManager.h"
#include <iostream>

void checkDataDir();
void displayMenu();
void handleLogin(FinanceManager& manager, User& user);
void addTransaction(FinanceManager& manager, User& user);
void viewBalance(const User& user);
void setSavingGoal(FinanceManager& manager, User& user);
void viewSavingGoal(const FinanceManager& manager, const User& user);
void clearScreen();
void delay(int seconds);