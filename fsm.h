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
    unsigned int entry_flag;
    unsigned int exit_flag;
} fsm_t;

// define symbol to point to fsm struct
// #define FSM_STRCT fsm

// fsm init - run once in init
#define FSM_INIT(entry_state) FSM_STRCT.state = entry_state; \
    FSM_STRCT.entry_flag = 1; FSM_STRCT.exit_flag = 0;

// fsm
#define BEGIN_FSM switch(FSM_STRCT.state) {
#define END_FSM }

// fsm state
#define BEGIN_STATE(state)  case (state):
#define END_STATE   break;

// fsm entry block (optional)
#define BEGIN_ENTRY if (FSM_STRCT.entry_flag) { FSM_STRCT.entry_flag = 0;
#define END_ENTRY }

// fsm during block
#define BEGIN_DURING {
#define END_DURING }

// fsm event block - add as many events as needed
#define BEGIN_EVENT(test, new_state) if(test){FSM_STRCT.state=new_state;\
    FSM_STRCT.entry_flag = FSM_STRCT.exit_flag = 1;
#define END_EVENT }

// fsm exit block (optional)
#define BEGIN_EXIT if (FSM_STRCT.exit_flag) {FSM_STRCT.exit_flag = 0;
#define END_EXIT }

#endif // _FSM_H_

