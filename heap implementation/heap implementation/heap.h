#include<iostream>
#include<math.h>
#include<cmath>
template<class type>
class heap_implementation
{
private:
	type* arr;
	int size_of_arr;
	int size_of_heap;
	int left_bacha;
	int right_bacha;
	int maximum_bacha;
	int get_parent(int element)
	{
		return (floor(element/2));
	}
	int get_left_child(int element)
	{
		return (2*element);
	}
	int get_right_child(int element)
	{
		return ((2*element)+1);
	}
	void recursive_bubble_up(int element)
	{
		int parent_of_child=0;
		if(element!=0)    //base case
		{
			parent_of_child=get_parent(element);
			if(arr[element]>arr[parent_of_child])
			{
				swap(arr[element],arr[parent_of_child]);
				recursive_bubble_up(parent_of_child);
			}
		}
		else
		{
			return;
		}
	}
	void recursive_bubble_down(int element)
	{
		left_bacha=get_left_child(element);
		right_bacha=get_right_child(element);
		if(right_bacha>=size_of_heap)
		{
			if(left_bacha<=size_of_heap) 
			{
				return;
			}
			else
			{
				maximum_bacha=left_bacha;
			}
		}
		else 
		{
			if(arr[left_bacha]>=arr[right_bacha])
			{
				maximum_bacha=left_bacha;
			}
			else
			{
				maximum_bacha=right_bacha;
			}
		}
		if(arr[element]<arr[maximum_bacha])
		{
			swap(arr[maximum_bacha],arr[element]);
			recursive_bubble_down(maximum_bacha);
		}


	}
public:
	//constructor
	heap_implementation()
	{
		size=0;
		arr=NULL;
	}
	//parametrized constructor
	heap_implementation(int size_of_data)          
	{
		maximum_bacha=0;
		left_bacha=0;
		right_bacha=0;
		size_of_heap=1;
		size_of_arr=size_of_data;
		arr= new type[size_of_arr]();
	}
	//destructor
	~heap_implementation()
	{
		delete [] arr;
	}
	void insert_and_heapify(type insert_element)
	{
		if(size_of_heap>=size_of_arr)
		{
			type* temp_ptr=arr;
			int size=size_of_arr;
			size_of_arr=size_of_arr*2;
			arr=new type[size_of_arr]();
			for(int i=1;i<size;i++)
			{
				arr[i]=temp_ptr[i];
			}
			delete temp_ptr;
		}
		size_of_heap++;
		arr[size_of_heap-1]=insert_element;
		recursive_bubble_up(size_of_heap-1);
	}
	void delete_max_and_heapify()
	{
		if(size_of_heap<=1)
		{
			return ;
		}
		else
		{
			arr[0]=arr[size_of_heap-1];
			size_of_heap--;
			if(size_of_heap>2)
			{
				recursive_bubble_down(1);
			}
		}

	}
	void print()
	{
		for(int i=0;i<size_of_heap;i++)
		{
			if(arr[i]!=0)
				cout<<arr[i]<<"|";
		}
	}
	void heap_sort()
	{

	}

};
