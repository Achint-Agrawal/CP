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

void add_neighbours(int c1, int c2, int d, vvi &dist){
    
    if(dist[c1][c2] == -1){
        dist[c1][c2] = d;
    }
    dist[c1][c2] = min(dist[c1][c2], d);
    fo(i, 26){
        if(dist[c2][i] != -1 && i!=c2 && (dist[c1][i] == -1 || dist[c1][i] > dist[c2][i] + 1)){
            add_neighbours(c1, i, dist[c2][i] + 1, dist);
        }
    }
    cout<<c1<<" "<<c2<<" "<<dist[c1][c2]<<endl;
}

int test_case2(){
    string s;
    cin>>s;
    
    vi freq(26, 0);
    fo(i, s.size()){
        int ch = s[i] - 'A';
        freq[ch]++;
    }

    vvi dist(26, vi(26, -1));
    fo(i, 26){
        arrout(dist[i], 26, " ");
        cout<<endl;
    }
    fo(i, 26){
        dist[i][i] = 0;
    }
    fo(i, 26){
        fo(j, 26){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    int n;
    cin>>n;
    fo(i, n){
        string x;
        cin>>x;
        int c1 = x[0] - 'A';
        int c2 = x[1] - 'A';
        add_neighbours(c1, c2, 1, dist);
        fo(i, 26){
            fo(j, 26){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    

    int ans = -1;
    fo(i, 26){
        int curr_ans = 0;
        fo(j, 26){
            if(freq[j] != 0){
                if(dist[j][i] == -1){
                    curr_ans = -1;
                    break;
                }
                curr_ans += freq[j] * dist[j][i];
            }
        }
        // cout<<i<<" "<<curr_ans<<endl;
        if(curr_ans != -1){
            if(ans == -1){
                ans = curr_ans;
            }
            ans = min(ans, curr_ans);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin>>t;
    
    fo(i, t){
        cout<<"Case #"<<(i+1)<<": "<<test_case2()<<endl;
        
    }
    return 0;
}