// -----------------------------------------------------------------------------
// main - MPF 12/2019
// -----------------------------------------------------------------------------

// includes
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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

// prototypes
void fsm_init(void);
void fsm_step(void);

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------
int i,j;
int stop;
int main(void){
    stop=0;
    fsm_init();
    for (j=0; j<50; j++) {
        if (j==40) stop=1;
        fsm_step();
    }
    return 0;
}

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
                // state 1 entry
                printf("Entry STATE_STATE1 i=%u\n",i);
            END_ENTRY;

            BEGIN_DURING;
                // state 1 during
                i++;
                printf("During STATE_STATE1 i=%u\n",i);
            END_DURING;
            
            BEGIN_EVENT(i==4,STATE_STATE2);
                // state 1 event
                printf("Event STATE_STATE1 i=%u\n",i);
                i=0;
            END_EVENT;
            
            BEGIN_EXIT;
                // state 1 exit
                printf("Exit STATE_STATE1 i=%u\n",i);
            END_EXIT;

        END_STATE;

        BEGIN_STATE(STATE_STATE2);
            
            BEGIN_ENTRY;
                // state 2 entry
                printf("Entry STATE_STATE2 i=%u\n",i);
            END_ENTRY;
            
            BEGIN_DURING;
                // state 2 during
                i++;
                printf("During STATE_STATE2 i=%u\n",i);
            END_DURING;
            
            BEGIN_EVENT(i==5,STATE_STATE1);
                // state 2 event 1
                printf("Event STATE_STATE2 i=%u\n",i);
                i=0;
            END_EVENT;

            BEGIN_EVENT(stop,STATE_STOP);
                // state 2 event 2
                printf("Stop event\n");
            END_EVENT;
            
            BEGIN_EXIT;
                // state 2 exit
                printf("Exit STATE_STATE2 i=%u\n",i);
            END_EXIT;

        END_STATE;

        BEGIN_STATE(STATE_STOP);

        END_STATE;

    END_FSM;
}