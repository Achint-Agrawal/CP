#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

void test_case(){
    int n, l, r, x;
    cin>>n>>l>>r>>x;
    vi c(n);
    arrin(c, n);
    sort(c.begin(), c.end());

    int n_ways = 0;
    for(int mask = 0; mask < (1<<n); mask++){
        int min_d = -1, max_d = -1, n_probs = 0, tot_d = 0;
        fo(j, n){
            if((mask>>j) & 1){
                n_probs++;
                if(min_d == -1){
                    min_d = c[j];
                }
                max_d = c[j];
                tot_d += c[j];
            }
        }
        // deb3(mask, n_probs, tot_d);
        // deb2(min_d, max_d);
        if(n_probs>=2 && (max_d-min_d)>=x && tot_d<=r && tot_d>=l){
            n_ways++;
        }
    }
    cout<<n_ways;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while(t--){
        test_case();
    }
    return 0;
}