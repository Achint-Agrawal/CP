#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int t,max=1;
    cin>>t;
    int a1[100001]={};
    a1[0]=a1[1]=1;
    for(int i = 2; i*i <= 100000 ; i++ ){
        if (a1[i]==0){
            for( int j = i+i; j<=100000; j+=i){
                a1[j]=1;
            }
        }
    }

    while(t--){
        int a,b;
        cin>>a;
        cin>>b;

        int a2[100001]={};
        if(a==1){
            a2[0]=1;
        }
        for(int i=2;i*i<=b;i++){
            if(a1[i]==0){
                int j;
                if(a%i==0){
                    j=a;
                }
                else{
                    j=(a/i)*i + i;
                }
                if(j<=i){
                    j=i*i;
                }
                for(;j<=b;j+=i){
                    a2[j-a]=1;
                }
            }
        }
        for(int i=a;i<=b;i++){
            if(a2[i-a]==0){
                cout<<i<<endl;
            }
        }
        cout<<"\n";
    }
    return 0;
}