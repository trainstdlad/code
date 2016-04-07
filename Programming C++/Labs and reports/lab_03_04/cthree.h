#ifndef CTHREE_H_
#define CTHREE_H_
#include "cone.h"
#include "ctwo.h"
#include <iostream>
#include <string>
using namespace std;

class CThree : public CTwo{
	protected:
		int h;
	public:
		CThree(): h(0){};
		CThree(const long, const string, const double, const int);
		CThree(const CThree &);
		~CThree();
		int get_int();
		virtual void print();
};
#endif /* CTHREE_H_ */
