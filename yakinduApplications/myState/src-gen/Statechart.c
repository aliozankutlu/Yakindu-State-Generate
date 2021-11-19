/** Generated by YAKINDU Statechart Tools code generator. */


#include "..\src\sc_types.h"

#include "Statechart.h"
#include "Statechart_required.h"

/*! \file Implementation of the state machine 'Statechart'
*/

#ifndef SC_UNUSED
#define SC_UNUSED(P) (void)(P)
#endif

/* prototypes of all internal functions */
static void enact_main_region_StateA(Statechart* handle);
static void enact_main_region_StateB(Statechart* handle);
static void enseq_main_region_StateA_default(Statechart* handle);
static void enseq_main_region_StateB_default(Statechart* handle);
static void enseq_main_region_default(Statechart* handle);
static void exseq_main_region_StateA(Statechart* handle);
static void exseq_main_region_StateB(Statechart* handle);
static void exseq_main_region(Statechart* handle);
static void react_main_region__entry_Default(Statechart* handle);

/*! State machine reactions. */
static sc_integer react(Statechart* handle, const sc_integer transitioned_before);

/*! The reactions of state StateA. */
static sc_integer main_region_StateA_react(Statechart* handle, const sc_integer transitioned_before);

/*! The reactions of state StateB. */
static sc_integer main_region_StateB_react(Statechart* handle, const sc_integer transitioned_before);


static void clear_in_events(Statechart* handle);

static void micro_step(Statechart* handle);

/*! Performs a 'run to completion' step. */
static void run_cycle(Statechart* handle);



static void statechart_eventqueue_init(statechart_eventqueue * eq, statechart_event *buffer, sc_integer capacity);
static sc_integer statechart_eventqueue_size(statechart_eventqueue * eq);
static void statechart_event_init(statechart_event * ev, StatechartEventID name);
static statechart_event statechart_eventqueue_pop(statechart_eventqueue * eq);
static sc_boolean statechart_eventqueue_push(statechart_eventqueue * eq, statechart_event ev);
static void statechart_add_event_to_queue(statechart_eventqueue * eq, StatechartEventID name);
static void statechart_dispatch_event(Statechart* handle, const statechart_event * event);
static statechart_event statechart_get_next_event(Statechart* handle);
static void statechart_dispatch_next_event(Statechart* handle);


void statechart_init(Statechart* handle)
{
	sc_integer i;
	
	for (i = 0; i < STATECHART_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Statechart_last_state;
	}
	
				
	clear_in_events(handle);
	
	
	
	handle->isExecuting = bool_false;
	statechart_eventqueue_init(&handle->in_event_queue, handle->in_buffer, STATECHART_IN_EVENTQUEUE_BUFFERSIZE);
}

void statechart_enter(Statechart* handle)
{
	/* Activates the state machine. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	/* Default enter sequence for statechart Statechart */
	enseq_main_region_default(handle);
	handle->isExecuting = bool_false;
}

void statechart_exit(Statechart* handle)
{
	/* Deactivates the state machine. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	/* Default exit sequence for statechart Statechart */
	exseq_main_region(handle);
	handle->isExecuting = bool_false;
}


sc_boolean statechart_is_active(const Statechart* handle)
{
	sc_boolean result = bool_false;
	sc_integer i;
	
	for(i = 0; i < STATECHART_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Statechart_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean statechart_is_final(const Statechart* handle)
{
	SC_UNUSED(handle);
	return bool_false;
}

sc_boolean statechart_is_state_active(const Statechart* handle, StatechartStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Statechart_main_region_StateA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART_MAIN_REGION_STATEA] == Statechart_main_region_StateA
			);
			break;
		case Statechart_main_region_StateB :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART_MAIN_REGION_STATEB] == Statechart_main_region_StateB
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clear_in_events(Statechart* handle)
{
	handle->iface.myEvent_raised = bool_false;
}

static void micro_step(Statechart* handle)
{
	switch(handle->stateConfVector[ 0 ])
	{
		case Statechart_main_region_StateA :
		{
			main_region_StateA_react(handle, -1);
			break;
		}
		case Statechart_main_region_StateB :
		{
			main_region_StateB_react(handle, -1);
			break;
		}
		default: break;
	}
}

static void run_cycle(Statechart* handle)
{
	/* Performs a 'run to completion' step. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	statechart_dispatch_next_event(handle);
	do
	{ 
		micro_step(handle);
		clear_in_events(handle);
		statechart_dispatch_next_event(handle);
	} while (handle->iface.myEvent_raised == bool_true);
	handle->isExecuting = bool_false;
}


void statechart_raise_myEvent(Statechart* handle)
{
	statechart_add_event_to_queue(&(handle->in_event_queue), Statechart_myEvent);
	run_cycle(handle);
}




/* implementations of all internal functions */

/* Entry action for state 'StateA'. */
static void enact_main_region_StateA(Statechart* handle)
{
	/* Entry action for state 'StateA'. */
	statechart_internal_init(handle);
	statechart_internal_setA(handle);
}

/* Entry action for state 'StateB'. */
static void enact_main_region_StateB(Statechart* handle)
{
	/* Entry action for state 'StateB'. */
	statechart_internal_setB(handle);
}

/* 'default' enter sequence for state StateA */
static void enseq_main_region_StateA_default(Statechart* handle)
{
	/* 'default' enter sequence for state StateA */
	enact_main_region_StateA(handle);
	handle->stateConfVector[0] = Statechart_main_region_StateA;
}

/* 'default' enter sequence for state StateB */
static void enseq_main_region_StateB_default(Statechart* handle)
{
	/* 'default' enter sequence for state StateB */
	enact_main_region_StateB(handle);
	handle->stateConfVector[0] = Statechart_main_region_StateB;
}

/* 'default' enter sequence for region main region */
static void enseq_main_region_default(Statechart* handle)
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default(handle);
}

