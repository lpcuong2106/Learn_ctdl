#include <conio.h>
#include "DefineFunction.cpp"
void sort_List(List *L){
	Position p, q;
	p = FirstList(*L);
	while(p != EndList(*L)){
		q = Next(p, *L);
		while(q != EndList(*L)){
			if( Retrieve(p, *L) > Retrieve(q, *L)){
				ElementType Temp;
				Temp = L->Elements[p-1];
				L->Elements[p-1] = L->Elements[q-1];
				L->Elements[q-1] = Temp;
			}
			q = Next(q, *L);
		}
		p = Next(p, *L);
	}
}
void merga(List L1, List L2, List *L3){
	Position P1,P2,P3, Q1,Q2,Q3;
	MakeNull_List(L3);
	P1 = FirstList(L1);
	P2 = FirstList(L2);
	P3 = FirstList(*L3);
	Q1= EndList(L1);
	Q2= EndList(L2);
	Q3 = EndList(*L3);
	while(P1 != Q1 && P2 != Q2){
		if( Retrieve(P1, L1) < Retrieve(P2, L2)){
			Insert_List( Retrieve(P1, L1) , Q3, L3);
			P1 = Next(P1, L1);
		}else{
			Insert_List( Retrieve(P2, L2) , Q3, L3);
			P2 = Next(P2, L2);
		}
		Q3 = Next(Q3, *L3);
	}	
	while(P1 != Q1){
			Insert_List( Retrieve(P1, L1) , Q3, L3);
			P1 = Next(P1, L1);
			Q3 = Next(Q3, *L3);
	}
	while(P2 != Q2){
		Insert_List( Retrieve(P2, L2) , Q3, L3);
		P2 = Next(P2, L2);
		Q3 = Next(Q3, *L3);
	}
}

int main(){
	List L1,L2,L3;
	MakeNull_List(&L1);
	MakeNull_List(&L2);
	MakeNull_List(&L3);
	printf("Nhap danh sach 1");
	Read_List(&L1);
	Print_List(L1);
	printf("danh sach sau khi xep");
	sort_List(&L1);
	Print_List(L1);
	
	printf("Nhap danh sach 2");
	Read_List(&L2);
	Print_List(L2);
	printf("danh sach sau khi xep");
	sort_List(&L2);
	Print_List(L2);
	merga(L1,L2,&L3);
	printf("danh sach sau khi merga");
	Print_List(L3);
	getch();
	return 0;
}
