// sortedPQ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void quickSort(int a[], int first, int last);
int pivot(int a[], int first, int last);
void swap(int& a, int& b);
void swapNoTemp(int& a, int& b);
void print(int array[], const int& N);

class PriorityQueue
{
public:
	PriorityQueue() { currentSize = 0; front = 0; end = 0; arraySize = 10; }
	void add(int inData);
	void remove(void);
	void display(void);
	void top(void);

private:
	int list[10];
	int arraySize;
	int currentSize;
	int end;
	int front;
};

void PriorityQueue::add(int inData)
{
	if (currentSize == arraySize) // catch overflow
	{
		cout << "OVERFLOW" << "\n";
	}
	else
	{
		cout << "Added " << inData << "\n";
		if (currentSize == 0)
		{
			list[end] = inData;
		}
		else
		{
			end++;
			if (end >= arraySize)
			{
				end = 0;
			}
			list[end] = inData;
		}
		currentSize++;
	}
	quickSort(list, front, end);
}

void PriorityQueue::display(void)
{
	cout << "Displaying:\n";
	int j = front;
	for (int i = 0; i < currentSize; i++)
	{
		cout << list[j] << "\n";
		j++;
		if (j == arraySize)
		{
			j = 0;
		}
	}
}

void PriorityQueue::remove(void)
{
	if (currentSize == 0) // catch overflow
	{
		cout << "UNDERFLOW" << "\n";
	}
	else
	{
		cout << "Removed " << list[front] << "\n";
		front++;
		if (front == arraySize)
		{
			front = 0;
		}
		currentSize--;
	}
}

int main()
{
	cout << "Dylan Maynard \t 04/11/18\n\n";
	PriorityQueue pq;
	pq.add(3);
	pq.add(8);
	pq.add(2);
	pq.display();
	pq.remove();
	pq.display();
	pq.remove();
	pq.display();

	return 0;
}
/**
* Quicksort.
* @param a - The array to be sorted.
* @param first - The start of the sequence to be sorted.
* @param last - The end of the sequence to be sorted.
*/
void quickSort(int a[], int first, int last)
{
	int pivotElement;
	if (first < last)
	{
		pivotElement = pivot(a, first, last);
		quickSort(a, first, pivotElement - 1);
		quickSort(a, pivotElement + 1, last);
	}
}
/**
* Find and return the index of pivot element.
* @param a - The array.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
* @return - the pivot element
*/
int pivot(int a[], int first, int last)
{
	int p = first;
	int pivotElement = a[first];
	for (int i = first + 1; i <= last; i++)
	{
		/* If you want to sort the list in the other order, change "<=" to ">" */
		if (a[i] <= pivotElement)
		{
			p++;
			swap(a[i], a[p]);
		}
	}
	swap(a[p], a[first]);
	return p;
}
/**
* Swap the parameters.
* @param a - The first parameter.
* @param b - The second parameter.
*/
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
/**
* Swap the parameters without a temp variable.
* Warning! Prone to overflow/underflow.
* @param a - The first parameter.
* @param b - The second parameter.
*/
void swapNoTemp(int& a, int& b)
{
	a -= b;
	b += a;// b gets the original value of a
	a = (b - a);// a gets the original value of b
}
/**
* Print an array.
* @param a - The array.
* @param N - The size of the array.
*/
void print(int a[], const int& N)
{
	for (int i = 0; i < N; i++)
		cout << "array[" << i << "] = " << a[i] << endl;
}
