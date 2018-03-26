#include"23tree.h";
#include<conio.h>
void main(){
	tree a;
	int data = 0;
	for (int i = 0; i != 4;){
		cout << "Press 1 to Insert , 2 to Search , 3 to Output tree and 4 to Exit" << endl << "Choice :";
		cin >> i;
		if (i == 1){
			cout << "Enter data:";
			cin >> data;
			a.insert(data);
		}
		else if (i == 2){
			cout << "Enter key to search for :";
			cin >> data;

			if (a.search(data))
				cout << "Key Exists " << endl;
			else
				cout << "Key doesnt exist " << endl;
		}
		else if (i == 3)
			a.print();

		cout << endl;
		_getch();
		system("cls");
	}

	system("pause");
}