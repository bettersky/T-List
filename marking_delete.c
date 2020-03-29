#include "main.h"

extern struct HEADER *list_header;

int marking_delete(uint64_t key){
	
	struct KNODE* delete_point=pure_search(list_header->curr_max, list_header->key_head, key,0);
	
	if(key==delete_point->key){
			delete_point->delete_marker=1;
			return 1;//marked
	}
	
	return 0;//not exist
}