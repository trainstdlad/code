#include <iostream>
#include <fstream>
using namespace std;

struct link {                          //one element of list
   int data;                          //data item
   link* next;                        //pointer to next link
   };
class linklist{                     //a list of links 
   private:
      link* first;                    //pointer to first link
   public:
      linklist()                      //no-argument constructor
         { first = NULL; }            //no first link
      void additem(int d);            //add data item (one link)
      void display();                 //display all links
      void diskOut();
      void diskIn();
   };
void linklist::additem(int d){         //add data item 
   link* newlink = new link;          //make a new link
   newlink->data = d;                 //give it data
   newlink->next = first;             //it points to next link
   first = newlink;                   //now first points to this
   }
void linklist::display()  {            //display all links  {
   cout << endl;
   link* current = first;             //set ptr to first link
   while( current != NULL ) {          //quit on last link
      cout << current->data << endl;  //print data
      current = current->next;        //move to next link
      }
   cout << endl;   
   }
void linklist::diskOut()
   {
   ofstream outfile;
   int d;
   outfile.open("data.txt", ios::binary | ios::app);
   link* current = first;           
   while( current != NULL )          
      {
      d = current->data;
      outfile.write(reinterpret_cast<char*>(&d), sizeof(int));
      current = current->next;        
      }
   outfile.close();
   }
void linklist::diskIn(){  
   ifstream infile;
   int d;
   infile.open("data.txt", ios::binary );
   infile.seekg(0);
   infile.read((char*)&d,sizeof(int));
   while(infile) {    
      link* newlink = new link;
      newlink->data = d;
      newlink->next = first;    
      first = newlink; 
      infile.read((char*)&d,sizeof(int));    
      }
   }
int main()
 {  
   linklist li;       
   int num;
   char ch;
   char ans;
   while(true){
   cout << "What do you want to do? "
   "\n'a'-add to list"
   "\n's'-show the list"
   "\n'w'-write to file"
   "\n'r'-read file" 
   "\n'x'-exit" << endl; cin >> ans;
    switch(ans) {
      case 'a':  cout << "Enter link in the list: "; cin >> num; li.additem(num); break;      
      case 's':  li.display(); break;
      case 'w':  li.diskOut(); break;
      case 'r':  li.diskIn(); break;
      //case 'x':  exit(break);
      default: cout << "Wrong command.";
      }
   }
   return 0;
 } 
