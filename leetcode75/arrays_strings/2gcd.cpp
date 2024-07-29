// For two strings s and t, we say "t divides s" 
// if and only if s = t + t + t + ... + t + t 
// (i.e., t is concatenated with itself one or more times).
// Given two strings str1 and str2, return the largest string 
// x such that x divides both str1 and str2.

// naivee
class Solution {
public:
    bool gcd(string str1, string str2, string ans){
        int n = ans.size();
        int size1= str1.size();
        int size2 = str2.size();
        int temp = size1/n;
        string temp_ans="";
        while(temp){
            temp_ans = temp_ans.append(ans);
            temp--;
        }
        if(temp_ans != str1)    return false;
        temp = size2/n;
        temp_ans="";
        while(temp){
            temp_ans = temp_ans.append(ans);
            temp--;
        }
        if(temp_ans != str2)    return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int size1= str1.size();
        int size2 = str2.size();
        int min_size = min(size1, size2);

        string ans = min(str1, str2);

        while(min_size){
            if(size1%min_size || size2%min_size){
                min_size--;
                continue;
            }
            ans = ans.substr(0, min_size);
            if(gcd(str1, str2, ans)){
                return ans;
            }
            min_size--;
        }
        return "";
    }
};

// better
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1)   return "";
        int val = gcd(str1.size(), str2.size());
        return str1.substr(0, val);
    }
};