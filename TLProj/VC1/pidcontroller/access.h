/**************************************************************************************************\
 *** 
 *** Simulink model       : vcfp
 *** TargetLink subsystem : vcfp/pidcontroller
 *** Codefile             : access.h
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
 *** TargetLink version      : 4.2 from 14-Oct-2016
 *** Code generator version  : Build Id 4.2.0.26 from 2016-10-17 16:31:48

\**************************************************************************************************/

#ifndef ACCESS_H
#define ACCESS_H

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/

#include "udt_a.h"

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
/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

/******************************************************************************\
   EXPORTED_FCN: global function(s) (exported to other modules)
\******************************************************************************/
extern ADC Get_ADC(ADC * varptr);

extern DAC Get_DAC(DAC * varptr);

/******************************************************************************\
   EXPORTED_FCN: global function(s) (exported to other modules)
\******************************************************************************/
extern void Set_ADC(ADC * varptr, ADC value);

extern void Set_DAC(DAC * varptr, DAC value);

#endif /* ACCESS_H */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
