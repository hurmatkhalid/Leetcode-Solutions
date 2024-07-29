// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. 
// The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces 
// or multiple spaces between two words. The returned 
// string should only have a single space 
// separating the words. Do not include any extra spaces.

// naive
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int end= s.size()-1;
        while(end>=0){
            while(end >=0 && s[end]==' '){
                end--;
            }        
            if(end<0)   break;
            int start= end;
            while(start>=0 && s[start] !=' '){
                start--;
            }
            if(!ans.empty())    ans.push_back(' ');
            ans.append(s.substr(start+1, end-start));
            end = start-1;
        }
        return ans;
    }
};

// better
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int i =0;
        int left=0, right=0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n)    break;
            while(i<n && s[i]!= ' '){
                s[right++]= s[i++];
            }
            reverse(s.begin() +left, s.begin()+right);
            s[right++]=' ';
            left = right;
            i++;
        }
        s.resize(right -1);
        return s;
    }
};