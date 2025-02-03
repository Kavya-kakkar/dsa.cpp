#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<char>vec={'a','b','c','d','e'};

    cout<<"size="<<vec.size()<<endl;

    cout<<vec.at(1)<<endl;
    for (char i:vec){
        cout<<i<<endl;
    }
   
    return 0;

}