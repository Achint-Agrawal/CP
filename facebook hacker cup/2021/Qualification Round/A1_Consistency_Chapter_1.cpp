#include <bits/stdc++.h>

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, a, b, x) for(int i=a; i<=b; i+=x)
#define arrin(a, n) fo(i, n) cin>>a[i]
#define arrin2(a, n) Fo(i, 1, n, 1) cin>>a[i]
#define arrout(a, n, s) fo(i, n) cout<<a[i]<<s
#define arrout2(a, n, s) Fo(i, 1, n, 1) cout<<a[i]<<s
#define mod 1000000007
#define pb push_back
#define mkp make_pair
#define deb(a) cout<<#a<<"="<<a<<"\n"
#define deb2(a,b) cout<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\n"
#define deb3(a,b, c) cout<<#a<<"="<<a<<"\t"<<#b<<"="<<b<<"\t"<<#c<<"="<<c<<"\n"
using namespace std;

const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> msi;
typedef long long ll;

bool isVowel(char c){
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return true;
    }
    return false;
}

int test_case(){
    string s;
    cin>>s;
    int l = s.size();
    vi freq(26, 0);
    int nVowels = 0, nConsonants = 0;
    for(int i = 0; i<l; i++){
        int ind = s[i] - 'A';
        freq[ind]++;
        if(isVowel(s[i])){
            nVowels++;
        }
        else{
            nConsonants++;
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i<26; i++){
        int changes = 0;
        char ch = (char)(i + 'A');
        if(isVowel(ch)){
            changes = 2*(nVowels - freq[i]) + nConsonants;
        }
        else{
            changes = 2*(nConsonants-freq[i]) + nVowels;
        }
        ans = min(ans, changes);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin>>t;
    fo(i, t){
        cout<<"Case #"<<(i+1)<<": "<<test_case()<<endl;
    }
    return 0;
}