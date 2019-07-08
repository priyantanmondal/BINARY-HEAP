#include<iostream>
using namespace std;

class binaryheap
{
	public:
	int* arr;
	int msize;
	int csize;
	binaryheap(int max)
	{
		msize=max;
		arr=new int[msize];
		csize=0;
	}
	
	int parent(int i){ return (i-1)/2;}
	int left(int i){ return 2*i+1;}
	int right(int i){	return 2*i+2;}
	
	void swap(int* a,int* b)
	{
		int c=*a;
		*a=*b;
		*b=c;
	}
	
	void insert(int val)
	{
		if(csize==msize)
		{
			cout<<"heap overflow!"<<endl;
		}
		else
		{
			int i=csize;
			csize++;
			arr[i]=val;
			while(i!=0 && arr[parent(i)]>arr[i])
			{
				swap(&arr[parent(i)],&arr[i]);
				i=parent(i);
			}
		}
	}
	
	int smaller(int i)
	{
		if(arr[left(i)] < arr[right(i)])
		{
			return left(i);
		}
		else
		{
			return right(i);
		}
	}
	
	void heapify(int i)
	{
		while( i<csize && smaller(i)<csize &&  arr[smaller(i)]<arr[i] )
		{
			int newi=smaller(i);
			swap(&arr[smaller(i)],&arr[i]);
			i=newi;
		}
	}
	
	void delet(int i)
	{
		if(i>csize)
		{
			cout<<"wrong index"<<endl;
		}
		else
		{
			if(left(i)>(csize-1) && right(i)>(csize-1))
			{
				arr[i]=arr[csize-1];
				csize--;
				while(i!=0 && arr[parent(i)]>arr[i])
				{
					swap(&arr[parent(i)],&arr[i]);
					i=parent(i);
				}
			}
			else if(left(i)<(csize-1) && right(i)>(csize-1))
			{
				arr[i]=arr[left(i)];
				csize--;
			}
			else
			{
				arr[i]=arr[csize-1];
				csize--;
				heapify(i);
			}
		}
	}
	
	
	void display()
	{
		if(csize==0)
		{
			cout<<" binaryheap is empty"<<endl;
		}
		else
		{
			int i=0;
			while(i<csize)
			{
				cout<<arr[i]<<" ";
				i++;
			}
		}
	}
	
	int getmin()
	{
		cout<<"minimum element is:"<<arr[0];
		return arr[0];
	}
	
	int extractmin()
	{
		int root=arr[0];
		delet(0);
		return root;
	}
	
	void decreasekey(int i,int val)
	{
		arr[i]=val;
		while(i!=0 && arr[parent(i)]>arr[i])
		{
			swap(&arr[parent(i)],&arr[i]);
			i=parent(i);
		}
	}
	
	void increasekey(int i,int val)
	{
		arr[i]=val;
		heapify(i);
	}
	
	void replacekey(int i,int val)
	{
		arr[i]=val;
		if(arr[parent(i)]>val)
		{
			while(i!=0 && arr[parent(i)]>arr[i])
			{
				swap(&arr[parent(i)],&arr[i]);
				i=parent(i);
			}
		}
		else
		{
			heapify(i);
		}
	}
	
};

int main()
{
	binaryheap b1(10);
	b1.insert(7);
	b1.insert(10);
	b1.insert(50);
	b1.insert(11);
	b1.insert(12);
	b1.insert(75);
	b1.insert(51);
	b1.insert(14);
	b1.insert(15);
	b1.insert(21);
	b1.display();
	cout<<endl;
	b1.display();
	cout<<endl;
	return 0;
}

			
	
	
	
	
