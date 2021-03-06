/**************************************************************************************************\
 *** 
 *** Simulink model       : vcfp
 *** TargetLink subsystem : vcfp/pidcontroller
 *** Codefile             : pidcontroller.c
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2020-04-04 23:39:12
 ***
 *** CODE GENERATOR OPTIONS:
 *** Code generation mode                     : Standard
 *** Compiler                                 : <unknown>
 *** Target                                   : Generic
 *** ANSI-C compatible code                   : yes
 *** Code Optimization                        : enabled
 *** Constant style                           : decimal
 *** Clean code option                        : disabled
 *** Logging mode                             : According to block-specific data
 *** Code Coverage                            : disabled
 *** Generate empty conditional branches      : disabled
 *** Loop unroll threshold                    : 5
 *** Shift mode                               : automatic
 *** Handle unscaled SF expr. with TL type    : enabled
 *** Assignment of conditions                 : AllBooleanOutputs 
 *** Scope reduction only to function level   : disabled
 *** Exploit ranges if not erasable           : disabled
 *** Exploit Compute Through Overflow         : optimized
 *** Linker sections                          : enabled
 *** Enable Assembler                         : disabled
 *** Variable name length                     : 31 chars
 *** Use global bitfields                     : disabled
 *** Stateflow: use of bitfields              : enabled
 *** State activity encoding limit            : 5
 *** Omit zero inits in restart function      : disabled
 *** Share functions between TL subsystems    : disabled
 *** Generate 64bit functions                 : enabled
 *** Inlining Threshold                       : 5
 *** Line break limit                         : 100
 *** Target optimized boolean data type       : enabled
 *** Keep saturation elements                 : disabled
 *** Extended variable sharing                : disabled
 *** Extended lifetime optimization           : enabled
 *** Style definition file                    : C:\Program Files\dSPACE TargetLink 4.2\Matlab\Tl\Con
 ***                                            fig\codegen\cconfig.xml
 *** Root style sheet                         : C:\Program Files\dSPACE TargetLink 4.2\Matlab\Tl\XML
 ***                                            \CodeGen\Stylesheets\TL_CSourceCodeSS.xsl
 *** Active Variant Config                    : VC1
 ***
 *** SUBSYS                   CORRESPONDING SIMULINK SUBSYSTEM
 *** Sa1                      pidcontroller
 *** 
 *** SUBSYS                   CORRESPONDING MODEL BLOCK (REFERENCED MODEL)
 *** 
 *** SF-NODE   CORRESPONDING STATEFLOW NODE                           DESCRIPTION
 *** 
 *** TargetLink version      : 4.2 from 14-Oct-2016
 *** Code generator version  : Build Id 4.2.0.26 from 2016-10-17 16:31:48

\**************************************************************************************************/

#ifndef PIDCONTROLLER_C
#define PIDCONTROLLER_C

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/

#include "pidcontroller.h"
#include "dsfxp.h"
#include "access.h"

/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

/******************************************************************************\
   ACCESS_FUNCTION: global variables (RAM) | Width: 16
\******************************************************************************/
ACCESS_FUNCTION ADC Sa1_REF; /* LSB: 2^-11 OFF: 0 MIN/MAX: -10 .. 10 */
ACCESS_FUNCTION DAC Sa1_U_M; /* LSB: 2^-15 OFF: -1 MIN/MAX: -1 .. 0.999969482421875 */
ACCESS_FUNCTION ADC Sa1_U_X; /* LSB: 2^-11 OFF: 0 MIN/MAX: -10 .. 10 */

/******************************************************************************\
   CAL: global calibratable parameters (ROM) | Width: 8
\******************************************************************************/
CAL UInt8 VariantSwitch = 2;

