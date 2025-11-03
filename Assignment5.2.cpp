#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//assume that queue is double ended queue
class MyQueue{
 public:
    int arr[10];
    int front;
    int rear;
    MyQueue(){
      front=-1;
      rear=-1;
    }

    bool isFull(){
      if((front==0 && rear==9) || (front==rear+1))  return true;
      else return false;
    }

    bool isEmpty(){
      if(front==-1)  return true;
      else return false;
    }

    void InsertFront(int x){
      if(isFull())  cout<<"Queue is overflow"<<endl;
      else if(isEmpty()){
        front=rear=0;
      }
      else if(front==0){
        front=9;
      }
      else front=front-1;
      arr[front]=x;
    }

    void InsertRear(int x){
       if(isFull())  cout<<"Queue is overflow"<<endl;
       else if(isEmpty()){
        front=rear=0;
       }
       else if(rear==9)  rear=0;
       else rear=rear+1;
       arr[rear]=x;
    }

    int DeleteFront(){
       if(isEmpty()){
         cout<<"Queue is underflow"<<endl;
         return -1;
       }
       int val = arr[front];
       if(front==rear){
         front=rear=-1;
       }
       else if(front==9){
         front=0;
       }
       else front=front+1;
       return val;
    }

    int DeleteRear(){
       if(isEmpty()){
         cout<<"Queue is underflow"<<endl;
         return -1;
       }
       int val = arr[rear];
       if(front==rear){
         front=rear=-1;
       }
       else if(rear==0){
         rear=9;
       }
       else rear=rear-1;
       return val;
    }

    int getFront(){
       if(isEmpty()){
         cout<<"Queue is underflow"<<endl;
         return -1;
       }
       else return arr[front];
    }

    int getRear(){
       if(isEmpty()){
         cout<<"Queue is underflow"<<endl;
         return -1;
       }
       else return arr[rear];
    }
};

int main(){
  MyQueue Q;
  int choice;
  while(true){
  cout<<"1.Insert at front\n2.Insert at end\n3.Delete from front\n4.Delete from end\n5.Get value at front\n6.Get value at end\n7.Exit"<<endl;
  cout<<"Enter your choice : ";
  cin>>choice;
  int x;
  switch (choice)
  {
  case 1:
    cout<<"Enter the value to insert : ";
    cin>>x;
    Q.InsertFront(x);
    break;
  case 2:
    cout<<"Enter the value to insert : ";
    cin>>x;
    Q.InsertRear(x);
    break;
  case 3:
    cout<<"Deleted Element : "<<Q.DeleteFront()<<endl;
    break;
  case 4:
    cout<<"Deleted Element : "<<Q.DeleteRear()<<endl;
    break;
  case 5:
    cout<<"Element at Front : "<<Q.getFront()<<endl;
    break;
  case 6:
    cout<<"Element at End : "<<Q.getRear()<<endl;
    break;
  case 7:
    cout<<"Program is terminating ..."<<endl;
    return 0;
    break; 
  default:
    cout<<"Please Enter a Correct Choice"<<endl;
    break;
  }
}
return 0;
}
