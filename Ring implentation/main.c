#include "ring.h"

int main() {
    struct Ring* head = NULL;
    head = pushAfter(head, 1);
    pushAfter(head, 2);
    pushAfter(head,4);
    pushBefore(head, 3);
    popBefore(head);
    popAfter(head);
    outputRing(head);
    return 0;
}
