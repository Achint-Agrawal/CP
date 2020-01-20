#include <iostream>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string p;
		string h;
		cin>>p;
		cin>>h;
		int lp,lh=0;
		lp=p.length();
		lh=h.length();
		int freqp[26]={};
		int freqh[26]={};
		for(int i=0;i<lp;i++){
			int x=p[i]-'a';
			freqp[x]++;
			int y=h[i]-'a';
			freqh[y]++;
		}
			// for(int i=0;i<26;i++){
			// 	cout<<i<<" "<<freqp[i]<<" "<<freqh[i]<<endl;
			// }
		int ans=1;
		for(int i=0;i<26;i++){
			if(freqp[i]!=freqh[i]){
				ans=0;
			}
		}
		for(int i=lp;i<lh;i++){
			if(ans==1){
				break;
			}
			int x=h[i-lp]-'a';
			freqh[x]--;
			int y=h[i]-'a';
			freqh[y]++;
			ans=1;
			for(int j=0;j<26;j++){
				if(freqp[j]!=freqh[j]){
					ans=0;
				}
			}
			// for(int i=0;i<26;i++){
			// 	cout<<ans<<" "<<i<<" "<<freqp[i]<<" "<<freqh[i]<<endl;
			// }
		}
		if(ans==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}