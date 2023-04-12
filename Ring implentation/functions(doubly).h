#include <stdio.h>
#include <stdlib.h>


struct Ring{
    int data;
    struct Ring* prev;
    struct Ring* next;
};


struct Ring* newElement(int);
void pushBefore(struct Ring**, int);
void pushAfter(struct Ring**, int);
void popBefore(struct Ring**);
void popAfter(struct Ring**);
void printRing(struct Ring*);
