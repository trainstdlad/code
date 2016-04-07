#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
template<typename T>
class Vector{
public:
    typedef T* iterator;
    Vector();
    Vector(int capacity);
    Vector(const Vector<T>& orig);
    const T& operator[](int index)const{return ptr_[index];}
    T& operator[](int index){return ptr_[index];}
    Vector<T>& operator=(const Vector<T>& orig);
    ~Vector();
    iterator begin(){return ptr_;}
    iterator end(){return ptr_+size_;}
    int capacity(){return capacity_;}
    int size(){return size_;}
    void push_back(T elem);
    T pop_back();
    void insert(int index, T elem);
    void remove(int index);
    void clear();
    friend ostream& operator<<(ostream& os,const Vector<T>& rhs){
        cout << endl;
        for(int i=0;i<rhs.size_;i++)
            cout<<rhs.ptr_[i]<<"";
        cout << endl;
        return os;
    }
private:
    int size_;
    int capacity_;
    T* ptr_;
    iterator it_;
};

template <typename T>
Vector<T>::Vector(){
    capacity_=10;
    size_=0;
    ptr_=new T[capacity_];
}
template <typename T>
Vector<T>::Vector(int capacity):capacity_(capacity){
    size_=0;
    ptr_=new T[capacity_];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& orig):size_(orig.size_),capacity_(orig.capacity_){
    ptr_=new T[capacity_];
    for (int i=0; i<capacity_;i++)
        ptr_[i]=orig[i];
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& orig){
    if(this!= &orig){
        if(capacity_!=orig.capacity_){
            delete[]ptr_;
            capacity_=orig.capacity_;
            ptr_=new T[capacity_];
        }
        for(int i=0;i<capacity_;i++)
            ptr_[i]=orig[i];
        size_=orig.size_;
    }
    return *this;
}
template <typename T>
Vector<T>::~Vector(){
    delete []ptr_;
}

template <typename T>
void Vector<T>::push_back(T elem){
   if(capacity_>size_+1){
       ptr_[size_]=elem;
       size_++;
   }
   else{
       int tmp_capacity=capacity_*2;
       T*tmp_ptr=new T[tmp_capacity];
       for(int i=0; i<capacity_;i++)
           tmp_ptr[i]=ptr_[i];
       tmp_ptr[size_]=elem;
       size_++;
       delete[]ptr_;
       capacity_=tmp_capacity;
       ptr_=tmp_ptr;
   }
}

template <typename T>
T Vector<T>::pop_back(){
    T tmp;
    if (size_>0){
        tmp=ptr_[size_-1];
        size_--;
    }
    return tmp;
}

template <typename T>
void Vector<T>::insert(int index, T elem){
    T* tmp_ptr;
    int tmp_capacity;
    if (capacity_>size_+1)
        tmp_capacity=capacity_;
    if (capacity_==size_+1)
        tmp_capacity=capacity_*2;
    tmp_ptr=new T[tmp_capacity];
    for(int i=0;i<index;i++)
        tmp_ptr[i]=ptr_[i];
    tmp_ptr[index]=elem;
    size_++;
    for (int i=index+1;i<capacity_;i++)
        tmp_ptr[i]=ptr_[i-1];
    delete []ptr_;
    ptr_=tmp_ptr;
    capacity_=tmp_capacity;
}

template <typename T>
void Vector<T>::remove(int index){
   for(int i=index;i<size_;i++)
       ptr_[i]=ptr_[i+1];
   size_--;
}

template <typename T>
void Vector<T>::clear(){
       for( int i=size_;i!=0;i--)
           size_--;
}
#endif // VECTOR_H

