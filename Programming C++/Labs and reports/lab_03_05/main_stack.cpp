#include "stack.h"

int main(){
        stack<int> A;
	const char * msg;
        A.print_stack();
        A.push(1);
        A.push(2);
        A.push(3);
        A.print_stack();
        cout << A.pop() << endl;
        cout << A.pop() << endl;
        cout << A.pop() << endl;
	try{
		cout << A.pop() << endl;
	} catch (const char* msg) {
		cout << msg << endl;
	}
        A.print_stack();
        A.push(4);
        cout << A.pop() << endl;
        return 0;
}
