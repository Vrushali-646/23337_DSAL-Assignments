#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//assume the queue is max-priority queue (higher value == higher priority)

struct Element{
    string news;
    int priority;
};

class MyQueue{
public:
  Element arr[20];
  int front;
  int rear;

  MyQueue(){
    front=-1;
    rear=-1;
  }

  void Insert(){
    if(!isFull()){
    Element NewElement;
    cout<<"Enter the news please : ";
    cin>>NewElement.news;
    cout<<"Enter the priority of news please : ";
    cin>>NewElement.priority;

    if(isEmpty()){
        front = rear = 0;
        arr[front] = NewElement;

    }
    else{
        int i=front;
        while(i<=rear && arr[i].priority>=NewElement.priority){
           i++;
        }
        if(i==rear+1){
            arr[++rear]=NewElement;
        }
        else{ 
            int temp=i;
            i=rear+1;
            while(i>temp){
               arr[i]=arr[i-1];
               i--;
            }
            arr[temp]=NewElement;
            rear++;
      }
    }
   }
   else  cout<<"Queue is FULL"<<endl;
  }

  void peek(){
    if(front==-1){
      cout<<"Queue is empty"<<endl;
    }
    else{
      cout<<"Highest priority news of Queue : "<<arr[front].news<<endl;
    }
  }

  void extract_max(){
    string Max;
    int i=front;
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
    }
    else{
      Max=arr[front].news;
      cout<<"Exacted max priority news : "<<Max<<endl;
      while(i<rear){
        arr[i]=arr[i+1];
        i++;
      }
      rear--;
      if (rear < front) { // queue became empty
            front = rear = -1;
        }
    }
  }

  bool isEmpty(){
    if(front==-1)   return true;
    else  return false;
  }

  bool isFull(){
    if(rear==19)   return true;
    else return false;
  }

  void display(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
    }
    else{
      for(int i=front; i<=rear; i++){
        cout<<arr[i].news<<"  priority : "<<arr[i].priority<<endl;
      }
    }
  }

};

int main(){
 MyQueue Q;
 int choice;
 while(true){
  cout<<"1.INSERT\n2.PEEK\n3.EXTRACT MAX\n4.DISPLAY\n5.EXIT"<<endl;
  cout<<"Enter your choice please : ";
  cin>>choice;
  switch(choice){
  case 1: 
     Q.Insert();
     break;
  case 2:
     Q.peek();
     break;
  case 3:
     Q.extract_max();
     break;
  case 4:
     Q.display();
     break;
  case 5:
     return 0;
  default :
     cout<<"Enter correct choice please "<<endl;
     break;
  } 
}
return 0;
}