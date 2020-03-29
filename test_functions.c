#include "main.h"
#include <time.h>
extern struct HEADER *list_header;

int get_total_stations(){

	int ts=0;
	int i;
	for(i=0;i<STATION_LEVEL_MAX;i++){
		if(list_header->key_head->next[i]!=NULL){
			struct KNODE *temp= list_header->key_head->next[i];
			//printf("\n");
			while(temp!=NULL){
				ts++;
				temp=temp->next[i];
			}
		}
		else{
			break;
		}
	}
	return ts;

}

int get_height(){
	int i;
	for(i=0;i<STATION_LEVEL_MAX;i++){
		if(list_header->key_head->next[i]==NULL){
			break;
		}		
	}
	return i;
}