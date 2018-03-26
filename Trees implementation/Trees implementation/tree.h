#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<windows.h>
#include<queue>  //to be used in level order traversal
template<class datatype>
struct node
{
	datatype element;
	node<datatype>* left_child;
	node<datatype>* right_child;
};

template<class datatype>
class tree_implementation
{
private:
	node<datatype>* root;
	void recursive_copy(node<datatype>* &copied_into,node<datatype>* copied_from)
	{
		if(copied_from==NULL)
		{
			copied_into=NULL;
		}
		else
		{
			copied_into=new node<datatype>;
			copied_into->element=copied_from->element;
			recursive_copy(copied_into->left_child,copied_from->left_child);
			recursive_copy(copied_into->right_child,copied_from->right_child);
		}
	}
	void recursively_delete(node<datatype>* & root_pointer)
	{
		if(root_pointer!=NULL)
		{
			recursively_delete(root_pointer->left_child);
			recursively_delete(root_pointer->right_child);
			delete root_pointer;
			root_pointer=NULL;
		}
	}
	bool recursive_equality(node<datatype>* root_node_1,node<datatype>* root_node_2)
	{
		if(root_node_1==NULL && root_node_2==NULL)        
		{
			return true;
		}
		return(root_node_1 && root_node_2    &&  (root_node_1->element && root_node_2->element)  && recursive_equality(root_node_1->left_child,root_node_2->left_child) && recursive_equality(root_node_1->right_child,root_node_2->right_child));
	}
	int recursive_depth(node<datatype>* root_node)
	{
		if(root_node==NULL)
		{
			return 0;
		}
		else
		{
			return 1+max_of_2(recursive_depth(root_node->left_child),recursive_depth(root_node->right_child));
		}
	}
	int recursive_count_nodes(node<datatype>* root_pointer)
	{
		int count=0;
		if(root_pointer)
		{
			count++;
			count=count+recursive_count_nodes(root_pointer->left_child);
			count=count+recursive_count_nodes(root_pointer->right_child);

		}
		return count;
	}
	void recursive_mirror(node<datatype>* root_pointer)
	{
		if(root_pointer==NULL)
		{
			return;
		}
		process_node(root_pointer);
		recursive_mirror(root_pointer->left_child);
		recursive_mirror(root_pointer->right_child);
	}
	void  process_node(node<datatype>* root_pointer)
	{
		if(root_pointer==NULL)
		{
			return;
		}
		node<datatype>* temp;
		temp=root_pointer->left_child;
		root_pointer->left_child=root_pointer->right_child;
		root_pointer->right_child=temp;
	}
	int max_of_2(int num1,int num2)
	{
		if(num1>=num2)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}
	void delete_private(node<datatype>* & node_pointer)
	{
		node<datatype>* current;
		node<datatype>* current_previous;
		node<datatype>* temp;
		if(node_pointer==NULL)
		{
			cout<<"The node to be deleted is NULL !"<<endl;
		}
		else if(node_pointer->left_child==NULL && node_pointer->right_child==NULL)
		{
			temp=node_pointer;
			node_pointer=NULL;
			delete temp;
		}
		else if(node_pointer->left_child==NULL)
		{
			temp=node_pointer;
			node_pointer=temp->right_child;
			delete temp;
		}
		else if(node_pointer->right_child==NULL)
		{
			temp==node_pointer;
			node_pointer=temp->left_child;
			delete temp;
		}
		else
		{
			current=node_pointer->left_child;
			current_previous=NULL;
			while (current->right_child!=NULL)
			{
				current_previous=current;
				current=current->right_child;
			}
			node_pointer->element=current->element;
			if(current_previous==NULL)
			{
				node_pointer->left_child=current->left_child;
			}
			else 

			{
				current_previous->right_child=current->left_child;
			}
			delete current;
		}
	}
	void in_order(node<datatype>* node_pointer)
	{
		if(node_pointer!=NULL)
		{
			in_order(node_pointer->left_child);
			cout<<node_pointer->element<<" ";
			in_order(node_pointer->right_child);
		}
	}
	void pre_order(node<datatype>* node_pointer)
	{
		if(node_pointer!=NULL)
		{
			cout<<node_pointer->element<<" ";
			pre_order(node_pointer->left_child);
			pre_order(node_pointer->right_child);
		}
	}
	void post_order(node<datatype>* node_pointer)
	{
		if(node_pointer!=NULL)
		{
			post_order(node_pointer->left_child);
			post_order(node_pointer->right_child);
			cout<<node_pointer->element<<" ";
		}
	}
	void level_by_level_traversal(node<datatype>* node_pointer)
	{
		if(node_pointer==NULL) 
			return;
		queue<node<datatype>*> Q;
		Q.push(root);
		while(!Q.empty())
		{
			node<datatype>* current=Q.front();
			cout<<current->element<<" ";
			if(current->left_child!=NULL)
			{
				Q.push(current->left_child);

			}
			if(current->right_child!=NULL)
			{
				Q.push(current->right_child);
			}
			Q.pop();
		}
	}
	void temp_recursive_inorder(node<datatype>* root_pointer)
	{
		if(root_pointer!=NULL)
		{
			temp_recursive_inorder(root_pointer->left_child);
			cout<<root_pointer->element<<" ";
			temp_recursive_inorder(root_pointer->right_child);
		}
	}
public:

