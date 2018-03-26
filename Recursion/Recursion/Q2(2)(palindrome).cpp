#include<iostream>
#include<stdio.h>
using namespace std;

void check_palindrome(char * arr,int index)
{
	int lenght=0;
	lenght=strlen(arr)-(index+1);
	if(arr[index]==arr[lenght])
	{
		if(lenght==index+1 || lenght==index)
		{
			cout<<"The given string is palindrome !"<<endl;
			return ;
		}
		check_palindrome(arr,index+1);
	}
	else 
	{
		cout<<"The given string is not palindrome !"<<endl;
	}

}

int main()
{


	char * arr=NULL;
	arr=new char [1000]();

	cout<<"Enter the to be checked for palindrome !"<<endl;
	gets(arr);

	check_palindrome(arr,0);

	delete arr;
	system("pause");
	return 0;
}







