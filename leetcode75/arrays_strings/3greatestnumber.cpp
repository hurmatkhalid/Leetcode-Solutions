// There are n kids with candies. You are given an integer 
// array candies, where each candies[i] represents the number 
// of candies the ith kid has, and an integer extraCandies, denoting 
// the number of extra candies that you have.
// Return a boolean array result of length n, where result[i] 
// is true if, after giving the ith kid all the extraCandies, 
// they will have the greatest number of candies among all the kids, or false otherwise.
// Note that multiple kids can have the greatest number of candies.

// naive
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> ans;
        int n = candies.size();
        int maximum = *max_element(candies.begin(), candies.end());
        for(int i=0; i<n; i++){
            if(candies[i]+extraCandies<maximum){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};
// or
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maximum = candies[0];
        int n = candies.size();
        for(int i =1; i<n; i++){
            maximum = max(maximum, candies[i]);
        }
        for(int i =0; i<n; i++){
            if(candies[i]+extraCandies < maximum)   ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};