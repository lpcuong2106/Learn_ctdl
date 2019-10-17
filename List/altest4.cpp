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
	
	printf("Nhap phan tu Them la");
	scanf("%d", &X);
	printf("Nhap vi tri phan tu Them la");
	scanf("%d", &P);
	Insert_List(X, P , &L);
	
	printf("danh sach sau khi them la");
	Print_List(L);
	
	printf("Nhap vi tri phan tu xoa la");
	scanf("%d", &P);
	Delete_List(P, &L);
	Print_List(L);
	
	getch();
}
