#include <iostream>

typedef int DataType;

struct cell {
	DataType info;
	cell* next;
};

typedef cell* CircularList;
cell* const emptyList = 0;

//functions prototypes
void head_insert(CircularList& l, DataType elem);
void delete_head(CircularList& l);
void print_List(const CircularList l);

int main(){
	DataType value;
	CircularList my_list = emptyList;
	//add 4 values at head
	for(int i = 0; i < 4; ++i){
		std::cout<<"Insert a value ["<<i<<"]: ";
		std::cin>>value;
		head_insert(my_list,value);
	}
	std::cout<<"Print the list (after head_insert ()):"<<std::endl;
	print_List(my_list);
	delete_head(my_list);
	std::cout<<"Print the list (after delete_head()):"<<std::endl;
	print_List(my_list);
	return 0;
}

//functions definitions
void head_insert(CircularList& l, DataType elem){
	cell* aux = new cell;
	aux->info = elem;
	if(l == emptyList) 
		aux->next = aux;
	else{
		cell* tmp = l;
		while (tmp->next != l){
			tmp = tmp->next;
		}
		tmp->next = aux;
		aux->next = l;
	}
    l = aux;
}
void print_List(const CircularList l){
	cell* temp = l;
	if(l != emptyList){
		do{
			std::cout<<temp->info<<" ";
			temp = temp->next;
		}while(temp != l);
	}
	std::cout<<std::endl;
}
void delete_head(CircularList& l){
	cell* cur = l;
	cell* temp;
	while(cur->next != l){
		cur = cur->next;
	}
	temp = l;
	l = l->next;
	cur->next = l;
}
