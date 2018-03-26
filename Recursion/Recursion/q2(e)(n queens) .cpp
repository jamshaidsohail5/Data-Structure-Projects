#include<iostream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
using namespace std;

 int no_of_queens=4;

void printboard(int ** board)
{
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole,13);

	int j=0;
	for(int i=0;i<no_of_queens;i++)
	{
		for( j=0;j<no_of_queens;j++)
			cout<<setw(5)<<board[i][j]<<" ";
			cout<<endl;  
		
	}
}
bool toplaceornottoplace(int **board,int row,int col)
{
	//cout<<no_of_queens;
	for(int i=0;i<col;i++)
	{
		if(board[row][i]==1)
			return false;
	}
	for(int i=row,j=col;i>=0 && j>=0;i--,j--)//diagonally top left
	{
		if (board[i][j]==1)
		{
			return false;
		}
	}
	for(int i=row,j=col;j>=0 && i<no_of_queens;i++,j--)//diagonally bottom left
	{
		if(board[i][j]==1)
			return false;
	}
	return true;

}
bool theboardsolver(int **board,int col)
{
	if(col>=no_of_queens)
	{
		return true;
	}
	for(int i=0;i<no_of_queens;i++)
	{
		if(toplaceornottoplace(board,i,col))
		{
			board[i][col]=1;
			if(theboardsolver(board,col+1))
			{
				return true;
			}
			board[i][col]=0;
		}
	}
	return false;
}

int main()
{
	cout<<"How many queens you want on an nxn board ?";
	cout<<"Where n=no_of_queens !"<<endl;
	cin>>no_of_queens;


	int **board=NULL;
	board=new int*[no_of_queens]();
	for(int i=0;i<no_of_queens;i++)
	{
		board[i]=new int [no_of_queens]();
	}

	if(!theboardsolver(board,0))
	{
		cout<<"Solution not found !"<<endl;
	}
	printboard(board);



	system("pause");
	return 0;
}