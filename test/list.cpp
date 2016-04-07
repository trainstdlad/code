#include <iostream>

using namespace std;

template <typename T>

struct element{
	T value;
	element * next;
};

template <typename T>

class container{
	private:
		element<T> * main;
	public:
		container();
		~container();
		void add(T);
		void print();
};

template <typename T>
container<T>::container(){
	main = NULL;
}
template <typename T>
container<T>::~container(){
	while(main != NULL){
		element<T> * temp = main->next;
		delete main;
		main = temp;
	}
}

template <typename T>
void container<T>::add(T value){
	element<T> * temp = new element<T>;
	temp->next = main;
	temp->value = value;
	main = temp;
}

template <typename T>
void container<T>::print(){
	element<T> * temp;
	temp = main;
		while(temp != NULL){
			cout << temp->value;
			temp = temp->next;
		}
}

template <typename T>
void func(container<T> & var, int numofval, T value){
	for (int i = 0; i < numofval; i++){
		cout << i + 1 << " value - ";
		cin >> value;
		var.add(value);
	}
}


int main(){
	int numofval;
	double value;
	container<double> var;
	cout << "Enter numofval ";
	cin >> numofval;
	func(var, numofval, value);
	var.print();
}
