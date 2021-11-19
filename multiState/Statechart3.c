/** Generated by YAKINDU Statechart Tools code generator. */


#include "sc_types.h"

#include "Statechart3.h"

/*! \file Implementation of the state machine 'Statechart3'
*/

#ifndef SC_UNUSED
#define SC_UNUSED(P) (void)(P)
#endif

/* prototypes of all internal functions */
static void enact_myRegion_start(Statechart3* handle);
static void enseq_myRegion_start_default(Statechart3* handle);
static void enseq_myRegion_default(Statechart3* handle);
static void exseq_myRegion_start(Statechart3* handle);
static void exseq_myRegion(Statechart3* handle);
static void react_myRegion__entry_Default(Statechart3* handle);






void statechart3_init(Statechart3* handle)
{
	sc_integer i;
	
	for (i = 0; i < STATECHART3_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Statechart3_last_state;
	}
	
				
	
	
	/* Default init sequence for statechart Statechart3 */
	handle->iface.state1 = sc_null;
	handle->iface.state2 = sc_null;
	
	handle->isExecuting = bool_false;
}

void statechart3_enter(Statechart3* handle)
{
	/* Activates the state machine. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	/* Default enter sequence for statechart Statechart3 */
	enseq_myRegion_default(handle);
	handle->isExecuting = bool_false;
}

void statechart3_exit(Statechart3* handle)
{
	/* Deactivates the state machine. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	/* Default exit sequence for statechart Statechart3 */
	exseq_myRegion(handle);
	handle->isExecuting = bool_false;
}


sc_boolean statechart3_is_active(const Statechart3* handle)
{
	sc_boolean result = bool_false;
	sc_integer i;
	
	for(i = 0; i < STATECHART3_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Statechart3_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean statechart3_is_final(const Statechart3* handle)
{
	SC_UNUSED(handle);
	return bool_false;
}

sc_boolean statechart3_is_state_active(const Statechart3* handle, Statechart3States state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Statechart3_myRegion_start :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART3_MYREGION_START] == Statechart3_myRegion_start
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}




Statechart* statechart3_get_state1(const Statechart3* handle)
{
	return handle->iface.state1;
}
void statechart3_set_state1(Statechart3* handle, Statechart* value)
{
	handle->iface.state1 = value;
}
Statechart* statechart3_get_state2(const Statechart3* handle)
{
	return handle->iface.state2;
}
void statechart3_set_state2(Statechart3* handle, Statechart* value)
{
	handle->iface.state2 = value;
}

/* implementations of all internal functions */

/* Entry action for state 'start'. */
static void enact_myRegion_start(Statechart3* handle)
{
	/* Entry action for state 'start'. */
	statechart_enter(handle->iface.state1);
	statechart_enter(handle->iface.state2);
}

/* 'default' enter sequence for state start */
static void enseq_myRegion_start_default(Statechart3* handle)
{
	/* 'default' enter sequence for state start */
	enact_myRegion_start(handle);
	handle->stateConfVector[0] = Statechart3_myRegion_start;
}

/* 'default' enter sequence for region myRegion */
static void enseq_myRegion_default(Statechart3* handle)
{
	/* 'default' enter sequence for region myRegion */
	react_myRegion__entry_Default(handle);
}

/* Default exit sequence for state start */
static void exseq_myRegion_start(Statechart3* handle)
{
	/* Default exit sequence for state start */
	handle->stateConfVector[0] = Statechart3_last_state;
}

/* Default exit sequence for region myRegion */
static void exseq_myRegion(Statechart3* handle)
{
	/* Default exit sequence for region myRegion */
	/* Handle exit of all possible states (of Statechart3.myRegion) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Statechart3_myRegion_start :
		{
			exseq_myRegion_start(handle);
			break;
		}
		default: break;
	}
}

/* Default react sequence for initial entry  */
static void react_myRegion__entry_Default(Statechart3* handle)
{
	/* Default react sequence for initial entry  */
	enseq_myRegion_start_default(handle);
}




