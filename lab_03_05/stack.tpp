template <typename T>
stack<T>::stack(){
        top = NULL;
}

template <typename T>
stack<T>::~stack(){
        struct element<T> * old;
        while(top != NULL){
                old = top;
                top = top -> next;
                delete old;
        }
        top = NULL;
}

template <typename T>
void stack<T>::push(T new_data){
        struct element<T> * new_element;
        new_element = new struct element<T>;
        new_element -> next = top;
        new_element -> data = new_data;
        top = new_element;
}

template <typename T>
T stack<T>::pop(){
        if(top == NULL)
                throw "Stack is empty";
        T tmp = top -> data;
        struct element<T> * p_element;
        p_element = top;
        top = top -> next;
        delete p_element;
        return tmp;
}

template <typename T>
void stack<T>::print_stack(){
        unsigned int i = 0;
        struct element<T> * p_element;
        p_element = top;
        while(p_element != NULL){
                cout << "[" << i << "] " << p_element -> data << endl;
                i++;
                p_element = p_element -> next;
        }
}
