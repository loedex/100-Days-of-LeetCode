#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		double averageSalary(vector<int>& salary){
			double sum = 0;
			int minimum = salary[0];
			int maximum = salary[0];
			for(int i=0; i<salary.size(); i++){
				sum+=salary[i];
				if(salary[i] > maximum){
					maximum = salary[i];
				}
				if(salary[i] < minimum){
					minimum = salary[i];
				}
			}
			
			sum = sum - minimum;
			sum = sum - maximum;
			sum = sum/(salary.size()-2);
			return sum;
			
		}
};
int main(){
	vector<int>V = {4000,3000,1000,2000};
	Solution obj;
	cout<<endl<<obj.averageSalary(V);
	return 0;
}
