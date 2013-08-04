class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1+len2 != len3)
            return false;
        if(!len1)
            return s2 == s3;
        if(!len2)
            return s1 == s3;
        if(s1[0] == s3[0] && isInterleave(s1.substr(1), s2, s3.substr(1)))
            return true;
        if(s2[0] == s3[0] && isInterleave(s1, s2.substr(1), s3.substr(1)))
            return true;      
        return false;
    }
};