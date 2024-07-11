
#ifndef TRANNSCONTROL_H
#define TRANNSCONTROL_H
#include BOARD_H
#if defined(CORE_AVR)
#include <util/atomic.h>
#endif



#define A_PIN_LOW()              ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*A_pin_port &= ~(A_pin_mask);}
#define A_PIN_HIGH()             ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*A_pin_port &= ~(A_pin_mask);}
#define B_PIN_LOW()             *B_pin_port &= ~(B_pin_mask)
#define B_PIN_HIGH()            *B_pin_port &= ~(B_pin_mask)
#define C_PIN_LOW()              ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*C_pin_port &= ~(C_pin_mask);}
#define C_PIN_HIGH()             ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*C_pin_port &= ~(C_pin_mask);}
#define inputN_PIN_LOW()         ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*inputN_pin_port &= ~(inputN_pin_mask);}
#define inputN_PIN_HIGH()        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*inputN_pin_port &= ~(inputN_pin_mask);}
#define inputR_PIN_LOW()         ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*inputR_pin_port &= ~(inputR_pin_mask);}
#define inputR_PIN_HIGH()        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {*inputR_pin_port &= ~(inputR_pin_mask);}


#define B_PIN_ON()     ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { ((configPage15.BpinPollarity) ? FAN_PIN_LOW() : FAN_PIN_HIGH()); }
#define B_PIN_OFF()    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { ((configPage15.BpinPollarity) ? FAN_PIN_HIGH() : FAN_PIN_LOW()); }

#define A_PIN_OFF()    A_PIN_LOW(); 
#define A_PIN_ON()   A_PIN_HIGH(); 

#define C_PIN_OFF()    C_PIN_LOW(); 
#define C_PIN_ON()    C_PIN_HIGH();

#define inputN_PIN_ON()   inputN_PIN_LOW(); 
#define inputN_PIN_OFF()  inputN_PIN_HIGH();

#define inputR_PIN_ON()   inputR_PIN_LOW(); 
#define inputR_PIN_OFF()  inputR_PIN_HIGH();


extern volatile PORT_TYPE *A_pin_port;
extern volatile PINMASK_TYPE A_pin_mask;
extern volatile PORT_TYPE *B_pin_port;
extern volatile PINMASK_TYPE B_pin_mask;
extern volatile PORT_TYPE *C_pin_port;
extern volatile PINMASK_TYPE C_pin_mask;
extern volatile PORT_TYPE *inputN_pin_port;
extern volatile PINMASK_TYPE inputN_pin_mask;
extern volatile PORT_TYPE *inputR_pin_port;
extern volatile PINMASK_TYPE inputR_pin_mask;







void initialiseTrannsCon(void);

void TRANNSCONTROL(void);


#endif