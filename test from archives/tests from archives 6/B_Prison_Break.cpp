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

void f(int a[], int b[], int l){
    fo(i, l){
        a[b[i]] = 1;
    }
}

int lon(int arr[], int l){
    int ans=0;
    int cur=0;
    fo(i, l){
        if(arr[i]==1){
            cur++;
        }
        else{
            
            if(cur>ans){
                ans=cur;
            }
            cur=0;
        }
    }
    if(cur>ans) ans=cur;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int x;
    cin>>x;
    int h[x];
    fo(i, x)    cin>>h[i];
    int y;
    cin>>y;
    int v[y];
    fo(i, y)    cin>>v[i];

    int h1[n+1] = {};
    int v1[m+1] = {};
    f(h1, h, x);
    f(v1, v, y);

    // fo(i, n+1)    deb2(i, h1[i]);

    int64 lh = lon(h1, n+1);
    int64 vh = lon(v1, m+1);
    // deb2(lh, vh);
    cout<<(lh+1)*(vh+1);

    return 0;
}