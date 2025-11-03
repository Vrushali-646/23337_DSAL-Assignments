#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

typedef struct student{
   string user_name;
   string password;
   struct student* next;
}student;

student* getNOde(){
   student* t = new student;
   cout<<"Enter Informationof Student : "<<endl;
   cout<<"Enter name of student : ";
   cin>>t->user_name;
   cout<<"Enter Password of student : ";
   cin>>t->password;
   t->next=NULL;
   return t;
}

class MyHash{
 public:
   student* SE11[10];
   MyHash(){
      for(auto& i : SE11){
         i=NULL;
      }
   }

   int HashCode(string name){
      int sum=0;
      for(int i=0; i<name.size(); i++){
         sum+=(name[i]-'a');
      }
      return sum%10;
   }

   void Chaining(int index, student* t){
      if(SE11[index]==NULL){
         SE11[index]=t;
      }
      else{
         student* p = SE11[index];
         while(p->next!=NULL){
            p=p->next;
         }
         p->next=t;
      }
   }

   void display(){
      cout<<"\nDisplaying Hash Table Data : "<<endl;
      for(int i=0; i<10; i++){
         cout<<"Index "<<i<<" : ";
         if(SE11[i]==NULL){
            cout<<"Empty"<<endl;
         }
         else{
            student* p = SE11[i];
            while(p!=NULL){
               cout<<"[Name: "<<p->user_name<<", Password: "<<p->password<<"] ";
               p=p->next;
               if(p!=NULL) cout<<"-> ";
            }
            cout<<endl;
         }
      }
   }

   void search(string name){
      int index = HashCode(name);
      student* p = SE11[index];
      bool found = false;
      while(p!=NULL){
         if(p->user_name==name){
            cout<<"\nStudent found at index "<<index<<endl;
            cout<<"User Name : "<<p->user_name<<endl;
            cout<<"Password : "<<p->password<<endl;
            found = true;
            break;
         }
         p=p->next;
      }
      if(!found){
         cout<<"\nStudent with name "<<name<<" not found."<<endl;
      }
   }
};

int main(){
   MyHash DataStructure;
   int n,choice2=1;

   cout<<"Enter total number of users you want to store : ";
   cin>>n;

   while(choice2){
      cout<<"\nEnter your choice : "<<endl;
      cout<<"1.Insert\n2.Search\n3.Display\n4.Exit"<<endl;
      int op;
      cin>>op;

      switch(op){
         case 1:{
            for(int i=0; i<n; i++){
               student* t=getNOde();
               int index=DataStructure.HashCode(t->user_name);
               DataStructure.Chaining(index, t);
            }
            break;
         }
         case 2:{
            string name;
            cout<<"Enter name to search : ";
            cin>>name;
            DataStructure.search(name);
            break;
         }
         case 3:{
            DataStructure.display();
            break;
         }
         case 4:{
            choice2=0;
            break;
         }
         default:{
            cout<<"Enter correct choice please"<<endl;
            break;
         }
      }
   }
   return 0;
}
