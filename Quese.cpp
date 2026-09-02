#include <iostream>
#define SIZE 10
using namespace std;

class Queue {
    int front, rear;
    int front, rear;

    void initialize() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }   

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (isEmpty()) {
            front++;
        }
        rear++;
        arr[rear] = item;
        cout << item << " enqueued to queue." << endl;
    }
    
    int dequeue() {
        int item;
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        item = data[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return item;
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.initialize();
    int ch, info;
    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. is Empty" << endl;
        cout << "5. is Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the item to be enqueued: ";
                cin >> info;
                q.enqueue(info);
                break;
            case 2:
                info = q.dequeue();
                if (info != -1) {
                    cout << "Dequeued: " << info << endl;
                }
                break;
            case 3:
                q.traverse();
                break;
            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (ch != 6);
    return 0;
}