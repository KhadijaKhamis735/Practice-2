#include <stdio.h>

float balance = 0.0;

void deposit(float amount) {
    balance += amount;
    printf("Deposited %.2f. Current balance: %.2f\n", amount, balance);
}

void withdraw(float amount) {
    if (amount > balance) {
        printf("Insufficient balance!\n");
    } else {
        balance -= amount;
        printf("Withdrew %.2f. Current balance: %.2f\n", amount, balance);
    }
}
