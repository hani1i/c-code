#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10000

typedef int Data;

typedef struct _queue{
	int arr[MAX_SIZE];
	int front;
	int rear;
	int size;
}Queue;

void InitQueue(Queue * pq){
	pq->size = 0;
	pq->front = 0;
	pq->rear = 0;
}

int getNextIdx(int idx){
	if(idx +1 >= MAX_SIZE) return 0;
	return idx + 1;
}

void setNextIdx(int *idx){
	if(*idx +1 >= MAX_SIZE) *idx = 0;
	else (*idx)++;
}

int Empty(Queue * pq){
	if(pq->front == pq -> rear) return TRUE;
	return FALSE;
}

int Full(Queue *pq){
	if(getNextIdx(pq -> rear) == pq -> front) return TRUE;
	return FALSE;
}

Data Front(Queue * pq){
	if(Empty(pq) == TRUE) return -1;
	return pq -> arr[pq -> front];
}

Data Back(Queue * pq){
	if(Empty(pq) == TRUE) return -1;
	return pq -> arr[pq -> rear -1]; 
}

void Push(Queue * pq, Data data){
	if(Full(pq) == TRUE) return;
	pq -> arr[pq -> rear]  = data;
	setNextIdx(&(pq -> rear));
	(pq -> size)++;
}

Data Pop(Queue * pq){
	if(Empty(pq) == TRUE) return -1;
	
	int data = pq -> arr[pq -> front];
	setNextIdx(&(pq -> front));
	(pq -> size)--;
	return data;
}

int main(){
	int i, N;
	
	scanf("%d", &N);
	
	char str[6];
	
	Queue q;
	InitQueue(&q);
	Data data;
	
	for(i = 0; i < N; i++){
		scanf("%s", str);
		
		if(!strcmp(str, "push")){
			scanf("%d", &data);
			Push(&q, data);
		}
		else if(!strcmp(str, "pop")){
			printf("%d\n", Pop(&q));
		}
		else if(!strcmp(str, "empty")){
			printf("%d\n", Empty(&q));
		}
		else if(!strcmp(str, "size")){
			printf("%d\n", q.size);
		}
		else if(!strcmp(str, "front")){
			printf("%d\n", Front(&q));
		}
		else if(!strcmp(str, "back")){
			printf("%d\n", Back(&q));
		}
	}
	
	return 0;
}
