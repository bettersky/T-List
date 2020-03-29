#include "main.h"
extern struct HEADER *list_header;


struct KNODE * pure_search(int curr_station_level, struct KNODE *bigger_station_point, uint64_t searching_key, int deep){
	assert(bigger_station_point!=NULL);
	struct KNODE* searching_point=bigger_station_point;// now this is not null	
	
	while(searching_point->next[curr_station_level]!=NULL){
//printf("11111thread:%d, curr_station_level=%d, searching_key=%llu\n",pthread_self(),curr_station_level,searching_key);	
		if(searching_key > searching_point->next[curr_station_level]->key){					
			searching_point=searching_point->next[curr_station_level];				
			continue;
		}	
		else if(searching_key < searching_point->next[curr_station_level]->key){//find insert point
			if(curr_station_level==0 ){
//printf("xxxxxxx thread:%d, curr_station_level=%d\n",pthread_self(),curr_station_level);	

				return searching_point;
			}
			else{
				return pure_search(curr_station_level-1, searching_point, searching_key,deep+1);
			}
		}
		else if(searching_key==searching_point->next[curr_station_level]->key){
			return searching_point->next[curr_station_level];
		}
	
	}
//printf("4444444444 thread:%d, curr_station_level=%d\n",pthread_self(),curr_station_level);	

	//now  searching_point->next[cur_station_level] must be NULL
	if(curr_station_level==0 ){
	//printf("yyyyyyyyy thread:%d, curr_station_level=%d\n",pthread_self(),curr_station_level);	

		return searching_point;
	}
	else{
		return pure_search(curr_station_level-1, searching_point, searching_key,deep+1);
	}
	
}
