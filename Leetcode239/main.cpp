// This program is used in sliding window maximum
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
      
       vector<int>result;
       deque<int>ans;

       for(int i=0; i<nums.size(); i++){
         ans.push_back(nums[i]);

        if(ans.size() == k ){
            int maximum = -100000;
            for(int i =0; i<ans.size(); i++){
                if(ans[i] > maximum){
                    maximum = ans[i];
                }
            } 
         result.push_back(maximum);
         ans.pop_front();
        }
       }
       return result;
}

int main(){
     vector<int> nums{-1, -3, -1, -3, -5, -3, -6,-7};

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }   
    cout << endl;

    vector<int> ans = maxSlidingWindow(nums, 3);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    } 

    return 0;
}