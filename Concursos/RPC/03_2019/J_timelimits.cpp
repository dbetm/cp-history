#include<bits/stdc++.h>
using namespace std; 
int main(){
	
	double n,s;
	cin>>n>>s;
	double max = 0;  
	double t; 
	while(n--){
		cin>>t; 
		max = t>max? t:max; 
	}
	
	
	
		double r = s*max/1000; 
		
		if(r-(int)r >0) r = r+1; 
		
		cout<<(int)r<<endl;
	
	
	return 0; 
}
