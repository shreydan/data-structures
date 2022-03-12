#include <iostream>
using namespace std;

class Queue {
   private:
    bool overflow() {
        if (FRONT == 0 && REAR == size - 1) {
            return true;
        }
        return false;
    }

    bool underflow() {
        if (FRONT == -1) {
            return true;
        }
        return false;
    }

   public:
    int FRONT;
    int REAR;
    int size;
    int *arr;

    void enqueue(int value) {
        if (!overflow()) {
            if (FRONT == -1 && REAR == -1) {
                FRONT++;
            }
            REAR++;
            arr[REAR] = value;
        } else {
            cout << "overflow\n";
        }
    }

    int dequeue() {
        if (!underflow()) {
            FRONT++;
            return arr[FRONT - 1];
        } else {
            cout << "underflow\n";
        }
        return -1;
    }

    void display() {
        if (!underflow()) {
            for (int i = FRONT; i <= REAR; i++)
                cout << arr[i] << endl;
        } else {
            cout << "empty queue\n";
        }
    }

    Queue(int size) {
        this->size = size;
        FRONT = -1;
        REAR = -1;
        arr = new int[size];
    }
};

int main() {
    Queue q(5);
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    cout << "removed: " << q.dequeue() << endl;
    cout << "removed: " << q.dequeue() << endl;
    q.display();
    return 0;
}