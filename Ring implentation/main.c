#include "ring.h"

int main() {
    struct Ring* head = NULL;
    head = pushAfter(head, 1);
    head = pushAfter(head, 2);
    head = pushAfter(head,4);
    head = pushBefore(head, 3);
    head = popBefore(head);
    head = popAfter(head);
    outputRing(head);
    free(head);
    return 0;
}
