#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	long long int n,m;
	cin>>n>>m;
	vector<vector<pair<long long int,long long int> > > f(n+1);
	vector<long long int> start(m);
	vector<long long int> end(m);
	vector<long long int> cost(m);
	vector<vector<pair<long long int,long long int> > > b(n+1);
	long long int u,v,w;
	for(long long int i=0;i<m;i++){
		cin>>u>>v>>w;
		f[u].push_back(make_pair(v,w));
		b[v].push_back(make_pair(u,w));
		start[i]=u;
		end[i]=v;
		cost[i]=w;
	}
	vector<long long int> dis(n+1);
	for(long long int i=0;i<=n;i++){
		if(i==1){
			dis[i]=0;
		}
		else{
			dis[i]=500000000000001;
		}
	}
	priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int> >,greater<pair<long long int,long long int> > > pq;
	pq.push({0,1});
	pair<long long int,long long int> p;
	while(!pq.empty()){
		p=pq.top();
		pq.pop();
		if(dis[p.second]<p.first){
			continue;
		}
		for(long long int i=0;i<f[p.second].size();i++){
			if(dis[(f[p.second][i]).first]>dis[p.second]+(f[p.second][i]).second){
				dis[(f[p.second][i]).first]=dis[p.second]+(f[p.second][i]).second;
				pq.push({dis[(f[p.second][i]).first],f[p.second][i].first});
			}
		}
	}
	
	vector<long long int> bdis(n+1);
	for(long long int i=0;i<=n;i++){
		if(i==n){
			bdis[n]=0;
		}
		else{
			bdis[i]=500000000000001;
		}
	}
	priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int> >,greater<pair<long long int,long long int> > > bpq;
	bpq.push({0,n});
	while(!bpq.empty()){
		p=bpq.top();
		bpq.pop();
		if(bdis[p.second]<p.first){
			continue;
		}
		for(long long int i=0;i<b[p.second].size();i++){
			if(bdis[(b[p.second][i]).first]>bdis[p.second]+(b[p.second][i]).second){
				bdis[(b[p.second][i]).first]=bdis[p.second]+(b[p.second][i]).second;
				bpq.push({bdis[(b[p.second][i]).first],b[p.second][i].first});
			}
		}
	}
	
	long long int ans=dis[n];
	for(long long int i=0;i<m;i++){
		long long int final=cost[i]-(ans-bdis[end[i]]-dis[start[i]]);
		if(ans-bdis[end[i]]-dis[start[i]]<0){
			cout<<"-1"<<'\n';
		}
		else{
			cout<<final<<'\n';
		}
	}
}
