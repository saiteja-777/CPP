#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int n){
	set<int> s;
	for(int i=1; i<=n+1; i++){
		s.insert(i);
	}
	
	for(int i=0; i<n; i++){
		s.erase(arr[i]);
	}
	
	int ans = *(s.begin());
	cout<<ans<<endl;
	return ans;
}
int main(){
	
	vector<int> arr;
	int n;
	cout<<"Enter n value:";
	cin>>n;
	
	cout<<"Enter array values: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	cout<<"smallest missing value of given array: "<<missingNumber(arr, n)<<endl;
	
	return 0;
}
