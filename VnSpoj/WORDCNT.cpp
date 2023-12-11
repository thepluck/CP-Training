/*
solved by hoaf13
00:53 AM
Friday
7/12/2019 
*/
#include<bits/stdc++.h>
 
#define pb push_back
#define faster() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
int T;
string s;
string x;
 
void init(){
	getline(cin ,s);
}
 
bool checkz(){
	for(int i=0;i<s.length();i++){
		if (s[i] != ' ') return false;
	}
	return true;
}
 
void process(){
	if(s.length() == 0 || checkz()){
		cout << 0 << endl;
		return;
	}
	int res = 1;
	int counter = 1;
	vector<string> ds;
	stringstream ss;
	ss << s;
	string tmp;
	while(ss >> tmp ){
		ds.pb(tmp);
	}
	for(int i=1;i<ds.size();i++){
		if (ds[i].length() == ds[i-1].length()){
			counter++;
			res = max(res,counter);
		}else{
			counter = 1 ;
		}
	}
	cout << res << endl;
}
 
int main(){
 
	faster();
 
	cin >> T;
	getline(cin,x);
	while(T--){
 
		init();
		process();
 
	}
	return 0;
}