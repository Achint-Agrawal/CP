#include <iostream>
using namespace std;

int main(){
    int t;
    int size=1000000;
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int result=1;
        while(n>1){
            if(result%arr[n-1]==0){
                result/=arr[n-1];
            }
            else{
                result*=arr[n-1];
            }
            n/=arr[n-1];
        }
        cout<<result<<"\n";
    }
}
