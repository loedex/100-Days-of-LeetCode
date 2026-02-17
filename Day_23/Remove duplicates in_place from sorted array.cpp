#include<iostream>
#include<array>
using namespace std;
class Solution{
	public:
		int find(int[]);
};
int Solution::find(int arr[]){
    int i=0;
	for(int j=1;j<6;j++){
		if(arr[j]!=arr[i]){
			arr[++i]=arr[j];
		}
	}
	cout<<endl<<"Updated Array: \n";
	for(int j=0;j<6;j++){
		cout<<arr[j]<<"\t";
	}
	return (i+1);
}
int main(){
	int ar[6];
	for(int i=0;i<6;i++){
		cout<<"Enter "<<i+1<<" value: ";
		cin>>ar[i];
	}
	Solution obj;
	int n;
	n=obj.find(ar);
	cout<<endl<<"\tNumber of Unique Elements: "<<n;
	return 0;
}