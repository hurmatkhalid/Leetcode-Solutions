// Given an m x n binary matrix mat, return the number of special positions in mat.

// A position (i, j) is called special if mat[i][j] == 1 and all other elements 
// in row i and column j are 0 (rows and columns are 0-indexed).


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> row(rows, 0);
        vector<int> col(cols, 0);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j] && row[i]==1 && col[j]==1) count++;
            }
        }
        return count;
    }
};