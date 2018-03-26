#include<iostream>
using namespace std;
class tree{
private:
	struct node{
		node * left;
		node * middle;
		node * right;
		int dl;
		int dr;
	};

	node * root;
	node * createnode(int a = -1, int b = -1){
		node * temp = new node;
		temp->dl = a;
		temp->dr = b;
		temp->left = nullptr;
		temp->right = nullptr;
		temp->middle = nullptr;
		return temp;
	}
	node * getprevious(node * a){
		node * pre = nullptr;
		node * temp = root;
		bool notfound = true;
		while (temp && notfound){
			if (temp == a)
				notfound = false;
			else{
				pre = temp;
				if (a->dl > temp->dl && a->dl < temp->dr)
					temp = temp->middle;
				else if (a->dl < temp->dl)
					temp = temp->left;
				else if (a->dl > temp->dr)
					temp = temp->right;
			}
		}
		return pre;
	}
public:
	tree(){
		root = nullptr;
	}
	void insert(int data){
		bool exists = search(data);
		if (exists)
			cout << "Data already exists !" << endl;
		else{
			if (root == nullptr)
			{
				node * temp = createnode(data);
				root = temp;
			}
			else {
				node * temp = root;
				node * insertat = nullptr;
				while (temp){
					insertat = temp;
					if (temp->left == nullptr && temp->right == nullptr && temp->middle == nullptr)
						temp = nullptr;

					else if (temp->dr == -1){
						if (temp->dl > data)
							temp = temp->left;
						else
							temp = temp->right;
					}
					else if (temp->dl == -1){
						if (temp->dr < data)
							temp = temp->right;
						else
							temp = temp->left;
					}
					else{
						if (temp->dl < data && temp->dr > data)
							temp = temp->middle;
						else if (temp->dl > data)
							temp = temp->left;
						else if (temp->dr < data)
							temp = temp->right;
					}
				}
				bool inserted = false;
				node * temp1 = nullptr;
				node * temp2 = nullptr;
				node * temp3 = nullptr;
				node * temp4 = nullptr;
				while (inserted == false){
					if (insertat == nullptr){
						node * tt = createnode(data);
						tt->left = temp1;
						tt->right = temp2;
						root = tt;
						inserted = true;
					}
					else if (insertat->dl == -1 && insertat->dr == -1){
						insertat->dl = data;
						insertat->left = temp1;
						insertat->middle = temp2;
						insertat->right = temp3;
						inserted = true;
					}
					else if (insertat->dl == -1){
						if (data > insertat->dr){
							insertat->dl = insertat->dr;
							insertat->dr = data;
						}
						else
							insertat->dl = data;

						inserted = true;
						insertat->left = temp1;
						insertat->middle = temp2;
						insertat->right = temp3;
					}
					else if (insertat->dr == -1){
						if (data < insertat->dl){
							insertat->dr = insertat->dl;
							insertat->dl = data;
						}
						else
							insertat->dr = data;

						inserted = true;
						insertat->left = temp1;
						insertat->middle = temp2;
						insertat->right = temp3;
					}
					else{
						bool l = false;
						bool m = false;
						bool r = false;
						node * previous = getprevious(insertat);
						if (previous != nullptr){
							if (insertat == previous->left)
								l = true;
							else if (insertat == previous->middle)
								m = true;
							else if (insertat == previous->right)
								r = true;
						}
						int dataleft = insertat->dl;
						int dataright = insertat->dr;
						int dataup = data;

						if (dataup < dataleft)
							swap(dataleft, dataup);
						else if (dataup > dataright)
							swap(dataup, dataright);

						node * split_left = createnode(dataleft);
						node * split_right = createnode(dataright);

						split_left->left = temp1;
						split_left->right = temp2;
						split_right->left = temp3;
						split_right->right = temp4;

						data = dataup;

						if (previous == nullptr){
							temp1 = split_left;
							temp2 = split_right;
						}
						else{
							bool three_or_four_split = false;

							if (previous->dl != -1 && previous->dr != -1)
								three_or_four_split = true;

							if (three_or_four_split){
								if (l){
									temp1 = split_left;
									temp2 = split_right;
									temp3 = previous->middle;
									temp4 = previous->right;
								}
								else if (m){
									temp1 = previous->left;
									temp2 = split_left;
									temp3 = split_right;
									temp4 = previous->right;
								}
								else if (r){
									temp1 = previous->left;
									temp2 = previous->middle;
									temp3 = split_left;
									temp4 = split_right;
								}
							}
							else{
								if (l){
									temp1 = split_left;
									temp2 = split_right;
									temp3 = previous->right;
								}
								else if (r){
									temp1 = previous->left;
									temp2 = split_left;
									temp3 = split_right;
								}
								temp4 = nullptr;
							}
						}
						insertat = getprevious(insertat);
					}
				}
			}
		}
	}
	void print(){
		output(root);
	}
	void output(node * a){
		if (a == nullptr)
			return;

		if (a->dl != -1)
			cout << a->dl;
		else
			cout << "-";
		cout << ","; 
		if (a->dr != -1)
			cout << a->dr;
		else
			cout << "-";
		cout << "    ";

		output(a->left);
		output(a->middle);
		output(a->right);
	}
	bool search(int data){
		node * temp = root;
		bool found = false;
		while (temp && found == false){
			if (temp->dl == data || temp->dr == data)
				found = true;
			else{
					if (temp->left == nullptr && temp->right == nullptr && temp->middle == nullptr)
						temp = nullptr;

					else if (temp->dr == -1){
						if (temp->dl > data)
							temp = temp->left;
						else
							temp = temp->right;
					}
					else if (temp->dl == -1){
						if (temp->dr < data)
							temp = temp->right;
						else
							temp = temp->left;
					}
					else{
						if (temp->dl < data && temp->dr > data)
							temp = temp->middle;
						else if (temp->dl > data)
							temp = temp->left;
						else if (temp->dr < data)
							temp = temp->right;
				}
			}
		}
		return found;
	}	
};