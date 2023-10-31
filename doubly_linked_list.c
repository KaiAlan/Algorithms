#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* previous;
};

// GETTING NODE
struct node* getNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

//SEARCHING NODE
struct node* searchNode(struct node** start,int dataToBeFound){
    struct node* current = (*start);
    while(current->next != NULL){
        if(current->data == dataToBeFound){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// INSERTING NODES

void insertAtBeginning(struct node** start, int data) {
    struct node* tempNode = getNode(data);
    tempNode->next = *start;
    if (*start != NULL) {
        (*start)->previous = tempNode;
    }
    *start = tempNode;
}

void insertAfterNode(struct node** start, int data, int previousNodeData) {
    struct node* tempNode = getNode(data);
    struct node* current = *start;
    while (current != NULL && current->data != previousNodeData) {
        current = current->next;
    }
    if (current != NULL) {
        tempNode->next = current->next;
        tempNode->previous = current;
        if (current->next != NULL) {
            (current->next)->previous = tempNode;
        }
        current->next = tempNode;
    }
}

void insertBeforeNode(struct node** start, int data, int nextNodeData) {
    struct node* tempNode = getNode(data);
    struct node* current = *start;
    while (current != NULL && current->data != nextNodeData) {
        current = current->next;
    }
    if (current != NULL) {
        tempNode->previous = current->previous;
        tempNode->next = current;
        (current->previous)->next = tempNode;
        current->previous = tempNode;
    }
}

void insertAtEnding(struct node** start, int data) {
    struct node* tempNode = getNode(data);
    struct node* current = *start;
    if (current == NULL) {
        *start = tempNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    tempNode->next = NULL;
    tempNode->previous = current;
    current->next = tempNode;
}

// DELETING NODES
void deleteStartingNode(struct node** start) {
    if (*start != NULL) {
        struct node* temp = *start;
        *start = (*start)->next;
        if (*start != NULL) {
            (*start)->previous = NULL;
        }
        free(temp);
    }
}

void deleteEndingNode(struct node** start) {
    struct node* current = *start;
    if (current == NULL) {
        return; 
    }
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->previous != NULL) {
        (current->previous)->next = NULL;
    } else {
        *start = NULL; 
    }
    free(current);
}

void deleteNode(struct node** start, int dataToBeDeleted) {
    struct node* current = *start;
    while (current != NULL && current->data != dataToBeDeleted) {
        current = current->next;
    }
    if (current != NULL) {
        if (current->previous != NULL) {
            (current->previous)->next = current->next;
        } else {
            *start = current->next;
        }
        if (current->next != NULL) {
            (current->next)->previous = current->previous;
        }
        free(current);
    } else {
        printf("\nNode with data %d not found in the list.", dataToBeDeleted);
    }
}

void deleteBeforeNode(struct node** start, int dataToBeDeleted) {
    struct node* current = *start;
    while (current != NULL && current->data != dataToBeDeleted) {
        current = current->next;
    }
    if (current != NULL) {
        if (current->previous != NULL && current->previous->previous != NULL) {
            struct node* temp = current->previous;
            current->previous = temp->previous;
            (temp->previous)->next = current;
            free(temp);
        } else if (current->previous != NULL) {
            struct node* temp = current->previous;
            *start = current;
            current->previous = NULL;
            free(temp);
        } else {
            printf("\nNo node to delete before %d.", dataToBeDeleted);
        }
    } else {
        printf("\nNode with data %d not found in the list.", dataToBeDeleted);
    }
}

void deleteAfterNode(struct node** start, int dataToBeDeleted) {
    struct node* current = *start;
    while (current != NULL && current->data != dataToBeDeleted) {
        current = current->next;
    }
    if (current != NULL && current->next != NULL) {
        struct node* temp = current->next;
        current->next = temp->next;
        if (temp->next != NULL) {
            (temp->next)->previous = current;
        }
        free(temp);
    } else if (current != NULL) {
        printf("\nNo node to delete after %d.", dataToBeDeleted);
    } else {
        printf("\nNode with data %d not found in the list.", dataToBeDeleted);
    }
}


// PRINTING NODES

void printNode(struct node* start) {
    struct node* current = start;
    while (current != NULL) {
        printf("\ndata = %d ", current->data);
        printf("\nnext = %p ", (void*)current->next);
        printf("\nprevious = %p ", (void*)current->previous);
        current = current->next;
    }
}

int main() {
    struct node* n1 = getNode(11);
    struct node* n2 = getNode(12);
    struct node* n3 = getNode(13);
    struct node* n4 = getNode(14);

    n1->next = n2;
    n2->previous = n1;
    n2->next = n3;
    n3->previous = n2;
    n3->next = n4;
    n4->previous = n3;

    printf("Original list:");
    printNode(n1);

    printf("\nInserting at the beginning:\n");
    insertAtBeginning(&n1, 0);
    printNode(n1);

    printf("\nInserting at the ending:\n");
    insertAtEnding(&n1, 0);
    printNode(n1);

    printf("\nInserting before 13 :\n");
    insertBeforeNode(&n1, 98, 13);
    printNode(n1);
    
     printf("\nInserting after 13 :\n");
    insertAfterNode(&n1, 99, 13);
    printNode(n1);

    printf("\nDeleting at the beginning:\n");
    deleteStartingNode(&n1);
    printNode(n1);

    printf("\nDeleting at the ending :\n");
    deleteEndingNode(&n1);
    printNode(n1);


    printf("\nDeleting before 13 :\n");
    deleteBeforeNode(&n1, 13);
    printNode(n1);
    
    printf("\nDeleting after 13 :\n");
    deleteAfterNode(&n1, 13);
    printNode(n1);
    
    printf("\nDeleting 13 :\n");
    deleteNode(&n1, 13);
    printNode(n1);
    
    printf("\nSearching 12 : \n");
    struct node* temp = searchNode(&n1,12);
    printf("data = %d \nnext = %p \nprevious = %p",temp->data,temp->next,temp->previous);

    return 0;
}