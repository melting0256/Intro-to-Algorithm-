#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	long long int t;
	cin>>t;
	long long int n;
	vector<long long int> v(10000000,0);
	vector<long long int> ans(10000000,0);
	v[1]=0;
	v[2]=2;
	v[3]=5;
	ans[1]=1;
	ans[2]=9;
	ans[3]=21;
	for(long long int i=4;i<=10000000;i++){
			v[i]=(v[i-1]+2*(v[i-2]+1)+1+v[i-3]);
			v[i]=v[i]%1000000007;
			ans[i]=v[i]*4%1000000007+1;
	}
	for(long long int i=0;i<t;i++){
		cin>>n;
		cout<<ans[n]<<'\n';
	} 
}
