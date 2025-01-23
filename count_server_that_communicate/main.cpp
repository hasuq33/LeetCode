#include<iostream>
#include<vector>
using namespace std;

int countServers(vector<vector<int>>& grid){
     int servers = 0;

    // Store row and column counts for servers
    vector<int> row_count(grid.size(),0);
    vector<int> col_count(grid[0].size(),0);

    // First pass: Count servers in each row and column
    for(int i=0; i < grid.size(); i++){
        for(int j=0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                row_count[i]++;
                col_count[j]++;
            }
        }
    }

    // Second pass: Check if a server can communicate
    for(int i=0; i < grid.size(); i++){
        for(int j=0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
                if(row_count[i] > 1 || col_count[j] > 1){
                    servers++;
                }
            }
        }
    }

    return servers; 
}

int main(){
    vector<vector<int>> server{{1,0},{1,1}};
    cout << countServers(server);
}