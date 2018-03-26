#include<iostream>
#include"ordered linked list.h"
using namespace std;
template<class type>

void main()
{
	int demand=0;
	ordered_linked_list<int>object;
	cout<<"How many elements you want to insert in the list ?"<<endl;
	cin>>demand;
	cout<<"Enter the elements of the list !"<<endl;
	int temp=0;
	for(int i=0;i<demand;i++)
	{
		cin>>temp;
		object.insert(temp);
	}

	cout<<endl;

	node<type> *temp1=NULL;
	object.print(temp);
	cout<<endl;
	node<type> *temp2=NULL;
	object.print_reverse(temp2);
	system("pause");
	
}