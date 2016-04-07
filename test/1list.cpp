#include <iostream>

using namespace std;
template <typename T>
struct element{
	T data;
	element * next;
};

template <typename T>
class list1{
private:
	element<T> * main;
	element<T> * current;
public:
	list1(){main = current = NULL;};
	list1(T);
	~list1();
	element * goto_first(){current = main; return current;};
    element * goto_next();
	void add(int);
	void remove();
	T get_value();
};

template <typename T>
list1::list1(T v){
	main = current = new element<T>;
	current->data = v;
	current->next = NULL;
}

template <typename T>
list1::~list1(){
	element<T> * tmp;
	current = main;
	while(current->next != NULL){
		tmp = current;
		current = current->next;
		delete tmp;
	}
}

template <typename T>
element * list1::goto_next(){
	if(current->next != NULL){
		current = current->next;
		return current;
	}
	return NULL;
}

template <typename T>
void list1::add(T v){
	element<T> * n = new element<T>;
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

template <typename T>
void list1::remove(){
	if(current == main && current->next == NULL){
		delete current;
		main = current = NULL;
		return;
	}
	element<T> * tmp = main;
	while(tmp->next != current && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current->next;
	delete current;
	current = tmp;
}

template <typename T>
T list1::get_value(){
	if(current != NULL)
		return current->data;
	return 0;
}

int main(){
	list1<int> L;
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
