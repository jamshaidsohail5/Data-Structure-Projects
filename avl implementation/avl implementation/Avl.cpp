#include <iostream>
#include <conio.h>
using namespace std;
template<class A>
class queue
{
public:
	queue()
	{
		ptr = NULL;
		size = 0;
	}
	bool operator ==(const queue &obj)
	{
		bool result = true;
		if (size != obj.size)
			return false;
		else
			for (int i = 0; i < size; i++)
				if (obj.ptr[i] != ptr[i])
					result = false;
		return result;
	}
	void add(A data)
	{
		if (ptr == NULL)
		{
			ptr = new A[1]();
			ptr[size] = data;
			size++;
		}
		else
		{
			A*temp = new A[size]();
			for (int i = 0; i < size; i++)
				temp[i] = ptr[i];
			delete[]ptr;
			ptr = new A[size + 1];
			for (int i = 0; i < size; i++)
				ptr[i] = temp[i];
			ptr[size] = data;
			size++;
		}
	}
	A get()
	{
		if (size != 0)
		{
			A *temp = new A[size - 1](), parent = ptr[size - 1];
			for (int i = 0; i < size - 1; i++)
				temp[i] = ptr[i];
			delete[]ptr;
			ptr = new A[size - 1]();
			for (int i = 0; i < size - 1; i++)
				ptr[i] = temp[i];
			size--;
			return parent;
		}
	}
	int get_size()
	{
		return size;
	}
	~queue()
	{
		delete[]ptr;
		ptr = NULL;
	}

private:
	A *ptr;
	int size;
};
class Tree
{
private:
	struct node
	{
		node*left;
		node*right;
		int data;
	};
	node*root;
	queue<int> a;
	node* create_node(int a)
	{
		node * temp = new node;
		temp->data = a;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
public:
	Tree()
	{
		root = NULL;
	}
	node * search(int a)
	{
		node * temp = root;
		while (temp)
		{
			if (temp->data = a)
			{
				return temp;
				break;
			}
			else if (a > temp->data)
				temp = temp->right;
			else if (a < temp->data)
				temp = temp->left;
		}
		return NULL;
	}
	void insert(int a)
	{
		if (root == NULL)
		{
			root = create_node(a);
		}
		else
		{
			node* temp = root;
			node* Nodetemp = NULL;
			bool datadoesnotxist = true;
			while (temp)
			{
				Nodetemp = temp;
				if (a>temp->data)
					temp = temp->right;
				else if (a < temp->data)
					temp = temp->left;
				else {
					cout << "Data already exists" << endl;
					datadoesnotxist = false;
					return;
				}
			}
			if (datadoesnotxist) {
				if (a > Nodetemp->data)
					Nodetemp->right = create_node(a);
				else if (a < Nodetemp->data)
					Nodetemp->left = create_node(a);
			}
		}
		node * Node = NULL;
		node * t = im_balance(root, Node);
		if (t != NULL)
		{
			if (t->left != NULL && balance_factor(t->left) == 1)
			{
				left_left(t, Node);
			}
			if (t->left != NULL && balance_factor(t->left) == -1)
			{
				left_right(t, Node);
			}
			if (t->right != NULL && balance_factor(t->right) == -1)
			{
				right_right(t, Node);
			}
			if (t->right != NULL && balance_factor(t->right) == 1)
			{
				right_left(t, Node);
			}
		}
	}
	node * im_balance(node * r, node * & Node)
	{
		bool found = false;
		bool found1 = false;
		while (r != NULL && found1 == false && (balance_factor(r) >= 2 || balance_factor(r) <= -2)) {
			found = true;
			found1 = true;
			if (r->left != NULL && (balance_factor(r->left) >= 2 || balance_factor(r->left) <= -2)) {
				found1 = false;
				Node = r;
				r = r->left;
			}
			if (r->right != NULL && (balance_factor(r->right) >= 2 || balance_factor(r->right) <= -2)) {
				found1 = false;
				Node = r;
				r = r->right;
			}
		}
		if (found)
			return r;
		return NULL;
	}
	void left_left(node * t, node * Node)
	{
		node * temptemp = t->left;
		node * tempright = temptemp->right;
		temptemp->right = t;
		if (Node != NULL)
		{
			if (Node->left == t) {
				Node->left = temptemp;
			}
			else if (Node->right == t) {
				Node->right = temptemp;
			}
			t->left = tempright;
		}
		else
		{
			root = temptemp;
			t->left = tempright;
		}
		temptemp = NULL;
		tempright = NULL;
	}
	void left_right(node * t, node * Node)
	{
		node * B = t->left;
		node * C = B->right;
		t->left = C->right;
		B->right = C->left;
		C->left = B;
		C->right= t;
		if (Node != NULL)
		{
			if (Node->left == t) {
				Node->left = C;
			}
			else if (Node->right == t) {
				Node->right = C;
			}
		}
		else
		{
			root = C;
		}
		B = NULL;
		C = NULL;
	}
	void right_right(node *t, node * Node)
	{
		node * B = t->right;
		node * templeft = B->left;
		B->left = t;
		t->right = templeft;
		if (Node != NULL)
		{
			if (Node->left == t) {
				Node->left = B;
			}
			else if (Node->right == t) {
				Node->right = B;
			}
		}
		else
		{
			root = B;
		}
		B = NULL;
		templeft = NULL;
	}
	void right_left(node * t, node * Node)
	{
		node * B = t->right;
		node * C = B->left;
		t->right = C->left;
		B->left = C->right;
		C->left = t;
		C->right = B;
		if (Node != NULL)
		{
			if (Node->left == t) {
				Node->left = C;
			}
			else if (Node->right == t) {
				Node->right = C;
			}
		}
		else
		{
			root = C;
		}
		B = NULL;
		C = NULL;
	}
	int balance_factor(node * temp)
	{
		int left_height = 0, right_height = 0;
		if (temp->left != NULL)
			left_height = height(temp->left);
		if (temp->right != NULL)
			right_height = height(temp->right);
		int bal_fac = left_height - right_height;
		return bal_fac;
	}
	int height(node * t)
	{
		int h = 0;
		if (t != NULL)
		{
			int lh = height(t->left);
			int rh = height(t->right);
			if (lh > rh)
				h = lh + 1;
			else
				h = rh + 1;
		}
		return h;
	}
	bool operator==(Tree &obj)
	{
		copy(root), obj.copy(obj.root);
		return (obj.a == a);
	}
	void remove(int data)
	{
		node * temp = root;
		node * parent = NULL;
		bool found = false;
		while (temp)
		{
			if (temp->data == data)
			{
				found = true;
				break;
			}
			else
			{
				parent = temp;
				if (data > temp->data)
					temp = temp->right;
				else if (data < temp->data)
					temp = temp->left;
			}
		}
		if (!found)
		{
			cout << "Key Not Found";
			return;
		}
		if (temp->left == NULL && temp->right == NULL) //case 1 both child are absent
		{
			if (parent == NULL)
				root = NULL;
			if (parent != NULL && parent->left == temp)
				parent->left = NULL;
			else if (parent != NULL && parent->right == temp)
				parent->right = NULL;
			delete[] temp;
			temp = NULL;
		}
		else if (temp->left == NULL || temp->right == NULL) //case 2 only 1 child
		{
			if (parent == NULL)
				if (temp->right != NULL)
					root = temp->right;
				else
					root = temp->left;
			if (parent != NULL && parent->left == temp)
				if (temp->left != NULL)
					parent->left = temp->left;
				else
					parent->left = temp->right;
			else if (parent != NULL && parent->right == temp)
				if (temp->left != NULL)
					parent->right = temp->left;
				else
					parent->right = temp->right;
			delete[] temp;
		}
		else //case 3 both children are present
		{
			node * temp2 = temp->right;
			while (temp2->left != NULL && temp2->right != NULL)
				temp2 = temp2->left;
			if (temp->left != temp2)
				temp2->left = temp->left;
			if (temp->right != temp2)
				temp2->right = temp->right;
			if (parent != NULL && parent->left == temp)
				parent->left = temp2;
			else if (parent != NULL && parent->right == temp)
				parent->right = temp2;
			if (parent == NULL)
				root = temp2;
			delete[] temp;
		}
	}
	void copy(node*p)
	{
		if (p != NULL)
		{
			if (p->left) copy(p->left);
			a.add(p->data);
			if (p->right) copy(p->right);
		}
		else return;
	}
	Tree(const Tree &obj)
	{
		root = NULL;
		copy(obj.root);
		while (a.get_size() != 0)
			insert(a.get());
	}
	Tree operator=(const Tree &obj)
	{
		root = NULL;
		root = NULL;
		copy(obj.root);
		while (a.get_size() != 0)
			insert(a.get());
		return *this;
	}
	bool is_Empty()
	{
		return (root == NULL);
	}
	void inorder(node *ptr)
	{
		if (!ptr)
			return;
		if (ptr->left)
			inorder(ptr->left);
		cout << ptr->data << " ";
		if (ptr->right)
			inorder(ptr->right);
	}
	void print_inorder()
	{
		inorder(root);
	}
	void postorder(node * ptr)
	{
		if (!ptr)
			return;
		if (ptr->left)
			inorder(ptr->left);
		if (ptr->right)
			inorder(ptr->right);
		cout << ptr->data << " ";
	}
	void print_postorder()
	{
		postorder(root);
	}
	void preorder(node*ptr)
	{
		if (!ptr)
			return;
		cout << ptr->data << " ";
		if (ptr->left)
			inorder(ptr->left);
		if (ptr->right)
			inorder(ptr->right);
	}
	void print_preorder()
	{
		preorder(root);
	}
	int sum(node *ptr)
	{
		if (ptr == NULL)
			return 0;
		else
			return (ptr->data + sum(ptr->left) + sum(ptr->right));
	}
	node* get()
	{
		return root;
	}
	~Tree()
	{
		while (root!=NULL)
		{
			remove(root->data);
		}
	}
};
#define TREE Tree
void main()
{
	TREE b;
	TREE b1;
	b.insert(50);
	b.insert(25);
	b.insert(75);
	b.insert(100);
	b.remove(75);
	b.print_inorder();
	b1 = b;
	cout << endl;
	_getch();
}