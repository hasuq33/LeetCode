#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

long long maximumHappinessSum(vector<int>&happiness, int k){
    ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0);
    sort(begin(happiness), end(happiness), greater<int>());
    int i = 0;
    long long res = 0;

    while(k--){
        happiness[i] = max(happiness[i] - i, 0);
        res += happiness[i++];
    }

    return res;
}

int main(){
    maximumHappinessSum(vector<int>{1,2,3},2);
}