/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */

-l"/home/david/Documents/ULL/4/Arquitecturas/proyecto_base/Proyecto_base/Release/configPkg/package/cfg/hello_p64P.o64P"
-l"/home/david/Documents/ULL/4/Arquitecturas/proyecto_base/Proyecto_base/src/sysbios/sysbios.a64P"
-l"/opt/ti/xdctools_3_25_03_72/packages/ti/targets/rts6000/lib/ti.targets.rts6000.a64P"
-l"/opt/ti/xdctools_3_25_03_72/packages/ti/targets/rts6000/lib/boot.a64P"


/* function aliases */
/* ignore error about def and ref in the same file */
--diag_remark=10268
--symbol_map _xdc_runtime_System_flush__E=_xdc_runtime_System_flush__F
--symbol_map _xdc_runtime_Memory_query__E=_xdc_runtime_Memory_query__F
--symbol_map _xdc_runtime_System_putch__E=_xdc_runtime_System_putch__F
--symbol_map _xdc_runtime_Registry_getMask__E=_xdc_runtime_Registry_getMask__F
--symbol_map _xdc_runtime_LoggerBuf_write4__E=_xdc_runtime_LoggerBuf_write4__F
--symbol_map _xdc_runtime_LoggerBuf_reset__E=_xdc_runtime_LoggerBuf_reset__F
--symbol_map _xdc_runtime_System_avsprintf__E=_xdc_runtime_System_avsprintf__F
--symbol_map _xdc_runtime_Startup_exec__E=_xdc_runtime_Startup_exec__F
--symbol_map _xdc_runtime_System_abort__E=_xdc_runtime_System_abort__F
--symbol_map _xdc_runtime_Text_matchRope__E=_xdc_runtime_Text_matchRope__F
--symbol_map _xdc_runtime_LoggerBuf_write8__E=_xdc_runtime_LoggerBuf_write8__F
--symbol_map _xdc_runtime_System_vsnprintf__E=_xdc_runtime_System_vsnprintf__F
--symbol_map _xdc_runtime_System_sprintf_va__E=_xdc_runtime_System_sprintf_va__F
--symbol_map _xdc_runtime_LoggerBuf_flushAll__E=_xdc_runtime_LoggerBuf_flushAll__F
--symbol_map _xdc_runtime_LoggerBuf_getFilterLevel__E=_xdc_runtime_LoggerBuf_getFilterLevel__F
--symbol_map _xdc_runtime_Error_getData__E=_xdc_runtime_Error_getData__F
--symbol_map _xdc_runtime_Memory_alloc__E=_xdc_runtime_Memory_alloc__F
--symbol_map _xdc_runtime_Error_raiseX__E=_xdc_runtime_Error_raiseX__F
--symbol_map _xdc_runtime_LoggerBuf_setFilterLevel__E=_xdc_runtime_LoggerBuf_setFilterLevel__F
--symbol_map _xdc_runtime_LoggerBuf_enable__E=_xdc_runtime_LoggerBuf_enable__F
--symbol_map _xdc_runtime_LoggerBuf_getNextEntry__E=_xdc_runtime_LoggerBuf_getNextEntry__F
--symbol_map _xdc_runtime_Memory_getStats__E=_xdc_runtime_Memory_getStats__F
--symbol_map _xdc_runtime_Error_init__E=_xdc_runtime_Error_init__F
--symbol_map _xdc_runtime_Registry_findByName__E=_xdc_runtime_Registry_findByName__F
--symbol_map _xdc_runtime_Log_doPrint__E=_xdc_runtime_Log_doPrint__F
--symbol_map _xdc_runtime_Memory_getMaxDefaultTypeAlign__E=_xdc_runtime_Memory_getMaxDefaultTypeAlign__F
--symbol_map _xdc_runtime_Text_putLab__E=_xdc_runtime_Text_putLab__F
--symbol_map _xdc_runtime_Registry_getModuleId__E=_xdc_runtime_Registry_getModuleId__F
--symbol_map _xdc_runtime_Registry_findById__E=_xdc_runtime_Registry_findById__F
--symbol_map _xdc_runtime_System_snprintf_va__E=_xdc_runtime_System_snprintf_va__F
--symbol_map _xdc_runtime_Gate_enterSystem__E=_xdc_runtime_Gate_enterSystem__F
--symbol_map _xdc_runtime_Registry_getNextModule__E=_xdc_runtime_Registry_getNextModule__F
--symbol_map _xdc_runtime_System_printf_va__E=_xdc_runtime_System_printf_va__F
--symbol_map _xdc_runtime_Text_cordText__E=_xdc_runtime_Text_cordText__F
--symbol_map _xdc_runtime_LoggerBuf_disable__E=_xdc_runtime_LoggerBuf_disable__F
--symbol_map _xdc_runtime_Registry_getModuleName__E=_xdc_runtime_Registry_getModuleName__F
--symbol_map _xdc_runtime_LoggerBuf_flush__E=_xdc_runtime_LoggerBuf_flush__F
--symbol_map _xdc_runtime_Registry_findByNamePattern__E=_xdc_runtime_Registry_findByNamePattern__F
--symbol_map _ti_sysbios_gates_GateHwi_query__E=_ti_sysbios_gates_GateHwi_query__F
--symbol_map _xdc_runtime_LoggerBuf_flushAllInternal__E=_xdc_runtime_LoggerBuf_flushAllInternal__F
--symbol_map _xdc_runtime_Error_check__E=_xdc_runtime_Error_check__F
--symbol_map _xdc_runtime_System_vsprintf__E=_xdc_runtime_System_vsprintf__F
--symbol_map _xdc_runtime_Text_putSite__E=_xdc_runtime_Text_putSite__F
--symbol_map _xdc_runtime_System_exit__E=_xdc_runtime_System_exit__F
--symbol_map _xdc_runtime_Error_print__E=_xdc_runtime_Error_print__F
--symbol_map _xdc_runtime_System_asprintf_va__E=_xdc_runtime_System_asprintf_va__F
--symbol_map _xdc_runtime_Registry_addModule__E=_xdc_runtime_Registry_addModule__F
--symbol_map _xdc_runtime_Registry_isMember__E=_xdc_runtime_Registry_isMember__F
--symbol_map _xdc_runtime_Error_getCode__E=_xdc_runtime_Error_getCode__F
--symbol_map _xdc_runtime_SysMin_putch__E=_xdc_runtime_SysMin_putch__F
--symbol_map _xdc_runtime_SysMin_exit__E=_xdc_runtime_SysMin_exit__F
--symbol_map _xdc_runtime_Memory_free__E=_xdc_runtime_Memory_free__F
--symbol_map _xdc_runtime_Startup_rtsDone__E=_xdc_runtime_Startup_rtsDone__F
--symbol_map _ti_sysbios_gates_GateMutex_query__E=_ti_sysbios_gates_GateMutex_query__F
--symbol_map _xdc_runtime_System_aprintf_va__E=_xdc_runtime_System_aprintf_va__F
--symbol_map _xdc_runtime_SysMin_flush__E=_xdc_runtime_SysMin_flush__F
--symbol_map _xdc_runtime_Gate_leaveSystem__E=_xdc_runtime_Gate_leaveSystem__F
--symbol_map _xdc_runtime_Error_getMsg__E=_xdc_runtime_Error_getMsg__F
--symbol_map _xdc_runtime_Memory_valloc__E=_xdc_runtime_Memory_valloc__F
--symbol_map _xdc_runtime_SysMin_ready__E=_xdc_runtime_SysMin_ready__F
--symbol_map _xdc_runtime_Diags_setMask__E=_xdc_runtime_Diags_setMask__F
--symbol_map _xdc_runtime_SysMin_abort__E=_xdc_runtime_SysMin_abort__F
--symbol_map _xdc_runtime_LoggerBuf_write0__E=_xdc_runtime_LoggerBuf_write0__F
--symbol_map _xdc_runtime_Text_ropeText__E=_xdc_runtime_Text_ropeText__F
--symbol_map _xdc_runtime_System_avprintf__E=_xdc_runtime_System_avprintf__F
--symbol_map _xdc_runtime_LoggerBuf_write1__E=_xdc_runtime_LoggerBuf_write1__F
--symbol_map _xdc_runtime_Error_getId__E=_xdc_runtime_Error_getId__F
--symbol_map _xdc_runtime_Error_getSite__E=_xdc_runtime_Error_getSite__F
--symbol_map _xdc_runtime_Memory_calloc__E=_xdc_runtime_Memory_calloc__F
--symbol_map _xdc_runtime_System_vprintf__E=_xdc_runtime_System_vprintf__F
--symbol_map _xdc_runtime_LoggerBuf_write2__E=_xdc_runtime_LoggerBuf_write2__F
--symbol_map _xdc_runtime_Text_putMod__E=_xdc_runtime_Text_putMod__F
--symbol_map _xdc_runtime_System_atexit__E=_xdc_runtime_System_atexit__F


