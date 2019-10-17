#include <conio.h>
#include "DefineFunction.cpp"
void Insert_List_Customize(ElementType X, Position P, List *L){
	int i=0;
	if(L->Last == Maxlength){
		printf("\nDanh sach day");
	}else if( (P<1) || P>L->Last +1 ){
		printf("\n Vi tri khong hop le");
	}else{
		for(i=L->Last ; i> P; i--){
			L->Elements[i] = L->Elements[i-1];
		}
			L->Last++;
			L->Elements[P] = X;
		
	}
}
void ReadList_Increase(List *L){
	printf("Nhap so phan tu ds:\n");
	int n;
	scanf("%d", &n);
	ElementType X;
	MakeNull_List(L);
	Position p;
		printf("\n Phan tu thu 1 la ");
		scanf("%d", &X); fflush(stdin);
			Insert_List(X, EndList(*L), L);
	for(int i = 2; i<=n; i++){
			printf("\n Phan tu thu %d la ", i);
		scanf("%d", &X); fflush(stdin);
		p = FirstList(*L);
		int found =0;
		while(p != EndList(*L) && found ==0){
			if(X >= Retrieve(p, *L) ){
			
				Insert_List_Customize(X, p , L);
				found=1;
			}else{
				Insert_List(X, p , L);
				p = Next(p, *L);
			}
		}
		if(p == EndList(*L)){
			Insert_List(X, EndList(*L), L);
		}
	}
	
	}	
int main(){
	List L;
	MakeNull_List(&L);
	ReadList_Increase(&L);
	Print_List(L);
	
}
