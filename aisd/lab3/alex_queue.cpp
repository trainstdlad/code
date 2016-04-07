#include <iostream>

using namespace std;

template <typename T>
struct element{
	T data;
	element * next;
};

template <typename T>
class tQueue{
private:
	element<T> * input;
	element<T> * output;
	T length;
public:
	tQueue(){output = input = NULL; length = 0;};
	tQueue(T);
	~tQueue();
	void push(T);
	T pull();
	bool in_queue(T);
	T get_length();
	void print();
};

template <typename T>
tQueue<T>::tQueue(T data){
	output = input = new element<T>;
	output->data = data;
	output->next = NULL;
	length = 1;
}

template <typename T>
tQueue<T>::~tQueue(){
	element<T> * n;
	while(output != NULL){
		n = output;
		output = output->next;
		delete n;
	}
}

template <typename T>
void tQueue<T>::push(T data){
	element<T> * n = new element<T>;
	if(output == NULL){
		input = output = n;
		n->next = NULL;
		n->data = data;
		length = 1;
		return;
	}
	input->next = n;
	n->next = NULL;
	n->data = data;
	input = n;
	length++;
}

template <typename T>
T tQueue<T>::pull(){
	if(output == NULL)
		return 0;
	T result = output->data;
	element<T> * tmp = output;
	output = output->next;
	delete tmp;
	length--;
	return result;
}

template <typename T>
bool tQueue<T>::in_queue(T data){
	element<T> * current = output;
	while(current->next != NULL)
		if(current->data == data)
			return true;
		else
			current = current->next;
	return false;
}

template <typename T>
T tQueue<T>::get_length(){
	return length;
}

template <typename T>
void tQueue<T>::print(){
	element<T> * n = output;
	while(n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

int main(){
	tQueue <int> q1;
	tQueue <int> q2;
	tQueue <int> q3;
	q1.push(10);
	q1.push(20);
	q1.push(30);
	q2.push(40);
	q2.push(10);
	cout << "q1: ";
	q1.print();
	cout << "q2: ";
	q2.print();
	int m = q1.get_length();
	for(int i = 0; i < m; i++)
		q3.push(q1.pull());
	m = q2.get_length();
	for(int i = 0; i < m; i++){
		int n = q2.pull();
		if(!q3.in_queue(n))
			q3.push(n);
	}
	cout << "q3: ";
	q3.print();
	return 0;
}

