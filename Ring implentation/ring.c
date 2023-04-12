#include "ring.h"

struct Ring* newElem(int val){
    struct Ring* buffer = (struct Ring*)malloc(sizeof(struct Ring));
    buffer -> data = val;
    buffer -> next = NULL;
    return buffer;
}

struct Ring* pushAfter(struct Ring* head, int val){
    struct Ring* temp = newElem(val);
    if (head == NULL){
        head = temp;
        head -> next = temp;
    }
    else{
        struct Ring* cursor = head -> next;
        head -> next = temp;
        temp -> next = cursor;
    }
    return head;
}

struct Ring* pushBefore(struct Ring* head, int val){
    struct Ring* temp = newElem(val);
    if (head == NULL){
        head = temp;
        head -> next = temp;
    }
    else{
        struct Ring* cursor = head;
        while(cursor -> next != head){
            cursor = cursor -> next;
        }
        cursor -> next = temp;
        temp -> next = head;
    }
    return head;
}

void outputRing(struct Ring* head){
    if (head == NULL){
        printf("Ring is empty.");
    }
    else {
        struct Ring *cursor = head;
        do {
            printf("%3d", cursor->data);
            cursor = cursor->next;
        } while (cursor != head);
    }
}

struct Ring* popBefore(struct Ring* head){
    if (head == NULL){
        fprintf(stderr, "Ring is empty.");
        abort();
    }
    if (head -> next == head){
        free(head);
        return NULL;
    }
    else{
        struct Ring* cursor = head;
        while(cursor -> next -> next != head){
            cursor = cursor -> next;
        }
        free(cursor -> next);
        cursor -> next = head;
    }
    return head;
}

struct Ring* popAfter(struct Ring* head){
    if (head == NULL){
        fprintf(stderr, "Ring is empty");
        abort();
    }
    if (head -> next == head){
        free(head);
        return NULL;
    }
    else{
        struct Ring* cursor = head -> next;
        head -> next = head -> next -> next;
        free(cursor);
    }
    return head;
}
