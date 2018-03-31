/*
************************************************************************************************************************
*                                                         eGON
*                                         the Embedded GO-ON Bootloader System
*
*                             Copyright(C), 2006-2008, SoftWinners Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name   : boot0.h
*
* Author      : Gary.Wang
*
* Version     : 1.1.0
*
* Date        : 2009.05.21
*
* Description :
*
* Others      : None at present.
*
*
* History     :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang      2009.05.21       1.1.0        build the file
*
************************************************************************************************************************
*/
#ifndef  __uboot_h
#define  __uboot_h

#include "type_def.h"
#include "gpio.h"

struct spare_boot_ctrl_head
{
	unsigned int  jump_instruction;   // one intruction jumping to real code
	unsigned char magic[8];           // ="u-boot"
	unsigned int  check_sum;          // generated by PC
	unsigned int  align_size;		  // align size in byte
	unsigned int  length;             // the size of all file
	unsigned int  uboot_length;       // the size of uboot
	unsigned char version[8];         // uboot version
	unsigned char platform[8];        // platform information
	unsigned int  run_addr;           //stamp space, 16bytes align
};

/******************************************************************************/
/*                          the data stored in file head                      */
/******************************************************************************/
struct spare_boot_data_head
{
	unsigned int                dram_para[32];
	int							run_clock;				// Mhz
	int							run_core_vol;			// mV
	int							uart_port;              // UART���������
	normal_gpio_cfg             uart_gpio[2];           // UART������(���Դ�ӡ��)GPIO��Ϣ
	int							twi_port;               // TWI���������
	normal_gpio_cfg             twi_gpio[2];            // TWI������GPIO��Ϣ�����ڿ���TWI
	int		                    work_mode;              // ����ģʽ
    int                         storage_type;           // �洢��������  0��nand   1��sdcard    2: spinor
    normal_gpio_cfg             nand_gpio[32];          // nand GPIO��Ϣ
    char						nand_spare_data[256];	// nand ������Ϣ
    normal_gpio_cfg             sdcard_gpio[32];		// sdcard GPIO��Ϣ
    char             			sdcard_spare_data[256];	// sdcard ������Ϣ
	int                         secureos_exist;
    int                         uboot_start_sector_in_mmc;     //use in OTA update
    int                         dtb_offset;
    int                         boot_package_size;
    int                         reserved[2];			// ��������λ,256bytes align

};

struct spare_boot_head_t
{
	struct spare_boot_ctrl_head    boot_head;
	struct spare_boot_data_head    boot_data;
};


#define UBOOT_MAGIC                            "uboot"

#endif     //  ifndef __uboot_h

