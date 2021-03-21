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

vi findhorv(vi &a, int n){
    vi horv(n, 0);
    if(a[0] > a[1]){
        horv[0] = 1;
    }
    else if(a[0] < a[1]){
        horv[0] = -1;
    }

    if(a[n-1] > a[n-2]){
        horv[n-1] = 1;
    }
    else if(a[n-1] < a[n-2]){
        horv[n-1] = -1;
    }

    Fo(i, 1, n-2, 1){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            horv[i] = 1;
        }
        else if(a[i] < a[i-1] && a[i] < a[i+1]){
            horv[i] = -1;
        }
    }
    return horv;
}

int find_intimidation(vi &horv, int n){
    int ans = 0;
    fo(i, n){
        ans+= abs(horv[i]);
    }
    return ans;
}

int max_reduction(vi &a, vi &horv, int n){
    int ans = 0;
    fo(i, n){
        int init = 0;
        int ai = max(0, i-1), bi = min(n-1, i+1)
        Fo(i, ai, bi, 1){
            init += abs(horv[i]);
        }
        vi sub(a.begin() + ai, a.begin() + bi+1);
        
    }
}

void test_case(){
    int n;
    cin>>n;
    vi a(n);
    arrin(a, n);
    vi horv = findhorv(a, n);      //hill or valley
    int intimidation = find_intimidation(horv, n);
    cout<<(intimidation - max_reduction(a, horv, n))<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin>>t;
    while(t--){
        test_case();
    }
    return 0;
}