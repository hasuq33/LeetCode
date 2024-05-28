#include<iostream>
#include<string>
using namespace std;

int equalSubstring(string s, string t, int maxCost){
    int ans =0, window=0, left =0;

    for(int right=0; right<s.size() ; right++){
        window += abs(s[right] - t[right]);
        while ( window > maxCost)
        {
            window -= abs(s[left] - t[left]);
            left++;
        }

        ans = max(ans, right -left+1);
    }
    return ans;
}

int main(){
    string s = "abcd";
    string t ="bcdf";
   cout << equalSubstring(s,t,3);
}