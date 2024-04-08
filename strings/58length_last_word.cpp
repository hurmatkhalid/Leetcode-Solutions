// Given a string s consisting of words 
// and spaces, return the length of the last word in the string.

// A word is a maximal substring
//  consisting of non-space characters only.


class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int count=0;
        for(int i =0; i<s.size(); i++){
            if(s[i]==' '){
                if(count){
                    ans=count;
                }
                count=0;
                continue;
            }
            count++;
        }
        if (count) {
            ans = count;
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i =0, j= s.size()-1;
        while(j>=0 && s[j]==' ')    j--;
        while(j>=0 && s[j]!= ' '){
            j--;
            i++;
        }
        return i;
    }
};