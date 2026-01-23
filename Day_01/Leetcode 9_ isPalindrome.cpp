#include<iostream>
using namespace std;
class Solution{
	public:
		bool isPalindrome(int x){
			if(x<0){
				cout<<"Number is Negative";
				return false;
	
			}
			int num = x;
			int reverseNum = 0;
			
			while(num>0){
				
				int last = num%10;
				num = num/10;
				reverseNum = reverseNum*10 + last;
				
			}
			if(reverseNum == x){
				return true;
			}else{
				return false;
			}
		}
};
int main(){
	Solution obj;
	bool result = obj.isPalindrome(10);
	if(result){
		cout<<"The Number is Palindrome";
	}
	else{
		cout<<"The Number is Not Palindrome";
	}
	return 0;
}