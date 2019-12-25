// -----------------------------------------------------------------------------
// main - MPF 12/2019
// -----------------------------------------------------------------------------

// includes
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

fsm_t fsm;
int i,j;

void fsm_init(void);
void fsm_step(void);

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------
int main(void){
    FSM_INIT(STATE_ENTRY);
    for (j=0; j<50; j++) fsm_step();
    return 0;
}

// -----------------------------------------------------------------------------
// sm init
// -----------------------------------------------------------------------------
void fsm_init(void){

    i=0;
}

// -----------------------------------------------------------------------------
// sm step
// -----------------------------------------------------------------------------
void fsm_step(void){
    
    BEGIN_FSM;

        BEGIN_STATE(STATE_ENTRY);
            // entry 
            BEGIN_ENTRY;
                printf("Entry STATE_ENTRY i=%u\n",i);
            END_ENTRY;
            // during 
            BEGIN_DURING;
                i++;
                printf("During STATE_ENTRY i=%u\n",i);
            END_DURING;
            // transistion event
            BEGIN_EVENT(i==3,STATE_STATE1);
                printf("Event STATE_ENTRY i=%u\n",i);
                i=0;
            END_EVENT;
            // exit
            BEGIN_EXIT;
                printf("Exit STATE_ENTRY i=%u\n",i);
            END_EXIT;
        END_STATE;

        BEGIN_STATE(STATE_STATE1);
            // entry
            BEGIN_ENTRY;
                printf("Entry STATE_STATE1 i=%u\n",i);
            END_ENTRY;
            // during
            BEGIN_DURING;
                i++;
                printf("During STATE_STATE1 i=%u\n",i);
            END_DURING;
            // transistion event
            BEGIN_EVENT(i==4,STATE_STATE2);
                printf("Event STATE_STATE1 i=%u\n",i);
                i=0;
            END_EVENT;
            // exit
            BEGIN_EXIT;
                printf("Exit STATE_STATE1 i=%u\n",i);
            END_EXIT;
        END_STATE;

        BEGIN_STATE(STATE_STATE2);
            // entry
            BEGIN_ENTRY;
                printf("Entry STATE_STATE2 i=%u\n",i);
            END_ENTRY;
            // during
            BEGIN_DURING;
                i++;
                printf("During STATE_STATE2 i=%u\n",i);
            END_DURING;
            // transistion event
            BEGIN_EVENT(i==5,STATE_STATE1);
                printf("Event STATE_STATE2 i=%u\n",i);
                i=0;
            END_EVENT;
            BEGIN_EVENT(j>30,STATE_STOP);
                printf("Event STOP j=%u\n",j);
                i=0;
            END_EVENT;
            // exit
            BEGIN_EXIT;
                printf("Exit STATE_STATE2 i=%u\n",i);
            END_EXIT;
        END_STATE;

        BEGIN_STATE(STATE_STOP);

        END_STATE;

    END_FSM;
}