#include "main.h"

extern struct HEADER *list_header;
extern uint64_t size;  
extern uint64_t total;  

extern built_info[];

int station_builder(struct KNODE* searching_point, struct KNODE* bigger_station_beginner, int lev){
	//we want add the the next node of searching_point as a higher station
	
	
	struct KNODE *setting_node=searching_point;//->next[lev];
	if(setting_node->next[lev+1] !=NULL){//it must have been set a higher station, but this
																	//doesn't affect if next is the last station
													//don't add
		built_info[0]++;
		return 0 ;//this says the setting node has been set
	}
	
	//int counter=0;
	//now we find the insert point of the higher station
	int lock_result=pthread_mutex_trylock( &(list_header->station_builder_mutex[lev]) );
	if(0!=lock_result){//try failed
		//printf("0!=lock_result\n");
		built_info[9]++;
		pthread_mutex_lock( &(list_header->station_builder_mutex[lev]) );
		//return 2; //mutex is locked by other thread, give up building, return and go on the travelling
		
	}
	int return_flag=0;
	while(1){
		//counter++;
		assert(bigger_station_beginner!=NULL);
		
		if(setting_node->next[lev+1]!=NULL){//need not set, step return to 0
			//printf("in station_adder2, setting_node has been station\n");
			built_info[1]++;
			return_flag=1;
			break;
			//return 0;
		}
		
		if( setting_node->next[lev]!=NULL && setting_node->next[lev]->next[lev+1]!=NULL){//need not set, step return to 0  
			//printf("in station_adder2, setting_node->next has been station\n");
			built_info[2]++;
			return_flag=1;
			break;
			//return 0;
		}
		
		if(( list_header->key_head->next[lev+1]==NULL )){ //find it. higher station is blank so height++
		
			assert(list_header->key_head == bigger_station_beginner);
			built_info[3]++;
			list_header->curr_max++;
			break;
		}
		
		if(bigger_station_beginner->next[lev+1]!=NULL){
			if(bigger_station_beginner->next[lev+1]==setting_node || bigger_station_beginner->next[lev+1]==setting_node->next[lev]){//need not set, step return to 0
				//printf("in station_adder2, interesting 1\n");
				built_info[4]++;
				return_flag=1;
				break;
			}
			else if(bigger_station_beginner==setting_node||bigger_station_beginner==setting_node->next[lev]){
				printf("in station_adder2, interesting 2\n");
				built_info[5]++;
				return_flag=1;
				break;
			}
		}
		
		if(bigger_station_beginner->next[lev+1]==NULL&& bigger_station_beginner->key <setting_node->key){//find it. will be set as the last higher station
		
			built_info[6]++;
			break;
		}
		
		if(bigger_station_beginner->next[lev+1]!=NULL&&bigger_station_beginner->next[lev+1]->key > setting_node->key){//find the insert point
			built_info[7]++;
			break;
		}
		
		if(bigger_station_beginner->next[lev+1]==NULL&&bigger_station_beginner->key >= setting_node->key){//exception
			built_info[8]++;
			printf("in station_adder2, exception, exit\n");
			exit(3);
		}
		
		bigger_station_beginner=bigger_station_beginner->next[lev+1];
	}
	
	if(return_flag==1){
		pthread_mutex_unlock( &(list_header->station_builder_mutex[lev]) );
		return 0;
	}
	//now we find the insert point, it is bigger_station_beginner
	//printf("counter=%d\n",counter);
	setting_node->next[lev+1]=bigger_station_beginner->next[lev+1];
	bigger_station_beginner->next[lev+1]= setting_node;
	
	pthread_mutex_unlock( &(list_header->station_builder_mutex[lev]) );
	
	
	return 1;

}