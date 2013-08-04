#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
		if(nRows <= 1 || nRows >= s.size())
			return s;
		string ret;
		int interval = 2*nRows-2;
		for(int i = 0; i < nRows; i++)
		{
			for(int j = i; j < s.size(); j += interval)
			{
				ret.push_back(s[j]);
				int sinterval = interval - 2*i;
				if(i != 0 && i != (nRows-1) && (j + sinterval) < s.size())
					ret.push_back(s[j+sinterval]);
			}
		}
		return ret;
    }
};
int main()
{
	string s = "heltfchqssrwqgwanggkjlsownsdpoowubszfzratjwlpuldarnmehcbvuemiulcxdedcxfygbjyyxbyqqmvxoyukchszuxwxdbbagzjklhiikiyavvzltwwyfqxzpvwszxvfzerknbuxkszhoaujwqhbjecycyrbyoizucjhddgpxfynftxelehulktnkkqkaajucsdgxjvvoukvphzamjvxtomfacqaezwhuzntkkqagbvxkxywgtvbjjijnylsajzwioruaiujlrgvoguwzrzkbivogggiphgzvytygnhtfnovwkuvctidbdrkkaubhbddzwbhmkatzqqvbktdgbgjezvqzqshtxmutpbhzdcyvvwwhpbnqjxujunkmhtfehzzwchxhlydiubqjddbmcxxzkilrdrvlsvjvehcrfhabjqkmvnaykyxviimnbkyufirlpvcwdcxmsjaowaogandkxsybcwvjgouxjytobscvdclbfzkfonqmfqpjmksvaoslnoaqgelmhxnmyxtnllbsbqcocwjendparrsywdkfazrbxmoiyrczjgplfypseguvymvuphzshsteejoccsclzrwesnyytsttgppvwqpfikjpvztxsxirrgxlvvjpnckttaqqqivbshsogllylwrccopylypaabvwbomuwjxqspezcszpqtrsjgsvgjxhltdohrifchvvyawbuxqkskecszzzkyixrnmagwfiebfcdbfxbyjtipxcoybzxjyowkrcjwnpxstawbzxzisjysloqnpnyoevavzjrmarhutdvtcwdwfdoqsffhuexazyvajpnkiugbzdwdzazedowxvchrgeshephogwaosiqtlmwmowssmopjswayduhhkrxqnzhijxbulyiawauirjtjitk";
	int nRows = 742;
	Solution sol;
	cout<<sol.convert(s, nRows);
	getchar();
}