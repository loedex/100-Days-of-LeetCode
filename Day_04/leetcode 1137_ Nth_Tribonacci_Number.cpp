#include<iostream>
using namespace std;
class Solution{
	public:
		int tribonacci(int n){
			if(n==0){
				return 0;
			}
			else if(n==1 || n==2){
				return 1;
			}
			else{
				int first = 0;
				int second = 1;
				int third = 1;
				int sum;
				for(int i=1; i<n-1; i++){
					sum = first + second + third;
					first = second;
					second = third;
					third = sum;
				}
				return sum;
			}
		}
};
int main(){
	Solution obj;
	int N;
	cout<<"Enter Number : ";
	cin>>N;
	cout<<endl<<"Result: "<<obj.tribonacci(N);
	return 0;
}
