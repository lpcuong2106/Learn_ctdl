#include <stdio.h>
#include <conio.h>
#define MaxLength 10
typedef int ElementType;
typedef struct {
	ElementType Element[MaxLength];
	int Front, Rear;
}Queue;

// tao mang rong

void MakeNull_Queue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

int Empty_Queue(Queue Q){
	return Q.Front == -1;
}
int Full_Queue(Queue Q){
	return (Q.Rear - Q.Front +1 ) == MaxLength;
}
void EnQueue(ElementType X, Queue *Q){
	if(!Full_Queue(*Q)){
		if(Empty_Queue(*Q)) Q->Front = 0;
		if(Q->Rear == MaxLength -1){
			for(int i = Q->Front; i <= Q->Rear; i++){
				Q->Element[i- Q->Front] = Q->Element[i];
			}
			// Xac dinh vi tri rear moi
			Q->Rear = MaxLength - 1 - Q->Front;
			Q->Front = 0;
		}
		Q->Rear = Q->Rear+1;
		Q->Element[Q->Rear] = X;
	}else{
		printf("Loi hang day");
	}
}
void DeQueue (Queue *Q){
	if(!Empty_Queue(*Q)){
		Q->Front = Q->Front +1;
		if(Q->Front > Q->Rear) MakeNull_Queue(Q);
	}else{
		printf("loi hang rong");
	}
}
void ReadQueue(Queue *Q){
	MakeNull_Queue(Q);
	ElementType X;
	int n;
	printf("\n\n Hang co bao nhieu phan tu ");
	scanf("%d", &n);
	for(int i=1; i <= n ; i++){
		printf("Phan tu thu %d: ", i);
		scanf("%d", &X);
		EnQueue(X, Q);
	}
}

void PrintQueue(Queue *Q){
	while(!Empty_Queue(*Q)){
		printf("%d\t", Q->Element[Q->Front]);
		DeQueue(Q);
	}
	printf("\n");
}

ElementType Front(Queue Q){
	return Q.Element[Q.Front];
}
