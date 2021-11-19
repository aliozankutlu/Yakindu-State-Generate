#include <stdio.h>
#include "Statechart.h"


void statechart_internal_init( Statechart* handle)
{
   printf("init\n");
}
void statechart_internal_setA( Statechart* handle)
{
   printf("stateA\n");
   //statechart_raise_myEvent(handle);
}

void statechart_internal_setB( Statechart* handle){
   printf("stateB\n");
   //statechart_raise_myEvent(handle);
}

int main(void)
{
    Statechart state;

    printf("Hello World!\n");

    statechart_init(&state);
    statechart_enter(&state);
    statechart_raise_myEvent(&state);
    statechart_raise_myEvent(&state);

    return 0;
}

