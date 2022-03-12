#include <iostream>
using namespace std;

class LinkedList {
    class Node {
       public:
        int value;
        Node *link;

        Node(int value) {
            this->value = value;
        }
    };

   public:
    Node *head;
    int length;

    void traverse() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->value << " -> ";
            temp = temp->link;
        }
        cout << "[X]\n";
    }

    void insertNode(int value, int position) {
        // indexing starts at 1
        // if position = 1 : insert at first
        // if position = -1 : insert at last
        // if position = n : insert at index n

        Node *newNode = new Node(value);

        if (position == 1) {
            newNode->link = head;
            head = newNode;
        } else if (position == -1) {
            if (head == NULL) {
                head = newNode;
            } else {
                Node *lastNode = head;
                while (lastNode->link != NULL) {
                    lastNode = lastNode->link;
                }
                lastNode->link = newNode;
            }
        } else {
            if (position < 0 || position > length + 1) {
                cout << "invalid position" << endl;
            } else {
                Node *prevNode = head;
                for (int i = 1; i < position - 1; i++) {
                    prevNode = prevNode->link;
                }
                newNode->link = prevNode->link;
                prevNode->link = newNode;
            }
        }

        length++;
    }

    int deleteNode(int position) {
        // if position = 1 : delete first node
        // if position = n : delete nth node

        if (head == NULL) {
            cout << "empty list" << endl;
            return -1;
        }

        int value;

        if (position == 1) {
            value = head->value;
            head = head->link;
        } else if (position > 1 && position <= length) {
            Node *prevNode = head;
            for (int i = 1; i < position - 1; i++) {
                prevNode = prevNode->link;
            }
            value = prevNode->link->value;
            prevNode->link = prevNode->link->link;
        } else {
            cout << "invalid position" << endl;
            return -1;
        }

        length--;
        return value;
    }

    LinkedList() {
        head = NULL;
        length = 0;
    }
};

int main() {
    LinkedList list;
    list.insertNode(5, 1);
    list.insertNode(10, 1);
    list.insertNode(15, -1);
    list.insertNode(20, 2);
    list.traverse();
    cout << "deleted Node: " << list.deleteNode(2) << endl;
    list.traverse();
    return 0;
}