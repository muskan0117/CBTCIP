#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Muskan Suryavanshi

#define SAV 1
#define CUR 2

struct Account {
    int number;
    char name[100];
    int type;
    float balance;
};

void initializeAccount(struct Account *acc);
void deposit(struct Account *acc, float amount);
void withdraw(struct Account *acc, float amount);
void checkBalance(struct Account *acc);
void calculateInterest(struct Account *acc);

int main() {
    printf("Welcome to the Bank Account Management System\n");

    struct Account user;
    initializeAccount(&user);

    int choice;
    float amount;
    do {
        printf("\nMenu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Calculate Interest\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&user, amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&user, amount);
                break;
            case 3:
                checkBalance(&user);
                break;
            case 4:
                calculateInterest(&user);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to initialize the account with default values
void initializeAccount(struct Account *acc) {
    acc->number = 1001;
    strcpy(acc->name, "Muskan Suryavanshi");
    acc->type = SAV;
    acc->balance = 0.0;
}

// Function to deposit an amount into the account
void deposit(struct Account *acc, float amount) {
    acc->balance += amount;
    printf("Deposit successful. Updated balance: %.2f\n", acc->balance);
}

// Function to withdraw an amount from the account
void withdraw(struct Account *acc, float amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Withdrawal successful. Updated balance: %.2f\n", acc->balance);
    } else {
        printf("Insufficient funds. Withdrawal failed.\n");
    }
}

// Function to check the account balance
void checkBalance(struct Account *acc) {
    printf("Account Balance: %.2f\n", acc->balance);
}

// Function to calculate and display the interest based on account type
void calculateInterest(struct Account *acc) {
    float rate;
    if (acc->type == SAV) {
        rate = 0.05; // 5% interest rate for savings account
    } else if (acc->type == CUR) {
        rate = 0.02; // 2% interest rate for current account
    } else {
        rate = 0.0; // No interest for other types
    }
    float interest = acc->balance * rate;
    printf("Interest calculated: %.2f\n", interest);
}

