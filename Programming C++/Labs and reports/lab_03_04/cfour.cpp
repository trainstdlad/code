#include "cfour.h"
#include "cthree.h"
#include "ctwo.h"
#include "cone.h"
#include <iostream>

CFour::CFour(const long l, const string new_s2, const double new_d, const int new_h, const double new_d2) : CThree(l, new_s2, new_d, new_h){
	d2 = new_d2;
}

CFour::CFour(const CFour & new_d2){  
	d2 = new_d2.d2;
}

int CFour::get_double(){
	return d2;
}

void CFour::print(){
	cout << "d2 = " << d2 << endl;
	cout << "l = " << l << endl;
	cout << "h = " << h << endl;
	obj.print();
}

CFour::~CFour(){
}
