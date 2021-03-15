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

struct Person{
    int id, h, w;
};

bool operator<(const Person &a, const Person &b) {
  return tie(a.h, a.w, a.id) < tie(b.h, b.w, b.id);
}

vi findSmallest(int n, vector<Person> &people){
    vi ans(n+1, -1);
    int si = 0, csi = 0;
    Fo(i, 1, people.size()-1, 1){
        Person currPerson = people[i];
        if(currPerson.h != people[csi].h){
            if(people[si].w > people[csi].w){
                si = csi;
            }
            csi = i;
        }
        if(people[si].w < currPerson.w && people[si].h < currPerson.h){
            ans[currPerson.id] = people[si].id;
        }
        // cout<<i<<" "<<csi<<" "<<si<<endl;
    }
    return ans;
}

void test_case(){
    int n;
    cin>>n;
    vector<Person> people;
    Fo(i, 1, n, 1){
        Person curr;
        int h, w;
        cin>>h>>w;
        curr = {i, h, w};
        people.push_back(curr);
        curr = {i, w, h};
        people.push_back(curr);
    }
    sort(people.begin(), people.end());
    int ind = 0;
    // for(auto i:people){
    //     cout<<ind++<<" "<<i.id<<" "<<i.h<<" "<<i.w<<endl;
    // }
    // cout<<endl;

    // Find person with smallest w till current index
    vi ans = findSmallest(n, people);
    arrout2(ans, n, ' ');
    cout<<endl;
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