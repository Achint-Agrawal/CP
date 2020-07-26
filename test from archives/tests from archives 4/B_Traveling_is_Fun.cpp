#include <bits/stdc++.h>

#define ll long long
#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, a, b, x) for(int i=a; i<=b; i+=x)
#define fod(i, n) for(int i=n-1; i>=0; i--)
#define Fod(i, a, b, x) for(int i=a; i>=b; i-=x)
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
    int n,g,q;
    cin>>n>>g>>q;
    int oc[q];
    int dc[q];
    fo(i, q){
        cin>>oc[i];
    }
    cin>>q;
    fo(i, q){
        cin>>dc[i];
    }
    int ans[q]={};
    fo(i, q){
        if(oc[i]<g || dc[i]<g)
            continue;
        int g2=__gcd(oc[i],dc[i]);
        if(g2>g){
            ans[i]=1;
            continue;
        }
        // int reqmul= (int)ceil((1.0*g)/(1.0*g2));
        int reqmul=g/g2+1;
        int k=max(oc[i], dc[i]) * reqmul;
        if(k<=n){
            ans[i]=1;
        }
    }
    fo(i, q){
        cout<<ans[i]<<"\n";
    }
    return 0;
}