#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int climbStairs(int n){
			if(n <= 2){
				return n;
			}
			int prev2 = 1;
			int prev1 = 2;
			for(int i = 3; i<=n; i++){
				
				int curr = prev1 + prev2;
				prev2 = prev1;
				prev1 = curr;
				
			}
			return prev1;
		}
};
int main(){
	Solution obj;
	cout<<endl<<obj.climbStairs(4);
	return 0;
}
