#include "main.h"

extern struct HEADER *list_header;

extern uint64_t size;  
extern uint64_t total; 

extern built_info[];

int insert(uint64_t key){

	struct KNODE *new_key=(struct KNODE *)malloc(sizeof(struct KNODE));
	memset(new_key,0, sizeof(struct KNODE));
	new_key->key=key;
	
	uint64_t searching_key=key;
					
	struct KNODE* insert_point= travel_build_not_recur(searching_key);
			//search_insert_point(list_header->curr_max, list_header->key_head, searching_key,0);
									//taveller with building
			
	if(key==insert_point->key){
				//printf("YYYYYYYYYYYYYY, equal\n");
	}
	else if(1){//insert_point->next[0]==NULL || key<insert_point->next[0]->key .then must be >0 and less than the next key, so we insert
				//printf("1111\n");
				int lock_result=1;
				lock_result=pthread_mutex_trylock(  &(list_header->insert_mutex) );//try one time to give infomation
				if(0!=lock_result){
					built_info[10]++;
					pthread_mutex_lock(  &(list_header->insert_mutex) );//blocked to wait
				}
				
				struct KNODE *advancer_insert=insert_point;
				
				while(advancer_insert->next[0]!=NULL){  //while(insert_point->next[0]!=NULL) 3.28 change
					if(key < advancer_insert->next[0]->key){
						break;
					}
					//printf("insert.c ooooooo, small travel effect\n");
					advancer_insert=advancer_insert->next[0];
				}
				//printf("999\n");
				assert(advancer_insert!=NULL);
				new_key->next[0]=advancer_insert->next[0];
				advancer_insert->next[0]=new_key;		
				
				pthread_mutex_unlock(  &(list_header->insert_mutex) );
	}
	else if(key> insert_point->next[0]->key){
				printf("%d:insert, OOOOOOOOOOOOOO, error. insert_point->next[0]->key=%d, key=%d\n",pthread_self(),insert_point->next[0]->key,key);
				
				
				//exit(9);
	}	
	return 1;
	
}
