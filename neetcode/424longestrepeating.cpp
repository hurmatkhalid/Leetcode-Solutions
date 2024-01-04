// You are given a string s and an integer k.
//  You can choose any character of the string and change 
// it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing
//  the same letter you can get after performing the above operations.

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int left = 0, right = 0;
        int maxf=0;
        int ans=0;
        for(right=0; right<s.size(); right++){
            mpp[s[right]]++;
            maxf = max(maxf, mpp[s[right]]);
            if((right-left+1-maxf)>k){
                mpp[s[left]]--;
                left++;
            }else{
                ans = max(ans, right-left+1);
            }
        }
        return ans;
    }
};