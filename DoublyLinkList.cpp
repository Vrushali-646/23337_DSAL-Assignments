#include<iostream>
using namespace std;
class Mnode{//the data that list will contain.
    public:
    long long int Number;
    string name;
    string add;
    Mnode *next;
     Mnode *prev;
};
Mnode* getNode(){
     Mnode *t;
     t=new Mnode;
     cout<<"Enter your data"<<endl;
     cout<<"Enter your number"<<endl;
     cin>>t->Number;
     long long int tempNum = t->Number;
     int countDigits = 0;
     while(tempNum > 0){
      tempNum /= 10;
      countDigits++;
     }
     if(countDigits != 10){
    cout<<"Please enter a correct number"<<endl;
    delete t;
    return getNode();
    }

     cout<<"Enter your name"<<endl;
     cin>>t->name;
     cout<<"Enter your add"<<endl;
     cin>>t->add;
     int atPos = -1, dotPos = -1;
     for(int i = 0; i < t->add.length(); i++){
          if(t->add[i] == '@' && atPos == -1){ // we will chek for only for first @ thats why we added that condition after &&
            atPos = i;
          }
          else if(t->add[i] == '.'){ // we are cheking last '.' thats why no any extra condition requried
            dotPos = i;
          }
      }
      if(atPos == -1 || dotPos == -1 || dotPos < atPos || atPos == 0 || dotPos == t->add.length()-1){
          cout<<"Wrong Email \nPlease Enter correct email address"<<endl;
          delete t;
          return getNode();
       }
     t->next=NULL;
     t->prev=NULL;
     return t;
}
class Mylist{
   Mnode *head;
   public:
   Mylist(){
     head=NULL;//its important to point head to null when you have not created list yet.
   }
   void create(){
        int choice;
        cout<<"Enter a nodes you want in your list"<<endl;
        cin>>choice;
        for(int i=0; i<choice; i++){
          Mnode *t, *p=head;
          t=getNode();
          if(head==NULL){//from this line we are attaching list to our created pointer or memory block 't'.
             head=t;
            }
     else{
        while(p->next!=NULL){
            p=p->next;
        }
           p->next=t;
           t->prev=p;
          }
        }
   }
   void insertE(){
     Mnode *t, *p=head;//creating a random memory block 't'.
     t=getNode();
     if(head==NULL){//from this line we are attaching list to our created pointer or memory block 't'.
        head=t;
     }
     else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=t;
        t->prev=p;
     }
   }
    void insertB(){
    Mnode *t;
    t=getNode();
     if(head==NULL){
      head=t;
     }
     else{
      t->next=head;
      head=t;
     }
   }
   void insertBe(){
    Mnode *t, *p=head;
    string name;
    cout<<"Enter name after which you want to add this details"<<endl;
    cin>>name;
    t=getNode();
    while(p->name!=name){
      p=p->next;
    }
    t->next=p->next;
    (p->next)->prev=t;
    t->prev=p;
    p->next=t;
   }
   void deleteN(){
      if(head==NULL){
        cout<<"Your list is empty"<<endl;
      }
      else{
        string name;
        cout<<"Enter a name whose details you want to delete"<<endl;
        cin>>name;
        Mnode *t=NULL,*p=head;
        if(p->name==name){
          head=p->next;
          head->prev=NULL;
          delete p;
        }
        else{
        while(p->name!=name){
          t=p;
          p=p->next;
        }
        t->next=p->next;
        if(p->next!=NULL)   (p->next)->prev=t;
        delete p;
      }
    }
   }
   void display(){
     Mnode *p;
     p=head;//we create dummy pointer because we cant loose our head if we loose our head we will loose our complete list.
     while(p!=NULL){//if you take condition as p->next!=0 it will not print last number or data you stored.
        cout<<p->Number<<" "<<p->name<<" "<<p->add<<endl;
        p=p->next;
     }
   }
};
int main(){
    Mylist s;
    cout<<"Create your list first"<<endl;
    s.create();
    s.display();
    while(true){
        int choice;
        cout<<"Enter your choice"<<endl;
        cout<<"1.Insert_End\n2.Insert_beginning\n3.Insert_between\n4.Delete\n5.Display\n6.quit"<<endl;
        cin>>choice;
    switch (choice)
    {
    case 1:
        s.insertE();
        break;
    case 2:
        s.insertB();
        break;
    case 3:
        s.insertBe();
        break;
    case 4:
        s.deleteN();
        break;
    case 5:
         s.display();
        break;
    case 6:
        cout<<"Program is ending....."<<endl;
         return 0;
    default:
        cout<<"Enter a correct choice"<<endl;
        break;
    }
    }
    return 0;
}