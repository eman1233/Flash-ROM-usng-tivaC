#ifndef __FLASH__
#define __FLASH__

#define FLASH_BASE_ADDRESS  ((volatile unsigned int*)0x00020000)
#define Flash_memory   (*((volatile unsigned long*)(0x400FD000)))
#define FMA            (*((volatile unsigned long*)(Flash_memory+0x000)))
#define FMD            (*((volatile unsigned long*)(Flash_memory+0x004)))
#define FMC            (*((volatile unsigned long*)(Flash_memory+0x008)))
#define FCRIS          (*((volatile unsigned long*)(Flash_memory+0x00C)))
#define BOOTCFG        (*((volatile unsigned long*)(Flash_memory+0x1D0)))

#define WRITE 0x01             //write word
#define ERASE 0x02             //erase word
#define WRKEY 0xA442           
#define PRIS  0x02             //indicate complete erase
#define KEY   0x10             //enable key

void enable(void);
void write(void *data,unsigned int num_word);
void erase(unsigned int blockCount);
void read(void *data,unsigned int num_word);
#endif
