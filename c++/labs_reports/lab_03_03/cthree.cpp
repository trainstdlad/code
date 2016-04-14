#include "cthree.h"
#include "ctwo.h"
#include "cone.h"
#include <iostream>

CThree::CThree(const long l, const string new_s2, const double new_d, const int new_h) : CTwo(l, new_s2, new_d){
	h = new_h;
}

CThree::CThree(const CThree & new_h){  
	h = new_h.h;
}

int CThree::get_int(){
	return h;
}

void CThree::print(){
	cout << h << endl;
	obj.print();
	cout << l << endl;
}

CThree::~CThree(){
}
