#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long
using namespace std;

void findfreq(string t, int tl, int freq[]){
    for(int i=0; i<tl; i++){
        freq[t[i]-'a']++;
    }
}

int lettersreq(int freq[], vector<int> pos[]){
    int ans=0;
    for(int i=0;i<26; i++){
        if(freq[i]>0){
            if(ans<pos[i][freq[i]-1]){
                ans=pos[i][freq[i]-1];
            }
        }
    }
    return ans+1;
}


void calculatepos(string s, int n, vector<int> pos[]){
    for(int i=0; i<n; i++){
        pos[s[i]-'a'].push_back(i);
    }
}

int main(){
    int n,m;
    string s;
    cin>>n>>s>>m;
    vector<int> pos[26];
    calculatepos(s, n, pos);
    while(m--){
        string t;
        cin>>t;
        int tl=t.length();
        int freq[26]={};
        findfreq(t,tl,freq);
        cout<<lettersreq(freq, pos)<<endl;
    }
    return 0;
}