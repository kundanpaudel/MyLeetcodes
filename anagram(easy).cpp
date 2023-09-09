class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> strS; // Map for string s.
        unordered_map<char, int> strT; // Map for string t.

        if(s.length()!=t.length()){ // If length of s and t are different they cannot be anagrams.
            return false;
        }else{
            for(int i = 0; i < s.length(); i++){ // Iterate through length of both strings s = t.
                strS[s[i]]++; // Store character and it's frequency in string s in strS map.
                strT[t[i]]++; // Store character and it's frequency in string t in strT map.
            }
            for(auto x:s){ // For each character in string s (you can also use t).
                if(strS[x]!=strT[x]){ // Check if each character have same frequency in each map.
                    return false; // If not, return false.
                }
            }
            return true; // If it passes each requirement, then return true.
        }
    }
};

