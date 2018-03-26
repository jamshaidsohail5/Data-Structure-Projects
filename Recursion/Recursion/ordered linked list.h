#include<iostream>

template <class type>
struct node
{
	type element;
	node<type>* next;
};
template<class type>
class ordered_linked_list
{
public:
	ordered_linked_list()
	{
		count=0;
		first=NULL;
		last=NULL;
	}
	bool search(const type& searchitem);
	void insert(const type & newitem);
	void insert_first(const type & newitem);
	void insert_last(const type & newitem);
	void delete_item(const type & deleteitem);
	void print(node<type>* current );
	void print_reverse(node<type>* current);
	void search_recursively(node<type>* temp,const type searchitem);
private:
	int count;
	node<type>* first;
	node<type>* last;
};
template  <class  type>
bool  ordered_linked_list<type>::search(const  type & searchItem) 
{ 
	{
		bool = found = false; 
		node<type> *current; 
		current = first; 
		while  (current != NULL && !found)
			if  (current->info >= searchItem)
				found = true; ;
			else
				current = current->link;
		if  (found)
		{
			found = (current->info == searchItem); //test for equality
		}
		return found;
	}
}
template<class type>
void ordered_linked_list<type>::insert(const type & newitem)
{
	node<type>* current;
	node<type>* trailcurrent;
	node<type>* newnode;

	bool found;
	newnode=new node<type>;
	newnode->element=newitem;
	newnode->next=NULL;

	if(first==NULL)
	{
		first=newnode;
		last=newnode;
		count++;
	}
	else
	{
		current=first;
		found=false;
		while(current!=NULL && !found)
		{
			if(current->element>=newitem)
			{
				found=true;
			}
			else
			{
				trailcurrent=current;
				current=current->next;
			}

		}
		if (current==first)
		{
			newnode->next=first;
			first=newnode;
			count++;
		}
		else
		{
			trailcurrent->next=newnode;
			newnode->next=current;
			if(current==NULL)
			{
				last =  newnode;
			}
			count++;
		}
	}
}
template<class type>
void ordered_linked_list<type>::insert_first(const type & newitem)
{
	insert(newitem);
}
template<class type>
void ordered_linked_list<type>::insert_last(const type & newitem)
{
	insert(newitem);
}
template<class type>
void ordered_linked_list<type>::delete_item(const type & deleteitem)
{
	node<type>* current;
	node<type>* trail_current;
	bool found;
	if(first==NULL)
	{
		cout<<"Cannot delete from an empty list !"<<endl;
	}
	else
	{
		current=first;
		found=false;
		while(current!=NULL && !found)
		{
			if(current->element>=deleteitem)
			{
				found=true;
			}
			else
			{
				trail_current=current;
				current=current->next;
			}

		}
		if(current==NULL)
		{
			cout<<"The item to be deleted is not in the list !"<<endl;
		}
		else
		{
			if(current->element==deleteitem)
			{
				if(first==current)
				{
					first=first->next;
					if(first==NULL)
						last=NULL;
					delete current;
				}
				else

				{
					trail_current->next=current->next;
					if(current==last)
						last=trail_current;
					delete current;
				}
				count--;
			}
			else
			{
				cout<<"The item to be deleted is not in the list !"<<endl;
			}

		}

	}
}
template<class type>
void ordered_linked_list<type>::print(node<type>* current)
{
	node<type>* current=NULL;
	current=first;
	if(current!=NULL)
	{
		cout<<current->element<<" ";
		print_reverse(current->next);
	}
}
template<class type>
void ordered_linked_list<type>::print_reverse(node<type>* current)
{
	node<type>* current=NULL;
	current=first;
	if(current!=NULL)
	{
		print_reverse(current->next);
		cout<<current->element<<" ";
	}
}
template<class type>
void ordered_linked_list<type>::search_recursively(node<type> * temp,const type searchitem)
{
	temp=first;
	if(current->element==searchitem)
	{
		cout<<"Key is present in list !"<<endl;
	}
	if(current->next==NULL)
	{
		cout<<"Key not found !"<<endl;
		return ;
	}
	search_recursively(current->next,key);
}