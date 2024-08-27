#include <iostream>
#include <stack>
using namespace std;

struct node {
    char word;
    node *link;
};
node *top = NULL;
void push(char s){
    node *temp = new node;
    temp -> word = s;
    temp -> link = NULL;
    if(top == NULL){
        top = temp;
    }
    else {
        node *temp1 = top;
        top = temp;
        temp -> link = temp1;
    }
}
void pop() {
    if(top == NULL ) {
        cout<<"the stack is empty";
        return;
    }
    else {
        node *del = top;
        top = top -> link;
        delete del;
    }
}
bool isPalindrome(string str){
for (int i = 0; i < str.size(); i++)
    // Pushing all characters onto the stack
    push(str[i]);

     // Comparing characters from both ends of the string
    for (int i = 0; i < str.size(); i++) {
        if (top -> word != str[i])
            return false;
        pop();
    }

    return true;
}

int main() {
    string str;
    int option = 1;
    while(option != 0){
      cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << str << " is a palindrome\n";
    else
        cout << str << " is not a palindrome\n";
    cout<<"do you want to try again if so enter '1' if not enter '0' ";
    cin>>option;
    }
    return 0;
}
