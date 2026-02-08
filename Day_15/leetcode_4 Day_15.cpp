#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<algorithm>
class Solution{
	public:
		int medianOfSortedArrays(vector<int>& nums1, vector<int>& nums2){
			if(nums1.size() > nums2.size()){
				return medianOfSortedArrays(nums2,nums1);
			}
			
			int m = nums1.size();
			int n = nums2.size();
			
			int low = 0;
			int high = m;
			
			while(low <= high){
				int noOfLeftNums1 = (low + high)/2; //mid. From nums 1
				int noOfLeftNums2 = (m+n+1)/2 - noOfLeftNums1; // From nums2 
				
				//left Half waly
				int leftNums1 = (noOfLeftNums1 == 0)? INT_MIN : nums1[noOfLeftNums1-1];
				int leftNums2 = (noOfLeftNums2 == 0)? INT_MIN : nums2[noOfLeftNums2-1];
				
				//Right Half Waly
				int rightNums1 = (noOfLeftNums1 == m)? INT_MAX : nums1[noOfLeftNums1];
				int rightNums2 = (noOfLeftNums2 == n)? INT_MAX : nums2[noOfLeftNums2];
				
				if((leftNums1 <= rightNums2) && (leftNums2 <= rightNums1)){
					
					if(((m+n)%2)==0){
						return ((max(leftNums1,leftNums2)) + (min(rightNums1,rightNums2)))/2.0;
					}
					else{
						return (max(leftNums1,leftNums2));
					}
				}
				else if((leftNums1 > rightNums2)){
					high = noOfLeftNums1-1; //mid-1
				}
				else{
					low = noOfLeftNums1+1; //mid+2
				}
			}
			return 0;
			
		}
};
int main(){
	vector<int>n1 = {1,3,4,7,10,12};
	vector<int>n2 = {2,3,6,15};
	Solution obj;
	cout<<endl<<obj.medianOfSortedArrays(n1,n2);
	return 0;
}