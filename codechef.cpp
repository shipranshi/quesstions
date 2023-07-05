#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
  	while(t--){
	    int n;
	    cin>>n;
	   int size=n;
	    int good=0;
	    vector<int>v;
	    int r=0,l=0,result=0,count=0;
	    
	    while(n--){
	    int x;
	    cin>>x;
	    v.push_back(x%2);
	    }
	    
	    while(r<n){
	        result += v[r];
	        if(result%2==0){
	            count += r-l+1;
	        while(l==1){
	        l++;}
	        }
	            
	        
	        r++;
	    }
	    
	   count+=n+1-l;
	    cout<<count;
	   // for(auto it:v){
	   //     cout<<it;
	   // }
	    
	    
	    
	    
	    good=pow(2,size)-count;
	   // good=good-count;
	        cout<<good<<endl;
	    
	}
	
	return 0;
}
