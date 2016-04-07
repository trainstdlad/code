#include "cone.h"
#include "ctwo.h"
#include <iostream>

int main(){
	COne A, B(12, "B1");
	CTwo C, D(1, "str2", 10);
	A = B;
	A.print();
	C = D;
	C.print();
	return 0;
}
