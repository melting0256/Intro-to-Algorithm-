#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
	long long int n,c,p;
	cin>>n>>c>>p;
	long long int k;
	long long int arr[p];
	vector<long long int> num;
	vector<vector<long long int> > order(n,num);	//�Ʀr�barr��index 
	vector<long long int> time(n,0);	//�C�ӼƦr�U���X���F 
	vector<int> flag(n,0);	//�����O�_�bcore�� 
	long long int size;
	long long int ans=0;
	map<long long int,long long int> incore;	//key�O�barr��index,value�O�Ʀr 
	map<long long int,long long int>::iterator it;
	long long int change;
	long long int count=p;
	for(int i=0;i<p;i++){
		cin>>k;
		arr[i]=k;
		order[k-1].push_back(i);
	}
	size=0;
	for(int i=0;i<p;i++){
		if(flag[arr[i]-1]==0){
			flag[arr[i]-1]=1;
			if(size<c){
				size+=1;
				time[arr[i]-1]+=1;
				if(order[arr[i]-1].size()==time[arr[i]-1]){
					incore[count]=arr[i];
					count+=1;
				}
				else{
					incore[order[arr[i]-1][time[arr[i]-1]]]=arr[i];
				}
				ans+=1;
			}
			else if(size==c){
				it=--incore.end();
				change=(*it).second;
				flag[change-1]=0;
				time[arr[i]-1]+=1;
				incore.erase(it);
				ans+=1;
				if(order[arr[i]-1].size()==time[arr[i]-1]){
					incore[count]=arr[i];
					count+=1;
				}
				else{
					incore[order[arr[i]-1][time[arr[i]-1]]]=arr[i];
				}
			}
		}
		else{
			time[arr[i]-1]+=1;
			if(order[arr[i]-1].size()==time[arr[i]-1]){
				incore[count]=arr[i];
				count+=1;
			}
			else{
				incore[order[arr[i]-1][time[arr[i]-1]]]=arr[i];
			}
		}
//		for(int w=0;w<n;w++){
//		}
//		cout<<"ans:"<<ans<<endl;
//		cout<<"-------"<<endl;
	}
	cout<<ans;
	
}
