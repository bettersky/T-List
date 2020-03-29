#include "main.h"
extern struct HEADER *list_header;

struct KNODE * pure_travel_not_recur(uint64_t searching_key){

	int curr_station_level;
	struct KNODE* searching_point=list_header->key_head;
	
	for(curr_station_level=list_header->curr_max;curr_station_level>=0;curr_station_level--){
		
		int continue_flag=0;
		while(searching_point->next[curr_station_level]!=NULL){
			if(searching_key > searching_point->next[curr_station_level]->key){//go on the current path					
				searching_point=searching_point->next[curr_station_level];				
				continue;
			}	
			else if(searching_key < searching_point->next[curr_station_level]->key){//maybe find or to lower path
				if(curr_station_level==0 ){ //find it t in path 0, not exist
					return searching_point;
				}
				else{
					break;//break the while to the lower path
				}
			}
			else if(searching_key==searching_point->next[curr_station_level]->key){//find it equal in any path
				return searching_point->next[curr_station_level];
			}		
		}
	}


}