/* Default exit sequence for state StateA */
static void exseq_main_region_StateA(Statechart* handle)
{
	/* Default exit sequence for state StateA */
	handle->stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for state StateB */
static void exseq_main_region_StateB(Statechart* handle)
{
	/* Default exit sequence for state StateB */
	handle->stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for region main region */
static void exseq_main_region(Statechart* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of Statechart.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Statechart_main_region_StateA :
		{
			exseq_main_region_StateA(handle);
			break;
		}
		case Statechart_main_region_StateB :
		{
			exseq_main_region_StateB(handle);
			break;
		}
		default: break;
	}
}

/* Default react sequence for initial entry  */
static void react_main_region__entry_Default(Statechart* handle)
{
	/* Default react sequence for initial entry  */
	enseq_main_region_StateA_default(handle);
}


static sc_integer react(Statechart* handle, const sc_integer transitioned_before)
{
	/* State machine reactions. */
	SC_UNUSED(handle);
	return transitioned_before;
}

static sc_integer main_region_StateA_react(Statechart* handle, const sc_integer transitioned_before)
{
	/* The reactions of state StateA. */
 			sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (handle->iface.myEvent_raised == bool_true)
		{ 
			exseq_main_region_StateA(handle);
			enseq_main_region_StateB_default(handle);
			react(handle, 0);
			transitioned_after = 0;
		} 
	} /* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(handle, transitioned_before);
	} return transitioned_after;
}

static sc_integer main_region_StateB_react(Statechart* handle, const sc_integer transitioned_before)
{
	/* The reactions of state StateB. */
 			sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (handle->iface.myEvent_raised == bool_true)
		{ 
			exseq_main_region_StateB(handle);
			enseq_main_region_StateA_default(handle);
			react(handle, 0);
			transitioned_after = 0;
		} 
	} /* If no transition was taken then execute local reactions */
	if ((transitioned_after) == (transitioned_before))
	{ 
		transitioned_after = react(handle, transitioned_before);
	} return transitioned_after;
}




static void statechart_eventqueue_init(statechart_eventqueue * eq, statechart_event *buffer, sc_integer capacity)
{
	eq->events = buffer;
	eq->capacity = capacity;
	eq->push_index = 0;
	eq->pop_index = 0;
	eq->size = 0;
}

static sc_integer statechart_eventqueue_size(statechart_eventqueue * eq)
{
	return eq->size;
}

static statechart_event statechart_eventqueue_pop(statechart_eventqueue * eq)
{
	statechart_event event;
	if(statechart_eventqueue_size(eq) <= 0) {
		statechart_event_init(&event, Statechart_invalid_event);
	}
	else {
		event = eq->events[eq->pop_index];
		
		if(eq->pop_index < eq->capacity - 1) {
			eq->pop_index++;
		} 
		else {
			eq->pop_index = 0;
		}
		eq->size--;
	}
	return event;
}
static sc_boolean statechart_eventqueue_push(statechart_eventqueue * eq, statechart_event ev)
{
	if(statechart_eventqueue_size(eq) == eq->capacity) {
		return bool_false;
	}
	else {
		eq->events[eq->push_index] = ev;
		
		if(eq->push_index < eq->capacity - 1) {
			eq->push_index++;
		}
		else {
			eq->push_index = 0;
		}
		eq->size++;
		
		return bool_true;
	}
}
static void statechart_event_init(statechart_event * ev, StatechartEventID name)
{
	ev->name = name;
}

static void statechart_add_event_to_queue(statechart_eventqueue * eq, StatechartEventID name)
{
	statechart_event event;
	statechart_event_init(&event, name);
	statechart_eventqueue_push(eq, event);
}

static void statechart_dispatch_event(Statechart* handle, const statechart_event * event) {
	switch(event->name) {
		case Statechart_myEvent:
		{
			handle->iface.myEvent_raised = bool_true;
			break;
		}
		default:
			break;
	}
}

static statechart_event statechart_get_next_event(Statechart* handle)
{
	statechart_event next_event;
	statechart_event_init(&next_event, Statechart_invalid_event);
	if(statechart_eventqueue_size(&(handle->in_event_queue)) > 0) {
		next_event = statechart_eventqueue_pop(&(handle->in_event_queue));
	}
	return next_event;
}

static void statechart_dispatch_next_event(Statechart* handle)
{
	statechart_event nextEvent;
	nextEvent = statechart_get_next_event(handle);
	statechart_dispatch_event(handle, &nextEvent);
}
