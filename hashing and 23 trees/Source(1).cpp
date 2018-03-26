#include"HashTable.h";
#include<conio.h>
void main(){
	cout << "Enter size of your array:";
	int size = 0;
	cin >> size;
	HashTable a(size);
	_getch();
	cout << endl << endl ;

	int data = 0;
	for (int i = 0; i != 4;){
		cout << "Press 1 to insert , 2 to search , 3 to output , 4 to exit" << endl << "Choice :";
		cin >> i;
		if (i == 1){
			cout << "Enter data:";
			cin >> data;
			a.insert(data);
		}
		else if (i == 2){
			cout << "Enter key to search :";
			cin >> data;
			a.search(data);
		}
		else if (i == 3){
			a.output();
			cout << endl;
		}
	}
	system("pause");
}