#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int maxProduct(vector<int>& nums){
			int largest = 0;
			int secondLargest = -1;
			for(int i=0; i<=nums.size()-1; i++){
				if(nums[i]>largest){
					secondLargest = largest;
					largest = nums[i];
				}
				else if(((nums[i]<largest) || (nums[i]==largest)) && (nums[i]>secondLargest)){
					secondLargest = nums[i];
				}
			}
			cout<<"Largest : "<<largest<<endl;
			cout<<"secondLargest : "<<secondLargest;
			return ((largest-1)*(secondLargest-1));
		}
};
int main(){
	vector<int> V = {3,4,5,2};
	Solution obj;
	int r = obj.maxProduct(V);
	cout<<endl<<"Maximum Product : "<<r;
	return 0;
}
