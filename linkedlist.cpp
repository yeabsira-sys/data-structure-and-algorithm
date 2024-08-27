#include <iostream>
using namespace std;

// Node structure
struct node {
    int data;
    node* next;
};

node* head = NULL;

// Function to create a new node
node* getNewNode(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
     newNode->next = head;
    head = newNode;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    node* newNode = getNewNode(data);
   // newNode->next = head;
   // head = newNode;
    cout << data << " inserted at beginning successfully.\n";
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    node* newNode =  new node;
   newNode -> data = data;
   newNode -> next = NULL;
   if(head == NULL){
    head = newNode;
    cout << data << " inserted at end successfully.\n";

   }
        
    else {
        node *temp = head;
    while (temp -> next != NULL)
        temp = temp -> next;

        temp -> next = newNode;
        cout << data << " inserted at end successfully.\n";
    }
     
}
// Function to insert a node at any position
void insertAtPosition(int data, int position) {
    node* newNode = new node;
    newNode -> data = data;
    if (position < 1) {
        cout << "Invalid position. Please enter a valid position.\n";
        return;
    }
   
    else if (position == 1) {
        newNode->next = head;
        head = newNode;
        cout << data << " inserted at position " << position << " successfully.\n";
        return;
    }
    else {
        node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            cout << "Position out of bounds. Please enter a valid position.\n";
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << data << " inserted at position " << position << " successfully.\n";
    }
    
}

// Function to sort the list
void sortList() {
    node* current = head;
    node* index = NULL;
    int temp;
    if (head == NULL) {
        return;
    }
    else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    cout << "List sorted successfully.\n";
}

// Function to delete a particular node
void deleteNode(int key) {
    node* temp = head;
    node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        delete temp;
        cout << key << " deleted successfully.\n";
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << key << " not found.\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << key << " deleted successfully.\n";
}

// Function to search for an element in the list
void searchElement(int key) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << key << " found.\n";
            return;
        }
        temp = temp->next;
    }
    cout << key << " not found.\n";
}

// Function to display the list
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the list
void reverse() {
    node* current = head;
    node *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    cout << "List reversed successfully.\n";
}

int main() {
    int choice, data, position, key;
    while (true) {
        cout <<endl;
        cout << "1. Create node\n2. Insert node at beginning\n3. Insert node at end\n4. Insert node at any position\n5. Sort list\n6. Delete a particular node\n7. Search element from list\n8. Display list\n9. Reverse list\n0. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            getNewNode(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            insertAtBeginning(data);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            insertAtEnd(data);
            break;
        case 4:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            insertAtPosition(data, position);
            break;
        case 5:
            sortList();
            break;
        case 6:
            cout << "Enter key to delete: ";
            cin >> key;
            deleteNode(key);
            break;
        case 7:
            cout << "Enter element to search: ";
            cin >> key;
            searchElement(key);
            break;
        case 8:
            display();
            break;
        case 9:
            reverse();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice. Please enter a valid choice.\n";
            break;
        }
    }
    return 0;
}

