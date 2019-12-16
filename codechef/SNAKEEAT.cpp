#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n;
		cin>>q;
		int a[n]={};
		long long p[n]={};
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		p[0]=a[0];
		for(int i=1;i<n;i++){
			p[i]=a[i]+p[i-1];
		}
		while(q--){
			int k;
			cin>>k;
			int l=0,u=n-1,m;
			while(l<=u){
				m=(l+u)/2;
				if(a[m]>=k){
					u=m-1;
				}
				else{
					l=m+1;
				}
				
				// cout<<"l="<<l<<" u="<<u<<" m="<<m<<endl;
			}
			int ans=0;
			m=l-1;
			l=0,u=m;
			
			while(l<=u){
				ans=(l+u)/2;
				// cout<<"l="<<l<<" u="<<u<<" m="<<m<<" ans="<<ans<<"  "<<1LL*(m-ans+1)*k<<" p[m]="<<p[m]<<" p[ans-1]="<<p[ans-1]<< "  "<<p[m]-p[ans-1]<<endl;
				if(((ans==0 && (1LL*(m-ans+1)*k-p[m]) <=ans)) || (ans!=0 && (1LL*(m-ans+1)*k-(p[m]-p[ans-1]) <=ans))){
					u=ans-1;
					
				}
				else{
					l=ans+1;
				}
				// cout<<realans<<endl;
			}
			/*
			correct but gives tle
			if(m==0){
				if(a[0]>=k){
					ans=n;
				}
				else{
					ans=n-1;
				}
			}
			else{
				ans=n-1-m;
				int eatenindex=k-a[m]-1;
				if(eatenindex<-1){
					eatenindex=-1;
				}
				// cout<<"ans="<<ans<<" ei="<<eatenindex<<endl;
				while(eatenindex<m && m>0){
					ans++;
					m--;
					eatenindex+=k-a[m];
					// cout<<"ans="<<ans<<" ei="<<eatenindex<<endl;
				}
			}*/
			cout<<n-u-1<<endl;
		}
	}
	return 0;
}