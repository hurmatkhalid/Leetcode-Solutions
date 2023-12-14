// You are given a 0-indexed m x n binary matrix grid.

// A 0-indexed m x n difference matrix diff is created with the following procedure:

// Let the number of ones in the ith row be onesRowi.
// Let the number of ones in the jth column be onesColj.
// Let the number of zeros in the ith row be zerosRowi.
// Let the number of zeros in the jth column be zerosColj.
// diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
// Return the difference matrix diff.


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();
        vector<int> onesRow(rows, 0);
        vector<int>onesCol(cols, 0);
        vector<int>zerosRow(rows, 0);
        vector<int>zerosCol(cols, 0);
        vector<vector<int>>diff;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==0)   zerosRow[i]++, zerosCol[j]++;
                else    onesRow[i]++, onesCol[j]++;  
            }
        }
        for(int i=0; i<rows; i++){
            vector<int>temp;
            for(int j=0; j<cols; j++){
                int element=onesRow[i] + onesCol[j]-zerosRow[i]-zerosCol[j];
                temp.push_back(element);
            }
            diff.push_back(temp);
        }
        return diff;
    }
};