#include <stdio.h>
#include <stdlib.h> // to use malloc()

struct Node {

    // struct Node: user defined data type
    // info: value stored in node
    // link: a pointer to the next node is linked list

    int info;
    struct Node *link;
};



struct Node *newNode(int value) {

    /*
    this function creates a new node dynamically
    using malloc()
    assigns the paramater value to the info part of the node
    by default the new node points to null but the link
    can be pointed to some other node
    */

    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->info = value;
    ptr->link = NULL;
    return ptr;

}

void Traverse(struct Node *START) {

    /*
    this function takes the START of a linked link
    and assigns it to a temporary node pointer

    if the node is not NULL i.e. exists, 
    it will print the value stored in that node
    and then changes the temp to the next node
    */

    struct Node *temp = START;

    while(temp != NULL) {
        printf("[%d]->", temp->info);
        temp = temp->link;
    }
    printf("X\n");


}


void InsertAtFirst(struct Node **START, int value) {

    // HERE a double pointer for START is used
    // since we need the address of START to point it
    // at something new while retaining the address of START

    /*
    here, new node created = N_new;
    ALGORITHM: (ignoring AVAIL-LIST)
        1. Create new node
        2. LINK[N_new] = START
        3. START = N_new
        4. INFO[N_new] = value;
    */

    struct Node *N_new = newNode(value);
    N_new->link = *START;
    *START = N_new;
    N_new->info = value;


}

void InsertAtEnd(struct Node **START, int value) {

    /*
    here, new node created = N_new;
    ALGORITHM: (ignoring AVAIL-LIST)
        1. Create new node
        2. LINK[N_new] = NULL
        3. INFO[N_new] = value;
        3. List is empty (START == NULL): START = N_new, EXIT
        4. List is not empty
        5. Create a lastNode = START
        6. LOOP: lastNode = link[lastNode] if link[lastNode] != NULL
        7. If link[lastNode] == NULL, link[lastNode] = N_new
                
    */

    struct Node *N_new = newNode(value);
    N_new->link = NULL;
    N_new->info = value;

    if(*START == NULL) {
        *START = N_new;
    }
    else {
        struct Node *lastNode = *START;
        while(lastNode->link != NULL) {
            lastNode = lastNode->link;
        }
        lastNode->link = N_new;
    }


}



int main() {

    // header node - starting point --- START with name A
    // since A holds the address of first node, A is the only
    // way to keep track of our created linked list
    
    struct Node *A;
    A = NULL; // initially points to NULL -- empty linked list
    struct Node *N1 = newNode(1);
    struct Node *N2 = newNode(2);
    struct Node *N3 = newNode(3);
    A = N1;
    N1->link = N2;
    N2->link = N3;
    N3->link = NULL;
    Traverse(A);
    InsertAtFirst(&A, 7);
    Traverse(A);
    InsertAtEnd(&A, 9);
    Traverse(A);

    return 0;
}