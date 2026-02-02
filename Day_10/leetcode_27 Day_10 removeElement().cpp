#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int removeElement(vector<int>& nums, int val){
			int ptr = 0;
			for(int i=0; i<nums.size(); i++){
				if(nums[i]!=val){
					nums[ptr]=nums[i];
					ptr++;
				}
			}
			return ptr;
		}
};
int main(){
	vector<int>V={0,1,2,2,3,0,4,2};
	int v = 2;
	Solution obj;
	cout<<endl<<obj.removeElement(V,v);
	return 0;
}
