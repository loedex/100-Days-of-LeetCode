#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int findPeakElement(vector<int>& nums){
			if(nums[0] > nums[1]){
				return 0;
			}
			else if(nums[nums.size()-1]>nums[nums.size()-2]){
				return nums.size()-1;
			}
			else{
				int left = 1;
				int right = nums.size()-2;
				
				while(left <= right){
					int mid = (left+right)/2;
					
					if((nums[mid]>nums[mid-1]) && (nums[mid]>nums[mid+1])){
						return mid;
					}
					if(nums[mid+1]>nums[mid]){
						left = mid+1;
					}else{
						right = mid-1;
					}
				}
			}
			return 0;
		}
};
int main(){
	vector<int>V={1,2,3,1};
	Solution obj;
	cout<<endl<<"Index of Peak Element is : "<<obj.findPeakElement(V);
	return 0;
}