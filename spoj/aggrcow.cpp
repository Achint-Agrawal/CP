#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int check(int stallpos[], int n, int c, int gap){
    c--;
    int prevpos=stallpos[0];
    for(int i=1; i<n && c; i++){
        if(stallpos[i]-prevpos>=gap){
            c--;
            prevpos=stallpos[i];
        }
    }
    return !c;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int N,C;
        cin>>N>>C;
        int stallpos[N];
        for(int i=0;i<N;i++){
            cin>>stallpos[i];
        }
        sort(stallpos, stallpos+N);
        int l=0,u=stallpos[N-1];
        while(l!=u){
            int mid=ceil((l+u)/2.0);
            //cout<<mid<<"  "<<check(stallpos, N, C, mid)<<endl;
            if(check(stallpos, N, C, mid)){
                l=mid;
            }
            else{
                u=mid-1;
            }
        }
        cout<<l<<endl;
    }
}