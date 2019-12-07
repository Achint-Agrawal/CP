#include <iostream>
#include <string>
using namespace std;

int main() {
	for(int k=0;k<10;k++){
		string a;
		string b;
		cin>>a;
		cin>>b;
		int l1=a.length();
		int l2=b.length();
		int ai[101]={};
		int bi[101]={};
		int x=100;
		for(int i=l1-1;i>=0;i--){
			ai[x]=a[i]-'0';
			x--;
		}
		x=100;
		for(int i=l2-1;i>=0;i--){
			bi[x]=b[i]-'0';
			x--;
		}
		int add[101]={};
		int sub[101]={};
		int carry1=0;
		for(int i=100;i>=0;i--){
			add[i]=(ai[i]+bi[i]+carry1)%10;
			carry1=(ai[i]+bi[i]+carry1)/10;
		}
		for(int i=100;i>=0;i--){
			if(ai[i]<bi[i]){
				ai[i]+=10;
				ai[i-1]--;
			}
			sub[i]=ai[i]-bi[i];
		}
		int div1=0;
		int div2=0;
		for(int i=0;i<=100;i++){
			div1=div1*10+add[i];
			div2=div2*10+sub[i];
			add[i]=div1/2;
			sub[i]=div2/2;
			div1=div1%2;
			div2=div2%2;
		}
		int f=0;
		for(int i=0;i<=100;i++){
			if(add[i]){
				f=1;
			}
			if(f){
				cout<<add[i];
			}
		}
		f=0;
		cout<<endl;
		for(int i=0;i<=100;i++){
			if(sub[i]){
				f=1;
			}
			if(f){
				cout<<sub[i];
			}
		}
		cout<<endl;
	}
	return 0;
}