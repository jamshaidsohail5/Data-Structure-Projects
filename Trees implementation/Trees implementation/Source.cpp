#include<iostream>
#include<windows.h>
#include"tree.h"   //implementation of the tree is in the tree.h file
using namespace std;
int main()
{
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);

	int data_type=0;
	SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
	cout<<"****************Welcome to tree implementation*****************"<<endl;
	cout<<endl;
	cout<<endl;

	SetConsoleTextAttribute(hconsole,13);
	cout<<"                 ************Menu************"<<endl;
	cout<<endl;
	cout<<endl;

	cout<<"Enter the datatype of element of Tree !"<<endl;
	cout<<"Enter 1 for integer datatype !"<<endl;
	cout<<"Enter 2 for char datatype !"<<endl;
	cin>>data_type;
	tree_implementation<char>tree_1;
	tree_implementation<int>tree;

	int choice=0;
	cout<<endl;
	cout<<endl;

	int demand=0;
	int temp=0;
	char temp1=0;

	int demand_for_tree_2=0;
	int demand_for_tree_3=0;
	int temp_for_tree_2=0;
	char temp_for_tree_3=0;


	SetConsoleTextAttribute(hconsole,6);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet

	if(data_type==1)
	{
		cout<<"How many integers you want to insert ?"<<endl;
		cin>>demand;
		cout<<"Start entering the elements you want to insert into the tree !"<<endl;
		for(int i=0;i<demand;i++)
		{
			cin>>temp;
			tree.insert_item(temp);
		}
	}
	else if(data_type==2)
	{
		cout<<"How many characters you want to insert ?"<<endl;
		cin>>demand;
		cout<<"Start entering the elements you want to insert into the tree !"<<endl;
		for(int i=0;i<demand;i++)
		{
			cin>>temp1;
			tree_1.insert_item(temp1);
		}
	}


	SetConsoleTextAttribute(hconsole,8);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet

	cout<<endl;
	cout<<endl;
	cout<<"       Enter ONLY the number which is asked to be entered !"<<endl;
	cout<<"       Enter 1 to delete an element from the TREE !"<<endl;
	cout<<"       Enter 2 to search an element from the TREE !"<<endl;
	cout<<"       Enter 3 to print the TREE !"<<endl;
	cout<<"       Enter 4 to know the no of nodes in the Tree !"<<endl;
	cout<<"       Enter 5 to know the heigth of the TREE !"<<endl;
	cout<<"       Enter 6 to check the equality of 2 Trees !"<<endl;
	cout<<"       Enter 7 to mirror the binary search tree !"<<endl;
	cin>>choice;
	cout<<endl;
	cout<<endl;

	int integer_delete=0;
	char character_delete=0;

	int integer_search=0;
	char character_search=0;
	bool search_result=false;

	if(choice==1)
	{
		if(data_type==1)
		{
			cout<<"Enter the element you want to delete !"<<endl;
			cin>>integer_delete;
			tree.delete_item(integer_delete);
			cout<<endl;
			cout<<endl;
			SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
			cout<<"After deleting the element from the tree the tree is "<<endl;
			tree.temp_inorder_traversal();
			cout<<endl;
			cout<<endl;

		}
		else if(data_type==2)
		{

			cout<<"Enter the element you want to delete !"<<endl;
			cin>>character_delete;
			cout<<endl;
			cout<<endl;
			tree_1.delete_item(character_delete);
			cout<<endl;
			cout<<endl;
			SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
			cout<<"After deleting the element from the tree the tree is "<<endl;
			tree_1.temp_inorder_traversal();
			cout<<endl;
			cout<<endl;
		}

	}
	else if(choice==2)
	{
		if(data_type==1)
		{
			cout<<"Enter the integer you want to search ?"<<endl;
			cin>>integer_search;
			cout<<endl;
			cout<<endl;
			search_result=tree.search(integer_search);
			if(search_result==true)
			{
				cout<<"The element is present in the tree !"<<endl;
			}
			else if(search_result==false)
			{
				cout<<"The element is not present in the tree !"<<endl;
			}
			cout<<endl;
			cout<<endl;
		}
		else if(data_type==2)
		{
			cout<<"Enter the character you want to search ?"<<endl;
			cin>>character_search;
			cout<<endl;
			cout<<endl;
			search_result=tree_1.search(character_search);
			if(search_result==true)
			{
				cout<<"The element is present in the tree !"<<endl;
			}
			else if(search_result==false)
			{
				cout<<"The element is not present in the tree !"<<endl;
			}
			cout<<endl;
			cout<<endl;
		}

	}

	if(choice==3)
	{
		if(data_type==1)
		{
			tree.print();
			cout<<endl;
			cout<<endl;

		}
		else if(data_type==2)
		{
			tree_1.print();
			cout<<endl;
			cout<<endl;
		}

	}
	else if(choice==4)
	{
		if(data_type==1)
		{
			cout<<"The number of nodes in the tree is "<<endl;
			cout<<tree.count_nodes();
			cout<<endl;
			cout<<endl;

		}
		else if(data_type==2)
		{
			cout<<"The number of nodes in the tree is "<<endl;
			cout<<tree_1.count_nodes();
			cout<<endl;
			cout<<endl;
		}

	}
	else if(choice==5)
	{
		if(data_type==1)
		{
			cout<<"The heigth of the tree is "<<endl;
			cout<<tree.depth();
			cout<<endl;
			cout<<endl;

		}
		else if(data_type==2)
		{

			cout<<"The heigth of the tree is "<<endl;
			cout<<tree_1.depth();
			cout<<endl;
			cout<<endl;

		}

	}
	else if(choice==6)
	{
		if(data_type==1)
		{
			SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
			cout<<"For comparison a second tree is needed !"<<endl;
			cout<<"Follow the procedure below to input second tree !"<<endl;
			cout<<endl;
			cout<<endl;
			tree_implementation<int> tree_2;
			cout<<"How many integer elements you want in second tree "<<endl;
			cout<<"to which the previously entered tree is to"<<endl;
			cout<<"be compared ?"<<endl;
			cin>>demand_for_tree_2;
			cout<<endl;
			cout<<endl;
			cout<<"Enter the elements for this new tree !"<<endl;
			for(int i=0;i<demand_for_tree_2;i++)
			{
				cin>>temp_for_tree_2;
				tree_2.insert_item(temp_for_tree_2);
			}
			cout<<endl;
			cout<<endl;
			if(tree==tree_2)
			{
				cout<<"The tree entered at start of program and freshly enetered tree are EQUAL !"<<endl;
			}
			else
			{
				cout<<"The tree entered at start of program and freshly enetered tree are NOT EQUAL !"<<endl;
			}
			cout<<endl;
			cout<<endl;
		}
		else if(data_type==2)
		{
			SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
			cout<<"For comparison a second tree is needed !"<<endl;
			cout<<"Follow the procedure below to input second tree !"<<endl;
			cout<<endl;
			cout<<endl;
			tree_implementation<char> tree_3;
			cout<<"How many character elements you want in second tree "<<endl;
			cout<<"to which the previously entered tree is to"<<endl;
			cout<<"be compared ?"<<endl;
			cin>>demand_for_tree_3;
			cout<<endl;
			cout<<endl;
			cout<<"Enter the elements for this new tree !"<<endl;
			for(int i=0;i<demand_for_tree_3;i++)
			{
				cin>>temp_for_tree_3;
				tree_3.insert_item(temp_for_tree_3);
			}
			cout<<endl;
			cout<<endl;
			if(tree_1==tree_3)
			{
				cout<<"The tree entered at start of program and freshly enetered tree are EQUAL !"<<endl;
			}
			else
			{
				cout<<"The tree entered at start of program and freshly enetered tree are NOT EQUAL !"<<endl;
			}
			cout<<endl;
			cout<<endl;
		}
	}

	else if(choice==7)
	{
		if(data_type==1)
		{
			SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
			cout<<"Before mirroring the tree is "<<endl;
			tree.temp_inorder_traversal();
			cout<<endl;
			cout<<endl;

			tree.mirror_bst();

			cout<<"After mirroring the tree is "<<endl;
			tree.temp_inorder_traversal();
			cout<<endl;
			cout<<endl;

		}
		else if(data_type==2)
		{
			SetConsoleTextAttribute(hconsole,10);            //10=Green,1=Blue,12=RED,13=pink,6=yellow,8=violet
			cout<<"Before mirroring the tree is "<<endl;
			tree_1.temp_inorder_traversal();
			cout<<endl;
			cout<<endl;

			tree_1.mirror_bst();

			cout<<"After mirroring the tree is "<<endl;
			tree_1.temp_inorder_traversal();
			cout<<endl;
			cout<<endl;
		}


	}
	system("pause");
	return 0;
}