#include <conio.h>
#include "DefineFunction.cpp"
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
void Find_Delete(ElementType X,List *L){
	Position p;
	p = FirstList(*L);
	int Found = 0;
	while(p != EndList(*L) && Found==0){
		if(X == Retrieve(p, *L)){
		
			do{
				printf("tim thay trung");
				printf("Vi tri phan tu can tim la: %d", p);
				Delete_List(p, L);
			
			}while(X == Retrieve(p, *L) && p != EndList(*L));
			
			Found = 1;
		}else{
				p = Next(p, *L);
		}
	
	}
}
int main(){
	List L;
	MakeNull_List(&L);
	Read_List(&L);
	sortInt(&L);
	Print_List(L);
	ElementType X;
	printf("nhap pt can xoa");
	scanf("%d", &X);
	Find_Delete(X, &L);
	Print_List(L);
}
