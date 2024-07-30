#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int i=n;
	int cnt=1;
	while(i>0){
		int space = n-i;
		while(space){
			cout<<" "<<" ";
			space--;
		}
		int j=1;
		while(j<=i){
			cout<<cnt<<" ";
			cnt++;
			j++;
		}
		cout<<endl;
		i--;
		cnt = n-i+1;
	}
	
	return 0;
}
