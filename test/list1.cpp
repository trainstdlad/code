#include <iostream>

using namespace std;

struct element{
	int data;
	element * next;
};

class list1{
private:
	element * main;
	element * current;
public:
	list1(){main = current = NULL;};
	list1(int);
	~list1();
	element * goto_first(){current = main; return current;};
    element * goto_next();
	void add(int);
	void remove();
	int get_value();
};

list1::list1(int v){
	main = current = new element;
	current->data = v;
	current->next = NULL;
}

list1::~list1(){
	element * tmp;
	current = main;
	while(current->next != NULL){
		tmp = current;
		current = current->next;
		delete tmp;
	}
}

element * list1::goto_next(){
	if(current->next != NULL){
		current = current->next;
		return current;
	}
	return NULL;
}

void list1::add(int v){
	element * n = new element;
	if(main == NULL){
		main = current = n;
		n->data = v;
		n->next = NULL;
		return;
	}
	n->next = current->next;
	current->next = n;
	current = n;
	n->data = v;
}

void list1::remove(){
	if(current == main && current->next == NULL){
		delete current;
		main = current = NULL;
		return;
	}
	element * tmp = main;
	while(tmp->next != current && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current->next;
	delete current;
	current = tmp;
}

int list1::get_value(){
	if(current != NULL)
		return current->data;
	return 0;
}

int main(){
	list1 L;
	for(int i = 0; i < 5; i++)
		L.add(i);
	L.goto_first();
	cout << L.get_value() << endl;
	L.goto_next();
	cout << L.get_value() << endl;
	L.add(66);
	L.goto_next();
	L.remove();
	cout << "Full list:" << endl;
	L.goto_first();
	cout << L.get_value() << endl;
	while(L.goto_next() != NULL)
		cout << L.get_value() << endl;
	return 0;
}
