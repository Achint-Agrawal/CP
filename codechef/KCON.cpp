#include <iostream>
using namespace std;

int main() {
	long long int t;
	cin>>t;
	while(t--){
		long long int n,k;
		cin>>n;
		cin>>k;
		long long int a[2*n]={};
		long long int totalsum=0;
		long long int m=-1000000;
		for(long long int i=0;i<n;i++){
			cin>>a[i];
			if(k!=1){
				a[n+i]=a[i];
			}
			else{
				a[n+i]=-1000000;
			}
			if(a[i]>m){
				m=a[i];
			}
			totalsum+=a[i];
		}
		
		long long int ans=m;
		long long int sum=0;
		for(long long int i=0;i<2*n;i++){
			
			sum += a[i];
			if(sum < 0){
				sum = 0;	
			} 
			else{
				ans = max(ans, sum);
			}
		}
		if(totalsum>0 && k!=1){
			ans+=(k-2)*totalsum;
		}
		cout<<ans<<endl;
	}
	return 0;
}