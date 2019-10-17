#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include "PLISTLIB.cpp"

void Delete_E_Old(List *L){
	Position P;
	P = First(*L);
	while(P != EndList(*L)){
	
		if(P->Next->Element %2 != 0){
			
			Delete_List(P, L);
		}else{
			P = P->Next;
		}
			
		
		
	}
}
int main(){
	List A;
	MakeNull_List(&A);

	printf("Nhap ds th nhat\n");
	Read_List(&A);
	Delete_E_Old(&A);
	Print_List(A);
	
}
