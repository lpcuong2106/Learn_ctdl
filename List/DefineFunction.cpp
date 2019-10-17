#include <stdio.h>
#include <conio.h>
#define Maxlength 30
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlength];
	Position Last;	
}List;

void MakeNull_List(List *L)
{
	L->Last = 0;
}
int Empty_List(List L){
	return (L.Last == 0);
}

int FullList(List L){
	return (L.Last == Maxlength);
}

Position FirstList(List L){
	return 1;
}

Position EndList (List L){
	return L.Last+1;
}
Position Next(Position P, List L){
	return P +1;
}
Position Previous(Position P, List L){
	return P-1;
}
ElementType Retrieve(Position P, List L){
	return L.Elements[P-1];
}

void Insert_List(ElementType X, Position P, List *L){
	int i=0;
	if(L->Last == Maxlength){
		printf("\nDanh sach day");
	}else if( (P<1) || P>L->Last +1 ){
		printf("\n Vi tri khong hop le");
	}else{
		for(i=L->Last ; i>= P; i--){
			L->Elements[i] = L->Elements[i-1];
		}
			L->Last++;
			L->Elements[P-1] = X;
		
	}
}
void Read_List(List *L){
	int i, N;
	ElementType X;
	MakeNull_List(L);
	printf("\nNhap vao so phan tu trong danh sach");
	scanf("%d", &N);
	fflush(stdin);
	for(int i=1; i<=N ; i++){
		printf("\n Phan tu thu %d la ", i);
		scanf("%d", &X); fflush(stdin);
		Insert_List(X, EndList(*L), L);
		}
	}
void Print_List(List L){
	Position P;
	P = FirstList(L);
	
	printf("Bat dau in danh sach");
	
	while(P != EndList(L)){
		printf("\n%d", Retrieve(P,L));
		P  = Next(P, L);
	}
	printf("\nKeet thuc in danh sach\n");
}
Position Locate(ElementType X, List L){
	Position P;
	int found = 0;
	P = FirstList(L);
	while( P!=EndList(L) && found==0){
		if( Retrieve(P, L) == X){
			found = 1;
		}else{
			P =Next(P, L);
		}
		return P;
	}
}
void Delete_List(Position P, List *L){
	if( P> L->Last || P<1){
		printf("vi tri k hop le\n");
	}else if( Empty_List(*L) ){
		printf("Danh sach rong\n");
	}else {
		Position i;
		for(i=P; i< L->Last; i++){
			L->Elements[i-1] = L->Elements[i];
		}
		L->Last--;
	}
	
}
