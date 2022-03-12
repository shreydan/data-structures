// array implementation of circular queue

#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int FRONT = -1;
int REAR = -1;

int underflow() {
    // condition to check for deletion

    /*
    if FRONT == -1 - no elt in list
        F
          _ _ _ _ _
    */


    if(FRONT == -1){
        printf("\nUNDERFLOW, cannot delete\n");
        return 1;
    }
    return 0;
}


int overflow() {
    // condition to check for insertion
    /*
    overflow conditions:

    FRONT = 0, REAR = SIZE-1
        F
        1 2 3 4 5
                R
    
    FRONT = REAR+1, arises in circular queue

                F
        1 2 3 4 5 
              R
    */


    if ((FRONT == 0 && REAR == SIZE-1) || (FRONT = REAR + 1)) {
        printf("\nOVERFLOW, cannot insert\n");
        return 1;
    }

    return 0;
}

void ENQUEUE(int value) {
    if(!overflow()) {
        if(FRONT == -1 && REAR==-1) {
            FRONT++;
        }
        REAR = (REAR + 1) % SIZE;
        queue[REAR] = value;
    }
}

int DEQUEUE() {
    int temp;
    if(!underflow()) {
        temp = queue[FRONT];
        FRONT++;
    }
    return temp;
}
