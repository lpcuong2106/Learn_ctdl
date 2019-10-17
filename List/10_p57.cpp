#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include "PLISTLIB.cpp"

void split(List a,List *b,List *c){
	MakeNull_List(b);
	MakeNull_List(c);
	Position p;
	p = First(a);

	while(p != EndList(a)){

		if(p->Next->Element % 2 == 0){
			Insert_List(p->Next->Element, EndList(*b), b);
		}else{
			Insert_List(p->Next->Element, EndList(*c), c);
		}
		p = p->Next;
	}
}
int main(){
	List A, B,C;
	MakeNull_List(&A);
	MakeNull_List(&B);
	MakeNull_List(&C);
	printf("Nhap ds th nhat\n");
	Read_List(&A);

	Print_List(A);
	split(A, &B,&C);
	printf("\n======== In ds chan =========\n");
	Print_List(B);
	printf("\n======== In ds le =========\n");
	Print_List(C);
	
}
