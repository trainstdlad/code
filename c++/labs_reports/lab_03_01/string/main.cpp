#include "string.h"
#include <iostream>
int main(){
        String str1("hey"), str2("lol"), str3;
        cout << "str1 is \"";
        str1.print();
        cout << "\"" << endl;

        cout << "str2 is \"";
        str2.print();
        cout << "\"" << endl;

        str2.Remove(2,1);

        cout << "str2 after Remove(2,1) is \"";
        str2.print();
        cout << "\"" << endl;

        str2.Substr(1,2);

        cout << "str2 after Substr(1,2) is \"";
        str2.print();
        cout << "\"" << endl;

        str2.Insert("XX", 1);

        cout << "str2 after Insert(\"XX\",1) is \"";
        str2.print();
        cout << "\"" << endl;

        cout << "Insert str3:";
        str3.read();

        cout << "str3 is \"";
        str3.print();
        cout << "\"" << endl;

        str3.trim();

        cout << "str3 after trim() is \"";
        str3.print();
        cout << "\"" << endl;

        return 0;
 }