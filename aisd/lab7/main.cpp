#include <iostream>

using namespace std;

int summ(int *ptr_x, int *ptr_y){
	return (*ptr_x + *ptr_y);
}

int main(){
	int *ptr_x, *ptr_y, x, y;
	ptr_x = &x;
	ptr_y = &y;
	cout << "Enter x ";
	cin >> x;
	cout << "Enter y ";
	cin >> y;
	cout << summ(ptr_x, ptr_y);
	return 0;
}