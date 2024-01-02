// Given an array of strings strs, group the anagrams together.
//  You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the 
// letters of a different word or phrase, typically using all the original letters exactly once.

// basic logic  70ms, 26.8MB
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>>mpp;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++){
            vector<int>ch(26,0);
            for(int j=0; j<strs[i].size(); j++){
                ch[strs[i][j]- 'a']++;
            }
            mpp[ch].push_back(strs[i]);
        }
        for(auto it=mpp.begin();it!=mpp.end(); it++)    ans.push_back(it->second);
        return ans;
    }
};

// better 58ms, 21mb
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mpp[s].push_back(strs[i]);
        }
        for(auto it:mpp)    ans.push_back(it.second);
        return ans;
    }
};