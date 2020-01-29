// -----------------------------------------------------------------------------
// fsm - MPF 12/2019
// -----------------------------------------------------------------------------

#ifndef _FSM_H_
#define _FSM_H_

// fsm states
typedef unsigned int state_t;

// fsm structure
typedef struct fsm_struct {
    state_t state;
    unsigned int entry_enable;
    unsigned int exit_enable;
    unsigned int event_block;
} fsm_t;

// define symbol to point to fsm struct
// #define FSM_STRCT fsm

// fsm init - run once in init
#define FSM_INIT(entry_state) FSM_STRCT.state = entry_state; \
    FSM_STRCT.entry_enable = 1; FSM_STRCT.exit_enable = 0; \
    FSM_STRCT.event_block = 0;

// fsm
#define BEGIN_FSM { FSM_STRCT.event_block = 0; switch(FSM_STRCT.state) {
#define END_FSM }}

// fsm state
#define BEGIN_STATE(state) case (state):
#define END_STATE FSM_STRCT.event_block = 0; break;

// fsm entry block (optional)
#define BEGIN_ENTRY if (FSM_STRCT.entry_enable) { FSM_STRCT.entry_enable = 0;
#define END_ENTRY }

// fsm during block
#define BEGIN_DURING {
#define END_DURING }

// fsm event block - add as many events as needed
// first event to pass test will execute, following events will be skipped
#define BEGIN_EVENT(test, new_state) if((!FSM_STRCT.event_block)&&(test))\
    {FSM_STRCT.state=new_state;\
    FSM_STRCT.entry_enable = FSM_STRCT.exit_enable = FSM_STRCT.event_block = 1;
#define END_EVENT }

// fsm exit block (optional)
#define BEGIN_EXIT if (FSM_STRCT.exit_enable) {FSM_STRCT.exit_enable = 0;
#define END_EXIT }

#endif // _FSM_H_

