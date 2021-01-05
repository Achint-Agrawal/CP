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
        int n, m;
        cin>>n>>m;
        vi an(n);
        vi am(m);
        arrin(an, n);
        arrin(am, m);
        int crashes = 0;
        si s(an.begin(), an.end());
        for(int i = 0; i<m; i++){
            if(s.find(am[i]) != s.end())    crashes++;
        }
        cout<<crashes<<endl;
    }

    //     int p1 = 0, p2 = 0;
    //     int crashes = 0;
    //     while(p1<n || p2<m){
    //         if(p1<n && p2<m){
    //             if(an[p1] == am[p2]){
    //                 crashes++;
    //                 p1++; p2++;
    //             } 
    //             else if(an[p1]<am[p2]){
    //                 p1++;
    //             }
    //             else    p2++;
    //         }
    //         else if(p1<n){
    //             if(an[p1] == am[p2]){
    //                 crashes++;
    //                 break;
    //             }
    //             else if(an[p1]<am[p2])  p1++;
    //             else    break;
    //         }
    //         else{
    //             if(an[p1] == am[p2]){
    //                 crashes++;
    //                 break;
    //             }
    //             else if(an[p1]>am[p2])  p2++;
    //             else    break;
    //         }
    //     }
    //     cout<<crashes<<endl;
    // }


    return 0;
}