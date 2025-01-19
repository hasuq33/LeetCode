#include<iostream>
#include<vector>
using namespace std;

 vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> answer(matrix[0].size(), vector<int>(matrix.size(), 0));
        int size = matrix.size();
        for(int i=0; i < size; i++) {
            for(int j=0; j < matrix[0].size();j++){
                answer[j][i] = matrix[i][j];
            }
        }

        return answer;
}

int main(){
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};

}