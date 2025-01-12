#include<iostream>
using namespace std;
#include<stack>


 bool canBeValid(string s, string locked) {
        int n = s.length(); 
        if(n%2 !=0){
             return false;
        }
        stack<int> openIndices;
        stack<int> unlockedIndices;

        for(int i=0; i < n; i++){
            if(locked[i] == '0'){
                unlockedIndices.push(i); 
            }else if(s[i]=='('){
                openIndices.push(i); 
            }else if(s[i]==')'){
                if(!openIndices.empty()){
                    openIndices.pop(); 
                }else if(!unlockedIndices.empty()){
                    unlockedIndices.pop();
                }else{
                    return false;
                }
            }
        }

        while(!openIndices.empty() && !unlockedIndices.empty() && openIndices.top() < unlockedIndices.top()){
            openIndices.pop(); 
            unlockedIndices.pop();
        }

        if(openIndices.empty() && !unlockedIndices.empty()){
            return unlockedIndices.size() %2 ==0;
        }
        return openIndices.empty();
}


int main(){
    string s = "))()))"; 
    string locked = "010100";
   cout << canBeValid(s , locked);
}