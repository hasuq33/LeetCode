#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(const string &sub){
    int left = 0, right = sub.length()-1;
    while(left < right){
        if(sub[left] != sub[right]){
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

void backtrack(const string&s, int start, vector<string>& path, vector<vector<string>>&res){
    if(start == s.length()){
        res.push_back(path);
        return;
    }

    for(int end = start+1; end <= s.length(); end++){
        string currentSob =  s.substr(start, end - start);
        if(isPalindrome(currentSob)){
            path.push_back(currentSob);
            backtrack(s, end, path, res);
            path.pop_back();
        }

    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    backtrack(s, 0, path, res);
    return res;
}


int main(){
   vector<vector<string>> n = partition("aab");
   for(int i = 0; i < n.size(); i++){
    for(int j =0; j < n.size(); j++){
        cout<<n[i][j]<<"";
    }
    cout<<endl;
   }
}