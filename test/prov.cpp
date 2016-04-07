#include <iostream>
#include <string>

using namespace std;

class COne{
	private:
		double d;
		string s;
	public:
		COne(): d(0), s(""){};
		COne(const double, const string);
		COne(const COne &);
		~COne();
		COne & operator=(const COne &);
		double get_double();
		string get_string();
		void print();
};

class CTwo{
	protected:
		long l;
		COne obj;
	public:
		CTwo(): obj(0, ""), l(0){};
		CTwo(const long, const string, const double);
		CTwo(const CTwo &);
		~CTwo();
		CTwo & operator=(const CTwo &);
		long get_long();
		COne get_cone();
		void forCThree();
		virtual void print();
};

class CThree : public CTwo{
	protected:
		int h;
	public:
		CThree(): h(0){};
		CThree(const long, const string, const double, const int);
		CThree(const CThree &);
		~CThree();
		int get_int();
		void print();
};

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



int main(){
	COne A, B(12, "B1");
	CTwo C(1, "str", 10);
	CThree D(1, "2123", 2, 24);
	D.print();
	return 0;
}
