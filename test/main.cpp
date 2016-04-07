#include <iostream>

using namespace std;
template <typename T>
class human{
	private:
		T *size_arm, *size_leg;
	public:
		human(T*, T*);
		~human();
		T s_a();
		T s_l();
		void print();
		void ace();
};

template <typename T>
human<T>::human(T* size_leg_t, T* size_arm_t){
	size_arm = size_arm_t;
	size_leg = size_leg_t;
}

template <typename T>
human<T>::~human(){
}

template <typename T>
T human<T>::s_a(){
	return size_arm;
}

template <typename T>
T human<T>::s_l(){
	return size_leg;
}

template <typename T>
void human<T>::print(){
	cout << size_leg << endl;
	cout << size_arm << endl;
}

template <typename T>
void human<T>::ace(){
	cout << "Hey!";
}
int main(){
	human<char> Renat("kek", "lol");
	Renat.print();
	Renat.ace();
	return 0;
}