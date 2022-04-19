#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
vector<long long int> order;

long long int find(long long int n){
	if(order[n]==n){
		return n;
	}
	else{
		order[n]=find(order[n]);
		return order[n];
	} 
}

int main(){
	long long int n,m,q;
	cin>>n>>m>>q;
	long long int a,b;
	order.resize(n);
	set<pair<long long int,long long int> > s; 
	for(long long int i=0;i<n;i++){
		order[i]=i;
	}
	for(long long int i=0;i<m;i++){
		cin>>a>>b;
		s.insert(make_pair(a,b));
	}
	vector<long long int> aa(q);
	vector<long long int> bb(q);
	vector<char> cha(q);
	set<pair<long long int,long long int> >f;
	for(long long int i=0;i<q;i++){
		cin>>cha[i]>>aa[i]>>bb[i];
		if(cha[i]=='U'){
			f.insert(make_pair(aa[i],bb[i]));
			f.insert(make_pair(bb[i],aa[i]));
		}
	}
	set<pair<long long int,long long int> >::iterator it;
	set<pair<long long int,long long int> >::iterator it1;
	for(it=f.begin();it!=f.end();it++){
		it1=s.find(*it);
		s.erase(*it1);
	}
	for(it=s.begin();it!=s.end();it++){
		order[find((*it).first)]=find((*it).second);
	}
	vector<string> ans;
	for(long long int i=q-1;i>=0;i--){
		if(cha[i]=='A'){
			if(find(aa[i])==find(bb[i])){
				ans.push_back("YES");
			}
			else{
				ans.push_back("NO");
			}
		}
		else if(cha[i]=='U'){
			order[find(aa[i])]=find(bb[i]);
		}
	}
	for(long long int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
