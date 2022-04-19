#include<iostream>
#include<set>
#define mod 1000000007
using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long int c,num;
	multiset<long long int> s;
	cin>>c;
	for(long long int i=0;i<c;i++){
		cin>>num;
		s.insert(num);
	}
	long long int ans=1;
	long long int position=0;
	for(multiset<long long int >::iterator it=s.begin();it!=s.end();it++){
		if (c<*it){
			ans=(ans*(c-position)) % mod;
		}
		else{
			ans=(ans*(*it-position)) % mod;
		}
		position++;
	}
	cout<<ans;
	return 0;
}
