#include <conio.h>
#include "DefineFunction.cpp"
void sort_List(List *L){
	Position p, q;
	p = FirstList(*L);
	while(p != EndList(*L)){
		q = Next(p, *L);
		while(q != EndList(*L)){
			if( Retrieve(p, *L) > Retrieve(q , *L) ){
				ElementType tam ;
				tam = L->Elements[p -1];
				L->Elements[p-1] = L->Elements[q-1];
				L->Elements[q-1] = tam;

			}
			q = Next(q, *L);		
		}
		p = Next(p, *L);
	}
}
void add_Element(ElementType X, List *L){
	Position P, Q;
	P = FirstList(*L);
	int found = 0;
	while( P != EndList(*L) && found == 0){

		if(X < Retrieve(P, *L) ){
			found = 1;
			break;
		}else{
			P = Next(P, *L);
		}
	}
	Insert_List(X, P , L);
	Print_List(*L);
}
int main(){
	List L;
	ElementType X;
	MakeNull_List(&L);
	printf("nhap danh sach");
	Read_List(&L);
	Print_List(L);
	sort_List(&L);
	Print_List(L);
	printf("nhap gia tri muon them"); scanf("%d", &X);
	add_Element(X, &L);
	
	
}
