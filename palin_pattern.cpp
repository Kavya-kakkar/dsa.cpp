#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int j;
        for(int j=1;j<=n-1;j++){
            cout<<"  ";
        }
        int k=i;
        for(;j<=n;j++){
            cout<<k--<<" ";

        }
        k=2;
        for(;j<=n+i-1;j++){
            cout<<k++<<" ";
        }
        cout<<endl;
        
    }
}
