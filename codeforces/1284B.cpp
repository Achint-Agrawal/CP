#include <vector>
#define ll long long
using namespace std;
 
void input(vector<int> v[], int n){
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        while(l--){
            int s;
            cin>>s;
            v[i].push_back(s);
        }
    }
}
 
void findnonincends(vector<int> s[], int n, vector<pair<int,int>> &ends){
    for(int i=0; i<n; i++){
        int isnoninc=1;
        for(int j=1; j<s[i].size(); j++){
            if(s[i][j-1]<s[i][j]){
                isnoninc=0;
                break;
            }
        }
        if(isnoninc){
            ends.push_back(make_pair(s[i][0], s[i][s[i].size()-1]));
        }
    }
}

ll nonincpairs(vector<pair<int,int>> ends){
    ll c=0;
    for(int i=0; i<ends.size(); i++){
        // int x=1+findsm(ends, ends[i].second);
        
        int x=upper_bound(ends.begin(), ends.end(), make_pair(ends[i].second, INT_MAX)) - ends.begin();
        // cout<<ends[i].second<<" "<<x<<endl;
        c+=x;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    vector<int> s[n];
    input(s, n);
    vector<pair<int,int>> ends;
    findnonincends(s, n, ends);
    sort(ends.begin(), ends.end());
 
    // cout<<"size="<<ends.size()<<endl;
    // for(int i=0;i<ends.size();i++){
    //     cout<<ends[i].first<<"\t"<<ends[i].second<<endl;
    // }
    
    ll c=nonincpairs(ends);
    cout<<((ll)n)*(ll)n-(ll)c<<endl;
    return 0;
}
