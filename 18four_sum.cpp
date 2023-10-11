//Given an array nums of n integers, return an array of all the unique 
//quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//0 <= a, b, c, d < n
//a, b, c, and d are distinct.
//nums[a] + nums[b] + nums[c] + nums[d] == target
//You may return the answer in any order.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// brute force
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        set <vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        long long sum = nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target){
                            vector <int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            ans.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> v1(ans.begin(), ans.end());
        return v1;
    }
};

// better approach
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        set<vector<int>>s1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                set<long long>hashset;
                for(int k=j+1; k<n;k++){
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth)!= hashset.end()){
                        vector<int>temp={nums[i],nums[j], nums[k], int(fourth)};
                        sort(temp.begin(), temp.end());
                        s1.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(s1.begin(), s1.end());
        return ans;
    }
};
//best
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        for(int i=0; i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n;j++){
                if(j!= (i+1) && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l= n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum==target){
                        vector<int> temp= {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]== nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};


int main()
{
    return 0;
}