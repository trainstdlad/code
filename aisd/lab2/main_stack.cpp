#include "stack.h"

void swap(stack<int>& A, stack<int>& B){
        int temp1 = A.pop();
        int temp2 = B.pop();
        A.push(temp2);
        B.push(temp1);
}

int main(){
        stack<int> A;
        stack<int> B;
        for(int i = 0; i < 5; i++){
                A.push(i);
        }

        for(int i = 4; i >= 0; i--){
                B.push(i);
        }
        cout << "Stack A " << endl;
        A.print_stack();
        cout << "Stack B" << endl;
        B.print_stack();
        swap(A, B);
        cout << endl;
        cout << "Stack swap A and B" << endl;
        A.print_stack();
        cout << endl;
        B.print_stack();
        return 0;
}
