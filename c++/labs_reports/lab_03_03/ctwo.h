#ifndef CTWO_H_
#define CTWO_H_
#include "cone.h"
#include <iostream>
#include <string>
using namespace std;

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
		void print();
};

#endif /* CTWO_H_ */