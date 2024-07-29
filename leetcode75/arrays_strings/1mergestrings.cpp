// You are given two strings word1 and word2. 
// Merge the strings by adding letters in alternating order, 
// starting with word1. If a string is longer than the other, 
// append the additional letters onto the end of the merged string.
// Return the merged string.

// naive
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int p1 = 0, p2=0;
        bool flag = true;
        int s1= word1.size();
        int s2= word2.size();
        while(p1<s1 && p2<s2){
            if(flag){
                ans.append(1, word1[p1]);
                p1++;
                flag=false;
            }
            else{
                ans.append(1, word2[p2]);
                p2++;
                flag = true;
            }
        }
        if(p1<s1)   ans.append(word1.substr(p1));
        if(p2<s2)   ans.append(word2.substr(p2));
        return ans;
    }
};

// better
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int p1 = 0, p2=0;
        int s1= word1.size();
        int s2= word2.size();
        while(p1<s1 || p2<s2){
            if(p1<s1){
                ans.push_back(word1[p1++]);
            }
            if(p2<s2){
                ans.push_back(word2[p2++]);
            }
        }
        return ans;
    }
};