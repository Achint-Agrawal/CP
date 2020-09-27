#include <bits/stdc++.h>

#define ll long long
#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, a, b, x) for(int i=a; i<=b; i+=x)
#define fod(i, n) for(int i=n-1; i>=0; i--)
#define Fod(i, a, b, x) for(int i=a; i>=b; i-=x)
#define arrin(a, n) fo(i, n) cin>>a[i]
#define arrin2(a, n) Fo(i, 1, n, 1) cin>>a[i]
#define arrout(a, n, s) fo(i, n) cout<<a[i]<<s
#define arrout2(a, n, s) Fo(i, 1, n, 1) cout<<a[i]<<s
#define mod 1000000007
#define PI  3.14159265358979323846
#define pb push_back
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
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int findLargestSmallerThanEqualTo(vi v, int t){
    if(v.empty()) return INT_MIN;
    int hi = v.size()-1, lo = 0;
    while(lo<=hi){
        int m = (hi+lo)/2;
        if(v[m] <= t)   lo = m+1;
        else    hi = m-1;
    }
    int ind = lo-1;
    if(ind<v.size() && ind>=0)  return v[ind];
    else return INT_MIN;
}


int findSmallestLargerThanEqualTo(vi v, int t){
    if(v.empty()) return INT_MAX;
    int hi = v.size()-1, lo = 0;
    while(lo<=hi){
        int m = (hi+lo)/2;
        if(v[m] >= t)   hi = m-1;
        else    lo = m+1;
    }
    int ind = hi + 1;
    if(ind<v.size() && ind>=0)  return v[ind];
    else return INT_MAX;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    int a[n+1];
    arrin2(a, n);

    vi inc, dec;

    Fo(i, 2, n, 1){
        if(a[i] > a[i-1])   inc.pb(i);
        else if(a[i] < a[i-1])  dec.pb(i);
    }

    // arrout(inc, inc.size(), " ");
    // cout<<"\n";
    // arrout(dec, dec.size(), " ");
    // cout<<"\n";

    while(m--){
        int l, r;
        cin>>l>>r;
        int largestInc = findLargestSmallerThanEqualTo(inc, r);
        int smallestDec = findSmallestLargerThanEqualTo(dec, l+1);

        // deb2(l, r);
        // deb2(largestInc, smallestDec);

        if(largestInc <= l || smallestDec > r || largestInc < smallestDec)   cout<<"Yes\n";
        else    cout<<"No\n";
    }

    return 0;
}