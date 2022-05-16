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

int test_case(){
    int a,b;
    cin>>a>>b;
    if(a == 0 && b == 0){
        return 0;
    }
    else if(a == b){
        return 1;
    }
    else if((a+b) %2 == 0){
        return 2;
    }
    else{
        return -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin>>t;
    while(t--){
        cout<<test_case()<<endl;
    }
    return 0;
}