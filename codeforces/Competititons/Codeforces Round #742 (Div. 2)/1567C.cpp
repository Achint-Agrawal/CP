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

vi flag1;
vi flag2;
ll ways(vi &a, int l, int ind){
    if(ind >= l){
        return 1;
    }
    ll ans = 0;
    if(a[ind] < 10){
        ans += (a[ind] + 1) * ways(a, l, ind+1);
    }
    else if(a[ind] < 19){
        flag1[ind] = 1;
        int x = 0;
        if(a[ind]%2 == 0){
            x= 1 + 2*(9-a[ind]/2);
        }
        else{
            x = 2*(9-a[ind]/2);
        }
        ans += x*ways(a, l, ind+1);
    }
    // ans += min((a[ind] + 1), 9) * ways(a, l, ind+1);
    // if(ind == 0){
    //     int s = 0;
    //     fo(i, l){
    //         s += flag1[i];
    //     }
    //     if(s<0)
    //     ans -= 2;
    // }
    if(ind +2 < l && a[ind] >0){
        a[ind]--;
        a[ind+2] += 10;
        // ans += min((a[ind] + 1), 9) * ways(a, l, ind+1);

        if(a[ind] < 10){
            ans += (a[ind] + 1) * ways(a, l, ind+1);
        }
        else if(a[ind] < 19){
            flag2[ind] = 1;
            int x = 0;
            if(a[ind]%2 == 0){
                x= 1 + 2*(9-a[ind]/2);
            }
            else{
                x = 2*(9-a[ind]/2);
            }
            ans += x*ways(a, l, ind+1);
        }
        a[ind+2] -= 10;
        a[ind]++;
        // if(ind == 0){
        //     int s = 0;
        //     fo(i, l){
        //         s += flag2[i];
        //     }
        //     if(s<0)
        //     ans -= 2;
        // }
    }
    // arrout(a, l, " ");
    // deb2(ind, ans);
    return ans;
}

void test_case(){
    int n;
    cin>>n;
    
    vi a;
    while(n > 0){
        a.push_back(n%10);
        n /= 10;
    }
    int l = a.size();
    flag1.resize(l, 0);
    flag2.resize(l, 0);
    reverse(a.begin(), a.end());
    ll temp = ways(a, l, 0);
    // arrout(flag1, l, " ");
    // cout<<endl;
    // arrout(flag2, l, " ");
    // cout<<endl;
    temp-=2;
    cout<<temp<<endl;
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