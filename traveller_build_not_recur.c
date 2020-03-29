#include "main.h"
extern struct HEADER *list_header;

//extern int equal_counter;
//extern double durations[];

struct KNODE * travel_build_not_recur(uint64_t searching_key){
	//durations[6]++;
	assert(list_header->key_head!=NULL);
	int curr_station_level;
	struct KNODE* searching_point=list_header->key_head;
	 struct KNODE *bigger_station_point=list_header->key_head;
	

	for(curr_station_level=list_header->curr_max;curr_station_level>=0;curr_station_level--){
		//durations[4]++;
		int step=0; // record the advanced width for adding new station		
		while(searching_point->next[curr_station_level]!=NULL){
			//durations[3]++;
			if(searching_key > searching_point->next[curr_station_level]->key){	
					//durations[11]++;
				if(step==STATION_LEVEL_PUFFER ){

					//durations[7]++;
					int br=station_builder(searching_point, bigger_station_point, curr_station_level);

					if(0==br){
						bigger_station_point=searching_point;//advance						
					}
					step=0;

				}
				
				searching_point=searching_point->next[curr_station_level];	
				step++;	

				continue;//continue the while cycle to go on travese the current path
			}	
			else if(searching_key < searching_point->next[curr_station_level]->key){//find insert point
								//durations[12]++;
				break;//break the while cycle
			}
			else if(searching_key==searching_point->next[curr_station_level]->key){
				//durations[8]++;
				return searching_point->next[curr_station_level];//why not return the searching point?
												//because the receiver doesn't know in which path
			}
			
		}		
		
		//come to here, the current path has been finished
		if(curr_station_level==0 ){
		
			return searching_point;
		}
		else{	
			bigger_station_point=searching_point;//go down a path
			continue;//continue the for cycle to go on the lower path
		}
	}


}

/*
if(curr_station_level==0 ){

					return searching_point;
				}
				else{
					bigger_station_point=searching_point;
					break;
				}
*/