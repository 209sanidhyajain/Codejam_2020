#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
	int c;
	cin>>c;
	int temp = c;
	while(c--){
		cout<<"Case #"<<temp-c<<": ";
		int n;
		cin>>n;
		vector<pair<int,int>>q,qi;
		map<pair<int,int>,int>mp;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			q.push_back({x,y});
			qi.push_back({x,y});
			mp[{x,y}] = i;
		}
		sort(q.begin(),q.end());
		char arr[n];
		for(int i=0;i<n;i++){
			arr[i]='J';
		}
		arr[mp[{q[0].first,q[0].second}]]='J';
		int jmx=q[0].second,cmx=0,flag=0,f=0;
		for(int i=1;i<n;i++){
			if(q[i].first>=jmx){
				arr[mp[{q[i].first,q[i].second}]]='J';
				jmx = q[i].second;
			}
			else if(f==0){
				arr[mp[{q[i].first,q[i].second}]]='C';
				cmx = q[i].second;
				f++;
			}
			else if(q[i].first>=cmx){
				arr[mp[{q[i].first,q[i].second}]]='C';
				cmx = q[i].second;
			}
			else{
				flag++;
				break;
			}
		}
		if(flag!=0){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			for(int i=0;i<n;i++)cout<<arr[i];
			cout<<endl;
		}
	}
}
