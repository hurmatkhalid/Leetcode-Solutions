// Given two strings s and t, 
// determine if they are isomorphic.
// Two strings s and t are isomorphic
//  if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with 
// another character while preserving the order of characters.
//  No two characters may map to the same character, but a character may map to itself.


// naive
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>mpp;
        set<char>s1;
        if(s.size()!=t.size())  return false;
        for(int i = 0; i<s.size(); i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]!=t[i])   return false;
            }
            else{
                if(s1.find(t[i])!=s1.end()) return false;
                s1.insert(t[i]);
                mpp[s[i]]=t[i];
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_arr[256]={0};
        bool t_arr[256]={0};
        for(int i =0; i<s.size(); i++){
            if(s_arr[s[i]]==0 && t_arr[t[i]]==0){
                s_arr[s[i]]=t[i];
                t_arr[t[i]]=true;
            }
        }
        for(int i =0; i<s.size(); i++){
            if(char(s_arr[s[i]])!=t[i]) return false;
        }
        return true;
    }
};