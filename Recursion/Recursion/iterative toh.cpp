#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int no_of_disks=0;

	cout<<"Enter the no of disks"<<endl;
	cin>>no_of_disks;

	for(int i=1;i<(1<<no_of_disks);i++)
	{
		cout<<"\n Move from Peg "<<(i&i-1)%3+1<<" to peg "<<((i|i-1)+1)%3+1;
	}
	cout<<endl;
	cout<<endl;
	system("pause");
	return 0;
}