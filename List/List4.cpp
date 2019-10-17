#include <conio.h>
#include "DefineFunction.cpp"

int Find_Max(List L){
	Position P;
	
	P = FirstList(L);
	int max=Retrieve(P, L);
	while(P != EndList(L)){
		if(max < Retrieve(P, L)){
			max = Retrieve(P, L);
		}
		P = Next(P, L);
	}
	return max;
}
int Find_Min(List L){
	Position P;
	
	P = FirstList(L);
	int min=Retrieve(P, L);
	while(P != EndList(L)){
		if(min > Retrieve(P, L)){
			min = Retrieve(P, L);
		}
		P = Next(P, L);
	}
	return min;
}
int count(ElementType X, List L){
	Position p;
	p = Locate(X, L);
	int count=0;
	if(p != EndList(L)){
		while(Retrieve(p, L) == X){
			count++;
			p = Next(p, L);
		}
		
	}
	return count;
}
void sort_List(List *L){
	Position p, q;
	p = FirstList(*L);
	while(p != EndList(*L)){
		q = Next(p, *L);
		while(q != EndList(*L)){
			if( Retrieve(p, *L) > Retrieve(q , *L) ){

				ElementType tam ;
				tam = L->Elements[p -1];
				L->Elements[p -1] = L->Elements[q -1];
				L->Elements[q -1] = tam;

			}
			q = Next(q, *L);
			
		}
		p = Next(p, *L);
	}
}
int main(){
	List L;
	ElementType X;
	Position P;
	MakeNull_List(&L);
	printf("nhap danh sach");
	Read_List(&L);
	printf("Max = %d, Min = %d", Find_Max(L), Find_Min(L) );
	sort_List(&L);
	Print_List(L);
	printf("nhap so can dem"); scanf("%d", &X);
	printf("so phan tu trung %d", count(X, L) );
	
}
