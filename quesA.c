#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,temp;
	cin>>x;
	temp = x;
	while(x--){
		cout<<"Case #"<<temp-x<<": ";
		int n;
		cin>>n;
		int arr[n][n],trace=0,r=0,c=0;
		for(int i=0;i<n;i++)
		{
		    set<int>st;
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
				if(i==j)
				{
					trace+=arr[i][j];
				}
				st.insert(arr[i][j]);
			}
			if(st.size()<n)r++;
		}
		for(int i=0;i<n;i++)
		{
			set<int>st;
			for(int j=0;j<n;j++)
			{
				st.insert(arr[j][i]);
			}
			if(st.size()<n)c++;
		}
		cout<<trace<<" "<<r<<" "<<c<<endl;
	}
}
