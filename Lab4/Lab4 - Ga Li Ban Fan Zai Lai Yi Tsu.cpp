#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	long long int n;
	cin>>n;
	vector<long long int> money(n);
	for(long long int i=0;i<n;i++){
		cin>>money[i];
	}
	long long int q;
	cin>>q;
	vector<long long int> temp(n+1);
	vector<long long int> target(q);
	vector<long long int> ans(q);
	long long int tmp=0;
	long long int m=0;
	for(long long int i=0;i<q;i++){
		for(long long int j=0;j<=n;j++){
			cin>>temp[j];
		}
		for(long long int j=0;j<n;j++){
			tmp+=temp[j+1]*money[j];
		}
		target[i]=tmp-temp[0];
		m=max(m,tmp-temp[0]);
		ans[i]=tmp-temp[0];
		temp.clear();
		tmp=0;
	}
	long long int a=m;
	vector<long long int> value(a+1,0);
	vector<long long int> v;
	sort(target.begin(),target.end());
	for(long long int i=0;i<n;i++){
		if(money[i]<=a){
			v.push_back(money[i]);
		}
	}
	for(long long int i=1;i<=a;i++){
		if(value[i]==0){
			value[i]=1+value[i-1];
			for(long long int j=0;j<v.size();j++){
				if(v[j]<=i){
					value[i]=min(value[i],value[i-v[j]]+1);	
				}
			}
		}
	}
	for(long long int i=0;i<q;i++){
		if(ans[i]==0){
			cout<<"0"<<'\n';
		}
		else{
			cout<<value[ans[i]]<<'\n';
		}
	}
	return 0;
}
