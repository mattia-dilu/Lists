#include <iostream>

typedef int DataType;

struct cell {
	DataType info;
	cell* next;
};

typedef cell* CircularList_Sentinel;
cell* const emptyList = nullptr;

//prototypes functions
void create_empty(CircularList_Sentinel& l);
void head_insert(CircularList_Sentinel& l, DataType elem);
void print_List(const CircularList_Sentinel l);

int main(){
	DataType value;
	CircularList_Sentinel my_list = emptyList;
	create_empty(my_list);
	//add 4 values at head
	for(int i = 0; i < 4; ++i){
		std::cout<<"Insert a value ["<<i<<"]: ";
		std::cin>>value;
		head_insert(my_list,value);
	}
	std::cout<<"Print the list (after head_insert ()):"<<std::endl;
	print_List(my_list);
}

//functions definitions
void create_empty(CircularList_Sentinel& l){
	cell* aux = new cell;
	aux->next = aux;
	l = aux;
}
void head_insert(CircularList_Sentinel& l, DataType elem){
	cell* aux = new cell;
	aux->info = elem;
	cell* tmp = l->next;
	l->next = aux;
	aux->next = tmp;
}
void print_List(const CircularList_Sentinel l){
	cell* aux = l->next; // skip sentinel
	while (aux != l) {
		std::cout<<aux->info<<" ";
		aux = aux->next;
	}		
	std::cout<<std::endl;
}

