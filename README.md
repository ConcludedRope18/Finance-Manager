# Personal Finance Manager

## Introduction
The Personal Finance Manager is a command-line application designed to help users manage their personal finances. Users can track their expenses and income, set saving goals, and view their current balance in the app.

## Features
- **Add Transaction**: Record income and expenses with details such as date, category, amount, and description.
- **View Balance**: Display the current total balance.
- **Set Saving Goal**: Set a savings target to track your progress.
- **View Saving Goal**: Display the current savings target.
- **List Last Transactions**: Show the most recent 10 transactions (or all transactions).

## Installation Instructions
- Clone the repository.
- Compile the project using C++17 or newer.
- Run.

## Usage Instructions
### Menu Options
1. Add Transaction
	-Follow the prompts to enter:
		- Date(DD-MM-YYYY)
		- Category
		- Amount
		- Type (income/expense)
		- Description
	- Example:
		`Enter date (YYYY-MM-DD): 2024-05-17
		Enter category: Food
		Enter amount: 50.0
		Enter type (income/expense): expense
		Enter description: Lunch at Cafe
		Transaction added successfully.`
2. View Balance
	- Displays the current total balance.
3. Set Saving Goal
	- Enter the desired saving goal amount.
4. View Saving Goal
	- Displays the current saving goal.
5. List Last 10 Transactions/List All Transactions
	- Displays the last 10 transactions/displays all past transactions on the account.

### Example Run
`Enter username: user1
Enter password: password123
1. Add Transaction
2. View Balance
3. Set Saving Goal
4. View Saving Goal
5. List Last Transactions
6. Exit
Choose an option: 1
Enter date (YYYY-MM-DD): 2024-05-17
Enter category: Food
Enter amount: 50.0
Enter type (income/expense): expense
Enter description: Lunch at Cafe
Transaction added successfully.
Press Enter to continue...`

## Project Structure
* `main.cpp`: Contains the `main` function of the program.
* `utils.h`/`utils.cpp`: Utility functions for displaying the menu, handling user input, other auxiliary tasks.
* `FinanceManager.h`/`FinanceManager.cpp`: Core functions for managing financial transactions, authentication, and saving goals.
* `User.h`/`User.cpp`: User related data and functions.
* `Transaction.h`/`Transaction.cpp`: Transaction related data and functions.