// Given an array of characters chars,
//  compress it using the following algorithm:
// Begin with an empty string s. For each group 
// of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned 
// separately, but instead, be stored in the input character a
// rray chars. Note that group lengths that are 10 or 
// longer will be split into multiple characters in chars.
// After you are done modifying the input array, return the new length of the array.
// You must write an algorithm that uses only constant extra space.

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int pointer = 0;
        while (i < chars.size()) {
            int count = 1;
            while (i + count < chars.size() && chars[i + count] == chars[i]) {
                count++;
            }
            chars[pointer] = chars[i];
            pointer++;
            if (count > 1) {
                string countString = to_string(count);
                for (int c = 0; c < countString.size(); c++) {
                    chars[pointer] = countString[c];
                    pointer++;
                }
            }
            i += count;
        }
        return pointer;
    }
};