#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target){
			int rows = matrix.size();
			int columns = matrix[0].size();
			
			int left = 0;
			int right = (rows * columns)-1;
			
			while(left <= right){
				int mid = (left + right)/2;
				
				int i = mid/columns;
				int j = mid%columns;
				
				if(target == matrix[i][j]){
					return true;
				}
				else if( target < matrix[i][j]){
					right = mid-1;
				}
				else if( target > matrix[i][j]){
					left = mid+1;
				}
			}
			return false;
		}
};
int main(){
	vector<vector<int>>V={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	int t = 13;
	Solution obj;
	bool res = obj.searchMatrix(V,t);
	if(res == 1){
		cout<<endl<<"True";
	}
	else{
		cout<<endl<<"False";
	}
	return 0;
}