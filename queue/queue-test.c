#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/* Print All Element from Queue - caso para inteiros */
void print_all_elements(Queue *queue){
	Node *ptr = queue->end;
	int cont = queue->size;
	
	if(isEmpty(queue)){
		printf("Queue empty\n");
		return ;	
	}

	while(ptr != NULL){
		printf("Position: %d, Value : %d\n",cont, *((int*)ptr->element));
		ptr = ptr->next;
		cont--;
	}
	return ;
}


int test_create_queue(){
	Queue *queue = create_queue(sizeof(int));
	
	if(queue != NULL){
		free(queue);		
		return 1;
	}else{
		return 0;
	}
}


int test_add_element_queue(){
	int value1 = 1;
	int value2 = 2; 
	
	Queue *queue = create_queue(sizeof(int));
	add(queue, &value1);
	add(queue, &value2);

	print_all_elements(queue);	
	int result = queue->size;
	free(queue);

	return result;

}

int test_get_elements_queue(){
	int value1 = 1;
	int value2 = 2; 
	int value3 = 3;
	void *ptr;

	Queue *queue = create_queue(sizeof(int));
	add(queue, &value1);
	add(queue, &value2);
	add(queue, &value3);

	print_all_elements(queue);
	printf("\n-- Removing --\n");
	

	while(1){
		ptr = get(queue);
		if(ptr != NULL){		
			printf("removing: %d\n", *((int*)ptr));
		}else{	
			printf("Queue Empty\n");
			break;
		}
	}
	free(queue);
	return 0;
}


void test_isEmpty_full(){
	int value1 = 1;	
	Queue *queue = create_queue(sizeof(int));
	add(queue, &value1);
	if(!isEmpty(queue))
		printf("Success - fila not empty\n");
	free(queue);
}

void test_isEmpty_not_full(){
	Queue *queue = create_queue(sizeof(int));
	if(isEmpty(queue))
		printf("Success - fila empty\n");
	free(queue);
}

void test_clear_queue(){
	int value1 = 1;
	int value2 = 2; 
	int value3 = 3;	
	Queue *queue = create_queue(sizeof(int));
	add(queue, &value1);
	add(queue, &value2);
	add(queue, &value3);

	print_all_elements(queue);

	clear(queue);

	print_all_elements(queue);
	
	free(queue);
}


void test_destroy_queue(){
	Queue *queue = create_queue(sizeof(int));
	destroy(queue);
}

int main(){

	int value = -1;	
    
	value = test_create_queue();

	if(value == 1) printf("Sucesso create_queue\n");
	else printf("Erro create_queue\n");
	
	value = -1;

	value = test_add_element_queue();

	if(value > 0) printf("Sucesso add_element_queue\n");
	else printf("Erro add_element_queue\n");

	test_get_elements_queue();
	
	test_isEmpty_full();
	
	test_isEmpty_not_full();	

	test_clear_queue();

	test_destroy_queue();

return 0;
}



