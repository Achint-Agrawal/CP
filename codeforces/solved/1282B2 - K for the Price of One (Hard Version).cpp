#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,p,k;
		cin>>n>>p>>k;
		int a[n+1]={};
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a,a+n+1);
		int amtreq[n+1]={};
		for(int i=1;i<=n;i++){
			if(i>k-1 ){
				amtreq[i]=a[i]+amtreq[i-k];
			}
			else{
				amtreq[i]+=a[i]+amtreq[i-1];
			}
		}
		int ans=n;
		while(amtreq[ans]>p){
			ans--;
		}
		cout<<ans<<endl;
	}
	return 0;
}