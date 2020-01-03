#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int pos[n+2]={};
	int maxocc[n+2]={};
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pos[x]++;
		maxocc[x]++;
	}
	int minans=0;
	for(int i=1;i<=n;i++){
		if(pos[i]!=0){
			minans++;
			i+=2;
		}
	}
	for(int i=0;i<=n;){
		int s=0;
		for(int j=i+1;j<=n+1;j++){
			if(pos[j]==0){
				if(s<j-i){
					i=j;
				}
				else if(s==j-i){
					maxocc[i]=1;
					i=j;
				}
				else{
					maxocc[i]=maxocc[j]=1;
					i=j+1;
					int s2=0;
					int f=1;
					while(f && i<=n+1){
						while(pos[i]!=0){
							s2+=pos[i];
							i++;
						}
						if(s2<i-j){
							f=0;
						}
						else{
							maxocc[i]=1;
							j=i;
							i++;
							s2=0;
						}
					}
				}
				break;
			}
			else{
				s+=pos[j];
			}
		}
	}
	int countmax=0;
	for(int i=0;i<=n+1;i++){
		if(maxocc[i]!=0){
			countmax++;
		}
	}
	cout<<minans<<" "<<countmax;
	return 0;
}