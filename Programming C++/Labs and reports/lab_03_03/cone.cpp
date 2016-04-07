#include "cone.h"

COne::COne(const double new_d, const string new_s){
	d = new_d;
	s = new_s;
}

COne::COne(const COne & new_cone){
	d = new_cone.d;
	s = new_cone.s;
}

COne::~COne(){
}

COne & COne::operator=(const COne & new_cone){
	d = new_cone.d;
	s = new_cone.s;
	return *this;
}

double COne::get_double(){
	return d;
}

string COne::get_string(){
	return s;
}

void COne::print(){
	cout << d << endl;
	cout << s << endl;
}