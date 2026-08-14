class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int count[26] = {0};
        
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < s.size(); right++) {
            
            // Current character ko window me add karo
            count[s[right] - 'a']++;
            
            // Agar current character 2 se zyada ho gaya
            while (count[s[right] - 'a'] > 2) {
                
                // Left se character remove karo
                count[s[left] - 'a']--;
                left++;
            }
            
            // Current valid window ki length
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};