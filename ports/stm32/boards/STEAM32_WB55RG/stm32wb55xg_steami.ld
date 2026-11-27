/*
    GNU linker script for STM32WB55xG

    STeaMi copy of stm32wb55xg.ld: the filesystem is moved up 16 KB to give
    the application 528 KB (frozen Spleen fonts); keep FLASH_FS below the
    BLE_HCILayer radio stack at 0x080E0000.
*/

/* Specify the memory areas */
MEMORY
{
    FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 528K /* pages 0-131 */
    FLASH_APP (rx)  : ORIGIN = 0x08008000, LENGTH = 496K /* pages 8-131 */
    FLASH_FS (r)    : ORIGIN = 0x08084000, LENGTH = 256K /* pages 132-195 */
    RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 192K /* SRAM1 */
    RAM2A (xrw)     : ORIGIN = 0x20030000, LENGTH = 10K  /* SRAM2A */
    RAM2B (xrw)     : ORIGIN = 0x20038000, LENGTH = 10K  /* SRAM2B */
}

/* produce a link error if there is not this amount of RAM for these sections */
_minimum_stack_size = 2K;
_minimum_heap_size = 16K;

/* RAM extents for the garbage collector */
_ram_start = ORIGIN(RAM);
_ram_end = ORIGIN(RAM) + LENGTH(RAM);

_micropy_hw_internal_flash_storage_ram_cache_end = ORIGIN(RAM) + LENGTH(RAM);
_micropy_hw_internal_flash_storage_ram_cache_start = _micropy_hw_internal_flash_storage_ram_cache_end - 4K; /* fs cache = 4K */

/* Define the stack.  The stack is full descending so begins at the bottom of FS cache.
   Note that EABI requires the stack to be 8-byte aligned for a call. */
_estack = _micropy_hw_internal_flash_storage_ram_cache_start - _estack_reserve;
_sstack = _estack - 16K;

_heap_start = _ebss; /* heap starts just after statically allocated memory */
_heap_end = _sstack;

_micropy_hw_internal_flash_storage_start = ORIGIN(FLASH_FS);
_micropy_hw_internal_flash_storage_end   = ORIGIN(FLASH_FS) + LENGTH(FLASH_FS);

SECTIONS
{
    /* Put all IPCC tables into SRAM2A. */
    .ram2a_bss :
    {
        . = ALIGN(4);
        . = . + 64; /* Leave room for the mb_ref_table_t (assuming IPCCDBA==0). */
        *rfcore.o(.bss.ipcc_mem_*)
        . = ALIGN(4);
    } >RAM2A

    /* Put all IPCC buffers into SRAM2B. */
    .ram2b_bss :
    {
        . = ALIGN(4);
        *rfcore.o(.bss.ipcc_membuf_*)
        . = ALIGN(4);
    } >RAM2B
}

/* Build-time layout checks */
_steami_radio_stack_start = 0x080E0000; /* BLE_HCILayer v1.20.0 */
ASSERT(ORIGIN(FLASH) + LENGTH(FLASH) == ORIGIN(FLASH_FS), "FLASH must end where FLASH_FS starts")
ASSERT(ORIGIN(FLASH_APP) + LENGTH(FLASH_APP) == ORIGIN(FLASH_FS), "FLASH_APP must end where FLASH_FS starts")
ASSERT(ORIGIN(FLASH_FS) + LENGTH(FLASH_FS) <= _steami_radio_stack_start, "FLASH_FS overlaps the BLE_HCILayer radio stack at 0x080E0000")
