#include<iostream>
#include<stdio.h>
using namespace std;
void mergeSort(int [], int, int, int);
void partitioning(int [],int, int);

int main()

{

	int arr[50];

	int demand=0;

	cout<<"Enter the no of elements to be sorted !"<<endl;
	cin>>demand;

	cout<<"Enter the elements !"<<endl;
	for(int i = 0; i < demand; i++)

	{

		cin>>arr[i];

	}

	partitioning(arr, 0, demand - 1);

	cout<<"After merge sort !"<<endl;
	for(int i = 0;i < demand; i++)

	{

		cout<<arr[i]<<"|";

	}


	system("pause");

	return 0;

}



void partitioning(int list[],int low,int high)

{

	int mid=0;



	if(low < high)

	{

		mid = (low + high) / 2;

		partitioning(list, low, mid);

		partitioning(list, mid + 1, high);

		mergeSort(list, low, mid, high);

	}

}



void mergeSort(int list[],int low,int mid,int high)

{

	int i, mid_after, lo, temp[50];



	lo = low;

	i = low;

	mid_after = mid + 1;

	while ((lo <= mid) && (mid_after <= high))

	{

		if (list[lo] <= list[mid_after])

		{

			temp[i] = list[lo];

			lo++;

		}

		else

		{

			temp[i] = list[mid_after];

			mid_after++;

		}

		i++;

	}

	if (lo > mid)

	{

		for (int k = mid_after; k <= high; k++)

		{

			temp[i] = list[k];

			i++;

		}

	}

	else

	{

		for (int k = lo; k <= mid; k++)

		{

			temp[i] = list[k];

			i++;

		}

	}



	for (int k = low; k <= high; k++)

	{

		list[k] = temp[k];

	}

}

