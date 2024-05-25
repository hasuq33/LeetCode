#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

vector<string> wordBreakHelper(const string& s, int start, const unordered_set<string>& dict) {
     vector<string> validSubstr;
        
        if (start == s.length())
            validSubstr.push_back("");
        for (int end = start + 1; end <= s.length(); ++end) {
            string prefix = s.substr(start, end - start);
            if (dict.find(prefix) != dict.end()) {
                vector<string> suffixes = wordBreakHelper(s, end, dict);
                for (const string& suffix : suffixes) {
                    validSubstr.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }
        return validSubstr;
}


vector<string> wordBreak(string s, vector<string>& wordDict){
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, 0, dict);
}



int main(){
    string s = "catsanddog";
    vector<string> worDict{"cat","cats","and","sand","dog"};
   vector<string> num= wordBreak(s, worDict);
   for(int i=0; i<num.size();i++){
    cout<< num[i]<<endl;
   }
}
