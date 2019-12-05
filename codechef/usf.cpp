#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int primes[100001]={};
    primes[0]=primes[1]=1;
    for(int i=2;i<=100000;i++){
        if(primes[i]==0){
            //primes[i]=1;
            for(int j=i; j<=100000; j+=i){
                primes[j]++;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[100001]={};
        while(n--){
            int x;
            cin>>x;
            a[x]++;
        }
        int p=1;
        for(int i=2; i<=100000;i++){
            int div=0;
            for(int j=i;j<=100000;j+=i){
                div+=a[j];
            }
            p=max(p,primes[i]*div);
        }
        cout<<p<<endl;
    }
    return 0;
}