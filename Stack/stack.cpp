#include <iostream>
using namespace std;

class Stack {
   public:
    int *arr;
    int TOP;
    int size;

    void push(int value) {
        if (TOP == size - 1) {
            cout << "OVERFLOW\n";
        } else {
            TOP++;
            arr[TOP] = value;
        }
    }

    int pop() {
        if (TOP == -1) {
            cout << "UNDERFLOW\n";
        } else {
            int value = arr[TOP];
            TOP--;
            return value;
        }
        return -1;
    }

    int peek() {
        if (TOP == -1) {
            cout << "EMPTY STACK\n";
        } else {
            return arr[TOP];
        }
        return -1;
    }

    void display() {
        if (TOP == -1) {
            cout << "EMPTY STACK\n";
        } else {
            for (int i = 0; i <= TOP; i++)
                cout << arr[i] << endl;
        }
    }

    Stack(int size) {
        this->size = size;
        arr = new int[this->size];
        TOP = -1;
    }
};

int main() {
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.push(6);
    cout << "top of the stack: " << s.peek() << endl;
    cout << "popped: " << s.pop() << endl;
    cout << "popped: " << s.pop() << endl;
    s.display();
    return 0;
}