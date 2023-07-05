#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    string ans,s1;
    vector<string>v;
    cin>>n;
    while(n--){
    string input;
    cin>>input;
    v.push_back(input);
    }

    reverse(v.begin(),v.end());
 
    for(int i=0;i<v.size();i++){
        string s1= v[i];
        int size=s1.length();
         string s= v[i].substr(size-2,2) ;
        // cout<<s;

        size_t found = ans.find(s);
if (found == string::npos)
        // if(ans.find(s)==ans.end())
       {  ans+=s;}

    }
    cout<<ans;
	return 0;
}
