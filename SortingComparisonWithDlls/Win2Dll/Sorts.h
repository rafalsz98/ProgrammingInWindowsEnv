#pragma once

#include <vector>

enum class SortMethod { Bubble, HalfInsertion, Insertion, MixedBubble, Selection, Quick, Heap };

class Sorts
{
	int* m_pArray;
	int* m_pSortingArray;
	int m_nSize;

	void InnerQuickSort(int low, int high);
	void Update(int L, int R);
public:
	Sorts(int size);
	~Sorts();

	void InsertionSort();
	void SelectionSort();
	void BubbleSort();
	void HalfInsertionSort();
	void MixedBubbleSort();
	void HeapSort();
	void QuickSort();

	void ShuffleArray();
	double MeasureExecutionTime(SortMethod sortMethod);

};

