//#include<bits/stdc++.h>  dont use it as it includes all header files which harms efficiency and speed of program.
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int Priority(char c){
    if(c=='^')   return 3;
    else if(c=='*'||c=='/'||c=='%')  return 2;
    else if(c=='+'||c=='-')  return 1;
    else return -1;
}

string InfixToPostfix(string infix){
    string ans;
    stack<char>st;
    for(int i=0; i<infix.length(); i++){

       if((infix[i]>='A' && infix[i]<='Z') ||
          (infix[i]>='a'&& infix[i]<='z')){
            ans+=infix[i];
          }

       else if(infix[i]=='('){
         st.push(infix[i]);
       }

       else if(infix[i]==')'){
         while(!st.empty() && st.top()!='('){
            ans+=st.top();
            st.pop();
         }
         st.pop();
       }

      else{
        if( st.empty() || Priority(infix[i])>Priority(st.top()) ){
            st.push(infix[i]);
        }
        else{
           if(infix[i]=='^'){
              while(!st.empty() && Priority(st.top())>Priority(infix[i])){
                ans+=st.top();
                st.pop();
            }
           }
           else{
            while(!st.empty() && Priority(st.top())>=Priority(infix[i])){
                ans+=st.top();
                st.pop();
            }
          }
            st.push(infix[i]);
        }
      }

    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    
    return ans;
}


double PostfixEvaluation(string postfix){
   double val;
    stack<double>st;
    for(int i=0; i<postfix.length(); i++){

       if((postfix[i]>='A' && postfix[i]<='Z') ||
          (postfix[i]>='a'&& postfix[i]<='z')){
             cout<<"Enter the value of : "<<postfix[i]<<endl;
             cin>>val;
             st.push(val);
          }
       else{
        double val2= st.top();
         st.pop();
        double val1= st.top();
        st.pop();
        switch (postfix[i])
        {
        case '*':
          st.push(val1*val2);
          break;
        case '/':
          if(val2==0){
            cout<<"Error can not divide by 0\nProgram is ending"<<endl;
            return INT8_MIN;
          }
          st.push(val1/val2);
          break;
        case '+':
          st.push(val1+val2);
          break;
        case '-':
          st.push(val1-val2);
          break;
        case '^':
          st.push(pow(val1,val2));
          break;
        default:
          cout<<"Wrong operator\nProgram is terminating"<<endl;
          return INT8_MIN;
        }
      }

  }
  return st.top();
}

string InfixToPrefix(string infix){
  string prefix="";
  reverse(infix.begin(),infix.end());
  for(int i=0; i<infix.length(); i++){
    if(infix[i]=='(')  infix[i]=')';
    else if(infix[i]==')')  infix[i]='(';
  }
  prefix=InfixToPostfix(infix);
  reverse(prefix.begin(),prefix.end()); 
  return prefix;
}


double PrefixEvaluation(string prefix){
   double val;
   stack<double>st;
  for(int i=prefix.length()-1; i>=0; i--){
      if((prefix[i]>='A' && prefix[i]<='Z') ||
          (prefix[i]>='a'&& prefix[i]<='z')){
             cout<<"Enter the value of : "<<prefix[i]<<endl;
             cin>>val;
             st.push(val);
          }
       else{
        double val1= st.top();
         st.pop();
        double val2= st.top();
        st.pop();
        switch (prefix[i])
        {
        case '*':
          st.push(val1*val2);
          break;
        case '/':
          if(val2==0){
            cout<<"Error can not divide by 0\nProgram is ending"<<endl;
            return INT8_MIN;
            }
          st.push(val1/val2);
          break;
        case '+':
          st.push(val1+val2);
          break;
        case '-':
          st.push(val1-val2);
          break;
        case '^':
          st.push(pow(val1,val2));
          break;
        default:
          cout<<"Wrong operator\nProgram is terminating"<<endl;
          return INT8_MIN;
        }
      }

  }
  return st.top();
}


int main(){
    string postfix,prefix;
    double ansPostfix,ansPrefix;

    string infix;
    cout<<"Enter your infix expression : ";
    cin>>infix;

    while(true){

    int choice;
    cout<<"1.INFIX to POSTFIX\n2.INFIX to PREFIX\n3.POSTFIX EVALUATION\n4.PREFIX EVALUATION\n5.EXIT"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice){
     case 1: postfix = InfixToPostfix(infix);
             cout<<"Postfix expression : "<<postfix<<endl;
              break;
     case 2: prefix = InfixToPrefix(infix);
             cout<<"Prefix expression : "<<prefix<<endl;
             break;

     case 3: ansPostfix=PostfixEvaluation(InfixToPostfix(infix));
             if(ansPostfix==INT8_MIN)   return 0;
             else   cout<<"ans : "<<ansPostfix<<endl;
             break;

     case 4: ansPrefix=PrefixEvaluation(InfixToPrefix(infix));
             if(ansPrefix==INT8_MIN)   return 0;
             else   cout<<"ans : "<<ansPrefix<<endl;
             break;

    case 5:  cout<<"program is terminating"<<endl;
             return 0;

     default: cout<<"Enter correct choice please"<<endl;
             break;
      }

    }
    
    return 0;
}
