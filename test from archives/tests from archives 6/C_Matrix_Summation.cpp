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
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    fo(i, n){
        fo(j, m){
            cin>>arr[i][j];
        }
    }
    int ans[n][m]={};
    fo(i, n){
        fo(j, m){
            int a = arr[i][j];
            if(i-1>=0){
                a-= arr[i-1][j];
                if(j-1>=0){
                    a+= arr[i-1][j-1];
                }
            }
            if(j-1>=0){
                a-=arr[i][j-1];
            }
            ans[i][j]=a;
        }
    }
    fo(i, n){
        fo(j, m){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}