#include "main.h"
#include <time.h>
extern struct HEADER *list_header;

extern uint64_t search_size;  
extern uint64_t size; 
extern uint64_t total;  
extern int thread_total;

extern int search_thread_total;

int search_with_lock(uint64_t searching_key){
	struct KNODE* insert_point=search_insert_point(list_header->curr_max, list_header->key_head, searching_key,0);
			
	if(searching_key==insert_point->key){
				//printf("YYYYYYYYYYYYYY, equal\n");
	}
	else if(insert_point->next[0]==NULL || searching_key<insert_point->next[0]->key){//then must be >0 and less than the next key, so we insert
				//new_key->next[0]=insert_point->next[0];
				//insert_point->next[0]=new_key;				
				//pthread_mutex_unlock(  &(insert_point->mutex) );
	}
	else if(searching_key> insert_point->next[0]->key){
				printf("%d:insert, OOOOOOOOOOOOOO, error. insert_point->next[0]->key=%d, key=%d\n",pthread_self(),insert_point->next[0]->key,searching_key);
				exit(9);
	}	
	return 1;
}
int random_search(uint64_t search_size){
//printf("%d:search begin,total=%d,  search_thread_total=%d, total/search_thread_total=%d\n",pthread_self(),total,search_thread_total,total/search_thread_total);
	
double duration=0;
struct timespec begin, end; 
int x=0;
int dice=rand()%8;
if(dice!=1){
	return;
}


	int y=search_size;
clock_gettime(CLOCK_MONOTONIC,&begin); //begin insert , so begin counting 	

	//for(;size<search_size;size++){
	for(;x<y;x++){
		
		uint64_t searching_key=rand();
		pure_travel_not_recur(searching_key);
		
	}
	//printf("end\n");
clock_gettime(CLOCK_MONOTONIC,&end); //begin insert , so begin counting
duration=( (int)end.tv_sec+((double)end.tv_nsec)/s_to_ns ) - ( (int)begin.tv_sec+((double)begin.tv_nsec)/s_to_ns );
printf("x=%d, random_search duration=%f s\n",x,duration);

}
