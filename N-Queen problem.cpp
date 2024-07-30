//N-Queen problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
	private:
		bool isSafe(int row, int col, vector<string>& board, int n){
			int duprow = row;
			int dupcol = col;
			
			//check left upper diagonal
			while(row>=0 && col>=0){
				if(board[row][col]=='Q')
				return false;
				
				row--;
				col--;
			}
			
			row = duprow;
			col = dupcol;
			
			//check left column
			while(col>=0){
				if(board[row][col]=='Q')
				return false;
				
				col--;
			}
			
			col = dupcol;
			
			//check left lower diagonal
			while(row<n && col>=0){
				if(board[row][col]=='Q')
				return false;
				
				row++;
				col--;
			}
			return true;
		}
		void solve(int col, vector<string>& board, vector<vector<string> >& ans, int n){
			//base case
			if(col == n){
				ans.push_back(board);
				return;
			}
			
			for(int row=0; row<n; row++){
				if(isSafe(row, col, board, n)){
					board[row][col]='Q';
					solve(col+1, board, ans, n);
					board[row][col]= '.';
				}
			}
		}
	public:
		vector<vector<string> > solveNqueen(int n){
			vector<vector<string> > ans;
			vector<string> board(n);
			string s(n, '.');
			for(int i=0; i<n; i++){
				board[i] = s;
			}
			solve(0, board, ans, n);
			return ans;
		}
};

int main(){
	int n;
	cin>> n;
	
	Solution obj;
	vector<vector<string> > ans = obj.solveNqueen(n);
	
	for(int i=0; i<ans.size(); i++){
		cout<<"Arrangement "<<i+1<<endl;
		for(int j=0; j<ans[i].size(); j++){
			cout<<ans[i][j];
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
