#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long long int n,m,s;
	cin>>n>>m>>s;
	vector<long long int>year(n);
	for(long long int i=0;i<n;i++){
		cin>>year[i];
	}
	sort(year.begin(),year.end());
	vector<long long int> begin(m);
	vector<long long int> end(m);
	vector<long long int> p(m);
	vector<long long int>::iterator result;
	long long int b,e;
	long long int total=n; 
	vector<long long int> game(m);
	for(long long int i=0;i<m;i++){
		cin>>begin[i]>>end[i]>>p[i];
	}
	for(long long int i=0;i<m;i++){
		if(year.front()<=begin[i]&&year.back()>=begin[i]){
			result=lower_bound(year.begin(),year.end(),begin[i]);
			b=result-year.begin();
		}
		else if(begin[i]<year.front()){
			b=0;
		}
		else if(begin[i]>year.back()){
			b=n-1;
		}
		if(end[i]>=year.front()&&end[i]<=year.back()){
			result=lower_bound(year.begin(),year.end(),end[i]);			
			if(*result==end[i]){
				e=result-year.begin();
			}
			else{
				e=result-year.begin()-1;
			}
		}
		else if(end[i]<year.front()){
			e=0;
		}
		else if(end[i]>year.back()){
			e=n-1;
		}
		if(b==0&&e==0&&end[i]<year.front()&&begin[i]<year.front()){
			game[i]=0;
			total=total;
		}
		else if(b==n-1&&e==n-1&&begin[i]>year.back()&&end[i]>year.back()){
			game[i]=0;
			total=total;
		}
		else{
			game[i]=e-b+1;
			total=total-game[i];
		}
	}
	vector<long long int> dp(s+1,0);	
	for(long long int i=0;i<m;i++){
		for(long long int j=s;j>=p[i];j--){
			dp[j]=max(dp[j],dp[j-p[i]]+game[i]);
		}
	}
	cout<<total+dp[s];
	return 0;
}
