#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int mySqrt(int x){
			
			if(x == 0 || x == 1){
				return x;
			}
			int k;
			int Min = 0;
			int Max = x;
			while(Min <= Max){
				int mid = (Min + Max)/2;
				
				if(mid == (x/mid)){
					return mid;
				}
				else if(mid < (x/mid)){
					k = mid;
					Min = mid+1;
				}
				else if(mid > (x/mid)){
					Max = mid-1;
				}
			}
			return k;
			
		}
};
int main(){
	int val = 4;
	Solution obj;
	cout<<endl<<obj.mySqrt(val);
	return 0;
}
