#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string s){
    stack<char> st;
    for(int i=0 ;i<s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if(ch == ')' && st.top() == '('){
            st.pop();
        }
        else if(ch == '}' && st.top() == '{')
        st.pop();
        else if(ch == ']' && st.top() == '[')
        st.pop();
        else{
            return 0;
        }
    }
    return 1;
}

int main(){
    string s;
    cin>>s;
    
    cout<<validParenthesis(s)<<endl;
    
    return 0;
}
