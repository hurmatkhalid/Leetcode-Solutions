// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring
//  of s such that every character in t 
// (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

class Solution {
public:
    string minWindow(string s, string t) {
        if(t == ""){
            return "";
        }
        unordered_map<char, int>t_map;
        unordered_map<char, int>s_map;
        int ans_size = INT_MAX;
        vector <int>ans;
        for( auto it:t)     t_map[it]++;
        int s_count =0, t_count= t_map.size();
        int left=0;
        for(int right =0; right<s.size(); right++){
            s_map[s[right]]++;
            if(t_map.find(s[right])!=t_map.end() && s_map[s[right]]== t_map[s[right]]){
                s_count++;
            }
            while(s_count== t_count){
                if(right-left+1 <ans_size){
                    ans = {left, right};
                    ans_size= right - left +1;
                }
                s_map[s[left]]--;
                if(t_map.find(s[left])!= t_map.end() && s_map[s[left]]<t_map[s[left]]){
                    s_count--;
                }
                left++;
            }
        }
        return ans_size != INT_MAX ? s.substr(ans[0], ans[1]-ans[0]+1) : "";
    }
};