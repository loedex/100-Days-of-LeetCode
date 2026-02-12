#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int singleNonDuplicate(vector<int>& nums){
			if(nums.size()==1){
				return nums[0];
			}
			if(nums[0]!=nums[1]){
				return nums[0];
			}
			else if(nums[nums.size()-1] != nums[nums.size()-2]){
				return nums[nums.size()-1];
			}
			else{
				int left = 0;
				int right = nums.size()-1;
				while(left<=right){
					int mid = (left+right)/2;
					
					if((nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1])){
						return nums[mid];
					}
					else if(mid%2==1){
						if(nums[mid] == nums[mid-1]){
							left = mid+1;
						}else{
							right = mid-1;
						}
					}
					else if(mid%2==0){
						if(nums[mid]==nums[mid+1]){
							left = mid+1;
						}else{
							right = mid-1;
						}
					}
				}
			}
			return 0;
		}
};