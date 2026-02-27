#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int diagonalSum(vector<vector<int>>& mat){
			
			int sum = 0;
			int columns = mat[0].size();
			
			for(int i=0; i<mat.size(); i++){
				sum+=mat[i][i];
				if(i != (columns-1-i)){
					sum+=mat[i][columns-1-i];
				}
			}
			return sum;
		}
};
int main(){
	vector<vector<int>>V={{1,2,3},{4,5,6},{7,8,9}};
	Solution obj;
	cout<<endl<<obj.diagonalSum(V);
	return 0;
}
