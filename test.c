#include "main.h"
extern struct HEADER *list_header;

int globle;
int thread_sleep=0;//100000;

uint64_t size=0;
uint64_t search_size=1000000;
uint64_t total=0;

int thread_total;
void print_tail2();
void print_list(struct KNODE *list);

int add_flag=0;

int search_thread_total=0;
int equal_counter=0;

int built_info[20]={0};
int test(){

	list_header=(struct HEADER *)malloc(sizeof(struct HEADER));
	memset(list_header , 0, sizeof(struct HEADER));
	list_header->key_head=(struct KNODE*)malloc(sizeof(struct KNODE));
	memset(list_header->key_head,0 , sizeof(struct KNODE));
	//pthread_mutex_init(&(list_header->key_head->mutex),NULL);
	
	pthread_mutex_init(&(list_header->insert_mutex),NULL);
	int i;
	for(i=0;i<STATION_LEVEL_MAX;i++){
		pthread_mutex_init(&(list_header->station_builder_mutex[i]),NULL);
	}
	
	
	//printf("Input thread_total:\n");
	//printf("Input bench size:\n");
	
	//thread_total=4;
	//total=10000;
	
	//scanf("%d",&thread_total);
	//scanf("%d",&total);
	
	//printf("%d threads\n",thread_total);
	
	//printf("%d KV\n",total);
	
	create_thread(0);//this will really create many threads
	
	//random_write();
	//print_tail2();
	printf("%d\t",get_height());
	printf("%d\t",get_total_stations());
	printf("%d\t",built_info[9]+built_info[10]);

	
	create_search_thread(0);

	
	printf("\n");
	for(i=0;i<15;i++){
		//printf("built_info[%d]=%d\n",i,built_info[i]);
	}
	
}


void print_tail2(){//debug function
	int i;
	for(i=0;i<STATION_LEVEL_MAX;i++){
		if(list_header->key_head->next[i]!=NULL){
			int j=0;
			struct KNODE *temp= list_header->key_head->next[i];
			//printf("\n");
			while(temp!=NULL){
				j++;
				
				//if(i>6){
					//printf("%p->",temp);
					//printf("in tail2, j is bigger than total, i=%d, exit\n", i);
					//exit(3);
				//}
				temp=temp->next[i];
			}
			//printf("\n");
			printf("flags in level %d:   %d\n",i,j);
		}
	}
	
	//printf("0 node is %p\n",list_header->key_head->next[0] );
	

}

/*
while(1){
		size=0;
		//search_thread_total=thread_total;
		search_size=1000000;
		printf("Input thread_total:\n");
		//printf("Input search_size:\n");
		scanf("%d",&search_thread_total);
		//scanf("%d",&search_size);
		printf("%d threads created to search %d items\n",search_thread_total,search_size);
		create_search_thread(0);
	}

*/
/*
	while(1){
		search_size=0;
		equal_counter=0;
		printf("Insert %llu items, now input search_thread_num and search size:\n", size);
		scanf("%d", &search_thread_total);
		scanf("%d", &total);
		printf("search_size=%d, total=%d,  Begin search...\n",search_size,total);
		create_search_thread(0);
		printf("equal_counter=%d, percent=%f\%\n",equal_counter,(double)equal_counter/total);
	}
	
	*/