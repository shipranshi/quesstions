
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n,x,O=0,A=0,B=0,AB=0;
	string y;
	cin>>n;
	while(n--){
		cin>>x;
		while(x--){
			cin>>y;
		

		if(y=="A"){
			A++;
		}
			if(y=="B"){
			B++;
		}
		
		if(y=="O"){
			O++;
		}
	if(y=="AB"){
			AB++;
		}
	}

	cout<<max(A,B)+AB+O<<endl;
	}
	return 0;
}
