#include "ACQUELIB.cpp"

int main(){
	Queue Q;
	printf("Nhap du lieu vao hang");
	ReadQueue(&Q);
	printf("Xoa 3 ptr ra khoi hang");
	DeQueue(&Q);
	DeQueue(&Q);
	DeQueue(&Q);
	printf("them phan tu 12 13 14 vao hang");
	EnQueue(12, &Q);
	EnQueue(13, &Q);
	EnQueue(14, &Q);
	printf("hang hien tai la");
	PrintQueue(&Q);
	if(Empty_Queue(Q)){
		printf("hang hien tai rong");
	}else{
		printf("Hang khac rong");
	}
}


