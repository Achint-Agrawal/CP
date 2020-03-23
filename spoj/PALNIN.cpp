#include <iostream>
#include <string>
using namespace std;

int deleteindex(string s){
	for(int i=0; i<s.length(); i++){
		if(s[i]!='0'){
			return i;
		}
	}
	return s.length()-1;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int i=deleteindex(s);
		s=s.substr(i, s.length()-i);
		// cout<<s<<endl;
		int status=0;
		int l=s.length();
		int flag=1;
		for(int i=0; i<l; i++){
			if(s[i]!='9'){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<'1';
			for(int i=0; i<l-1; i++){
				s[i]-=9;
			}
			s[l-1]='1';
			cout<<s<<endl;
			continue;
		}
		for(int i=l-1; i>=l/2; i--){
			int j=l-i-1;
			if(s[i]>s[j]){
				status=-1;
			}
			else if(s[i]<s[j]){
				status=1;
			}
			s[i]=s[j];
		}
		if(status!=1){
			int pos=l/2;
			while(s[pos]=='9' && s[l-pos-1]=='9'){
				s[pos]=s[l-pos-1]='0';
				pos++;
			}
			s[pos]++;
			if(pos!=l-pos-1)	s[l-pos-1]++;
		}
		cout<<s<<endl;
	}
	return 0;
}
