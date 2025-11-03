#include <iostream>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;
 struct student{ //we have to work on array of object
    string name;
    int roll_no;
    float cgpa;
};

 student getNode(){
    student s;
    cout<<"Enter the information of student : "<<endl;
    cout<<"Enter name : ";
    cin>>s.name;
    cout<<"Enter roll number : ";
    cin>>s.roll_no;
    cout<<"Enter GPA : ";
    cin>>s.cgpa;
    return s;
 }

 void createFile(){
    ofstream outfile("StudentData.txt");
    if(outfile.is_open()){  //always we call functions of class by using objects only
       int n;
       cout<<"Enter number of records you want : ";
       cin>>n;
       for(int i=0; i<n; i++){
        student s = getNode();
        outfile<<s.name<<"  "<<s.roll_no<<"  "<<s.cgpa<<endl;
       }
    }
    outfile.close();
 }

 void DisplayFile(){
   ifstream infile("StudentData.txt");
   if(!infile.is_open()){
     cout<<"File does not exist or not able to open"<<endl;
     return;
   }
   string s;
   while(getline(infile,s)){
     cout<<s<<endl;
   }
   infile.close();
 }

 void AddNewRecords(){
   ofstream outfile("StudentData.txt",ios::app);
   student s = getNode();
   outfile<<s.name<<"  "<<s.roll_no<<"  "<<s.cgpa<<endl;
   outfile.close();
 }

 void SearchRecord(int key){
   ifstream infile("StudentData.txt");
   if(!infile.is_open()){
     cout<<"File does not exist or not able to open"<<endl;
     return;
   }
    string name;
    int roll_no;
    float cgpa;
    bool found=false;
    while(infile>>name>>roll_no>>cgpa){
     if(roll_no==key){
       cout<<"Record Found"<<endl;
       cout<<name<<"  "<<roll_no<<"  "<<cgpa<<endl;
       found=true;
       break;
     } 
   }
   if(!found){
    cout<<"Record not found in file"<<endl;
    infile.close();
   }
   else infile.close();
 }

 void ModifyRecord(int key){
   ifstream infile("StudentData.txt");
   if(!infile.is_open()){
     cout<<"File does not exist or not able to open"<<endl;
     return;
   }
   ofstream outfile("Temporary.txt");
    string name;
    int roll_no;
    float cgpa;
    bool found=false;
    while(infile>>name>>roll_no>>cgpa){
     if(roll_no==key){
       cout<<"Record Found"<<endl;
       cout<<name<<"  "<<roll_no<<"  "<<cgpa<<endl;
       cout<<"Please enter new information : "<<endl;
       found=true;
       student s = getNode();
       outfile<<s.name<<"  "<<s.roll_no<<"  "<<s.cgpa<<endl;
     } 
     else{
        outfile<<name<<"  "<<roll_no<<"  "<<cgpa<<endl;
     }
   }
   if(!found)  cout<<"Record not found"<<endl;
   outfile.close();
   infile.close();
   remove("StudentData.txt");
   rename("Temporary.txt","StudentData.txt");
 }

 void DeleteRecord(int key){
   ifstream infile("StudentData.txt");
   if(!infile.is_open()){
     cout<<"File does not exist or not able to open"<<endl;
     return;
   }
    ofstream outfile("Temporary.txt");
    string name;
    int roll_no;
    float cgpa;
    bool found=false;
    while(infile>>name>>roll_no>>cgpa){
     if(roll_no==key){
       cout<<"Record Found"<<endl;
       cout<<name<<"  "<<roll_no<<"  "<<cgpa<<endl;
       found=true;
     } 
     else{
        outfile<<name<<"  "<<roll_no<<"  "<<cgpa<<endl;
     }
   }
   if(!found)  cout<<"Record not found"<<endl;
   outfile.close();
   infile.close();
   remove("StudentData.txt");
   rename("Temporary.txt","StudentData.txt");
 }

int main(){
    int choice,key;
    while(true){
     cout<<"1.create file\n2.display file\n3.add new record\n4.search record\n5.modify record\n6.delete record\n7.exit"<<endl;
     cout<<"Enter your choice : ";
     cin>>choice;
     switch (choice)
     {
     case 1:
        createFile();
        break;
     case 2:
        DisplayFile();
        break;
     case 3:
        AddNewRecords();
        break;
     case 4:
        cout<<"Enter roll number for search record : ";
        cin>>key;
        SearchRecord(key);
        break;
     case 5:
        cout<<"Enter roll number for modify record : ";
        cin>>key;
        ModifyRecord(key);
        break;
     case 6:
        cout<<"Enter roll number for delete record : ";
        cin>>key;
        DeleteRecord(key);
        break;
     case 7:
        cout<<"Terminating Program...."<<endl;
        return 0;
     default:
        cout<<"Enter correct choice please"<<endl;
        break;
     }
    }

    return 0;
}
