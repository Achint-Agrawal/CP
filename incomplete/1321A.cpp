#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n]={};
    int b[n]={};
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    int a1=0,b1=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            a1++;
        }
        else if(b[i]>a[i]){
            b1++;
        }
    }
    if(a1==0){
        cout<<-1<<endl;
    }
    else{
        cout<<(b1/a1+1)<<endl;
    }
    return 0;
}