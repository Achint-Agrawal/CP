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

vi lsd(1e6+1, 1);     // largest square divisor

void seive(){
    Fo(i, 2, 1e3, 1){
        int sq = i*i;
        Fo(j, sq, 1e6, sq){
            lsd[j] = sq;
        }
    }
}

void replace(vi &a, int n){
    fo(i, n){
        a[i] = a[i]/lsd[a[i]];
    }
}

mii findFreq(vi &a, int n){
    mii freq;
    fo(i, n){
        freq[a[i]]++;
    }
    return freq;
}

pii findBeauty(mii freq){
    int eventotal = 0, maxodd = 0, maxall = 0;
    for(auto i:freq){
        // deb2(i.first, i.second);
        maxall = max(maxall, i.second);
        if(i.second%2 && i.first!=1){
            maxodd = max(maxodd, i.second);
        }
        else{
            eventotal += i.second;
        }
    }
    return mkp(maxall, max(eventotal, maxodd));
}

void test_case(){
    int n;
    cin>>n;
    vi a(n);
    arrin(a, n);
    replace(a, n);  // replace with multiple of single power of each prime with odd power
    mii freq= findFreq(a, n);
    int q;
    cin>>q;
    pii ans = findBeauty(freq);
    while(q--){
        ll w;
        cin>>w;
        if(w==0){
            cout<<ans.first<<endl;
        }
        else{
            cout<<ans.second<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    ll t = 1;
    cin>>t;
    while(t--){
        test_case();
    }
    return 0;
}