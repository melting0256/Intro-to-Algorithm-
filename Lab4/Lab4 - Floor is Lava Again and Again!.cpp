#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	vector<vector<long long int> > num(t);
	vector<long long int> temp(n);
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
			cin>>temp[j];
		}
		num[i]=temp;
	}
	vector<long long int> dp(n);
	for(long long int i=t-2;i>=0;i--){
		for(long long int j=0;j<n;j++){
			if(n!=1){
				if(j!=0&&j!=n-1){
					dp[j]=num[i+1][j];
					dp[j]=max(dp[j],num[i+1][j+1]);
					dp[j]=max(dp[j],num[i+1][j-1]);
					num[i][j]=dp[j]+num[i][j];
				}
				else if(j==0){
					dp[0]=num[i+1][0];
					dp[0]=max(dp[0],num[i+1][j+1]);
					num[i][j]=dp[j]+num[i][j];
				}
				else if(j==n-1){
					dp[n-1]=num[i+1][n-1];
					dp[n-1]=max(dp[n-1],num[i+1][j-1]);
					num[i][j]=dp[j]+num[i][j];
				}
			}
			else{
				num[i][0]=num[i][0]+num[i+1][0];
			}
			
		}
	}
	for(long long int i=0;i<n;i++){
		cout<<num[0][i]<<" ";
	}
	return 0;
}
