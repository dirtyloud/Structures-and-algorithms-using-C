#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* patrition(node*, int);
node* pushBack(node*, int);
void printList(node*);
int SizeOfList(node*);
node* BubbleSort(node*);
void swap(node*, node*);
node* insertionSort(node*);
node* returnPos(node*, size_t);
node* shellSort(node*);



int main(){
    int N;
    scanf_s("%d", &N);
    node* head = NULL;
    int a;
    while(N){
        scanf_s("%d", &a);
        head = pushBack(head, a);
        N--;
    }
    printList(head);;
    printf("\n");
    head = insertionSort(head);
    printList(head);
    return 0;
}

int SizeOfList(node* head){
    int cnt = 0;
    while(head){
        cnt++;
        head = head-> next;
    }
    return cnt;
}

node* BubbleSort(node* head){
    for (size_t i = 0; i < SizeOfList(head) - 1; i++){
        node* cursor = head;
        node* prev = head;
        for (size_t j = 0; j < SizeOfList(head) - i - 1; j++){
            node* next = cursor -> next;
            if (j == 0 && cursor -> val > next -> val){
                swap(cursor, next);
                head = next;
                prev = head;
                continue;
            }
            else if(cursor -> val > next -> val){
                swap(cursor, next);
                prev -> next = next;
                next = cursor;
                prev = prev -> next;
                cursor = next;
                continue;
            }
            prev = cursor;
            cursor = next;
        }
    }
    return head;
}


node* pushBack(node* head, int value){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->val = value;
    tmp->next = NULL;
    if (head == NULL){
        head = tmp;
    }
    else{
        node* pList = head;
        while(pList -> next){
            pList = pList -> next;
        }
        pList -> next = tmp;
    }
    return head;
}

void printList(node* head){
    while(head){
        printf("%5d", head -> val);
        head = head -> next;
    }
}


node* patrition(node* head, int x){
    node* small = (node*)malloc(sizeof(node));
    node* high = (node*)malloc(sizeof(node));
    node* lsmall_head = small;
    node* lhigh_head = high;
    while(head){
        if (head -> val <= x){
            small -> next = head;
            small = small -> next;
            head = head -> next;
            small -> next = NULL;
        }
        else{
            high -> next = head;
            high = high -> next;
            head = head -> next;
            high -> next = NULL;
        }
    }
    small -> next = lhigh_head -> next;
    return lsmall_head->next;
}

void swap(node* ptr1, node* ptr2){
    node* buf = ptr2 -> next;
    ptr2 -> next = ptr1;
    ptr1 -> next = buf;
}


node* insertionSort(node* head){
    for (size_t i = 1; i < SizeOfList(head); i++){
        for (size_t j = i; j > 0 && returnPos(head, j - 1) -> val > returnPos(head, j) -> val; j--){
            node* prev = returnPos(head, j - 1);
            node* current = returnPos(head, j);
            if (prev == head){
                swap(prev, current);
                head = current;
            }
            else{
                node* prev2 = returnPos(head, j - 2);
                swap(prev, current);
                prev2 -> next = current;
            }
        }
    }
    return head;
}




node* returnPos(node* head, size_t index){
    node* cursor = head;
    while(index && cursor){
        cursor = cursor -> next;
        index--;
    }
    return cursor;
}