/******************************************************************************\
   CAL: global calibratable parameters (ROM) | Width: N.A.
\******************************************************************************/
CAL Vca_DV_tp Vca_DV_db_fast = {
   37 /* 0.145 */, /* P_Ad: LSB: 2^-8 OFF: 0 MIN/MAX: 0 .. 0.99609375 */
   224 /* 7. */, /* P_Kd: LSB: 2^-5 OFF: 0 MIN/MAX: 0 .. 7.96875 */
   72 /* 0.07 */, /* P_Ki: LSB: 2^-10 OFF: 0 MIN/MAX: 0 .. 0.2490234375 */
   192 /* 1.5 */ /* P_Kp: LSB: 2^-7 OFF: 0 MIN/MAX: 0 .. 1.9921875 */
};

CAL Vca_DV_tp Vca_DV_fast = {
   35 /* 0.1378 */, /* P_Ad: LSB: 2^-8 OFF: 0 MIN/MAX: 0 .. 0.99609375 */
   244 /* 7.6196 */, /* P_Kd: LSB: 2^-5 OFF: 0 MIN/MAX: 0 .. 7.96875 */
   51 /* 0.05 */, /* P_Ki: LSB: 2^-10 OFF: 0 MIN/MAX: 0 .. 0.2490234375 */
   179 /* 1.3982 */ /* P_Kp: LSB: 2^-7 OFF: 0 MIN/MAX: 0 .. 1.9921875 */
};

CAL Vca_DV_tp Vca_DV_slow = {
   31 /* 0.122 */, /* P_Ad: LSB: 2^-8 OFF: 0 MIN/MAX: 0 .. 0.99609375 */
   255 /* 7.96 */, /* P_Kd: LSB: 2^-5 OFF: 0 MIN/MAX: 0 .. 7.96875 */
   82 /* 0.08 */, /* P_Ki: LSB: 2^-10 OFF: 0 MIN/MAX: 0 .. 0.2490234375 */
   154 /* 1.2 */ /* P_Kp: LSB: 2^-7 OFF: 0 MIN/MAX: 0 .. 1.9921875 */
};

/******************************************************************************\
   SLStaticGlobal: Default storage class for global static variables | Width: 32
\******************************************************************************/
static const volatile Vca_DV_tp * pVca_DV;

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INLINE FUNCTIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

/**************************************************************************************************\
 ***  FUNCTION:
 ***      Vca_SwitchDV
 *** 
 ***  DESCRIPTION:
 ***      
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***
\**************************************************************************************************/
void Vca_SwitchDV(void)
{
   switch (VariantSwitch) {
      case 1: {
         pVca_DV = &Vca_DV_slow;
         break;
      }
      case 2: {
         pVca_DV = &Vca_DV_db_fast;
         break;
      }
      case 3: {
         pVca_DV = &Vca_DV_fast;
         break;
      }
      default: {
         pVca_DV = &Vca_DV_slow;
         break;
      }
   }
}

/**************************************************************************************************\
 ***  FUNCTION:
 ***      RESTART_pidcontroller
 *** 
 ***  DESCRIPTION:
 ***      Main restart function
 ***      
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***
\**************************************************************************************************/
void RESTART_pidcontroller(void)
{
   Vca_SwitchDV();
}

