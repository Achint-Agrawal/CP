#include <iostream>
#include <algorithm>
#include <queue> 
using namespace std;

int bfs(int n, int m){
	int y=max(n,m);
	int visited[2*y]={};
	int level[2*y]={};
	vector<int> bacche[2*y];
	queue<int> q;
	q.push(n);
	visited[n]=1;
	level[n]=0;
	while(1){
		int x=q.front();
		q.pop();
		if(2*x<2*y)	bacche[x].push_back(2*x);
		if(x>1)		bacche[x].push_back(x-1);
		for(int i=0; i<bacche[x].size(); i++){
			if(visited[bacche[x][i]] == 0){
				visited[bacche[x][i]]=1;
				level[bacche[x][i]]=level[x]+1;
				if(bacche[x][i] == m){
					return level[bacche[x][i]];
				}
				q.push(bacche[x][i]);
			}
		}
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	cout<<bfs(n,m);
	return 0;
}