#include<iostream>
using namespace  std;

class student{
    int roll_no ;
    char name[15];

    public:
    void getdata()
    {
        cout<<"enter name";
        cin>>name;
        cout<<"enter roll_no";
        cin>>roll_no ;
    }
    void display()
    {
        cout<<"name"<<name<<endl;
        cout<<"roll_no"<<roll_no<<endl;
    }
};
const int size = 5;
int main() {
    int i;
    student*p=new student[size];
    student*q=p;
    for(int i=0;i<size;i++) {
        cout<<"record"<<i+1<<endl;
        q->getdata();
        q++;

    }
    cout<<"list of items we have :";
    for(i=0;i<size;i++) {
        cout<<"record"<<i+1<<endl;
        q->display();
        q++;

    }
    return 0;


};
