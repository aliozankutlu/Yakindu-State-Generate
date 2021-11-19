#include "control.h"

Statechart3 myHandle;
Statechart handle[2];
void statechart_opeStateA( Statechart* handle, const sc_integer evnt)
{
    int id = handle - myHandle.iface.state1;
    printf("opeStateA:  %d state %d evnt \n",id,evnt);
    statechart_raise_myEvent(handle,evnt);
}

void statechart_opeStateB( Statechart* handle, const sc_integer evnt)
{
    int id = handle - myHandle.iface.state1;
    printf("opeStateB:  %d state %d evnt \n",id,evnt);
}

void statechart_set_timer(Statechart* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic)
{
     int id =handle - myHandle.iface.state1;
     printf("Timer:  %d \n",id);
     statechart_raise_time_event(handle,evid);
}

void statechart_unset_timer(Statechart* handle, const sc_eventid evid)
{

}
