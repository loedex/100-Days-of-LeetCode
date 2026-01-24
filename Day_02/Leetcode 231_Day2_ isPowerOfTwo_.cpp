#include<iostream>
using namespace std;
class Solution{
	public:
		bool isPowerOfTwo(int n){
			if(n<1){
				return false;
			}
			else if(n==1){
				return true;
			}
			else{
				while(n%2==0){
					n=n/2;
				}
				if(n==1){
					return true;
				}
				else{
					return false;
				}
			}
		}
};
int main(){
	Solution obj;
	bool result = obj.isPowerOfTwo(20);
	if(result){
		cout<<"Number is Power of Two";
	}
	else{
		cout<<"Number is not Power of Two";
	}
	return 0;
	
}
