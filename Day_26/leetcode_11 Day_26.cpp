#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<algorithm>
class Solution{
	public:
		int waterContainer(vector<int>& height){
			int left = 0;
			int right = height.size()-1;
			int maxWater = 0;
			
			while(left < right){
				int width = right - left;
				int currentHeight = min(height[left], height[right]);
				int water = width * currentHeight;
				
				maxWater = max(maxWater, water);
				
				if(height[left] < height[right]){
					left++;
				}
				else{
					right--;
				}
				
			}
			return maxWater;
		}
};
int main(){
	Solution obj;
	vector<int>V = {1,1};
	cout<<endl<<obj.waterContainer(V);
	return 0;
}