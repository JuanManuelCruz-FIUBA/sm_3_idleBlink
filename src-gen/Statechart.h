/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef STATECHART_H_
#define STATECHART_H_

/*!
Forward declaration for the Statechart state machine.
*/
class Statechart;


#include "../modules/leds/leds.h"
#include <deque>
#include "sc_types.h"
#include "sc_statemachine.h"
#include "sc_timer.h"

/*! \file
Header of the state machine 'Statechart'.
*/


#ifndef SCT_EVENTS_STATECHART_H
#define SCT_EVENTS_STATECHART_H
#ifndef SC_INVALID_EVENT_VALUE
#define SC_INVALID_EVENT_VALUE 0
#endif

namespace statechart_events
{
typedef enum  {
	invalid_event = SC_INVALID_EVENT_VALUE,
	Statechart_IdleBlink_BLINK_time_event_0,
	Statechart_IdleBlink_BLINK_Blink_Turn_OFF_time_event_0,
	Statechart_IdleBlink_BLINK_Blink_Turn_ON_time_event_0,
	Statechart_IdleBlink_IDLE_time_event_0
} StatechartEventName;

class SctEvent
{
	public:
		SctEvent(StatechartEventName name_) : name(name_){}
		virtual ~SctEvent(){}
		const StatechartEventName name;
		
};
		
template <typename T>
class TypedSctEvent : public SctEvent
{
	public:
		TypedSctEvent(StatechartEventName name_, T value_) :
			SctEvent(name_),
			value(value_)
			{}
		virtual ~TypedSctEvent(){}
		const T value;
};

class TimedSctEvent : public SctEvent
{
	public:
		TimedSctEvent(StatechartEventName name_) : SctEvent(name_){};
};

}
#endif /* SCT_EVENTS_STATECHART_H */


/*! Define indices of states in the StateConfVector */
#define SCVI_IDLEBLINK_BLINK 0
#define SCVI_IDLEBLINK_BLINK_BLINK_TURN_OFF 0
#define SCVI_IDLEBLINK_BLINK_BLINK_TURN_ON 0
#define SCVI_IDLEBLINK_IDLE 0


class Statechart : public sc::timer::TimedInterface, public sc::StatemachineInterface
{
	public:
		Statechart();
		
		virtual ~Statechart();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			Statechart_last_state,
			IdleBlink_BLINK,
			IdleBlink_BLINK_Blink_Turn_OFF,
			IdleBlink_BLINK_Blink_Turn_ON,
			IdleBlink_IDLE
		} StatechartStates;
					
		static const sc_integer numStates = 4;
		
		
		
		/*! Can be used by the client code to trigger a run to completion step without raising an event. */
		void triggerWithoutEvent();
		/*
		 * Functions inherited from StatemachineInterface
		 */
		virtual void enter();
		
		virtual void exit();
		
		/*!
		 * Checks if the state machine is active (until 2.4.1 this method was used for states).
		 * A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		 */
		virtual sc_boolean isActive() const;
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		virtual sc_boolean isFinal() const;
		
		/*! 
		 * Checks if member of the state machine must be set. For example an operation callback.
		 */
		sc_boolean check();
		
		/*
		 * Functions inherited from TimedStatemachineInterface
		 */
		virtual void setTimerService(sc::timer::TimerServiceInterface* timerService_);
		
		virtual sc::timer::TimerServiceInterface* getTimerService();
		
		virtual void raiseTimeEvent(sc_eventid event);
		
		virtual sc_integer getNumberOfParallelTimeEvents();
		
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(StatechartStates state) const;
		
		//! number of time events used by the state machine.
		static const sc_integer timeEventsCount = 4;
		
		//! number of time events that can be active at once.
		static const sc_integer parallelTimeEventsCount = 2;
		
		
	protected:
		
		
	private:
		Statechart(const Statechart &rhs);
		Statechart& operator=(const Statechart&);
		
		void iface_dispatch_event(statechart_events::SctEvent * event);
		
		uint32_t viMyCounter;
		void internal_dispatch_event(statechart_events::SctEvent * event);
		
		
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_ushort maxOrthogonalStates = 1;
		
		sc::timer::TimerServiceInterface* timerService;
		sc_boolean timeEvents[timeEventsCount];
		
		
		StatechartStates stateConfVector[maxOrthogonalStates];
		
		
		
		
		sc_boolean isExecuting;
		
		
		// prototypes of all internal functions
		
		void enact_IdleBlink_BLINK();
		void enact_IdleBlink_BLINK_Blink_Turn_OFF();
		void enact_IdleBlink_BLINK_Blink_Turn_ON();
		void enact_IdleBlink_IDLE();
		void exact_IdleBlink_BLINK();
		void exact_IdleBlink_BLINK_Blink_Turn_OFF();
		void exact_IdleBlink_BLINK_Blink_Turn_ON();
		void exact_IdleBlink_IDLE();
		void enseq_IdleBlink_BLINK_default();
		void enseq_IdleBlink_BLINK_Blink_Turn_OFF_default();
		void enseq_IdleBlink_BLINK_Blink_Turn_ON_default();
		void enseq_IdleBlink_IDLE_default();
		void enseq_IdleBlink_default();
		void enseq_IdleBlink_BLINK_Blink_default();
		void exseq_IdleBlink_BLINK();
		void exseq_IdleBlink_BLINK_Blink_Turn_OFF();
		void exseq_IdleBlink_BLINK_Blink_Turn_ON();
		void exseq_IdleBlink_IDLE();
		void exseq_IdleBlink();
		void exseq_IdleBlink_BLINK_Blink();
		void react_IdleBlink_BLINK_Blink__entry_Default();
		void react_IdleBlink__entry_Default();
		sc_integer react(const sc_integer transitioned_before);
		sc_integer IdleBlink_BLINK_react(const sc_integer transitioned_before);
		sc_integer IdleBlink_BLINK_Blink_Turn_OFF_react(const sc_integer transitioned_before);
		sc_integer IdleBlink_BLINK_Blink_Turn_ON_react(const sc_integer transitioned_before);
		sc_integer IdleBlink_IDLE_react(const sc_integer transitioned_before);
		void clearInEvents();
		void microStep();
		void runCycle();
		
		
		statechart_events::SctEvent* getNextEvent();
		void dispatch_event(statechart_events::SctEvent * event);
		statechart_events::StatechartEventName getTimedEventName(sc_eventid evid);
		std::deque<statechart_events::SctEvent*> inEventQueue;
		
		
};




#endif /* STATECHART_H_ */
