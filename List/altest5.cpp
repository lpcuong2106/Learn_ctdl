#include <conio.h>
#include "DefineFunction.cpp"


int main(){
	List L;
	ElementType X;
	Position P;
	MakeNull_List(&L);
	printf("Nhap danh sach tu ban phim");
	Read_List(&L);
	Print_List(L);
	printf("nhap noi dung can xoa"); scanf("%d", &X);
	P = Locate(X, L);
	if(P == EndList(L) ){
		printf("k tim thay");
	}else{
		Delete_List(P, &L);
	}
	printf("danh sach sau khi remove");
	Print_List(L);
	getch();
	
	
}

