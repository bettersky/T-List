#include "main.h"
extern struct HEADER *list_header;


struct KNODE * search_insert_point(int curr_station_level, struct KNODE *bigger_station_point, uint64_t searching_key, int deep){
	int i;

	assert(bigger_station_point!=NULL);
	
	struct KNODE* searching_point=bigger_station_point;// now this is not null
	
	int step=0; // record the advanced width for adding new station
	int continue_station=0;
	while(searching_point->next[curr_station_level]!=NULL){
	
		//if(continue_station==1 || deep==0){
			//pthread_mutex_lock( &(searching_point->mutex) );
		//}	
		
		if(searching_key > searching_point->next[curr_station_level]->key){
				
				//build station --begin
				if(step==STATION_LEVEL_PUFFER ){
					
					station_builder(searching_point, bigger_station_point, curr_station_level);
					
					bigger_station_point=bigger_station_point->next[curr_station_level+1];
					step=0;
				}
				//build station --end
			//struct KNODE *temp=searching_point;		
			searching_point=searching_point->next[curr_station_level];		
			//pthread_mutex_unlock( &(temp->mutex) );
			step++;	
			continue_station=1;
			continue;
		}
		
		else if(searching_key < searching_point->next[curr_station_level]->key){//find insert point
			if(curr_station_level==0 ){
				return searching_point;
			}
			else{
				return search_insert_point(curr_station_level-1, searching_point, searching_key,deep+1);
			}
		}
		else if(searching_key==searching_point->next[curr_station_level]->key){
			//pthread_mutex_unlock( &(searching_point->mutex) );
			return searching_point->next[curr_station_level];
		}
	
	}
	//now  searching_point->next[cur_station_level] must be NULL
	if(curr_station_level==0 ){
		return searching_point;
	}
	else{
		return search_insert_point(curr_station_level-1, searching_point, searching_key,deep+1);
	}
	
}