#include<iostream>
#include<conio.h>
using namespace std;
template < class A >
class u_array
{
public:
	u_array(int din, int *ptr)
	{
		int s = 1;
		dim = new int[din]();
		for (int i = 0; i < din; i++)
		{
			s = ptr[i] * s;
			dim[i] = ptr[i];
		}
		data = new A[s]();
		dt_size = s;
		d_size = din;
	}
	u_array(const u_array &obj)
	{
		dt_size = obj.dt_size;
		d_size = obj.d_size;
		data = new A[d_size]();
		dim = new int[d_size]();
		for (int i = 0; i < dt_size; i++)
		{
			data[i] = obj.data[i];
		}
		for (int i = 0; i < d_size; i++)
		{
			dim = obj.dim;
		}
	}
	bool set(A x, int *ptr, int size)
	{
		if (size != d_size)
			return false;
		else
		{
			if (getIndex(ptr, size) >= dt_size)
				return false;
			data[getIndex(ptr, size)] = x;
			return true;
		}
	}
	bool get(int *ptr, int size, A & obj)
	{
		if (size != d_size)
			return false;
		else
		{
			if (getIndex(ptr, size) >= dt_size)
				return false;
			obj = data[getIndex(ptr, size)];
			return true;
		}
	}
	~u_array()
	{
		delete[]dim;
		delete[]data;
	}
private:
	int *dim;
	int d_size;
	A *data;
	int dt_size;
	
	
	
	int getIndex(int * d, int size)
	{
		int Index = 0;
		for (int i = 0; i < size; i++)
		{
			int temp = d[i];
			for (int j = i + 1; j < size; j++)
				temp = temp*dim[j];
			Index = Index + temp;
		}
		return Index;
	}



};
template <>
class u_array < char * >
{
public:
	u_array(int din, int *ptr)
	{
		int s = 1;
		dim = new int[din]();
		for (int i = 0; i < din; i++)
		{
			s = ptr[i] * s;
			dim[i] = ptr[i];
		}
		data = new char *[s]();
		for (int i = 0; i < s; i++)
		{
			data[i] = nullptr;
		}
		dt_size = s;
		d_size = din;
	}
	u_array(const u_array &obj)
	{
		dt_size = obj.dt_size;
		d_size = obj.d_size;
		data = new char *[d_size]();
		dim = new int[d_size]();
		for (int i = 0; i < dt_size; i++)
		{
			data[i] = new char[strlen(obj.data[i])]();
			strcpy(data[i], obj.data[i]);
		}
		for (int i = 0; i < d_size; i++)
		{
			dim = obj.dim;
		}
	}
	bool set(char *x, int *ptr, int size)
	{
		if (size != d_size)
			return false;
		else
		{
			if (getIndex(ptr, size) >= dt_size)
				return false;
			data[getIndex(ptr, size)] = new char[strlen(x) + 1]();
			strcpy(data[getIndex(ptr, size)], x);
			return true;
		}
	}
	bool get(int *ptr, int size, char *& obj)
	{
		if (size != d_size)
			return false;
		else
		{
			if (getIndex(ptr, size) >= dt_size)
				return false;
			obj = new char[strlen(data[getIndex(ptr, size)])]();
			strcpy(obj, data[getIndex(ptr, size)]);
			return true;
		}
	}
	~u_array()
	{
		delete[]dim;
		delete[]data;
	}
private:
	int *dim;
	int d_size;
	char  **data;
	int dt_size;
	int getIndex(int * d, int size)
	{
		int Index = 0;
		for (int i = 0; i < size; i++)
		{
			int temp = d[i];
			for (int j = i + 1; j < size; j++)
				temp = temp*dim[j];
			Index = Index + temp;
		}
		return Index;
	}
};
int main()
{
	int size = 5, ptr[] = { 5, 5, 5, 5, 5 };
	u_array<char> a(size, ptr);
	
	int ptr1[] = { 4, 4, 4, 4, 4 };
	
	char arr = 'a';
	
	a.set(arr, ptr1, size);
	
	char b = 0;
	
	a.get(ptr1, size, b);
	
	
	if (b != NULL)
		cout << b;

	cout << endl;
	_getch();
}
