#include "main.h"


extern int search_thread_total;

extern uint64_t search_size;  
extern uint64_t size;
void *search_threadl(void *args);

int  create_search_thread(int thread_num){

	//printf("begin create %d  search_threads\n", search_thread_total);
	pthread_t pth[search_thread_total];
	int i;
	size=0;
	srand( (unsigned)time( NULL ) );
double duration=0;
struct timespec begin, end; 
clock_gettime(CLOCK_MONOTONIC,&begin); //begin insert , so begin counting 
	
	
	for(i=0;i<search_thread_total;i++){
		char arg[10];
		pthread_create(&(pth[i]), NULL,search_threadl, (void*)arg);	
	}
printf("created search thread succeed\n");	
	 
	for(i=0;i<search_thread_total;i++){	
	printf("search before----- joined\n");
		pthread_join( pth[i], NULL);
		printf("search thread joined\n");
	}
	
clock_gettime(CLOCK_MONOTONIC,&end); //begin insert , so begin counting
duration=( (int)end.tv_sec+((double)end.tv_nsec)/s_to_ns ) - ( (int)begin.tv_sec+((double)begin.tv_nsec)/s_to_ns );
//printf("searched size=%llu, duration=%f s\n",size,duration);	
printf("%f\t",duration);	

}

void *search_threadl(void *args){
	random_search(search_size);
}


