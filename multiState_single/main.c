#include <stdio.h>
#include "control.h"
int main(void)
{
    printf("Hello World!\n");

    /*statechart3_init(&myHandle);
    statechart3_set_state1(&myHandle,&handle[0]);
    statechart3_set_state2(&myHandle,&handle[1]);
    statechart3_enter(&myHandle);
    statechart_raise_myEvent(myHandle.iface.state1,1);
    statechart_raise_myEvent(&handle[0],0);
    statechart_raise_myEvent(&handle[1],0);*/

    statechart_init(&handle[0]);
    statechart_enter(&handle[0]);
    statechart_raise_myEvent(&handle[0],1);

    return 0;
}


