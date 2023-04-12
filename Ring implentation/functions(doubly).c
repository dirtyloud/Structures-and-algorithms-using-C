#include "functions.h"


struct Ring* newElement(int data){
    struct Ring* buffer = (struct Ring*)malloc(sizeof(struct Ring));
    buffer -> data = data;
    buffer -> next = NULL;
    buffer -> prev = NULL;
    return buffer;
}

void pushAfter(struct Ring** head, int data){
    struct Ring* newNode = newElement(data);
    if (*head == NULL){
        *head = newNode;
        (*head) -> prev = *head;
        (*head) -> next = *head;
    }
    else{
        struct Ring* buffer = (*head) -> next;
        (*head) -> next = newNode;
        newNode -> prev = (*head);
        newNode -> next = buffer;
        buffer -> prev = newNode;
        if (newNode -> next == (*head)){
            (*head) -> prev = newNode;
        }
    }
}

void pushBefore(struct Ring** head , int data){
    struct Ring* newNode = newElement(data);
    if (*head == NULL){
        *head = newNode;
        (*head) -> prev = *head;
        (*head) -> next = *head;
    }
    else{
        struct Ring* cursor = (*head);
        while(cursor -> next != *head){
            cursor = cursor -> next;
        }
        cursor -> next = newNode;
        newNode -> prev = cursor;
        newNode -> next = (*head);
        (*head) -> prev = newNode;
    }
}

void printRing(struct Ring* head){
    if (head == NULL){
        printf("Ring is empty.\n");
    }
    else{
        struct Ring* cursor = head;
        do{
            printf("%5d", cursor -> data);
            cursor = cursor -> next;
        }while(cursor != head);
    }
}

void popAfter(struct Ring** head){
    if (*head == NULL){
        fprintf(stderr, "Stack is empty.\n");
        abort();
    }
    else if(*head == (*head) -> prev){
        free(*head);
        *head = NULL;
    }
    else{
        struct Ring* buffer = (*head) -> next;
        (*head) -> next = (*head) -> next -> next;
        (*head) -> next -> prev = (*head);
        free(buffer);
    }
}

void popBefore(struct Ring** head){
    if (*head == NULL){
        fprintf(stderr, "Stack is empty.\n");
        abort();
    }
    else if(*head == (*head) -> prev){
        free(*head);
        *head = NULL;
    }
    else{
        struct Ring* cursor = (*head);
        while(cursor -> next -> next != (*head)){
            cursor = cursor -> next;
        }
        struct Ring* buffer = cursor -> next;
        cursor -> next = (*head);
        (*head) -> prev = cursor;
        free(buffer);
    }
}
