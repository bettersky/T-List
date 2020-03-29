#include "main.h"

extern int thread_total;

extern uint64_t size;  
extern uint64_t total;  
void *real_thread(void *args);

int  create_thread(int thread_num){

	//printf("begin create %d threads\n", thread_total);
	pthread_t pth[thread_total];
	int i;
	size=0;
	srand( (unsigned)time( NULL ) );
double duration=0;
struct timespec begin, end; 
clock_gettime(CLOCK_MONOTONIC,&begin); //begin insert , so begin counting 

	for(i=0;i<thread_total;i++){
		char arg[10];
		pthread_create(&(pth[i]), NULL,real_thread, (void*)arg);	
	}

printf("created succeed\n");	
	for(i=0;i<thread_total;i++){	
		pthread_join( pth[i], NULL);
	}
	
clock_gettime(CLOCK_MONOTONIC,&end); //begin insert , so begin counting
duration=( (int)end.tv_sec+((double)end.tv_nsec)/s_to_ns ) - ( (int)begin.tv_sec+((double)begin.tv_nsec)/s_to_ns );
printf("%f\t",duration);	


}


void *real_thread(void *args){
	random_write();
}


