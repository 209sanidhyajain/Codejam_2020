#include<bits/stdc++.h>
using namespace std;

 int main()
{
    int x,temp;
	cin>>x;
	temp = x;
	while(x--){
		cout<<"Case #"<<temp-x<<": ";
		string s;
		string res="";
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(i==0){
				for(int j=0;j<s[i]-'0';j++){
					res+="(";
				}
				res+=s[i]; //verify = s[i]-'0';
			}
			else{
				int p = s[i]-s[i-1];
				if(p<0){
					for(int i=0;i<abs(p);i++){
						res+=")";
					}
					res+=s[i];
				}
				else{
					for(int i=0;i<p;i++){
						res+="(";
					}
					res+=s[i];
				}

			}
		}
		for(int i=0;i<s[s.length()-1]-'0';i++){
			res+=")";
		}
		cout<<res<<endl;
	}
}
