#include<iostream>
#include"stacklinked.h"
using namespace std;
void move(int tiles,stacklinked<int>&from,stacklinked<int>&to)
{
	int temp=0;
	temp=from.top();
	to.push(temp);
	from.pop();
}
void hanoi(int tiles,stacklinked<int>& from,stacklinked<int>& to,stacklinked<int>& spare)
{
	if(tiles>0)
	{
		hanoi(tiles-1,from,spare,to);
		move(tiles,from,to);
		hanoi(tiles-1,spare,to,from);
	}
}


int main()
{
	stacklinked<int>from;
	stacklinked<int>spare;
	stacklinked<int>to;

	
	int demand=0;
	cout<<"How many tiles you want in tower of hanoi ?"<<endl;
	cin>>demand;

	for(int i=0;i<demand;i++)
	{
		from.push(i);
	}

	hanoi(demand,from,to,spare);
	
	
	int temp=0;
	
	cout<<"After moving all the tiles from peg1 to peg3, peg3 now contains !"<<endl;
	for(int i=0;i<demand;i++)
	{
		temp=to.top();
		cout<<temp<<endl;

		to.pop();
	}
	cout<<endl;


	system("pause");
	return 0;
}