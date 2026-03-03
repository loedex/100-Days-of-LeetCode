#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		bool isPerfectSquare(int num){
			if(num == 1){
				return true;
			}
			
			long long Min = 1;
			long long Max = num/2;
			while(Min<=Max){
				long long mid = Min + (Max - Min)/2;
				long long square = mid*mid;
				
				if(square == num){
					return true;
				}
				else if(square < num){
					Min = mid+1;
				}
				else if(square > num){
					Max = mid-1;
				}
			}
			return false;
		}
};
int main(){
	int val = 5;
	Solution obj;
	cout<<endl<<obj.isPerfectSquare(val);
	return  0;
}