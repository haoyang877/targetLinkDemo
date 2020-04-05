@echo off
rem *************************************************************
rem ** Cleanup all files generated by TargetLink
rem ** for systems containing in the model(s)
rem **    vcfp
rem *************************************************************

rem Cleanup files created by the TargetLink code generator
if exist TLProj rmdir /s /q TLProj

rem Cleanup browseable code view files
if exist CodeViewFiles rmdir /s /q CodeViewFiles

rem Cleanup documentation files
if exist doc rmdir /s /q doc

rem Cleanup files created by the make procedure
if exist TLSim rmdir /s /q TLSim

rem Cleanup file related to TL subsystem pidcontroller
set tl_subsys=pidcontroller
if exist %tl_subsys%_sf.c        del %tl_subsys%_sf.c
if exist %tl_subsys%_sf.dll      del %tl_subsys%_sf.dll
if exist %tl_subsys%_sf.mexw32   del %tl_subsys%_sf.mexw32
if exist %tl_subsys%_sf.mexw64   del %tl_subsys%_sf.mexw64
if exist %tl_subsys%_sfcn.c      del %tl_subsys%_sfcn.c
if exist %tl_subsys%_sfcn.dll    del %tl_subsys%_sfcn.dll
if exist %tl_subsys%_sfcn.mexw32 del %tl_subsys%_sfcn.mexw32
if exist %tl_subsys%_sfcn.mexw64 del %tl_subsys%_sfcn.mexw64
if exist %tl_subsys%_sf*.pdb     del %tl_subsys%_sf*.pdb
if exist %tl_subsys%_sf.ilk      del %tl_subsys%_sf.ilk

rem cleanup model specific files
set model=vcfp
if exist %model%.mk                 del %model%.mk

rem cleanup ASAP2 files and files created during A2L file generation
if exist a2lexport.log                del a2lexport.log
if exist a2l_export_param.dd          del a2l_export_param.dd
if exist asap2_all_in_one.xsl         del asap2_all_in_one.xsl
if exist asap2_all_in_one_module.xsl  del asap2_all_in_one_module.xsl
if exist asap2_default.xsl            del asap2_default.xsl
if exist SymTabParser.cfg             del SymTabParser.cfg
if exist *.a2l                        del *.a2l

rem cleanup other files
if exist tl_autoscaling.log           del tl_autoscaling.log
if exist dsdd_validate.log            del dsdd_validate.log
if exist lnk*.tmp                     del lnk*.tmp
if exist make*.lck                    del make*.lck
if exist vc40.pdb                     del vc40.pdb
if exist vc50.pdb                     del vc50.pdb
if exist vc*.idb                      del vc*.idb
if exist NONE                         del NONE
if exist BS_Debug.txt                 del BS_Debug.txt
if exist hdi.hdc                      del hdi.hdc
if exist hdi.hds                      del hdi.hds
if exist tl_diff_cgopt_report.log     del tl_diff_cgopt_report.log

