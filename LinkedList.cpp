#wap for linked list in c++ using stack.

#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node* next;
    Node(int val) {
        info = val;
        next = NULL;
    }
};

void Push(Node* &top, int item) {
    Node* temp = new Node(item);
    temp->next = top;
    top = temp;
    cout << item << " pushed to stack." << endl;
}

int Pop(Node* &top) {
    if (top == NULL) {
        cout << "Underflow." << endl;
        return -1; // Return -1 to indicate stack is empty
    }
    Node* temp = top;
    int item = temp->info;
    top = top->next;
    delete temp;
    cout << item << " popped from stack." << endl;
    return item;
}

int Peek(Node* top) {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return top->info;
}

void Traverse(Node* top) {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* temp = top;
    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main () {
    Node* top = NULL;
    int choice, item;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Traverse\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                Push(top, item);
                break;
            case 2:
                Pop(top);
                break;
            case 3:
                item = Peek(top);
                if (item != -1) {
                    cout << "Top item is: " << item << endl;
                }
                break;
            case 4:
                Traverse(top);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}