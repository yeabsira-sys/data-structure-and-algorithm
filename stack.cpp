#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int top = -1;
int stack[MAX_SIZE];

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow! Cannot push element " << element << " onto the stack.\n";
    }
    else {
        top++;
        stack[top] = element;
        cout << "Element " << element << " pushed onto the stack successfully.\n";
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        cout << "Stack underflow! Cannot pop element from the stack.\n";
    }
    else {
        int element = stack[top];
        top--;
        cout << "Element " << element << " popped from the stack successfully.\n";
    }
}

// Function to display the contents of the stack
void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
    }
    else {
        cout << "Contents of the stack are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, element;
    while (true) {
        cout << "\n";
        cout << "1. enter '1' Push elements onto the stack\n2. Pop elements from the stack\n3. Display the contents of the stack\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter element to push onto the stack: ";
            cin >> element;
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please enter a valid choice.\n";
            break;
        }
    }
    return 0;
}

