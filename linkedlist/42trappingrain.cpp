// Given n non-negative integers representing an
//  elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.


// brute force
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int answer=0;
        for(int i=0; i<n; i++){
            int j =i;
            int leftMax=0, rightmax=0;
            while(j>=0){
                leftMax= max(leftMax, height[j]);
                j--;
            }
            j=i;
            while(j<n){
                rightmax= max(rightmax, height[j]);
                j++;
            }
            answer += min(rightmax, leftMax)- height[i];
        }
        return answer;
    }
};

// better
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left =0, right = n-1;
        int ans=0;
        int maxLeft = 0, maxRight = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>= maxLeft){
                    maxLeft = height[left];
                }else{
                    ans += maxLeft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>= maxRight){
                    maxRight = height[right];
                }else{
                    ans += maxRight - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};