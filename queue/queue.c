/* Implementation Queue */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define	EXIT_FAILURE  1                                    
#define	EXIT_SUCCESS  0   

/* Auxiliar function to check function malloc*/
void *mallocc( unsigned int nbytes)
{
   void *ptr;
   ptr = malloc( nbytes);
   if (ptr == NULL) {
	  printf("System close, malloc return NULL \n"); 	
      exit( EXIT_FAILURE);
   }
   return ptr;
}



/* Persuit second element queue */
Node *find_second_element(Queue *queue){
	Node *ptr = queue->end;	
	
	while(ptr->next != queue->start){
		ptr = ptr->next;
	}

	return ptr;
} 

/* Creates queue */
Queue* create_queue(){
	Queue* queue = (Queue*) mallocc(sizeof(Queue));
	queue->start = NULL;
	queue->end = NULL;
	queue->size = 0;
	return queue;
}

/* Add element in the tail the queue*/
void add(Queue *queue,void *element){
	Node *node = mallocc(sizeof(Node));
	node->element = element;

	if(queue->size == 0){
		queue->start = node;
		queue->end = node;
		node->next = NULL;
		queue->size++;
	}else{
		node->next = queue->end;		
		queue->end = node;
		queue->size++;
	}	

}
/* Return element on the head's queue 
	and remove it from queue */
void* get(Queue* queue){
	void *element = NULL;	

	if(queue->size == 0) //empty queue
		return element; 
	else if(queue->size == 1){ // one element
		element = queue->start->element;
		free(queue->start);
		queue->start = NULL;
		queue->end = NULL;
		queue->size--;	
	}else{	// more than one
		element = queue->start->element;
		free(queue->start);
		queue->start = find_second_element(queue);
		queue->start->next = NULL;
		queue->size--;		
	}
	return element;
}

/* Return 1 if queue is empty else return 0  */
int isEmpty(Queue *queue){
	if(queue->size == 0)
		return 1;
	else
		return 0;
}

/* Check if elements is in queue
	return 0 is not in queue
	return 1 is in queue	 */
int find(Queue *queue, void *element){
	Node *ptr = queue->end;

	while(ptr->element != element && ptr != NULL)
		ptr = ptr->next;		
	
	if(ptr == NULL)
		return 0;
	else
		return 1;

}

/* Return number of elements from queue
   Return -1 if list is not alocate */
int size(Queue *queue){
	if(queue != NULL)	
		return queue->size;
	else
		return -1;
}

/* Eliminate all elements from queue */
void clear(Queue *queue){
	Node *ptr = queue->end;
			
	while(ptr != NULL){
		free(ptr);
		ptr = ptr->next;
	}

	queue->start = queue->end = NULL;
	queue->size = 0;	
	
}


void destroy(Queue *queue){
	clear(queue);
	free(queue);
	queue = NULL;
}








