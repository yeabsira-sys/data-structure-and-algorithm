#include <iostream>
using namespace std;

struct node{
    int data, priority;
    node *next;
};
node *top = NULL;
void insertToPriorityQueue() {
    node *temp = new node;
    int number, priority;
    cout<<"enter the number : ";
    cin>>number;
    temp -> data = number;
    cout<<"\nenter it's priority : ";
    cin>>priority;
    temp -> priority = priority;
    temp -> next = NULL;
    if(top == NULL){
        top = temp;
    }
    else{
        node *get = top, *temp1;
        if(get -> priority < temp -> priority) {
            top = temp;
            temp -> next = get; 
        }
        
        else if(get -> priority > temp -> priority){
            while (get -> next != NULL && get -> next -> priority >= temp -> priority)
            {
                get = get -> next;  
            }
            temp1 = get -> next;
            get -> next = temp;
            temp -> next = temp1;
        }
    }
    return;
}
// to delete high priority element from the queue
void deleteFromPriorityQueue() {
     if(top == NULL) {
        cout<<"the queue is empty!!\n";
        return;
     }
    node *temp = top;
    top = top -> next;
    int delnum = temp -> data;
    delete temp;
    cout<<"\n deleted number is : "<<delnum;
}
// to display all elements from the stack
void displayprQueue() {
    node *temp = top; 
    cout<<"\tnumber\t\tpriority\n";
    while (temp != NULL)
    {
        cout<<"\t"<<temp -> data<<"\t\t"<<temp -> priority<<endl;
        temp = temp -> next;
    }
    
}
int main() {
    int choice;
    do {
        // Displaying menu of operations on queue
        cout << endl;
        cout << "--------------------------------\n";
        cout << "1. To insert element to queue\n";
        cout << "2. To delete element from queue\n";
        cout << "3. To display all the elements of queue\n";
        cout << "4. To exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                insertToPriorityQueue();
                break;

            case 2:
                deleteFromPriorityQueue();
                break;

            case 3:
                displayprQueue();
                break;

            case 4: 
                break;

            default:
                cout << "\nInvalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

