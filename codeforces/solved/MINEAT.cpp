#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,H;
        cin>>N>>H;
        int pile[N];
        int sum=0,max=0;
        for(int i=0;i<N;i++){
            cin>>pile[i];
            sum+=pile[i];
            if(pile[i]>max){
                max=pile[i];
            }
        }
        int min=ceil((double)sum/H);
        //int K=ceil((min+max)/(double)2);
        int K=(min+max)/2;
        while(min<max){
            int reqtime=0;
            for(int i=0;i<N;i++){
                reqtime+=ceil(pile[i]/(double)K);
            }
            if(reqtime<=H){
                max=K;
            }
            else{
                min=K+1;
            }
            K=(min+max)/2;
        }
        cout<<K<<"\n";
    }
}