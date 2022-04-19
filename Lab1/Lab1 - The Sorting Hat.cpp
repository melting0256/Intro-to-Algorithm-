#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class student{  
	public:
		string name;
		int arr[4];//¤À¼Æ
		int house[4];   //¶¶§Ç
};

bool cmp(student a,student b){
	if(a.arr[a.house[0]]!=b.arr[b.house[0]]){
		return a.arr[a.house[0]]>b.arr[b.house[0]];
	}
	else{
		if(a.arr[a.house[1]]!=b.arr[b.house[1]]){
			return a.arr[a.house[1]]>b.arr[b.house[1]];
		}
		else{
			if(a.arr[a.house[2]]!=b.arr[b.house[2]]){
				return a.arr[a.house[2]]>b.arr[b.house[2]];
			}
			else{
				if(a.arr[a.house[3]]!=b.arr[b.house[3]]){
					return a.arr[a.house[3]]>b.arr[b.house[3]];
				}
				else{
					return a.name<b.name;
				}
			}
		}
	}
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	student st;
	char p1[4][4];
	int p[4][4];
	for(int i=0;i<4;i++){
		for(int t=0;t<4;t++){
			cin>>p1[i][t];
			if(p1[i][t]=='G'){
				p[i][t]=0;
			}
			else if(p1[i][t]=='H'){
				p[i][t]=1;
			}
			else if(p1[i][t]=='R'){
				p[i][t]=2;
			}
			else{
				p[i][t]=3;
			}
		}
	}
	vector<student> vg;
	vector<student> vh;
	vector<student> vr;
	vector<student> vs; 
	for(int i=0;i<n;i++){
		cin>>st.name>>st.arr[0]>>st.arr[1]>>st.arr[2]>>st.arr[3];
		int n=sizeof(st.arr)/sizeof(st.arr[0]);
		int target=*std::max_element(st.arr,st.arr+n);
		if(target==st.arr[0]){
			st.house[0]=p[0][0];
			st.house[1]=p[0][1];
			st.house[2]=p[0][2];
			st.house[3]=p[0][3];
			vg.push_back(st);
		}
		else if(target==st.arr[1]){
			st.house[0]=p[1][0];
			st.house[1]=p[1][1];
			st.house[2]=p[1][2];
			st.house[3]=p[1][3];
			vh.push_back(st);
		}
		else if(target==st.arr[2]){
			st.house[0]=p[2][0];
			st.house[1]=p[2][1];
			st.house[2]=p[2][2];
			st.house[3]=p[2][3];
			vr.push_back(st);
		}
		else{
		    st.house[0]=p[3][0];
			st.house[1]=p[3][1];
			st.house[2]=p[3][2];
			st.house[3]=p[3][3];
			vs.push_back(st);
		}
	}
	cout<<"GRYFFINDOR:"<<'\n';
	if(!vg.empty()){
		sort(vg.begin(),vg.end(),cmp);
		for(int i=0;i<vg.size();i++){
			cout<<vg[i].name<<'\n';
		}
	}
	else{
		cout<<"NO NEW STUDENTS"<<'\n';
	}
	cout<<"HUFFLEPUFF:"<<'\n';
	if(!vh.empty()){
		sort(vh.begin(),vh.end(),cmp);
		for(int i=0;i<vh.size();i++){
			cout<<vh[i].name<<'\n';
		}
	}
	else{
		cout<<"NO NEW STUDENTS"<<'\n';
	}
	cout<<"RAVENCLAW:"<<'\n';
	if(!vr.empty()){
		sort(vr.begin(),vr.end(),cmp);
		for(int i=0;i<vr.size();i++){
			cout<<vr[i].name<<'\n';
		}
	}
	else{
		cout<<"NO NEW STUDENTS"<<'\n';
	}
	cout<<"SLYTHERIN:"<<'\n';
	if(!vs.empty()){
		sort(vs.begin(),vs.end(),cmp);
		for(int i=0;i<vs.size();i++){
			cout<<vs[i].name<<'\n';
		}
	}
	else{
		cout<<"NO NEW STUDENTS"<<'\n';
	}
	return 0;
} 
