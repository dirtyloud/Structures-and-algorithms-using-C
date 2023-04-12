#include "functions.h"

int main(){
    struct Ring* head = NULL;
    pushAfter(&head, 1);
    pushAfter(&head, 2);
    pushAfter(&head, 3);
    popBefore(&head);
    pushAfter(&head, 5);
    pushAfter(&head, 10);
    pushBefore(&head, 15);
    pushBefore(&head, 11);
    popAfter(&head);
    popAfter(&head);
    popAfter(&head);
    popAfter(&head);
    popAfter(&head);
    printRing(head);
    return 0;
}
