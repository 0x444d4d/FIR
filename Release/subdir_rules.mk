################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Ejemplo_comienzo.obj: ../Ejemplo_comienzo.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv64+ --abi=coffabi -O2 --include_path="/opt/ti/ccsv5/tools/compiler/c6000_7.4.4/include" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Ejemplo_comienzo.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

hello.obj: ../hello.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/ccsv5/tools/compiler/c6000_7.4.4/bin/cl6x" -mv64+ --abi=coffabi -O2 --include_path="/opt/ti/ccsv5/tools/compiler/c6000_7.4.4/include" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="hello.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../hello.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_25_03_72/xs" --xdcpath="/opt/ti/bios_6_35_04_50/packages;/opt/ti/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.C64P -p ti.platforms.sim64Pxx -r debug -c "/opt/ti/ccsv5/tools/compiler/c6000_7.4.4" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd


