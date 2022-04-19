#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int> line;
vector<vector<long long int> > adj;
vector<long long int> num;
vector<int> visit;

void dfs(long long int a){
	visit[a]=1;
	for(long long int j=0;j<adj[a].size();j++){
		if(visit[adj[a][j]]==0){
			dfs(adj[a][j]);
			num[a]+=num[adj[a][j]];
		}
	}
	num[a]+=1;
}

struct edge{
	long long int x,y;
	long long int c;
};

bool cmp(edge x,edge y){
	return x.c<y.c;
}


long long int find(long long int a){
	if(line[a]==a){
		return a;
	}
	else{
		line[a]=find(line[a]);
		return line[a];
	}
}


int main(){
	long long int n,m;
	cin>>n>>m;
	line.resize(n+1);
	adj.resize(n+1);
	num.resize(n+1,0);
	visit.resize(n+1,0);
	for(long long int i=0;i<=n;i++){
		line[i]=i;
	}
	long long int todo=n-1;
	long long int ans=0;
	long long int x,y,c;
	vector<edge> v(m);
	for(long long int i=0;i<m;i++){
		cin>>v[i].x>>v[i].y>>v[i].c;
	}
	sort(v.begin(),v.end(),cmp);
	vector<edge> choose;
	vector<long long int> count(n+1,0);
	vector<long long int> cal(n+1,0);
	for(long long int i=0;i<m;i++){
		x=find(v[i].x);
		y=find(v[i].y);
		if(x==y){
			continue;
		}
		else{
			line[y]=x;
			todo=todo-1;
			ans+=v[i].c;
			ans=ans%1000000007;
		}
		choose.push_back({v[i].x,v[i].y,v[i].c});
		adj[v[i].x].push_back(v[i].y);
		adj[v[i].y].push_back(v[i].x);
	}
	long long int ans2=0;
	if(todo==0){
		dfs(1);
		for(long long int i=0;i<choose.size();i++){
			long long int r=min(num[choose[i].x],num[choose[i].y]);
			long long int tmp=(((r*(n-r))%1000000007)*choose[i].c)%1000000007;
			ans2+=tmp;
			ans2%=1000000007;
		}
	}
	if(todo==0){
		ans%=1000000007;
		ans2%=1000000007;	
		ans=(2*ans)%1000000007;
		ans2=(2*ans2)%1000000007;
		cout<<ans<<" ";
		cout<<ans2;
	}
	else{
		cout<<"-1";
	}
	return 0;
}
