class Solution {
public:
    bool isScramble(string s1, string s2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = s1.size();
		if(len != s2.size())
			return false;
		if(s1 == s2)
			return true;
		for(int i = 1; i <= len/2; i++)
		{
			string a1 = s1.substr(0,i);
			string b1 = s1.substr(i);
			string a2 = s2.substr(0,i);
			string b2 = s2.substr(i);
			string c1 = s1.substr(0,len-i);
			string d1 = s1.substr(len-i);
			string c2 = s2.substr(0,len-i);
			string d2 = s2.substr(len-i);
			if(isScramble(a1,a2) && isScramble(b1,b2))
				return true;
			if(isScramble(a1,d2) && isScramble(b1,c2))
				return true;
			if(isScramble(a2,d1) && isScramble(b2,c1))
				return true; 
			if(isScramble(c1,c2) && isScramble(d1,d2))
				return true;    
		}
		return false;
	}
};