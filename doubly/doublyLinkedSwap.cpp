#include "doublyLinkedSwap.h"

void swapWithNext(Node * p){ 
    Node * afterp = p->next;
    Node * beforep = p->prev;
    if(p->prev == nullptr || p->next == nullptr || afterp->next == nullptr || beforep ->prev == nullptr){ 
        return;
    }
    else{
        Node * afterafterp = afterp->next;
        afterafterp->prev = p;
        beforep->next = afterp;
        afterp->next = p;
        afterp->prev = beforep;
        p->next = afterafterp;
        p->prev = afterp;
    }



    
}
// used for testing
int main(){
    int myArray[5];
    myArray[0] = 1;
    myArray[1] = 2;
    myArray[2] = 3;
    myArray[3] = 4;
    myArray[4] = 5;

    Node * listHead = arrayToList(myArray, 5);
    swapWithNext(listHead->next);
    printForwards(listHead);
     return 0;
}