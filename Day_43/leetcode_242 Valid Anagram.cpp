#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		bool isAnagram(string s, string t){
			if(s.size() != t.size()){
				return false;
			}
			int count[26] = {0};
			for(int i=0; i<s.size(); i++){
				count[s[i]-'a']++;
				count[t[i]-'a']--;
			}
			for(int x : count){
				if(x != 0){
					return false;
				}
			}
			return true;
		}
};
int main(){
	string S = "anagram";
	string T = "nagaam";
	Solution obj;
	bool result = obj.isAnagram(S,T);
	if(result){
		cout<<T<<" is ANAGRAM of "<<S;
	}else{
		cout<<T<<" is not an ANAGRAM of "<<S;
	}
	return 0;
}