/* Elf symbols */
--symbol_map ___TI_STACK_BASE=__stack
--symbol_map ___TI_STACK_SIZE=__STACK_SIZE
--symbol_map ___TI_STATIC_BASE=___bss__
--symbol_map __c_int00=_c_int00



--args 0x0
-heap  0x0
-stack 0x1000

MEMORY
{
    IRAM (RWX) : org = 0x800000, len = 0x200000
    DDR : org = 0x80000000, len = 0x10000000
}

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from ti.targets.rts6000 (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from xdc.services.getset (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.rts (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sysbios.family.c62 (null): */

/* Content from ti.sysbios.family.c64p.tci6482 (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.platforms.sim64Pxx (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.c64p (ti/sysbios/family/c64p/linkcmd.xdt): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.timers.timer64 (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from configPkg (null): */

/* Content from xdc.services.io (null): */


/*
 * symbolic aliases for numeric constants or static instance objects
 */
_xdc_runtime_Startup__EXECFXN__C = 1;
_xdc_runtime_Startup__RESETFXN__C = 1;
_TSK_idle = _ti_sysbios_knl_Task_Object__table__V + 0;

SECTIONS
{
    .text: load >> DDR
    .stack: load > DDR
    .bss: load > DDR
    .cinit: load > DDR
    .pinit: load > DDR
    .const: load >> DDR
    .data: load >> DDR
    .switch: load >> DDR
    .sysmem: load > DDR
    .far: load >> DDR
    .args: load > DDR align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> DDR
    .vecs: load > DDR
    xdc.meta: load > DDR, type = COPY

}

