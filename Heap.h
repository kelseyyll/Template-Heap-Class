/*
PIC 10C Homework 2, Heap.h
Purpose: Define a template heap class
PIC 10C Homework 2
Author: Kelsey Lin
Date: 01/31/2022
*/

#ifndef __HEAP_H__
#define __HEAP_H__

#include<string>
#include<iostream>
#include <vector>
using std::string;

// Heap<T,CMP>
// when compare elements of type T, have member variable CMP comparator
// then call comparator(t1, t2)

template<typename T, typename CMP = std::greater<T>>
class Heap
{
public:
	Heap(); 
	Heap(std::vector<T> vect); 
	void display(); 
	void push(); // no
	T top(); 
	void pop(); 

	// helper member functions to find parent, left child, right child
	void sift_up(size_t i);
	void sift_down(size_t i); 

	size_t parent(size_t i);
	size_t left_child(size_t i); 
	size_t right_child(size_t i); 

private:
	std::vector<T> data; 
	CMP comparator; 

};


// Default constructor: empty heap
template<typename T, typename CMP>
Heap<T, CMP>::Heap() 
	: data(), comparator()
{
	
}

// Constructor: one arg of vector but construct into heap
template<typename T, typename CMP>
Heap<T, CMP>::Heap(std::vector<T> heap)
	: data(heap),comparator()
{
	//sift_up 0 to length heap-1??
	for (int i = 0; i < (data.size() - 1); i++)
	{
		sift_up(data[i]);
	}


}

// return max of heap ( as defined by comparator)
template<typename T, typename CMP>
T Heap<T, CMP>::top()
{
	if (!(data.empty()))
	{
		return data[0];
	}

}

// helper functions for parent, left child, right child
template<typename T, typename CMP>
size_t Heap<T, CMP>::parent(size_t i)
{
	return (i - 1) / 2;
}

template<typename T, typename CMP>
size_t Heap<T, CMP>::left_child(size_t i)
{
	return 2 * i + 1;
}

template<typename T, typename CMP>
size_t Heap<T, CMP>::right_child(size_t i)
{
	return 2 * i + 2;
}

template<typename T, typename CMP>
void Heap<T, CMP>::sift_down(size_t i)
{
	size_t target_i = i;

	if (left_child(i) < data.size() && comparator(data[left_child(i)], data[target_i]))
	{
		target_i = left_child(i);
	}
	else if (left_child(i) < data.size() && comparator(data[left_child(i)], data[target_i]))
	{
		target_i = right_child(i);
	}

	if (i != target_i)
	{
		// swap index and target index
		T temp = data[target_i];
		data[i] = data[parent(target_i)];
		data[i] = temp;

		// recursively continue
		sift_down(target_i);
	}
}

template<typename T, typename CMP>
void Heap<T, CMP>::sift_up(size_t i)
{
	// if at top
	if (i == 0)
	{
		return;
	}

	if (comparator(data[i], data[parent(i)]))
	{
		// swap index and parent index
		T temp = data[i];
		data[i] = data[parent(i)];
		data[parent(i)] = temp;

		// recursively continue
		sift_up(parent(i));
	}
}

template<typename T, typename CMP>
void Heap<T, CMP>::display()
{
	for (int i = 0; i < (data.size() - 1); i++)
	{
		std::cout << data[i];
	}
}

// remove max value, if empty then no effect
template<typename T, typename CMP>
void Heap<T, CMP>::pop()
{
	if (!(data.empty()))
	{
		data.front() = data.back();
		data.pop_back();

		sift_down(0);
	}

	return 0;
}

// base
template<typename T, typename CMP> //add 
void Heap<T, CMP>::push()
{

}

// variadic ..?
template<typename T, typename CMP> //add 
void Heap<T, CMP>::push()
{

}

// base: empty list of heaps
void print()
{

}

// inductive case
template<typename T, typename CMP, typename... Rest>
void print(Heap<T, CMP> one, Rest... rest)
{
	// 
}

#endif
