#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <semaphore.h>
#include <string.h>
#include <assert.h>
#define STATION_LEVEL_MAX 24
#define STATION_LEVEL_PUFFER 2

#define s_to_ns 1000000000	

struct KNODE{
	uint64_t key;
	//pthread_mutex_t mutex;
	struct KNODE *next[STATION_LEVEL_MAX];
	char delete_marker;
};

struct HEADER{

	struct KNODE *key_head;
	int curr_max;
	pthread_mutex_t insert_mutex;
	pthread_mutex_t station_builder_mutex[STATION_LEVEL_MAX];
	
}; 


int test();
int random_write();
int insert(uint64_t key);
int marking_delete(uint64_t key);
int exist(uint64_t key);
struct KNODE * search_insert_point(int curr_station_level, struct KNODE *bigger_station_point, uint64_t searching_key, int deep);

struct KNODE * pure_search(int curr_station_level, struct KNODE *bigger_station_point, uint64_t searching_key, int deep);
struct KNODE * pure_travel_not_recur(uint64_t searching_key);

struct KNODE * travel_build_not_recur(uint64_t searching_key);

int  create_thread(int thread_num);
//int  create_search_thread(int thread_num);

//int station_adder();

int station_builder(struct KNODE* searching_point, struct KNODE* bigger_station_beginner, int lev);


#endif