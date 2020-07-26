#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	int t;
	cin>>t;
	vector<ll> cumsum;
	cumsum.push_back(0);
	for(int i=1; i<=100000; i++)	cumsum.push_back(cumsum[i-1]+i);
	while(t--){
		int n, k;
		cin>>n>>k;
		int x=lower_bound(cumsum.begin(), cumsum.end(), k) - cumsum.begin();
		int pos1=n-x-1;
		int pos2=n+cumsum[x-1]-k;
		for(int i=0; i<n; i++){
			if(i==pos1||i==pos2)	cout<<'b';
			else	cout<<'a';
		}
		cout<<endl;
	}
	return 0;
}
