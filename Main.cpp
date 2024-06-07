#include "Utils.h"

int main() {
    checkDataDir();

    FinanceManager manager;
    User user;
    int choice;
    
    handleLogin(manager, user);
    std::string filename = "Data/" + user.username + ".csv";

    do {
        std::cout << "\n";
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            clearScreen();
            addTransaction(manager, user);
            manager.saveData(user, filename);
            break;
        case 2:
            clearScreen();
            viewBalance(user);
            break;
        case 3:
            clearScreen();
            setSavingGoal(manager, user);
            break;
        case 4:
            clearScreen();
            viewSavingGoal(manager, user);
            break;
        case 5:
            clearScreen();
            manager.printLastTransactions(user, 10);
            break;
        case 6:
            clearScreen();
            manager.printLastTransactions(user, 1000);
            break;
        case 7:
            std::cout << "Exiting...\n";
            break;
        default:
            clearScreen();
            std::cout << "Invalid choice. Please try again.\n";
        }
        delay(1);
    } while (choice != 7);

    return 0;
}