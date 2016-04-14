#ifndef CONE_H_
#define CONE_H_
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

#endif /* CONE_H_ */