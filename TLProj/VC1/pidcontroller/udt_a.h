/**************************************************************************************************\
 *** 
 *** Simulink model       : vcfp
 *** TargetLink subsystem : vcfp/pidcontroller
 *** Codefile             : udt_a.h
 ***
 *** Generation date: 2020-04-04 23:39:12
 ***
 *** TargetLink version      : 4.2 from 14-Oct-2016
 *** Code generator version  : Build Id 4.2.0.26 from 2016-10-17 16:31:48

\**************************************************************************************************/

#ifndef UDT_A_H
#define UDT_A_H


#include "tl_basetypes.h"


#ifndef ADC_TYPE
#define ADC_TYPE
typedef Int16 ADC; /* 
   LSB: 2^-11 OFF: 0 MIN/MAX: -10 .. 10
   Description: User-defined data type ADC. Imported from TL 1.3 */
#endif /* ADC_TYPE */
#ifndef DAC_TYPE
#define DAC_TYPE
typedef UInt16 DAC; /* 
   LSB: 2^-15 OFF: -1 MIN/MAX: -1 .. 0.999969482421875
   Description: User-defined data type DAC. Imported from TL 1.3 */
#endif /* DAC_TYPE */

#endif /* UDT_A_H */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
