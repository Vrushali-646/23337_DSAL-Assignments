#include<iostream>
#include<string>
using namespace std;
typedef struct Mnode{
  string data;
  struct Mnode* next;
}Mnode;
Mnode* getNode(){
   Mnode* t=new(Mnode);
   cout<<"Enter your data: ";
   cin>>t->data;
   t->next=NULL;
   return t;
}
class MyQueue{
  public:
  Mnode* front;
  Mnode* rear;
  MyQueue(){
    front=NULL;
    rear=NULL;
  } 
  ~MyQueue(){
    while(front!=NULL){
        Mnode* p=front->next;
        delete front;
        front=p;
    }
  } 
  void EnQueue(){
    Mnode* temp=getNode();
    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
    rear->next=temp;
    rear=temp;
    }
  }
  void DeQueue(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
    Mnode* temp=front;
    front=front->next;
    if(front==NULL)   rear=NULL;
    delete temp;
    }
  }
  void Peep(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Front element is: "<<front->data<<endl;
  }
  void Display_Queue(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
     Mnode* temp=front;
     while(temp!=NULL){
       cout<<temp->data<<"  ";
       temp=temp->next;
     }
     cout<<endl;
  }
};
int main(){
    MyQueue q;
    int choice;
    while(true){
    cout<<"1.Enqueue(insert_element)\n2.DeQueue(delete_element)\n3.Peep(Display_front)\n4.Display_Queue\n5.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
         q.EnQueue();
         break;
        case 2:
         q.DeQueue();
         q.Peep();
         break;
        case 3:
         q.Peep();
         break;
        case 4:
         q.Display_Queue();
         break;
        case 5:
          cout<<"Program is Ending"<<endl;
          return 0;
        default: 
           cout<<"Enter correct choice please"<<endl;
           break;
    }
}
    return 0;
}