#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution{
	public:
		bool validPalindrome(string s){
			int left = 0;
			int right = s.length()-1;
			while(left < right){
				
				while((left < right) && (!isalnum(s[left]))){
					left++;
				}
				while((left<right) && (!isalnum(s[right]))){
					right--;
				}
				if(tolower(s[left]) != tolower(s[right])){
					return false;
				}
				left ++;
				right --;
				
			}
			return true;
		}
};
int main(){
	string str = "A man, a plan, a canal: Panama";
	Solution obj;
	cout<<endl<<obj.validPalindrome(str);
	return 0;
}