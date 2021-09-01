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

bool isIntimidating(vi &A, int ind, int n){
    if(ind>n-2 || ind<1){
        return false;
    }
    if((A[ind] < A[ind+1] && A[ind] < A[ind-1])
    || (A[ind] > A[ind+1] && A[ind] > A[ind-1])){
        return true;
    }
    return false;
}

void test_case(){
    int n;
    cin>>n;
    vi A(n);
    arrin(A, n);
    
    int intimidation = 0;
    Fo(i, 1, n-1, 1){
        if(isIntimidating(A, i, n)){
            intimidation++;
        }
    }

    // deb(intimidation);
    int max_dec = 0;
    Fo(i, 1, n-1, 1){
        int temp = A[i];
        int initial_intimidation = isIntimidating(A, i, n) + isIntimidating(A, i-1, n) + isIntimidating(A, i+1, n);
        A[i] = A[i-1];
        int intimidation1 = isIntimidating(A, i, n) + isIntimidating(A, i-1, n) + isIntimidating(A, i+1, n);
        A[i] = A[i+1];
        int intimidation2 = isIntimidating(A, i, n) + isIntimidating(A, i-1, n) + isIntimidating(A, i+1, n);
        A[i] = temp;
        max_dec = max(max_dec, initial_intimidation - min(intimidation1, intimidation2));
        // deb3(i, intimidation1, intimidation2);
    }

    cout<<(intimidation - max_dec)<<"\n";
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