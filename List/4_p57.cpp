#include "DefineFunction.cpp"
#include <conio.h>

void sortInt(List *L){
	Position P, Q;
	P = FirstList(*L);
	while(P != EndList(*L)){
		Q = Next(P, *L);
		while(Q != EndList(*L)){
			if(Retrieve(P, *L) > Retrieve(Q, *L)){
				ElementType temp;
				temp = L->Elements[P-1];
				L->Elements[P-1] = L->Elements[Q-1];
				L->Elements[Q-1] = temp;
			}
			Q= Next(Q, *L);	
		}
		P = Next(P, *L);
	}
}
void Insert_To_List_Sorted(ElementType X, List *L){
	Position p;
	p = FirstList(*L);
	int found = 0;
	while(p!= EndList(*L) && found == 0 ) {
		if(X <= L->Elements[p-1]){
			found = 1;
			Insert_List(X, p, L);
		}
		p = Next(p, *L);
	}
	
}
int main(){
	List L;
	MakeNull_List(&L);
	Position P;
	P = FirstList(L);
	printf("nhap ds: \n");
	Read_List(&L);
	printf("danh sach vua nhap la: \n");
	sortInt(&L);
	Print_List(L);
	printf("nhap so can them:");
	ElementType X;
	scanf("%d", &X);
	Insert_To_List_Sorted(X, &L);
	Print_List(L);
	
}
