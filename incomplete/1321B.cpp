#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    ll beauty[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>beauty[i];
    }
    vector<int> pos;
    vector<ll> totalbeauty;
    pos.push_back(1);
    totalbeauty.push_back(beauty[1]);
    for(int i=2;i<=n;i++){
        int flag=0;
        for(int j=0;j<pos.size();j++){
            if(i-pos[j] == beauty[i]-beauty[pos[j]]){
                pos[j]=i;
                totalbeauty[j]+=beauty[i];
                flag=1;
                break;
            }
        }
        if(flag==0){
            pos.push_back(i);
            totalbeauty.push_back(beauty[i]);
        }
    }
    // for(int i=0; i<pos.size();i++){
    //     cout<<totalbeauty[i]<<" ";
    // }
    // cout<<endl;
    ll m=0;
    for(int i=0;i<pos.size(); i++){
        if(totalbeauty[i]>m){
            m=totalbeauty[i];
        }
    }
    cout<<m<<endl;
    return 0;
}