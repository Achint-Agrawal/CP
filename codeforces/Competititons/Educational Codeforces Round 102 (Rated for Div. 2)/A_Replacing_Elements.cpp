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
        int n,d;
        cin>>n>>d;
        vi a(n);
        arrin(a, n);
        int n1 = INT_MAX, ind = -1;
        int f = 0;
        fo(i, n){
            if(a[i]>d){
                f = 1;
                break;
            }
        }
        if(!f){
            cout<<"YES\n";
            continue;
        }
        fo(i, n){
            if(a[i]<n1){
                n1 = a[i];
                ind = i;
            }
        }
        int n2 = INT_MAX;
        fo(i, n){
            if(a[i]<n2 && i!=ind){
                n2 = a[i];
            }
        }
        if(n1 + n2 <= d)    cout<<"YES\n";
        else                cout<<"NO\n";
    }
    return 0;
}