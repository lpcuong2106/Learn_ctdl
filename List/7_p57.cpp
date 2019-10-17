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
void Delete_Element_Same(List *L){
	Position p, q;
	p = FirstList(*L);

	while(p != EndList(*L)){
		q = Next(p, *L);
		while(q != EndList(*L)){
			if(Retrieve(p, *L) == Retrieve(q, *L)){
				Delete_List(q, L);
			}else{
				q = Next(q, *L);
			}
		
		}
		p = Next(p, *L);
	
	}
}
int main(){
	List L;
	MakeNull_List(&L);
	Read_List(&L);
	sortInt(&L);
	printf("in ds da xep \n");
	Print_List(L);

	Delete_Element_Same(&L);
	printf("in ds da xoa trung\n");
	Print_List(L);
}
