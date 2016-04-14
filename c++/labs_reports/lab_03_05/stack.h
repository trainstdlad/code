#ifndef STACK_H_
#define STACK_H_
#include <iostream>
using namespace std;

template <typename T>
struct element{
        T data;
        element * next;
};

template <typename T>
class stack{
private:
        struct element<T> * top;
public:
        stack();
        ~stack();
        void push(T);
        T pop();
        void print_stack();
};

#include "stack.tpp"
#endif /* STACK_H_ */
