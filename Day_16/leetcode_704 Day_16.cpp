#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int binarySearch(vector<int>& nums, int target){
			int low = 0;
			int high = nums.size()-1;
			while(low<=high){
				int mid = (low + high)/2;
				if(target > nums[mid]){
					low = mid+1;
				}
				else if(target < nums[mid]){
					high = mid-1;
				}
				else{
					return mid;
				}
			}
			return -1;
		}
};
int main(){
	vector<int>V = {-1,0,3,5,9,12};
	Solution obj;
	cout<<endl<<obj.binarySearch(V, 2);
	return 0;
}