/**************************************************************************************************\
 ***  FUNCTION:
 ***      pidcontroller
 *** 
 ***  DESCRIPTION:
 ***      
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***      void
 ***
 ***  SETTINGS:
 ***
\**************************************************************************************************/
void pidcontroller(void)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   Int16 Sa1_Kd; /* LSB: 2^-15 OFF: 0 MIN/MAX: -1 .. 0.999969482421875 */
   Int16 Sa1_e; /* LSB: 2^-18 OFF: 0 MIN/MAX: -0.125 .. 0.124996185302734 */
   Int16 Sa1_sD; /* LSB: 2^-15 OFF: 0 MIN/MAX: -1 .. 0.999969482421875 */
   Int16 Sa1_xd; /* LSB: 2^-15 OFF: 0 MIN/MAX: -1 .. 0.999969482421875 */
   Int16 Sa1_xi; /* LSB: 2^-19 OFF: 0 MIN/MAX: -0.0625 .. 0.0624980926513672 */

   /* SLLocal: Default storage class for local variables | Width: 32 */
   Int32 Aux_S32;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   ADC Aux_Sa1_REF_a; /* LSB: 2^-11 OFF: 0 MIN/MAX: -10 .. 10 */
   ADC Aux_Sa1_U_X_a; /* LSB: 2^-11 OFF: 0 MIN/MAX: -10 .. 10 */
   DAC Aux__a; /* LSB: 2^-15 OFF: -1 MIN/MAX: -1 .. 0.999969482421875 */

   /* SLStaticLocalInit: Default storage class for static local variables with initvalue | Width: 16
    */
   static Int16 X_Sa1_xd = 0; /* LSB: 2^-15 OFF: 0 MIN/MAX: -1 .. 0.999969482421875 */
   static Int16 X_Sa1_xi = 0; /* LSB: 2^-19 OFF: 0 MIN/MAX: -0.0625 .. 0.0624980926513672 */

   Aux_Sa1_U_X_a = Get_ADC(&Sa1_U_X);
   Aux_Sa1_REF_a = Get_ADC(&Sa1_REF);

   /* Unit delay: pidcontroller/xi */
   Sa1_xi = X_Sa1_xi;
   LOG_VAR(a, _Sa1_xi, Sa1_xi);
   LOG_VAR(a, _Sa1_REF, Aux_Sa1_REF_a);
   LOG_VAR(a, _Sa1_U_X, Aux_Sa1_U_X_a);

   /* Sum: pidcontroller/e */
   Aux_S32 = ((Int32) (((Int32) Aux_Sa1_REF_a) << 7)) - ((Int32) (((Int32) Aux_Sa1_U_X_a) << 7));
   Sa1_e = C__I16FITI32_SAT(Aux_S32, 32767 /* 0.124996185302734 */);

   /* Unit delay: pidcontroller/xi
      # combined # Sum: pidcontroller/sum_i
      # combined # Gain: pidcontroller/Ki */
   X_Sa1_xi = (Int16) (((Int16) (((Int16) ((((Int32) Sa1_e) * ((Int32) pVca_DV->P_Ki)) >> 8)) >> 1))
     + Sa1_xi);
   LOG_VAR(a, _Sa1_e, Sa1_e);

   /* Unit delay: pidcontroller/xd */
   Sa1_xd = X_Sa1_xd;
   LOG_VAR(a, _Sa1_xd, Sa1_xd);

   /* Gain: pidcontroller/Kd */
   Sa1_Kd = (Int16) ((((Int32) Sa1_e) * ((Int32) pVca_DV->P_Kd)) >> 8);

   /* Sum: pidcontroller/sD */
   Sa1_sD = (Int16) (Sa1_xd + Sa1_Kd);

   /* Unit delay: pidcontroller/xd
      # combined # Sum: pidcontroller/sum_d
      # combined # Gain: pidcontroller/ad */
   X_Sa1_xd = (Int16) (((Int16) (((Int16) ((((Int32) Sa1_sD) * ((Int32) pVca_DV->P_Ad)) >> 6)) >>
    2)) - Sa1_Kd);

   /* TargetLink outport: pidcontroller/U_M
      # combined # Sum: pidcontroller/sPID
      # combined # Sum: pidcontroller/sPI
      # combined # Gain: pidcontroller/Kp */
   Aux__a = (UInt16) (((Int16) (((Int16) (((Int16) (((Int16) (Sa1_xi >> 2)) + ((Int16) ((((Int32)
    Sa1_e) * ((Int32) pVca_DV->P_Kp)) >> 8)))) >> 2)) + Sa1_sD)) + 32768);
   Set_DAC(&Sa1_U_M, Aux__a);
   LOG_VAR(a, _Sa1_U_M, Aux__a);
}

/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/
#endif /* PIDCONTROLLER_C */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
