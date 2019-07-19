#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int check(int a[], int b[], int days, long long balloons, long long m){
    for(int i=0; i<days; i++){
        if(b[i]>0){
            balloons-=max(a[i]-m/b[i], 0ll);
        }
        //cout<<i<<"  "<<balloons<<endl;
    }
    if(balloons>=0){
        return 1;
    }
    return 0;
}

int main(){
    int N;
    long long M;
    cin>>N>>M;
    int A[N];
    int B[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    long long u=0;
    for(int i=0; i<N; i++){
        cin>>B[i];
        if((long long)A[i]*B[i]>u){
            u= (long long)A[i]*B[i];
        }
    }
    long long l=0;
    while(l!=u){
        long long mid=(l+u)/2;
        if(check(A, B, N, M, mid)){
            u=mid;
        }
        else{
            l=mid+1;
        }
    }
    //cout<<check(A, B, N, M, 11)<<endl;
    cout<<l<<endl;
    return 0;
}