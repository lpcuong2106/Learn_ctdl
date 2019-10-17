#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include "PLISTLIB.cpp"

void sortInt(List *L){
	Position p,q;
	p = First(*L);
	while(p != EndList(*L)){
		q = p->Next;
		while(q != EndList(*L)){
			if(Retrieve(p, *L) > Retrieve(q, *L)){
				ElementType T ;
				T = p->Next->Element;
				p->Next->Element = q->Next->Element;
				q->Next->Element = T;
							
			}
			q = q->Next;
		}
		p = p->Next;
	}
}
void merge(List *A,List L1, List L2){
//	if(L1==NULL) return L2;
//	if(L2==NULL) return L1;
//	if(L1->Element < L2->Element) {
//		L1->Next = merge(L1->Next, L2);
//		return L1;
//	}else{
//		return merge(L2,L1);
//	}
//	
	List A;
	Position p,q,r;
	p = FirstList(L1);
	while(p != EndList(L1)){
		q = FirstList(L2);
		while(q != EndList(L2)){
			if(p->Next->Element <= q->Next->Element){
				Insert_List(p->Next->Element, EndList(*A), A);
			}else{
				Insert_List(q->Next->Element, EndList(*A), A);
			}
			q = q->Next;
		}
	}
}
int main(){
	List A,B,C;
	MakeNull_List(&A);
	MakeNull_List(&B);
	MakeNull_List(&C);
	printf("Nhap ds th nhat\n");
	Read_List(&A);
	printf("Nhap ds th hai\n");
	Read_List(&B);
	sortInt(&A);
	sortInt(&B);
	printf("===DS A sau khi xep ===\n");
	Print_List(A);
		printf("\n===DS B sau khi xep ===\n");
	Print_List(B);
	printf("\n=== Tron 2 ds ===\n");
	List R = merge(A, B);
		Print_List(R);
}
