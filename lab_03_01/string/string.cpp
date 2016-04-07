#include "string.h"

String::String(){
        length = 0;
        data = new char[1];
        data[length] = '\0';
}

String::String(const char * str){
        length = strlen(str);
        data = new char[length + 1];
        for(unsigned int i = 0; i < length; i++)
                data[i] = str[i];
        data[length] = '\0';
}

String::~String(){
        delete [] data;
}

unsigned int String::Length(){
        return length;
}

void String::Copy(const String & str){
        length = str.length;
        delete [] data;
        data = new char[length + 1];
        for(unsigned int i = 0; i < length; i++)
                data[i] = str.data[i];
        data[length] = '\0';
}

void String::Copy(const char * str){
        length = strlen(str);
        delete [] data;
        data = new char[length + 1];
        for(unsigned int i = 0; i < length; i++)
                data[i] = str[i];
        data[length] = '\0';
}

String String::Substr(unsigned int i, unsigned int n){
        char * new_data = new char[n + 1];
        strncpy(new_data, data + i, n);
        new_data[n] = '\0';
        String result(new_data);
        return result;
}

void String::Remove(unsigned int i, unsigned int n){
        length -= n;
        char * new_data = new char[length + 1];
        new_data[0] = '\0';
        strncat(new_data, data, i);
        new_data[i] = '\0';
        strcat(new_data, data + i + n);
        new_data[length] = '\0';
        delete [] data;
        data = new_data;
}

void String::Insert(const char * str, unsigned int i){
        length += strlen(str);
        char * new_data = new char[length + 1];
        new_data[0] = '\0';
        strncat(new_data, data, i);
        new_data[i] = '\0';
        strcat(new_data, str);
        new_data[i + strlen(str)] = '\0';
        strcat(new_data, data + i);
        new_data[length] = '\0';
        delete [] data;
        data = new_data;
}

void String::trim(){
        unsigned int x = 0, y = length - 1;
        while(data[x] == ' ')
                x++;
        while(data[y] == ' ')
                y--;
        if(x == 0 && y == length - 1)
                return;
        length = y - x + 1;
        char * new_data = new char[length];
        strncpy(new_data, data + x, length);
        new_data[length] = '\0';
        delete [] data;
        data = new_data;
}

void String::read(){
        char input_data[255];
        std::cin.getline(input_data, 255, '\n');
        length = strlen(input_data);
        delete [] data;
        data = new char[length + 1];
        strcpy(data, input_data);
        data[length] = '\0';
}

void String::print(){
        std::cout << data;
}

