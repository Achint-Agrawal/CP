#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int find(vector<int> notav, int floors, int s, int d){
    if((s-d>0 && find(notav.begin(), notav.end(), s-d)==notav.end()) || (s+d<=floors && find(notav.begin(), notav.end(), s+d)==notav.end())){
        return d;
    }
    return find(notav, floors, s, d+1);
} 
 
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s,k;
	    cin>>n>>s>>k;
	    vector<int> notav;
	    while(k--){
	        int x;
	        cin>>x;
	        notav.push_back(x);
	    }
	    cout<<find(notav, n, s, 0)<<endl;
	}
	return 0;
}