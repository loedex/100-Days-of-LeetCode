#include<iostream>
using namespace std;
class Solution{
	public:
		int fib(int n){
			if(n==0){
				return 0;
			}
			if(n==1){
				return 1;
			}
			else{
				int first = 0;
				int second = 1;
				int third;
				for(int i=1; i<n; i++){
					third = first + second;
					first = second;
					second = third;
				}
				return third;
			}
		}
};
int main(){
	Solution obj;
	cout<<obj.fib(5);
	return 0;
}