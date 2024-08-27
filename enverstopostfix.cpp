#include <bits/stdc++.h>
using namespace std;

struct inverser {
    char ch;
    inverser *link;
};
    inverser *top = NULL;
void push(char ch){
    inverser *temp = new inverser;
    temp -> ch = ch;
    temp -> link = NULL;
    if(top == NULL){
        top = temp;
    }
    else {
        inverser *temper = top;
        top = temp;
        temp -> link = temper;
    }
}
void pop() {
    if(top == NULL ) {
        cout<<"the stack is empty";
    }
    else {
        inverser *del = top;
        top = top -> link;
        delete del;
    }
}
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; // For brackets
}

string infixToPostfix(string exp) {
    string postfix = "";
//inverser *temp1 = top;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If scanned character is an operand, add to output string
        if (isalnum(c))
            postfix += c;

        // If scanned character is '(' push it to stack
        else if (c == '(')
            push(c);

        // If scanned character is ')' pop it from stack and append its contents to output
        else if (c == ')') {
    
            while (top != NULL && top -> ch != '(') {
                postfix += top -> ch;
                pop();
            }
            if (top != NULL)
                pop();
        }

        // If scanned character is an operator, pop and append to output
        // those operators in the stack of equal or higher precedence.
         else {
            
            while (top != NULL && prec(c) <= prec(top -> ch)) {
                postfix += top -> ch;
                pop();

            }
            push(c);
        }
     }

     // Pop remaining operators from the stack and add to output
     while (top != NULL) {
         postfix += top -> ch;
         pop();
     }

     return postfix;
}

int main() {
    string exp;
     char say;
    
    menu:
    cout << "Enter an infix expression: ";
    cin >> exp;

    string postfix = infixToPostfix(exp);

    cout << "The corresponding postfix expression is: " << postfix << endl;

    cout<<"do you want to try again ('y' / 'n')\n";
    cin>>say;
    if(say == 'y') {
        goto menu;
    }
    else
        return 0;
    return 0;
}

