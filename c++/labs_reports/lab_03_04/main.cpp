#include "ctwo.h"
#include "cone.h"
#include "cthree.h"
#include "cfour.h"

void print_all(CTwo**, unsigned int);

void print_all(CTwo** CArray, unsigned int num){
	for(int i = 0; i < num; i++){
		cout << "== object " << i << " ==" << endl;
		CArray[i]->print();
	}
}

int main(){
	CTwo** CArray = new CTwo*[3];
	CArray[0] = new CTwo(12, "ctwo", 2.5);
	CArray[1] = new CThree(4, "cthree", 5.7, 7);
	CArray[2] = new CFour(5, "cfour", 8.9, 2, 12.3);
	print_all(CArray, 3);
	return 0;
}
