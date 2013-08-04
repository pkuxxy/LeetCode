#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	void getNext(char* needle, int next[]) {
	    int j,k;
		int len = strlen(needle);
	    next[0]=-1;
	    j=0;
	    k=-1;
	    while(j<len-1)
	    {
	        if( k==-1 ||needle[j] == needle[k])    //匹配的情况下,p[j]==p[k]
	        {
	            j++;
	            k++;
	            next[j]=k;
	        }
	        else                   //p[j]!=p[k]
	            k=next[k];
	    }
	}
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len2 = strlen(needle);
        if(!len2)
    		return haystack;
    	int len1 = strlen(haystack);
        int* next= new int[len2];
        int i = 0;
        int j  = 0;
        getNext(needle,next);
        
        while(i < len1 && j < len2)
        {
        	if(j == -1 || haystack[i] == needle[j])
        	{
        		i++;
        		j++;
        	}
        	else
        		j = next[j];
        	if(j == len2)
			{
				delete[] next;
        		return &haystack[i-j];
			}
        }
		delete[] next;
        return NULL;
    }
};