

#include "globals.h"
#include "auxiliaries.h"
#include "maths.h"
#include "timers.h"
#include "src/PID_v1/PID_v1.h"
#include "decoders.h"
#include "utilities.h"
#include "TRANNSCONTROL.h"


void TRANNSCONTROL(void)
{
  if(configPage15.TrannsEnable == 1)
  {                     
           byte vssLimit = table2D_getValue(&shift3_4Table, currentStatus.TPS);
            if(currentStatus.vss > vssLimit){digitalWrite(pinA, HIGH);}
                        
           byte vssLimit = table2D_getValue(&shift4_3Table, currentStatus.TPS);
            if(currentStatus.vss < vssLimit)
             {  
           byte vssLimit = table2D_getValue(&shift2_1Table, currentStatus.TPS);
            if(currentStatus.vss < vssLimit){digitalWrite(pinA, HIGH);}
                           
           byte vssLimit = table2D_getValue(&shift3_2Table, currentStatus.TPS);
            if(currentStatus.vss < vssLimit){digitalWrite(pinB, ! digitalRead(pinB));}
                              
            if (digitalRead (pininputN) == HIGH)
             {
            if (currentStatus.RPMdiv100 > configPage15.ApinMaxRPMdiv100) 
                {digitalWrite(pinA, LOW);} 
                                  
            if (currentStatus.TPS < 85)
             {            
           byte vssLimit = table2D_getValue(&shift1_2Table, currentStatus.TPS);
            if(currentStatus.vss > vssLimit){digitalWrite(pinA, LOW);}                    
             }
             if (digitalRead (pininputR) == HIGH)
             {
            if (currentStatus.RPMdiv100 > configPage15.BpinMaxRPMdiv100) 
             {  
           byte vssLimit = table2D_getValue(&shift3_2Table, currentStatus.TPS);
            if(currentStatus.vss > vssLimit)digitalWrite(pinB, ! digitalRead(pinB));                                    
             }                               
            if (currentStatus.TPS < 85) 
             {
            byte vssLimit = table2D_getValue(&shift2_3Table, currentStatus.TPS);
            if(currentStatus.vss > vssLimit){digitalWrite(pinB, ! digitalRead(pinB));}                     
             }
             }                    
             }
             }
            byte vssLimit = table2D_getValue(&unlockshiftTable, currentStatus.TPS);
             if(currentStatus.vss < vssLimit){digitalWrite(pinC, LOW);}
                         
            byte vssLimit = table2D_getValue(&lockshiftTable, currentStatus.TPS);
             if(currentStatus.vss > vssLimit){digitalWrite(pinC, HIGH);}                            
  }
}












