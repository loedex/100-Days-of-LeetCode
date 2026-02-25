#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<algorithm>
class Solution{
	public:
		void rotateImage(vector<vector<int>>& matrix){
			int rows = matrix.size();
			int columns = matrix[0].size();
			cout<<"Rows : "<<rows;
			cout<<"Columns : "<<columns<<endl;
			for(int i=0; i<rows; i++){
				for(int j=i+1; j<columns; j++){
					swap(matrix[i][j], matrix[j][i]);
				}
			}
			for(auto& row:matrix){
				reverse(row.begin(), row.end());
			}
			for(int i=0; i<rows; i++){
				for(int j=0; j<columns; j++){
					cout<<matrix[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
};
int main(){
	vector<vector<int>>V={{1,2,3},{4,5,6},{7,8,9}};
	Solution obj;
	obj.rotateImage(V);
	return 0;
}