#include <stdio.h>
#include <stdlib.h>

struct Ring{
    int data;
    struct Ring* next;
};

struct Ring* pushAfter(struct Ring*, int);
struct Ring* pushBefore(struct Ring*, int);
struct Ring* newElem(int);
struct Ring* popAfter(struct Ring*);
struct Ring* popBefore(struct Ring*);
void outputRing(struct Ring*);
