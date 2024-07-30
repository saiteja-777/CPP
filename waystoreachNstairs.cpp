#include<bits/stdc++.h>
using namespace std;

void findWays(int ind, vector<int>& ds, vector<vector<int>>& ans){
    //base casee
    if(ind==0){
        ans.push_back(ds);
        return;
    }
    
    ds.push_back(1);
    findWays(ind-1, ds, ans);
    ds.pop_back();
    if(ind>1){
        ds.push_back(2);
        findWays(ind-2, ds, ans);
        ds.pop_back();
    }
}

int countWays(int ind, int count){
    if(ind == 0)
    return ++count;
    
    count = countWays(ind-1, count);
    if(ind>1)
    count+= countWays(ind-2, count);
}

int main(){
    int n;
    cin>>n;
    
    vector<int> ds;
    vector<vector<int>> ans;
    
    findWays(n, ds, ans);
    
    cout<<countWays(n, 0)<<endl;
    
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
