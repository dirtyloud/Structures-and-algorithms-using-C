#include "ring.h"

int main() {
    struct Ring* head = NULL;
    head = pushAfter(head, 1);
    head = pushAfter(head, 2);
    head = pushAfter(head, 3);
    head = pushAfter(head, 4);
    head = pushBefore(head, 5);
    head = popAfter(head);
    head = popBefore(head);
    head = popBefore(head);
    head = popAfter(head);
    head = popAfter(head);
    outputRing(head);
    return 0;
}
