#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(words.size() == 0)
        	return ret;
        int len = words[0].length();
        int whiteCount = 0;
        vector<int> index;
        vector<int> lengh;
        for(int i = 1 ;i < words.size(); i++)
        {
        	int curLen = len;
        	curLen++;
        	curLen += words[i].length();
        	if(curLen > L)
        	{
				index.push_back(i);
				lengh.push_back(len-whiteCount);
        		len = words[i].length();
        		whiteCount = 0;
        	}
        	else
        	{
        		len = curLen;
        		whiteCount++;
        	}
        }
		index.push_back(words.size());
		lengh.push_back(len-whiteCount);
        int start = 0;
        for(int i = 0; i < index.size(); i++)
        {
        	int end = index[i];
        	string sb;
        	sb.append(words[start]);
        	int wordCount = end-start;
        	whiteCount = L-lengh[i];
        	if(wordCount == 1 || i == index.size()-1)
        	{
        		for(int j = start+1; j < end; j++)
        		{
        			sb.append(" ");
        			sb.append(words[j]);
        		}
        		for(int k = 0; k < whiteCount - wordCount+1; k++)
        		{
        			sb.append(" ");
        		}
        	}
        	else
        	{
        		int left = whiteCount % (wordCount-1);
        		int interval = whiteCount / (wordCount-1);
            	for(int j = start+1; j <= start+left; j++)
            	{
            		for(int k = 0; k < interval+1; k++)
            		{
            			sb.append(" ");
            		}
            		sb.append(words[j]);
            	}
            	for(int j = start+(left == 0?1:left+1); j < end; j++)
            	{
            		for(int k = 0; k < interval; k++)
            		{
            			sb.append(" ");
            		}
            		sb.append(words[j]);
            	}
        	}
			ret.push_back(sb);
        	start = end;
        }
        return ret;
    }
};