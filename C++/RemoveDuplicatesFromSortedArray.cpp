class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = 0;
		for(int i = 0; i < n; i++)
		{
			if(i == 0 || A[i] != A[i-1])
				A[index++] = A[i];
		}
		return index;
    }
};