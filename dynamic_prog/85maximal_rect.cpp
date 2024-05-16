// Given a rows x cols binary matrix filled with 0's and 1's, 
// find the largest rectangle containing only 1's and return its area.


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int size= matrix[0].size();
        vector<int>heights(size, 0);
        int maxArea=0;
        for(auto& row: matrix){
            for(int i =0; i<size; i++){
                if(row[i]=='1'){
                    heights[i]++;
                }
                else{
                    heights[i]=0;
                }
            }
            maxArea= max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>&heights){
        int result=0;
        int n= heights.size();
        vector<int>left(n,-1);
        vector<int>right(n, n);
        stack<int>stk;
        for(int i=0; i<n; i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                right[stk.top()]=i;
                stk.pop();
            }
            if(stk.empty()){
                left[i]=-1;
            }
            else{
                left[i]= stk.top();
            }
            stk.push(i);
        }
        for(int i=0; i<n; i++){
            result = max(result, heights[i]*(right[i]-left[i]-1));
        }
        return result;
    }
};