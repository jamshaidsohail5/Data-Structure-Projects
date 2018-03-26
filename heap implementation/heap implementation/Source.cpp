#include<iostream>
#include<conio.h>
#include<windows.h>
#include"heap.h"
using namespace std;
int main()
{
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
	
	int datatype=0;
	cout<<"Enter the datatype of heap !"<<endl;
	cout<<"Enter 1 for integer datatype!"<<endl;
	cout<<"Enter 2 for character datatype !"<<endl;
	cin>>datatype;
	cout<<endl;
	cout<<endl;
	SetConsoleTextAttribute(hconsole,13);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet

	int heap_size=0;
	int demand=0;
	cout<<"Enter the size of array !"<<endl;
	cout<<"Enter size less than or equal to 10 "<<endl;
	cin>>demand;
	cout<<endl;
	cout<<endl;
	heap_implementation<int> obj(demand);
	heap_implementation<char>obj1(demand);

	SetConsoleTextAttribute(hconsole,6);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet


	cout<<"How many elements you want in your heap ?"<<endl;
	cin>>heap_size;
	cout<<endl;

	int temp=0;
	char temp1=0;
	SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet

	if(datatype==1)
	{
		cout<<"Enter the elements of heap !"<<endl;
		for(int i=0;i<heap_size;i++)
		{
			cin>>temp;
			obj.insert_and_heapify(temp);
		}
	}
	else if(datatype==2)
	{
		cout<<"Enter the elements of heap !"<<endl;
		for(int i=0;i<heap_size;i++)
		{
			cin>>temp1;
			obj1.insert_and_heapify(temp1);
		}
	}

	cout<<endl;
	cout<<endl;
	SetConsoleTextAttribute(hconsole,13);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
	if(datatype==1)
	{
		cout<<"The elements after insertion and heapify are !"<<endl;
		obj.print();
		cout<<endl;
		cout<<endl;
	}
	else if(datatype==2)
	{
		cout<<"The elements after insertion and heapify are !"<<endl;
		obj1.print();
		cout<<endl;
		cout<<endl;
	}

	int for_operation=0;
	cout<<"Press 1 for heap sort operation !"<<endl;
	cout<<"Press 2 for delete a max element from heap !"<<endl;
	cin>>for_operation;

	cout<<endl;
	cout<<endl;
	SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet

    if(datatype==1)
	{
		if(for_operation==1)
		{
			obj.heap_sort();
			cout<<"After heap sort !"<<endl;
			obj.print();
			cout<<endl;
			cout<<endl;
		}
		else if(for_operation==2)
		{
			obj.delete_max_and_heapify();
			cout<<"After deleting the maximum element from the heap the heap is "<<endl;
			cout<<endl;
			obj.print();
		}
	}
	else if(datatype==2)
	{
		if(for_operation==1)
		{
			obj1.heap_sort();
			cout<<"After heap sort !"<<endl;
			obj1.print();
			cout<<endl;
			cout<<endl;


		}
		else if(for_operation==2)
		{
			obj1.delete_max_and_heapify();
			cout<<"After deleting the maximum element from the heap the heap is "<<endl;
			cout<<endl;
			obj1.print();
		

		}
	}




	system("pause");
	return 0;
}