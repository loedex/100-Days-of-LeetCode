#include<iostream>
using namespace std;
#include<array>
class Solution{
	public:
		int removeDuplicate(int[]);
};
int Solution::removeDuplicate(int arr[]){
	int j;
	for(j=2;j<8;j++){
		if(arr[j]==arr[j-2]){
			for(int k=j;k<8;k++){
				arr[k]=arr[k+1];
			}
			j--;
		}
		else if(arr[j]!=arr[j-2]){
			
		}
	}
	cout<<"\nupdated Array:";
	for(int i=0;i<8;i++){
		cout<<arr[i]<<"\t";
	}
	return 0;
}
int main(){
	int ar[8];
	for(int i=0;i<8;i++){
		cout<<"Enter "<<i+1<<" value: ";
		cin>>ar[i];
	}
	Solution obj;
	obj.removeDuplicate(ar);
	return 0;
}