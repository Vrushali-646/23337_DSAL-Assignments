#include<iostream>
#include<string>
#include<list>
using namespace std;
typedef struct Mnode{//the data that list will contain.
    string data;
    Mnode *next;
}Mnode;
Mnode* getNode(){
     Mnode *t;
     t=new Mnode;
     cout<<"Enter your data"<<endl;
     cin>>t->data;
     t->next=NULL;
     return t;
}
class Mylist{
   Mnode *head;
   string prev={"\0"};
   string sprev[20];
   int i=0, j=0;
   public:
   Mylist(){
     head=NULL;//its important to point head to null when you have not created list yet.
   }

   ~Mylist(){
    while(head!=NULL){
      Mnode* p=head->next;
      free(head);
      head=p;
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

   void deleteN(){
     Mnode *temp=head;
      if(head==NULL){
        cout<<"Your list is empty"<<endl;
      }
      else{
        Mnode *p=head;
          prev=head->data;
          sprev[i++]=prev;
          head=p->next;
          delete p;
        }
   }

   void display_top(){
     if(head==NULL){
        cout<<"Your list is emty"<<endl;
     }
     else{
        cout<<"Your top element is: ";
        cout<<head->data<<endl;
     }
   }

   void undo(){
    if(i==0){
      cout<<"All actions are recovered"<<endl;
      cout<<"no more undo can be done"<<endl;
      return;
    }
    j++;
    Mnode* temp;
     temp=new Mnode;
     temp->data=sprev[i-1];
     i--;
     temp->next=head;
     head=temp;
   }

   void redo(){
    if(j==0) {
      cout<<"no more redo can be done"<<endl;
      return;
    }
      j--;
      deleteN();
   }

   void display_Complete(){
     Mnode *p;
     p=head;//we create dummy pointer because we cant loose our head if we loose our head we will loose our complete list.
     while(p!=NULL){//if you take condition as p->next!=0 it will not print last number or data you stored.
        cout<<p->data<<" "<<endl;;
        p=p->next;
     }
   }
};
int main(){
    Mylist s;
    Mnode* t=NULL;
    while(true){
        int choice;
        cout<<"1.Insert\n2.Delete\n3.Display_top\n4.undo\n5.redo\n6.display_complete_stack\n7.quit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
    switch (choice)
    {
    case 1:
        s.insertB();
        break;
    case 2:
        s.deleteN();
        s.display_top();
        break;
    case 3:
         s.display_top();
        break;
    case 4:
         s.undo();
         s.display_top();
        break;
    case 5:
         s.redo();
         s.display_top();
        break;
    case 6:
         s.display_Complete();
        break;
    case 7:
        cout<<"Program is ending....."<<endl;
         return 0;
    default:
        cout<<"Enter a correct choice"<<endl;
        break;
    }
    }
    return 0;
}