#include "flash.h"
#include <stdint.h>
void enable(void){
	if(BOOTCFG&KEY)
		FMC|=WRKEY;
	
}

int erase(unsigned int blockCount){
	FMA&=0xFFFC0000;
	for(unsigned int i=0;i<blockCount;i++){
		FMA|=((uint32_t)FLASH_BASE_ADDRESS)+(i*1024);
	}
	FMC|=ERASE;
	while(FMC&ERASE){}
		return 0;
}

void write(void *data,uint32_t num_word){
	volatile unsigned int blockCount=((num_word*sizeof(uint32_t))/1024)+1;
	erase(blockCount);
	for(uint32_t i=0;i<num_word;i++){
		FMD=((volatile unsigned long*)data)[i];
		FMA&=0xFFFC0000;
		FMA|=((uint32_t)FLASH_BASE_ADDRESS)+(i*sizeof(uint32_t));
		FMC|=WRITE;
		while(FMC&WRITE){}
	}
	
}
void read(void *data,unsigned int num_word){
	for(uint32_t i=0;i<num_word;i++){
		((unsigned int*)data)[i]=FLASH_BASE_ADDRESS[i];
	}
}