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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi an(n+2, 0);
        arrin2(an, n);
        vi d(n+2, 0);
        Fo(i, 2, n, 1){
            d[i] = an[i] - an[i-1];
        }
        // arrout(d, n+2, ' ');
        // cout<<endl;
        vi scores(n+2,0);
        int maxind = 0;
        scores[1] = abs(d[2]);
        scores[n] = abs(d[n] + d[n+1]);
        Fo(i, 1, n, 1){
            if((d[i]>0 && d[i+1]<0) || (d[i]<0 && d[i+1]>0))
            scores[i] =2* min(abs(d[i]), abs(d[i+1]));
            if(scores[i] > scores[maxind])  maxind = i;
        }
        // arrout(scores, n+2, ' ');
        // cout<<endl;
        // cout<<maxind<<endl;
        ll ans = 0;
        Fo(i, 1, n, 1)  ans+= abs(d[i]);
        ans -= abs(d[maxind]) + abs(d[maxind+1]);
        if(maxind!=n && maxind!=1) ans+= abs(d[maxind] + d[maxind+1]);
        cout<<ans<<endl;
    }

    return 0;
}