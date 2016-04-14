#include "ctwo.h"
#include "cone.h"
#include "cthree.h"

int main(){
	COne A, B(12, "B1");
	CTwo C, D(1, "str2", 10);
	CThree E, F(1, "2123", 2, 24);
	A = B;
	A.print();
	C = D;
	C.print();
	F.print();
	E.forCThree();
	return 0;
}