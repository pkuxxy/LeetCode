class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = num1.size();
        int len2 = num2.size();
        if(!len1 || !len2)
            return "";
    	vector<int> tmp(len1+len2, 0);
        //string ret(len1+len2+1,0);
        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                tmp[i+j] += (num1[len1-1-i]-'0') * (num2[len2-1-j]-'0');
            }
        }
        for(int i = 0; i < len1+len2; i++)
        {
            tmp[i+1] += tmp[i]/10;
            tmp[i] %= 10;
        }
		int i = len1+len2-1;
        while(i >= 0 && tmp[i] == 0)
			i--;
		if(i == -1)
			return "0";
		string ret;
		for(int j = i; j >= 0; j --)
		{
			ret.push_back('0'+tmp[j]);
		}
        return ret;
    }
};