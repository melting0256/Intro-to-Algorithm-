#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
	long long int n,k;
	cin>>n>>k;
	long double c[n],p[n];
	long double score;
	priority_queue<pair<long double,long long int> > pq;
	long double ans;
	pair<long double,long long int>tmp;
	double total=0.0;
	long long int count[n]={0};
	pair<long double,long long int> use;
	for(long long int i=0;i<n;i++){
		cin>>c[i]>>p[i];
		if(p[i]==0){
			use=make_pair(c[i],i);
			pq.push(use);
		}
		else if(p[i]!=0){
			score=(c[i]*p[i])/((p[i]+1)*(p[i]+1)-p[i]-1);
			use=make_pair(score,i);
			pq.push(use);
		}
	}
	tmp=pq.top();
	pq.pop();
	count[tmp.second]+=1;
	total+=tmp.first;
	for(long long int i=2;i<=k;i++){
		if(p[tmp.second]==0){
			use=make_pair(0,tmp.second);
			pq.push(use);
		}
		else{
			score=(c[tmp.second]*p[tmp.second])/((p[tmp.second]+count[tmp.second]+1)*(p[tmp.second]+count[tmp.second]+1)-p[tmp.second]-count[tmp.second]-1);
			use=make_pair(score,tmp.second);
			pq.push(use);
		}
		tmp=pq.top();
		total+=tmp.first;
		pq.pop();
		count[tmp.second]+=1;
//		cout<<"tmp:"<<tmp.first<<endl;
//		cout<<"total:"<<total<<endl;
	}
	cout<<fixed<<setprecision(10) <<total;
	return 0;
}
