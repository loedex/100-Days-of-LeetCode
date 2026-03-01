#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution{
	public:
		vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image){
			int n = image.size()-1;
			
			for(int i = 0; i<=n; i++){
				int left = 0;
				int right = n;
				while(left <= right){
					int temp = image[i][left];
					image[i][left] = 1-image[i][right];
					image[i][right] = 1-temp;
					left++;
					right--;
				}
			}
			return image;
		}
};
int main(){
	vector<vector<int>>V={{1,1,0},{1,0,1},{0,0,0}};
	Solution obj;
	vector<vector<int>>res = obj.flipAndInvertImage(V);
	
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[0].size(); j++){
			cout<<res[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}