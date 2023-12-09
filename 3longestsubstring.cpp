// Given a string s, find the length of the longest substring without repeating characters.

// naive approach o(n^2)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int count=0;
        for(int i = 0; i < n; i++){
            set<char>s1;
            int count1=0;
            for(int j = i; j < n; j++){
                if(s1.find(s[j])!=s1.end()){
                    break;
                }
                s1.insert(s[j]);
                count1++;
            }
            count = max(count, count1);
        } 
        return count;
    }
};

// better approach o(2n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int length=0;
        int l=0;
        set <char> s1;
        for(int r =0; r<n; r++){
            if(s1.find(s[r])!= s1.end()){
                while(l<r && s1.find(s[r])!=s1.end()){
                    s1.erase(s[l]);
                    l++;
                }
            }
            s1.insert(s[r]);
            length= max(length, r-l+1);
        }
        return length;
    }
};

// best approach o(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r=0;
        int length = 0;
        vector<int> mpp(256, -1);
        while(r<n){
            if(mpp[s[r]]!=-1){
                l = max(l, mpp[s[r]]+1);
            }
            mpp[s[r]]= r;
            length= max(length, r-l+1);
            r++;
        }
        return length;
    }
};