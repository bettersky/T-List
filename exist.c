#include "main.h"

extern struct HEADER *list_header;

int exist(uint64_t key){
	
	struct KNODE* exist_point=pure_search(list_header->curr_max, list_header->key_head, key,0);
	
	if(key==exist_point->key){
			return 1;//exist
	}
	
	return 0;//not exist
}