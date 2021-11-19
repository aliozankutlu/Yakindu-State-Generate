/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef STATECHART_REQUIRED_H_
#define STATECHART_REQUIRED_H_

#include "sc_types.h"
#include "Statechart.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- statechart_set_timer and
	- statechart_unset_timer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- statechart_opeStateA
	- statechart_opeStateB
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void statechart_opeStateA( Statechart* handle, const sc_integer evnt);
extern void statechart_opeStateB( Statechart* handle, const sc_integer evnt);


/*!
 * This is a timed state machine that requires timer services
 */ 

/*! This function has to set up timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milliseconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset 
*/
extern void statechart_set_timer(Statechart* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! This function has to unset timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
extern void statechart_unset_timer(Statechart* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* STATECHART_REQUIRED_H_ */
