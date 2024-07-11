



#include "utilities.h"
#include "globals.h"
#include "auxiliaries.h"
#include "maths.h"
#include "src/PID_v1/PID_v1.h"
#include "decoders.h"
#include "timers.h"
#include "TRANNSCONTROL.h"




volatile PORT_TYPE *A_pin_port;
volatile PINMASK_TYPE A_pin_mask;
volatile PORT_TYPE *B_pin_port;
volatile PINMASK_TYPE B_pin_mask;
volatile PORT_TYPE *C_pin_port;
volatile PINMASK_TYPE C_pin_mask;
volatile PORT_TYPE *inputN_pin_port;
volatile PINMASK_TYPE inputN_pin_mask;
volatile PORT_TYPE *inputR_pin_port;
volatile PINMASK_TYPE inputR_pin_mask;
bool trannsEnabled;

void initialiseTrannsCon(void)
{
   if(configPage15.TrannsEnable > 0)
  {
      A_pin_port = portOutputRegister(digitalPinToPort(pinA));
      A_pin_mask = digitalPinToBitMask(pinA);

      B_pin_port = portOutputRegister(digitalPinToPort(pinB));
      B_pin_mask = digitalPinToBitMask(pinB);

     if(configPage15.CpinEnable > 0)
      {
      C_pin_port = portOutputRegister(digitalPinToPort(pinC));
      C_pin_mask = digitalPinToBitMask(pinC);
      }
      inputN_pin_port = portOutputRegister(digitalPinToPort(pininputN));
      inputN_pin_mask = digitalPinToBitMask(pininputN);

      inputR_pin_port = portOutputRegister(digitalPinToPort(pininputR));
      inputR_pin_mask = digitalPinToBitMask(pininputR);


    trannsEnabled = true;

  }

else
  {
    trannsEnabled = false;
  }



}
  void TRANNSCONTROL(void)
{
     if(trannsEnabled == true)
    {  A_PIN_ON();
                      
           //byte vssLimit = table2D_getValue(&shift3_4Table, currentStatus.TPS);
            //if(currentStatus.vss > vssLimit){A_PIN_ON();}
                        
           //byte vssLimit = table2D_getValue(&shift4_3Table, currentStatus.TPS);
            //if(currentStatus.vss < vssLimit)
            // {  
          // byte vssLimit = table2D_getValue(&shift2_1Table, currentStatus.TPS);
           // if(currentStatus.vss < vssLimit){A_PIN_ON();}
                           
          // byte vssLimit = table2D_getValue(&shift3_2Table, currentStatus.TPS);
           // if(currentStatus.vss < vssLimit){B_PIN_ON();}
                              
            //if (inputN_PIN_OFF())
             //{
            //if (currentStatus.RPMdiv100 > configPage15.ApinMaxRPMdiv100) 
               // {A_PIN_OFF();} 
                                  
            //if (currentStatus.TPS < 85)
            // {            
          // byte vssLimit = table2D_getValue(&shift1_2Table, currentStatus.TPS);
           // if(currentStatus.vss > vssLimit){A_PIN_OFF() ;}                    
             //}
             //if inputR_PIN_OFF()
             //{
           // if (currentStatus.RPMdiv100 > configPage15.BpinMaxRPMdiv100) 
            // {  
           //byte vssLimit = table2D_getValue(&shift3_2Table, currentStatus.TPS);
            //if(currentStatus.vss > vssLimit) B_PIN_OFF() ;                                    
            // }                               
           // if (currentStatus.TPS < 85) 
            // {
            //byte vssLimit = table2D_getValue(&shift2_3Table, currentStatus.TPS);
            //if(currentStatus.vss > vssLimit){B_PIN_OFF() ;}                     
            // }
             //}                    
             //}
            // }
           // byte vssLimit = table2D_getValue(&unlockshiftTable, currentStatus.TPS);
           //  if(currentStatus.vss < vssLimit){C_PIN_OFF() ;}
                         
       // byte vssLimit = table2D_getValue(&lockshiftTable, currentStatus.TPS);
             //if(currentStatus.vss > vssLimit){C_PIN_ON();}                            


    }
}












