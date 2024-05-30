#include<iostream>
#include<vector>
using namespace std;

int countTriplets(vector<int>& arr){
    int count = 0;

    for(int i=0;i<arr.size();i++){
        int val = arr[i];

        for(int k = i+1; k < arr.size(); k++){
            val^= arr[k];
            if(val == 0){
                count+= (k-i);
            }
        }
    }

    return count;
}

int main(){
    vector<int> nums{2,3,1,6,7};
    cout << countTriplets(nums);
}