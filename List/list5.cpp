#include <conio.h>
#include "DefineFunction.cpp"

void split_List(List L, List *Even, List *Odd){
	Position p;
	p = FirstList(L);
	while(p != EndList(L)){
		if(Retrieve(p, L) % 2 == 0){
			Insert_List(Retrieve(p, L) , FirstList(*Even) , Even);
		}else{
			Insert_List(Retrieve(p, L) , FirstList(*Even) , Odd);
		}
		p =Next(p, L);
	}
}
int main(){
	List L, Even, Odd;
	MakeNull_List(&L);
	MakeNull_List(&Even);
	MakeNull_List(&Odd);
	printf("nhap danh sach");
	Read_List(&L);
	printf("danh sach nhap");
	Print_List(L);
	
	split_List(L, &Even, &Odd);
	Print_List(Even);
	Print_List(Odd);
	getch();
	return 0;
}