	//constructor and destructor and is_empty function
	tree_implementation()//constructor
	{
		root=NULL;
	}	                 
	~tree_implementation()//destructor

		{
			recursively_delete(root);
		}                 
	bool is_empty()
	{
		return (root==NULL);
	}
	//general functions of tree
	bool search(const datatype & key)
	{
		node<datatype>* current;
		bool found=false;
		if(root==NULL)
		{
			cout<<"The tree is empty and it cannot be searched !"<<endl;
		}
		else
		{
			current=root;
			while(current!=NULL && !found)
			{
				if(current->element==key)
				{
					found=true;
				}
				else if(current->element>key)
				{
					current=current->left_child;
				}
				else
				{
					current=current->right_child;
				}
			}
		}
		return found;
	}
	void insert_item(const datatype & new_element)
	{
		node<datatype>* new_node;
		node<datatype>* current;
		node<datatype>* current_previous;

		new_node=new node<datatype>;
		new_node->element=new_element;
		new_node->left_child=NULL;
		new_node->right_child=NULL;

		if(root==NULL)
		{
			root=new_node;
		}
		else 
		{
			current=root;
			while(current!=NULL)
			{
				current_previous=current;
				if(current->element==new_element)
				{
					cout<<"Duplicates not allowed !"<<endl;
					return;
				}
				else if(current->element>new_element)
				{
					current=current->left_child;
				}
				else 
				{
					current=current->right_child;
				}
			}
			if(current_previous->element>new_element)
			{
				current_previous->left_child=new_node;
			}
			else 
			{
				current_previous->right_child=new_node;
			}
		}
	}
	void delete_item(const datatype & delete_element)
	{
		node<datatype>* current;
		node<datatype>* current_previous;
		bool found=false;
		if(root==NULL)
		{
			cout<<"Cannot delete from an empty tree !"<<endl;
		}
		else
		{
			current=root;
			current_previous=root;
			while (current!=NULL && !found)
			{
				if(current->element==delete_element)
				{
					found=true;
				}
				else
				{
					current_previous=current;
					if(current->element>delete_element)
					{
						current=current->left_child;
					}
					else 
					{
						current=current->right_child;
					}
				}

			}
			if(current==NULL)
			{
				cout<<"The item to be deleted is not in the tree !"<<endl;

			}
			else if(found)
			{
				if(current==root)
				{
					delete_private(root);
				}
				else if(current_previous->element>delete_element)
				{
					delete_private(current_previous->left_child);
				}
				else 
				{
					delete_private(current_previous->right_child);
				}
			}
			else 
			{
				cout<<"The element to be deleted is not in the tree !"<<endl;
			}
		}
	}
	void print()
	{
		int choice=0;
		cout<<"Enter the choice !"<<endl;
		cout<<"Enter 1 for inorder printing of tree !"<<endl;
		cout<<"Enter 2 for preorder printing of tree !"<<endl;
		cout<<"Enter 3 for postorder printing of tree !"<<endl;
		cout<<"Enter 4 for level by level printing of tree!"<<endl;
	    cin>>choice;
		cout<<endl;
		cout<<endl;
		if(choice==1)
		{
			cout<<"The tree is "<<endl;
			in_order(root);
		}
		else if(choice==2)
		{
			cout<<"The tree is "<<endl;
			
			pre_order(root);
		}
		else if(choice==3)
		{
			cout<<"The tree is "<<endl;
			
			post_order(root);
		}
		else if(choice==4)
		{
			cout<<"The tree is "<<endl;
			
			level_by_level_traversal(root);
		}

	}

	//operator= and copy constructor for deep copy of tree
	const tree_implementation<datatype> & operator=(const tree_implementation<datatype> & rightobject)
	{
		if(this!=&rightobject)
		{
			if(root!=NULL)
			{
				recursively_delete(root);
			}
			if(rightobject.root==NULL)
			{
				root=NULL;
			}
			else
			{
				recursive_copy(root,rightobject.root);
			}
		}
		return *this;
	}
	tree_implementation(const tree_implementation<datatype> & rightobject)
	{
		if(rightobject.root==NULL)
		{
			root=NULL;
		}
		else
			recursive_copy(root,rightobject.root);
		
	}
	//operator== and count_nodes and heigth or depth of tree and mirror binary tree function
	bool operator==(const tree_implementation<datatype> & rightobject)
	{
		return recursive_equality(root,rightobject.root);

	}
	int count_nodes()
	{
		int count=0;
		count=recursive_count_nodes(root);
		return count;
	}
	int depth()
	{
		return recursive_depth(root);
	}
	void mirror_bst()
	{
		recursive_mirror(root);
	}
	void temp_inorder_traversal()
	{
		temp_recursive_inorder(root);
	}
};