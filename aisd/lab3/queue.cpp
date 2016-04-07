#include <iostream>
#include <queue>

/*void compare(queue<int> &list, queue<int> & list2){
	for(int i = 0; i < list.size(); i++){
		if(list(i) == list2(i)){
			list.pop(i);
			list2.pop(i);
		}
	}
}*/

using namespace std;

int main(){
	queue <int> list;
	queue <int> list2;

	list.push(0);
	list.push(3);
	list.push(4);

	list2.push(0);
	list2.push(4);
	list2.push(7);

	//compare(list, list2);

	for(int i = 0, j = 0; i < list.size(); ++i){
		if(list.front() == list2.(i){
			list.pop();
			list2.pop();
		}
		else 
			cout << "Ooops";
	}

	cout << endl;

	while(!list.empty()){
		cout << list.front() << " ";
		list.pop();
	}

	cout << endl;
	while(!list2.empty()){
		cout << list2.front() << " ";
		list2.pop();
	}

	return 0;
}