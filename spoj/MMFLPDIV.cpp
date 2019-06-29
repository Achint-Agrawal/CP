#include <iostream>
using namespace std;

int main(){
    int n;
    int size=100000000;
    int arr[size]={};
    for(int i=0;i<size;i++){
        arr[i]=i+1;
    }
    for(int i=2;i*i<=size;i++){
        for(int j=i*i-1;j<size;j+=i){
            if(arr[j]==j+1){
                arr[j]=i;
            }
        }
    }
    cin>>n;
    while(n){
        cout<<arr[n-1]<<"\n";
        cin>>n;
    }
}
