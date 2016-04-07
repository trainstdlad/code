#include <iostream>

using namespace std;

struct element{
	int data;
	element * next;
};

class tQueue{
private:
	element * input;
	element * output;
	int length;
public:
	tQueue(){output = input = NULL; length = 0;};
	tQueue(int);
	~tQueue();
	void push(int);
	int pull();
	bool in_queue(int);
	int get_length();
	void print();
};

tQueue::tQueue(int data){
	output = input = new element;
	output->data = data;
	output->next = NULL;
	length = 1;
}

tQueue::~tQueue(){
	element * n;
	while(output != NULL){
		n = output;
		output = output->next;
		delete n;
	}
}

void tQueue::push(int data){
	element * n = new element;
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

int tQueue::pull(){
	if(output == NULL)
		return 0;
	int result = output->data;
	element * tmp = output;
	output = output->next;
	delete tmp;
	length--;
	return result;
}

bool tQueue::in_queue(int data){
	element * current = output;
	while(current->next != NULL)
		if(current->data == data)
			return true;
		else
			current = current->next;
	return false;
}

int tQueue::get_length(){
	return length;
}

void tQueue::print(){
	element * n = output;
	while(n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

int main(){
	tQueue q1, q2, q3;
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
