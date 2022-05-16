#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int l;
		cin>>l;
		char a[l+1];
		char b[l+1];
		a[l]=b[l]='\0';
		string c;
		cin>>c;
		int d=0;
		for(int i=0; i<l; i++){
			if(c[i]=='0')	a[i]=b[i]='0';
			else if(d){
				if(c[i]=='1'){
					a[i]='0';
					b[i]='1';
				}
				else{
					a[i]='0';
					b[i]='2';
				}
			}
			else{
				if(c[i]=='1'){
					a[i]='1';
					b[i]='0';
					d=1;
				}
				else	a[i]=b[i]='1';
			}
		}
		cout<<a<<"\n"<<b<<"\n";
	}
	return 0;
}
