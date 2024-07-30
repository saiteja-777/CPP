#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > subsequence(int ind, int n, int sum, int arr[], vector<int>& ds, vector<vector<int> >& ans, int currsum){
	//base case
	if(currsum == sum){
		ans.push_back(ds);
		return ans;
	}
	
	if(currsum > sum) return ans;
	
	if(ind == n) return ans;
	
	ds.push_back(arr[ind]);
	subsequence(ind+1, n, sum, arr, ds, ans, currsum+arr[ind]);	
	ds.pop_back();
	subsequence(ind+1, n, sum, arr, ds, ans, currsum);
	return ans;
}

int main(){
	int arr[] = {2,1,3,8,10,6};
	int n = 6;
	int sum = 11;
	
	vector<int> ds;
	vector<vector<int> > ans; 
	subsequence(0, n, sum, arr, ds, ans, 0);
	
	for(int i=0; i<ans.size(); i++){
		vector<int> sub = ans[i];
		for(int j=0; j<sub.size(); j++){
			cout<<sub[j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
