#include "ctwo.h"

CTwo::CTwo(const long new_l, const string new_s2, const double new_d)
	: obj(new_d, new_s2) {
	l = new_l;
}

CTwo::CTwo(const CTwo & new_ctwo){
	l = new_ctwo.l;
	obj = new_ctwo.obj;
}

CTwo & CTwo::operator=(const CTwo & new_ctwo){
	l = new_ctwo.l;
	obj = new_ctwo.obj;
	return *this;
}

long CTwo::get_long(){
	return l;
}

COne CTwo::get_cone(){
	return obj;
}

void CTwo::print(){
	cout << l << endl;
	obj.print();
}

void CTwo::forCThree(){
	cout << "New CThree class!" << endl;
}

CTwo::~CTwo(){
}
