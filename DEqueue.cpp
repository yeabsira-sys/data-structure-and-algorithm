#include <iostream>
using namespace std;

// deque to store elements of the queue

struct node {
    int data;
    node *prev, *next;
};
node *front = NULL, *rear = NULL;
// Function to insert an element at the front of the queue
void enqueueFront() {
    int element;
    cout << "Enter element to insert at front of queue: ";
    cin >> element;
    node *temp = new node;
    temp -> data = element;
    temp -> next = temp -> prev = NULL;
    if(front == NULL){
         front = temp;
         rear = temp;

    }
    else {
        node *temp1 = front;
        front = temp;
        front -> next = temp1; 
        temp1 -> prev = temp;
    }
    cout<< "Element " << element << " added to front of queue successfully.\n";
}

// Function to insert an element at the back of the queue
void enqueueBack() {
    int element;
    cout << "Enter element to insert at back of queue: ";
    cin >> element;
    node *temp = new node;
    temp -> data = element;
    temp -> next = temp -> prev = NULL;
    if(rear == NULL){
        front = rear = temp;
    }
    else {
        node *temp1 = rear; 
            rear = temp;
            rear -> prev = temp1;
            temp1 -> next = temp;
    }
    cout << "Element " << element << " added to back of queue successfully.\n";
}

// Function to delete an element from the front of the queue
void dequeueFront() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
    }
    else {
       node *temp = front;
   front = front -> next;
   int element = temp -> data;
   delete temp;
   cout << "Element " << element << " deleted from front of queue successfully.\n";   
    }
}

// Function to delete an element from the back of the queue
void dequeueBack() {
   if (rear == NULL) {
        cout << "Queue is empty.\n";
    }
    else {
       node *temp = rear;
   rear = rear -> prev;
   rear -> next = NULL;
   int element = temp -> data;
   delete temp;
   cout << "Element " << element << " deleted from back of queue successfully.\n";   
    }
}

// Function to display all the elements of the queue
void displayQueue() {
    if (front == NULL && rear == NULL)
    {
        cout<<"queue is empty";
    }
    else {
        node *temp = front;
        cout<<"\t\t elements of the stack \n";
        while (temp != NULL)
        {
            cout<<temp -> data<<", ";
            temp = temp -> next;
        }
        
    }
    
}

int main() {
    int choice;
    while (true) {
        cout << "\n\nMenu Operations on queue\n";
        cout << "1. Insert element at front of queue\n2. Insert element at back of queue\n3. Delete element from front of queue\n4. Delete element from back of queue\n5. Display all the elements of queue\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            enqueueFront();
            break;
        case 2:
            enqueueBack();
            break;
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueBack();
            break;
        case 5:
            displayQueue();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Please enter a valid choice.\n";
            break;
        }
    }
    return 0;
}

