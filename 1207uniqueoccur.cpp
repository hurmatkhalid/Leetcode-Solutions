// Given an array of integers arr, return true if the number 
// of occurrences of each value in the array is unique or false otherwise.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int, int> mpp;
        set <int> s1;
        for(int i=0; i<arr.size(); i++) mpp[arr[i]]++;
        for(auto it: mpp) s1.insert(it.second);
        return(mpp.size()==s1.size());
    }
};