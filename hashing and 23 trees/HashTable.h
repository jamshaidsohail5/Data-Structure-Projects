#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

class HashTable{
private:
	int * dataarray;
	int * parray;
	int arrsize;
	int no_inserted;
	int get_no_of_digits(int key){
		int no = 0;
		int temp = key;
		while (temp > 0){
			temp = temp / 10;
			no++;
		}
		return no;
	}
	int get_middle_digits(int number, int no_of_digits){

		int asize = get_no_of_digits(number);
		int * arr = new int[asize]();
		int temp = number;
		for (int i = asize - 1; i >= 0; i--)
		{
			arr[i] = temp % 10;
			temp = temp / 10;
		}
		int mid = ceil(get_no_of_digits(number) / 2);
		int start = mid;
		int end = mid;
		no_of_digits--;
		while (no_of_digits > 0)
		{
			start--;
			no_of_digits--;
			if (no_of_digits > 0){
				end++;
				no_of_digits--;
			}
		}
		int new_number = 0;
		for (int i = start; i <= end; i++){
			new_number = new_number * 10;
			new_number += arr[i];
		}
		return new_number;
	}

public:
	HashTable(){
		dataarray = nullptr;
		parray = nullptr;
		arrsize = 0;
		no_inserted = 0;
	}
	HashTable(int size){
		srand(time(NULL));
		arrsize = size;
		no_inserted = 0;
		dataarray = new int [arrsize]();
		parray = new int[arrsize]();

		for (int i = 0; i < arrsize;){

			bool fit = true;
			int random = rand() % arrsize;
			for (int j = 0; j < i; j++){
				if (parray[j] == random)
					fit = false;
			}
			if (fit){
				parray[i] = random;
				i++;
			}
		}
		cout << "Random array is : ";
		for (int i = 0; i < arrsize; i++)
			cout << parray[i] << " , ";
	}
	int hashfunction(int key){
		int temp = key*key;
		int maxdigits = get_no_of_digits(arrsize-1);
		if (get_no_of_digits(temp) > maxdigits)
			temp = get_middle_digits(temp, maxdigits);

		if (temp > arrsize)
			temp = temp%arrsize;

		return temp;
	}
	void insert(int key){
		if (no_inserted == arrsize)
			cout << "Capacity full " << endl;
		else{
			int index = hashfunction(key);

			if (dataarray[index] == 0)
				dataarray[index] = key;
			else
			{
				bool inserted = false;
				int tempindex = 0;
				for (int i = 0; i < arrsize && inserted == false; i++){
					tempindex = parray[i] + index;
					if (tempindex >= arrsize)
						tempindex = tempindex % arrsize;

					if (dataarray[tempindex] == 0)
						inserted = true;
				}
				dataarray[tempindex] = key;
			}
			no_inserted++;
		}
	}
	void search(int key){
		int index = hashfunction(key);
		bool found = false;
		bool doesntexist = false;
		int tempindex = index;
		for (int i = 0; i < arrsize && found == false && doesntexist == false; i++){
			if (dataarray[tempindex] == key)
				found = true;
			else if (dataarray[tempindex] == 0)
				doesntexist = true;
			else {
				tempindex = index + parray[i];
				if (tempindex > arrsize)
					tempindex = tempindex % arrsize;
			}
		}
		if (found)
			cout << "Key exists at index :" << tempindex << endl;
		else
			cout << "Key doesnt exist " << endl;
	}
	void output(){
		for (int i = 0; i < arrsize; i++){
			cout << dataarray[i] << " , ";
		}
	}
};