# Implementation of MACRO based Finite State Machine (FSM)

This code implements a macro based finite state machine. Purpose of this implementation is to have a fsm that can be graphed for easy visualization.

# Usage

- Include "fsm.h" in project
- Create states and fsm structure
- Create init and step functions
- Fill up fsm with BEGIN_STATE/END_STATE for every state
- Fill up ENTRY/DURING/EXIT and EVENT on any state that needs it

Example:

```
// include fsm macro
#include "fsm.h"

// enumerate states
enum states_enum {
    STATE_STATE1,
    STATE_STATE2,
    STATE_STOP,
};

// fsm structure
fsm_t fsm;
#define FSM_STRCT fsm

// -----------------------------------------------------------------------------
// sm init
// -----------------------------------------------------------------------------
void fsm_init(void){
    FSM_INIT(STATE_STATE1);
}

// -----------------------------------------------------------------------------
// sm step
// -----------------------------------------------------------------------------
void fsm_step(void){
    
    BEGIN_FSM;

        BEGIN_STATE(STATE_STATE1);

            BEGIN_ENTRY;
                printf("Entry STATE_STATE1 i=%u\n",i);
            END_ENTRY;

            BEGIN_DURING;
                i++;
                printf("During STATE_STATE1 i=%u\n",i);
            END_DURING;
            
            BEGIN_EVENT(i==4,STATE_STATE2);
                printf("Event STATE_STATE1 i=%u\n",i);
                i=0;
            END_EVENT;
            
            BEGIN_EXIT;
                printf("Exit STATE_STATE1 i=%u\n",i);
            END_EXIT;

        END_STATE;

        BEGIN_STATE(STATE_STATE2);
            
            BEGIN_ENTRY;
                printf("Entry STATE_STATE2 i=%u\n",i);
            END_ENTRY;
            
            BEGIN_DURING;
                i++;
                printf("During STATE_STATE2 i=%u\n",i);
            END_DURING;
            
            BEGIN_EVENT(i==5,STATE_STATE1);
                printf("Event STATE_STATE2 i=%u\n",i);
                i=0;
            END_EVENT;

            BEGIN_EVENT(stop,STATE_STOP);
                printf("Stop event\n");
            END_EVENT;
            
            BEGIN_EXIT;
                printf("Exit STATE_STATE2 i=%u\n",i);
            END_EXIT;

        END_STATE;

        BEGIN_STATE(STATE_STOP);

        END_STATE;

    END_FSM;
}
```


