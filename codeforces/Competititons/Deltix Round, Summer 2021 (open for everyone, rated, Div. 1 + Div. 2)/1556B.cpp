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
    int n;
    cin>>n;
    vi arr(n);
    arrin(arr, n);
    fo(i, n){
        arr[i] %= 2;
    }
    int notOK = -1;
    ll ans = 0;
    Fo(i, 1, n-1, 1){
        if(notOK == -1){
            if(arr[i] == arr[i-1]){
                notOK = i;
            }
        }
        else{
            if(arr[i] != arr[i-1]){
                swap(arr[i], arr[notOK]);
                ans += i-notOK;
                int temp = notOK;
                notOK = -1;
                Fo(j, temp+1, i, 1){
                    if(arr[j] == arr[j-1]){
                        notOK = j;
                    }
                }
            }
        }
    }
    if(notOK == n-1 && arr[0] != arr[notOK]){
        // ans += n-2;
        ans += n/2;
        notOK = -1;
    }
    if(notOK == -1){
        return ans;
    }
    return -1;
}

int test_case2(){
    int n;
    cin>>n;
    vi arr(n);
    arrin(arr, n);
    fo(i, n){
        arr[i] %= 2;
    }

    int ans1 = 0;
    vi case1(n, 0);
    fo(i, n){
        case1[i] = i%2;
    }
    // fo(i, n){
    //     cout<<i<<" "<<arr[i]<<" "<<case1[i]<<endl;
    // }
    // cout<<endl;
    vi v1;
    vi v2;
    fo(i, n){
        if(arr[i] != case1[i] && arr[i] == 0){
            v1.push_back(i);
        }
        else if(arr[i] != case1[i] && arr[i] == 1){
            v2.push_back(i);
        }
    }
    if(v1.size() != v2.size()){
        // return -1;
        ans1 = -1;
    }
    else{
        fo(i, v1.size()){
            ans1 += abs(v1[i] - v2[i]);
        }
    }

    int ans2 = 0;
    // vi case1(n, 0);
    fo(i, n){
        case1[i] = (i%2 == 0);
    }
    // vi v1;
    // vi v2;
    // fo(i, n){
    //     cout<<i<<" "<<arr[i]<<" "<<case1[i]<<endl;
    // }
    v1.clear();
    v2.clear();
    fo(i, n){
        if(arr[i] != case1[i] && arr[i] == 0){
            v1.push_back(i);
        }
        else if(arr[i] != case1[i] && arr[i] == 1){
            v2.push_back(i);
        }
    }
    // cout<<v1.size()<<" "<<v2.size()<<endl;
    if(v1.size() != v2.size()){
        ans2 = -1;
    }
    else{
        fo(i, v1.size()){
            // cout<<v1[i]<<" "<<v2[i]<<endl;
            ans2 += abs(v1[i] - v2[i]);
        }
    }
    if(ans1 == -1){
        return ans2;
    }
    if(ans2 == -1){
        return ans1;
    }
    return min(ans1, ans2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin>>t;
    while(t--){
        cout<<test_case2()<<endl;
    }
    return 0;
}