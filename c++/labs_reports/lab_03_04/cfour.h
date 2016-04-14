#ifndef CFOUR_H_
#define CFOUR_H_
#include "cone.h"
#include "ctwo.h"
#include "cthree.h"
#include <iostream>
#include <string>
using namespace std;
class CFour: public CThree{
	private:
		double d2;
	public:
		CFour(): d2(0.){};
		CFour(const long, const string, const double, const int, const double);
		CFour(const CFour &);
		~CFour();
		int get_double();
		virtual void print();
};
#endif /* CFOUR_H_ */
