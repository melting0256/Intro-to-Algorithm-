#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long int cal(long long int a,long long int n,long long int b)
{
    long long int t;
    if(n==0){
    	return 1%b;
	}
    if(n==1){
    	return a%b;
	} 
    t=cal(a,n/2,b);
    t=t*t%b;
    if((n&1)==1) {
    	t=t*a%b;
	}
    return t;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long int a,b,n,num,tmp1,tmp2,tmp3,ans;
	cin>>a>>b>>n; 
	for(long long int i=0;i<n;i++){
		cin>>num;
		tmp3=cal(a,num-1,1000000007);
		tmp1=tmp3%1000000007;
		tmp2=b/(1-a)%1000000007;
		ans=(tmp1*(1-tmp2)+tmp2)%1000000007;
		if(ans<0){
			cout<<ans+1000000007<<'\n';
		}
		else{
			cout<<ans<<'\n';
		}
	}
	return 0;
}
