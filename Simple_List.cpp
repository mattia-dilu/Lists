#include <iostream>

typedef int DataType;

struct cell{
	DataType info;
	cell* next;
};

typedef cell* List;

cell* const emptyList = nullptr;

//function prototypes
void head_insert(List& l, DataType elem);
void delete_head(List& l);
void print_List(const List l);
void insert_order(List& l, DataType elem);
bool is_in(const List l, DataType elem);

int main(){
	DataType value;
	List my_list = emptyList;
	//add 4 values at head
	for(int i = 0; i < 4; ++i){
		std::cout<<"Insert a value ["<<i<<"]: ";
		std::cin>>value;
		head_insert(my_list,value);
	}
	std::cout<<"Print the list (after head_insert ()):"<<std::endl;
	print_List(my_list);
	std::cout<<std::endl;
	delete_head(my_list);
	std::cout<<"Print the list (after delete_head()):"<<std::endl;
	print_List(my_list);
	std::cout<<std::endl;
	std::cout<<"Insert a value: ";
	std::cin>>value;
	insert_order(my_list, value);
	print_List(my_list);
	return 0;
}

//function definition
void head_insert(List& l, DataType elem){
	cell* aux  = new cell;
	aux->info = elem;
	aux->next = l;
	l = aux;
}
void delete_head(List& l){
	cell* cur = l;
	l = cur->next;
	delete cur;
}
void print_List(const List l){
	if(l == nullptr) return;
	std::cout<<l->info<<" ";
	return print_List(l->next);
}
bool is_in(const List l, DataType elem){
	if(l == nullptr) return false;
	if(l->info == elem) return true;
	return is_in(l->next, elem);
}
void insert_order(List& l, DataType elem){
	if(is_in(l, elem)) return;
	cell* aux = new cell;
	aux->info = elem;
	aux->next = nullptr;
	if(l == nullptr || l->info > elem){
		aux->next = l;
		l = aux;
	}else{
		insert_order(l->next, elem);
	}
}
