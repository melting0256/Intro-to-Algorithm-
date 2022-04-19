#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
vector<map<long long int,long long int> > graph;
vector<long long int> parent;

bool bfs(long long int s,long long int t){
	vector<bool> visit(t+1,false);
	queue<long long int> q;
	q.push(s);
	visit[s]=true;
	parent[s]=-1;
	while(!q.empty()){
		long long int u=q.front();
		q.pop();
		map<long long int,long long int>::iterator it;
		for(it=graph[u].begin();it!=graph[u].end();it++){
			if(visit[(*it).first]==false&&(*it).second>0){
				if((*it).first==t){
					parent[(*it).first]=u;
					return true;
				}
				q.push((*it).first);
				parent[(*it).first]=u;
				visit[(*it).first]=true;
			}
		}
	}
	return false;
}

long long int fordfulkerson(long long int s,long long int t){
	long long int maxflow=0;
	parent.resize(t+1);
	while(bfs(s,t)){
		long long int pathflow=LLONG_MAX;
		for(long long int i=t;i!=s;i=parent[i]){
			long long int u=parent[i];
			pathflow=min(pathflow,graph[u][i]);
		}
		for(long long int i=t;i!=s;i=parent[i]){
			long long int u=parent[i];
			graph[u][i]-=pathflow;
			graph[i][u]+=pathflow;
		}
		maxflow+=pathflow;
	}
	return maxflow;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	long long int n;
	cin>>n;
	graph.resize(n+2);
	long long int a,b;
	for(long long int i=1;i<=n;i++){
		cin>>a;
		graph[0][i]=a;
	}
	for(long long int i=1;i<=n;i++){
		cin>>b;
		graph[i][n+1]=b;
	}
	long long int m,x,y,c;
	cin>>m;
	map<long long int,long long int>::iterator it;
	for(long long int i=0;i<m;i++){
		cin>>x>>y>>c;
		it=graph[x].find(y);
		if(it!=graph[x].end()){
			graph[x][y]+=c;
		}
		else{
			graph[x][y]=c;
		}
		it=graph[y].find(x);
		if(it!=graph[y].end()){
			graph[y][x]+=c;
		}
		else{
			graph[y][x]=c;
		}
	}
	long long int ans;
	ans=fordfulkerson(0,n+1);
	cout<<ans;
}
