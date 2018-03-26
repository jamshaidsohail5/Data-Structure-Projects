#include<iostream>
using namespace std;

int binary_search(int arr[],int low,int high,int key)
{
	int mid=0;
	if(low>high)
	{
		return -1;
	}
	mid=(low+high)/2;
	if(key==arr[mid])
	{
		return mid;
	}
	else if(key < arr[mid])
	{
		return(binary_search(arr,low,mid-1,key));
	}
	{	
		return(binary_search(arr,mid+1,high,key));
	}
}

void main()
{
	int arr[1000]={0};
	int demand=0;
	cout<<"Enter the number of elements !"<<endl;
	cin>>demand;
	if(demand<0 || demand>1000)
	{
		while (demand<0 || demand>1000)
		{
			cout<<"Invalid Demand !"<<endl;
			cout<<"Enter the no of elements !"<<endl;
			cin>>demand;
		}
	}


	cout<<"Enter the elements !"<<endl;
	for(int i=0;i<demand;i++)
	{
		cin>>arr[i];
	}

	int key=0;
	cout<<"Enter the element to be searched !"<<endl;
	cin>>key;


	int result=0;
	result=binary_search(arr,0,demand-1,key);

	if(result==-1)
	{
		cout<<"The key is not in the list !"<<endl;

	}
	else
		cout<<"The key is found at "<<result<<" index in array !" <<endl;

	system("pause");
}