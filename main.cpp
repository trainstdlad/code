#include <iostream>

using namespace std;

class human{
	private:
		int size_arm, size_leg;
	public:
		human();
		human(int, int);
		~human();
		int s_a();
		int s_l();
		void print();
};

human::human(){
	size_leg = 0;
	size_arm = 0;
}

human::human(int size_leg_t, int size_arm_t){
	size_arm = size_arm_t;
	size_leg = size_leg_t;
}

human::~human(){
}

int human::s_a(){
	return size_arm;
}

int human::s_l(){
	return size_leg;
}

void human::print(){
	cout << size_leg << endl;
	cout << size_arm << endl;
}

int main(){
	human Renat(10, 20);
	Renat.print();
	return 0;
}