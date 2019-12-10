#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[159]={};
		a[157]=n%10;
		a[156]=(n/10)%10;
		a[155]=(n/100)%10;
		int carry = 0;
		while(--n){
			int backup=0;
			for(int i=157;i>=0;i--){
				int temp=a[i];
				int k=a[i]*(n%10) + backup*((n/10)%10) + carry;
				a[i]=k%10;
				carry=k/10;
				backup=temp;
			}
		}
		int f=0;
			for(int i=0;i<=157;i++){
				if(a[i]!=0){
					f=1;
				}
				if(f==1){
					cout<<a[i];
				}
			}
			cout<<endl;
		}
	return 0;
}