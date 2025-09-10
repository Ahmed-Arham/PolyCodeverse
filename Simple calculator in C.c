#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
float calculate(float num1, float num2, char operation);

int main() {
    char choice;
    float num1, num2, result;
    
    printf("Welcome to Simple Calculator!\n\n");
    
    do {
        displayMenu();
        
        printf("Enter your choice (1-5): ");
        scanf(" %c", &choice);
        
        if(choice == '5') {
            printf("Thank you for using the calculator. Goodbye!\n");
            break;
        }
        
        if(choice < '1' || choice > '5') {
            printf("Invalid choice! Please try again.\n\n");
            continue;
        }
        
        printf("Enter first number: ");
        scanf("%f", &num1);
        
        printf("Enter second number: ");
        scanf("%f", &num2);
        
        // Perform calculation based on user's choice
        switch(choice) {
            case '1':
                result = calculate(num1, num2, '+');
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case '2':
                result = calculate(num1, num2, '-');
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case '3':
                result = calculate(num1, num2, '*');
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case '4':
                if(num2 == 0) {
                    printf("Error: Division by zero is not allowed!\n");
                } else {
                    result = calculate(num1, num2, '/');
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
        }
        
        printf("\n");
        
    } while(1);
    
    return 0;
}

void displayMenu() {
    printf("Please select an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

float calculate(float num1, float num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}
