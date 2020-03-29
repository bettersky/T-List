#include "main.h"
#include <time.h>

extern uint64_t size;  
extern uint64_t total;  

int random_write(){

	
	
	for(;size<total;size++){		
		insert(rand());	
	}
	//printf("end\n");

}
