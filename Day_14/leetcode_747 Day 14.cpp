#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int dominantIndex(vector<int>& nums){
			int largest = nums[0];
			int secondLargest = INT_MIN;
			int largestIndex = 0;
			for(int i=1; i<nums.size(); i++){
				if(nums[i]>largest){
					secondLargest = largest;
					largest = nums[i];
					largestIndex = i;
				}
				else if((nums[i]<largest) && (nums[i]>secondLargest)){
					secondLargest = nums[i];
				}
			}
			if(largest < (2*secondLargest)){
				return -1;
			}
			return largestIndex;
		}
};
int main(){
	vector<int>V = {1,0};
	Solution obj;
	cout<<endl<<obj.dominantIndex(V);
	return 0;
}