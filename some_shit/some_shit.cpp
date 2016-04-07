#include <iostream>

using namespace std;

struct value{
	int data;
	value * lastValue;
	value * nextValue; 

};

class list{
private:
	value * nowValue;
	value * lastElem;
	int first_element;
	int last_element;
public:
	list(){nowValue = NULL;};
	list(int);
	~list();
	void push_front(int);
	void push_back(int);
	void print();
	int lastElement();
	int firstElement();
};

list::~list(){

}

void list::push_front(int numb){
	value * temp = new value;
	temp->data = numb;
	temp->lastValue = nowValue;
	nowValue = temp;
}

/*void list::push_back(int v){
	value * temp = new value;
	value * temp2;
	while(nowValue != NULL){
		temp2 = temp2->lastValue;
	}
	temp2->data = v;
	nowValue = temp;

}*/

oid list::push_back(int numb){
	value * temp = new value;
	temp->data = numb;
	temp->nextValue = nowValue;
	nowValue = temp;
}

void list::print(){
	value * temp;
	temp = nowValue;
	while(temp != NULL){
		cout << endl;
		cout << temp->data;
		temp = temp->lastValue;
	}
}

int list::lastElement(){
	value * temp;
	temp = nowValue;
	while(temp != NULL){
		last_element = temp->data;
		temp = temp->lastValue;
	}
	return last_element;
}

int list::firstElement(){
	value * temp;
	temp = nowValue;
	while(temp != NULL){
		first_element = temp->data;
		temp = temp->nextValue;
	}
	return first_element;
}



int main(){
	list list1;
	list1.push_front(1);
	list1.push_front(3);
	list1.push_front(5);
	list1.push_back(4);
	list1.print();
	cout << list1.lastElement();
	return 0;
}