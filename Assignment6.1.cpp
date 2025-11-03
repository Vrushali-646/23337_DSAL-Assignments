#include<iostream>
#include<string>
using namespace std;

typedef struct student {
   string user_name;
   string password;
   int next;  
}student;

class MyHash {
 public:
   student SE11[10];
   bool occupied[10];

   MyHash() {
      for(int i=0; i<10; i++) {
         occupied[i] = false;
         SE11[i].next = -1;
      }
   }

   int HashCode(string name) {
      int sum = 0;
      for(int i=0; i<name.size(); i++) {
         sum += (name[i] - 'a');
      }
      return sum % 10;
   }

   void Insert() {
      string name, pass;
      cout<<"Enter Information of Student : "<<endl;
      cout<<"Enter name of student : ";
      cin>>name;
      cout<<"Enter Password of student : ";
      cin>>pass;

      int index = HashCode(name);

      if(!occupied[index]) {
         SE11[index].user_name = name;
         SE11[index].password = pass;
         SE11[index].next = -1;
         occupied[index] = true;
      }
      else {
         int i = (index + 1) % 10;
         while(i != index && occupied[i]) {
            i = (i + 1) % 10;
         }

         if(i == index) {
            cout<<"Hash Table is Full"<<endl;
            return;
         }

         SE11[i].user_name = name;
         SE11[i].password = pass;
         SE11[i].next = -1;
         occupied[i] = true;

         int temp = index;
         while(SE11[temp].next != -1)
            temp = SE11[temp].next;

         SE11[temp].next = i;
      }
   }

   void Search() {
      string name;
      cout<<"Enter name to search : ";
      cin>>name;

      int index = HashCode(name);
      int temp = index;

      while(temp != -1) {
         if(occupied[temp] && SE11[temp].user_name == name) {
            cout<<"\nStudent found at index "<<temp<<endl;
            cout<<"User Name : "<<SE11[temp].user_name<<endl;
            cout<<"Password  : "<<SE11[temp].password<<endl;
            return;
         }
         temp = SE11[temp].next;
      }

      cout<<"\nStudent with name "<<name<<" not found."<<endl;
   }

   void Display() {
      cout<<"\nDisplaying Hash Table Data : "<<endl;
      cout<<"Index    Name    Password    Next"<<endl;
      for(int i=0; i<10; i++) {
         if(occupied[i])
            cout<<i<<"    "<<SE11[i].user_name<<"    "<<SE11[i].password<<"      "<<SE11[i].next<<endl;
         else
            cout<<i<<"    "<<"Empty    ---      -1"<<endl;
      }
   }
};

int main() {
   MyHash DataStructure;
   int choice = 1;

   while(choice) {
      cout<<"\nEnter your choice : "<<endl;
      cout<<"1.Insert\n2.Search\n3.Display\n4.Exit"<<endl;
      int op;
      cin>>op;

      switch(op) {
         case 1:
            DataStructure.Insert();
            break;
         case 2:
            DataStructure.Search();
            break;
         case 3:
            DataStructure.Display();
            break;
         case 4:
            choice = 0;
            break;
         default:
            cout<<"Enter correct choice please"<<endl;
            break;
      }
   }
   return 0;
}
