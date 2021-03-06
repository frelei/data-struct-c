/* Interface Queue*/

/* Structure */
typedef struct node{
     void *element;	
     struct node *next;
}Node;

typedef struct queue{
	Node *start;
	Node *end;
	int size;
}Queue;

/* operations   unsigned int element_bytes */
Queue* create_queue();
void add(Queue *queue,void *element);
void* get(Queue* queue);
int isEmpty(Queue *queue);
int find(Queue *queue, void *element);
int size(Queue *queue);
void clear(Queue *queue);
void destroy(Queue *queue);

