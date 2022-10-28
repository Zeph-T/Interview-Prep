// #include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<char> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	string ans="";
	int i=0;
	while(v[i]!='S')i++;
	v[i]='_';
	for(i;i<n;i++){
	    if(v[i]=='D') break;
	    if(v[i]=='_') {
    	    if(v[i+1]=='*') ans+='J';
    	    else ans+='W';
	    }
	}
	cout<<ans;
	return 0;
}