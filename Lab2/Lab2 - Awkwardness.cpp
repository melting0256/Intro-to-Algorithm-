#include<iostream>
#include<vector>
using namespace std;
vector<int> in;
vector<int> post;
vector<int> address;
vector<int> arr;
vector<int> num;
int n;
int build(int ins,int ine,int posts,int poste){
	int ans=0;
		int root=post[poste];
	    int position;
	    position=address[root]-1;
	    //cout<<"address:"<<address[root];
	    int llen=position-ins;
	    int rlen=ine-position;
	    //cout<<"llen:"<<llen <<endl<<"rlen"<<rlen<<endl<<"position:"<<position<<endl;
	    if(poste<=posts||ine<=ins){
	    	return ans;
		}
		if(rlen){
			if(arr[root-1]<arr[post[posts+llen+rlen-1]-1]){
	    	    ans+=1;
		    }
		}
		if(llen){
			if(arr[root-1]<arr[post[posts+llen-1]-1]){
			    ans+=1;
		    }
		}	
			
		if(llen){
			ans+=build(ins,ins+llen-1,posts,posts+llen-1);
		}
		if(rlen){
			ans+=build(position+1,ine,posts+llen,posts+llen+rlen-1);
		}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	post.resize(n);
	in.resize(n);
	arr.resize(n);
	address.resize(n+1);
	num.resize(n);
	address[0]=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	for(int i=0;i<n;i++){
		cin>>in[i];
		num[i]=i+1;
	}
	for(int i=0;i<n;i++){
		cin>>post[i];
	}
	for(int i=0;i<n;i++){
		address[in[i]]=num[i];
	}
	cout<<build(0,n-1,0,n-1);
	return 0;
}
