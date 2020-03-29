#include "main.h"
struct HEADER *list_header;

extern int thread_total;//for put
extern uint64_t total;//for put

extern int search_thread_total;//for get
extern uint64_t search_size;//for get

extern uint64_t size;//for put and get, set to 0 before put and get



int main(int argc, char **argv){
	
	search_size=atoi(argv[1]);
	total=atoi(argv[2]);
	thread_total=atoi(argv[3]);
	search_thread_total=thread_total;
	
	test();
	
	
	//usleep(100000000);
	
	
}