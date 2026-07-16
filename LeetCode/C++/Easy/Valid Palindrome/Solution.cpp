class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char ch : s){
            if(isalnum(ch)){
                temp+=tolower(ch);
            }
        }
        string rev=temp;
        reverse(rev.begin(),rev.end());
        
        return temp==rev;
        
    }
};