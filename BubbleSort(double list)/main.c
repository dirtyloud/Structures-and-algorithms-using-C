#include <stdio.h>
#include <stdlib.h>


struct node{
    int val;
    struct node* next;
    struct node* prev;
};

typedef struct node node;


node* pushBack(node*, int);
void printList(node*);
node* insertLast(node*, int);
node* addInSpecifiedPos(node*, size_t, int);
node* BubbleSort(node*);
int sizeOfList(node*);

int main(){
    node* head = NULL;
    head = pushBack(head, 1);
    head = pushBack(head, 2);
    head = pushBack(head, 3);
    head = pushBack(head, 4);
    head = pushBack(head, 5);
    head = pushBack(head, 6);
    head = pushBack(head, 7);
    head = pushBack(head, 8);
    head = pushBack(head, 9);
    head = pushBack(head, 10);
    printf("\n"); printList(head);
    head = BubbleSort(head);
    printf("\n"); printList(head);
    return 0;
}


void printList(node* head){
    while(head){
        printf("%5d", head -> val);
        head = head -> next;
    }
}


node* pushBack(node* head, int value){
    node* tmp = (node*)malloc(sizeof(node));
    tmp -> val = value;
    tmp -> next = head;
    tmp -> prev = NULL;
    if (head != NULL){
        head -> prev = tmp;
    }
    head = tmp;
    return head;
}

node* insertLast(node* head, int value){
    node* pListNode = (node*)malloc(sizeof(node));
    pListNode -> val = value;
    pListNode -> next = NULL;
    node* tmp = head;
    while(tmp -> next){
        tmp = tmp -> next;
    }
    tmp -> next = pListNode;
    pListNode -> prev = tmp;
    return head;
}

node* addInSpecifiedPos(node* head, size_t pos, int value){
    node* prevNode = NULL;
    node* tmp = head;
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> val = value;
   if (pos == 0){
       head = pushBack(head, value);
       return head;
   }
    while(tmp && pos){
        prevNode = tmp;
        tmp = tmp -> next;
        pos--;
    }
    prevNode -> next = newNode;
    tmp -> prev = newNode;
    newNode -> next = tmp;
    newNode -> prev = prevNode;
    return head;
}

int sizeOfList(node* head){
    int cnt = 0;
    while(head){
        cnt++;
        head = head -> next;
    }
    return cnt;
}

node* BubbleSort(node* head){
    int sizeList = sizeOfList(head);
    for (int i = 0; i < sizeList - 1; i++){
        node* cursor = head;
        for (int j = 0; j < sizeList - 1 - i; j++){
            if (j == 0 && cursor -> val > cursor -> next -> val){
                head = head -> next;
                head -> prev = NULL;
                cursor -> next = head -> next;
                    if (head -> next != NULL) {
                        head->next->prev = cursor;
                    }
                    head->next = cursor;
                cursor -> prev = head;
                continue;
            }
            else if (cursor -> val > cursor -> next -> val){
                node* buffer = cursor -> next;
                    cursor -> prev -> next = buffer;
                    cursor -> next -> prev = cursor -> prev;
                    cursor -> prev = buffer;
                    cursor -> next = buffer -> next;
                    if (buffer -> next != NULL)
                        buffer -> next -> prev = cursor;
                    buffer -> next = cursor;
                continue;
            }
            cursor = cursor -> next;
        }
    }
    return head;
}
