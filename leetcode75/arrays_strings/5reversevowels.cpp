// Given a string s, reverse only all the
//  vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u',
// and they can appear in both lower and upper cases, more than once.

class Solution {
public:
    string reverseVowels(string s) {
        int start=0;
        int end = s.size()-1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(start<end){
            while(start<end && vowels.find(s[start])==vowels.end()){
                start++;
            }
            while(start<end && vowels.find(s[end])== vowels.end()){
                end--;
            }
            char temp = s[start];
            s[start]= s[end];
            s[end]= temp;

            start++;
            end--;
        }
        return s;
    }
};