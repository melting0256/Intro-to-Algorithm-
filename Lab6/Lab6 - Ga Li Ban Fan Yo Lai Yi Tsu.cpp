#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<climits>
#include<map>
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
	long long int f,n,m;
	cin>>f>>n>>m;
	long long int farm,factory,store;
	graph.resize(3+f+2*n+m);
	map<long long int,long long int>::iterator it; 
	for(long long int i=0;i<f;i++){
		cin>>farm;
		graph[0][i+1]=farm;
	}
	for(long long int i=0;i<n;i++){
		cin>>factory;
		graph[f+2*i+1][f+2*i+2]=factory;
	}
	for(long long int i=0;i<m;i++){
		cin>>store;
		graph[f+2*n+i+1][1+f+2*n+m]=store;
	}
	long long int C;
	cin>>C; 
	long long int x,y,c;
	for(long long int i=0;i<C;i++){
		cin>>x>>y>>c;
		it = graph[x].find(f+2*y-1);
		if(it != graph[x].end()){
			graph[x][f+2*y-1]+=c;
		}
		else{
			graph[x][f+2*y-1]=c;
		}
	}
	long long int l;
	cin>>l;
	for(long long int i=0;i<l;i++){
		cin>>x>>y>>c;
		it = graph[f+2*x].find(f+2*n+y);
		if(it != graph[f+2*x].end()){
			graph[f+2*x][f+2*n+y]+=c;
		}
		else{
			graph[f+2*x][f+2*n+y]=c;
		}
	}
	long long int k;
	cin>>k;
	graph[1+f+2*n+m][2+f+2*n+m]=k;
	long long int ans;
	ans=fordfulkerson(0,2+f+2*n+m);
	cout<<ans;
}
