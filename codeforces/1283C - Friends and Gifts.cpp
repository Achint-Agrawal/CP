#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	int giftto[n+1]={};
	int receivefrom[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>giftto[i];
		receivefrom[giftto[i]]=i;
	}
	vector<int> sedpeeps;
	vector<int> notreceiving;
	vector<int> notgifting;
	for(int i=1;i<=n;i++){
		if(giftto[i]==0 && receivefrom[i]==0){
			sedpeeps.push_back(i);
		}
		else if(giftto[i]==0){
			notgifting.push_back(i);
		}
		else if(receivefrom[i]==0){
			notreceiving.push_back(i);
		}
	}
	if(!sedpeeps.empty()){
		if(sedpeeps.size()==1){
			giftto[notgifting[notgifting.size()-1]]=sedpeeps[0];
			notgifting.pop_back();
			receivefrom[notreceiving[notreceiving.size()-1]]=sedpeeps[0];
			giftto[sedpeeps[0]]=notreceiving[notreceiving.size()-1];
			notreceiving.pop_back();
		}
		else{
			for(int i=0;i<sedpeeps.size()-1;i++){
				giftto[sedpeeps[i]]=sedpeeps[i+1];
				receivefrom[sedpeeps[i+1]]=sedpeeps[i];
			}
			giftto[sedpeeps[sedpeeps.size()-1]]=sedpeeps[0];
			receivefrom[sedpeeps[0]]=sedpeeps[sedpeeps.size()-1];
		}
	}
	for(int i=0;i<notgifting.size();i++){
		giftto[notgifting[i]]=notreceiving[i];
	}
	for(int i=1;i<=n;i++){
		cout<<giftto[i]<<" ";
	}
	return 0;
}