#include <stdio.h>
#include "DefineFunction.cpp"

int main(){
	List L;
	ElementType X;
	Position P;
	MakeNull_List(&L);
	
	printf("Nhap danh sach tu ban phim");
	Read_List(&L);
	
	printf("danh sach nhap la");
	Print_List(L);
	
	printf("Nhap noi dung can tim");
	scanf("%d", &X);
	P=Locate(X, L);
	if(P==EndList(L)){
		printf("khong tim thay phan tu");
	}else{
		printf("vi tti phan tu dau tien trong danh sach la %d", P);
	}
	getch();
}
