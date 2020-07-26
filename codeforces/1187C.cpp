#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
typedef pair<int, int> pii;

void setvals(int b[], int n, vector<pii> &dec){
    int m;
    cin>>m;
    while(m--){
        int t,l,r;
        cin>>t>>l>>r;
        l--;
        r--;
        if(t==1){
            for(int i=l; i<r; i++){
                b[i]=0;
            }
        }
        else{
            dec.push_back(make_pair(l,r));
        }
    }
}

bool check(vector<pii> dec, int b[], int n){
    for(int i=0; i<dec.size(); i++){
        int found=0;
        for(int j=dec[i].first; j<dec[i].second; j++){
            if(b[j]==-1){
                found=1;
            }
        }
        if(!found)  return false;
    }
    return true;
}

void modifyb(int b[], int n){
    b[0]+=n+1;
    for(int i=1;i<n;i++){
        b[i]+=b[i-1];
    }
}

void print(int b[], int n){
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    n--;
    int b[n];
    memset(b, -1, sizeof(b));
    vector<pii> dec;
    setvals(b, n, dec);
    if(check(dec, b, n)){
        modifyb(b, n);
        cout<<"YES"<<endl<<n+1<<" ";
        print(b, n);
    }
    else{
        cout<<"NO";
    }
    return 0;
}
