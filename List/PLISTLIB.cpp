#include <stdio.h>
#include <conio.h>
#include <malloc.h>

	typedef int ElementType;
	typedef struct Node{
		ElementType Element;
		Node* Next;
	};
	typedef Node* Position;
	typedef Position List;

void MakeNull_List(List *Header){
	(*Header) = (Node*)malloc(sizeof(Node));
	(*Header)->Next = NULL;
}

int Empty_List(List L){
	return (L->Next == NULL);
}

void Insert_List(ElementType X, Position P, List *L){
	Position T;
	T = (Node*)malloc(sizeof(Node));
	T->Element = X;
	T->Next = P->Next;
	P->Next = T;
}
void Delete_List(Position P, List *L){
	Position T;
	if(P->Next != NULL){
		T = P->Next;
		P->Next = P->Next->Next;
		free(T);
	}else{
		printf("\n-Loi danh sach khong the xoa");
	}
}
Position First(List L){
	return L;
}
ElementType Retrieve(Position P, List L){
	if(P->Next != NULL){
		return P->Next->Element;
	}
}
Position Locate(ElementType X, List L){
	Position P= First(L);
	int found = 0;
	while( (P->Next != NULL) && found ==0 ){
		if(P->Next->Element == X){
			found =1;
		}else{
			P = P->Next;
		}
	}
	return P;
}
Position EndList(List L){
	Position P;
	P = First(L);
	while(P->Next != NULL){
		P = P->Next;
	}
	return P;
}
void Read_List(List *L){
	int i,n,t;
	ElementType X;
	Position P;
	P = First(*L);
	printf("So Phan Tu trong ds: "); scanf("%d", &n);
	for(int i= 1; i<=n; i++){
		printf("Phan tu thu %d ", i); scanf("%d", &X);
		Insert_List(X, EndList(*L), L);
	}
}
void Print_List(List L){
	Position P;
	P = First(L);
	while(P != EndList(L)){
		printf("%d\t", Retrieve(P, L));
		P = P->Next;
	}
}
