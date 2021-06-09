#include "pch.h"
#include "Sorts.h"
#include <stdexcept>

void Sorts::InnerQuickSort(int low, int high)
{
	int i = low;
	int j = high;
	int x = m_pSortingArray[(low + high) / 2];

	do
	{
		while (m_pSortingArray[i] < x) i++;
		while (m_pSortingArray[j] > x) j--;

		if (i <= j)
		{
			int temp = m_pSortingArray[i];
			m_pSortingArray[i++] = m_pSortingArray[j];
			m_pSortingArray[j--] = temp;
		}
	} while (i <= j);

	if (low < j) InnerQuickSort(low, j);
	if (i > high) InnerQuickSort(i, high);
}

void Sorts::Update(int L, int R)
{
	if (L == R) return;
	int i = L;
	int j = 2 * i + 1;
	int x = m_pSortingArray[i];

	while (j <= R)
	{
		if (j < R)
		{
			if (m_pSortingArray[j] < m_pSortingArray[j + 1])
				j++;
		}
		if (x > m_pSortingArray[j])
			break;
		m_pSortingArray[i] = m_pSortingArray[j];
		i = j;
		j = 2 * j + 1;
	}
	m_pSortingArray[i] = x;
}

Sorts::Sorts(int size)
{
	m_pArray = new int[size];
	m_pSortingArray = new int[size];
	m_nSize = size;

	ShuffleArray();
}

Sorts::~Sorts()
{
	delete[] m_pArray;
	delete[] m_pSortingArray;
}

void Sorts::InsertionSort()
{
	for (int i = 1; i < m_nSize; i++)
	{
		int key = m_pSortingArray[i];
		int j = i - 1;

		while (j >= 0 && m_pSortingArray[j] > key)
			m_pSortingArray[j + 1] = m_pSortingArray[j--];
		m_pSortingArray[j + 1] = key;
	}
}

void Sorts::SelectionSort()
{
	for (int i = 0; i < m_nSize - 1; i++)
	{
		int k = i;
		int x = m_pSortingArray[i];

		for (int j = i + 1; j < m_nSize; j++)
		{
			if (m_pSortingArray[j] < x)
			{
				k = j;
				x = m_pSortingArray[k];
			}
		}
		m_pSortingArray[k] = m_pSortingArray[i];
		m_pSortingArray[i] = x;
	}
}

void Sorts::BubbleSort()
{
	for (int i = 0; i < m_nSize - 1; i++)
	{
		for (int j = m_nSize - 1; j > i; j--)
		{
			if (m_pSortingArray[j] < m_pSortingArray[j - 1])
			{
				int temp = m_pSortingArray[j];
				m_pSortingArray[j] = m_pSortingArray[j - 1];
				m_pSortingArray[j - 1] = temp;
			}
		}
	}
}

void Sorts::HalfInsertionSort()
{
	for (int i = 1; i < m_nSize; i++)
	{
		int val = m_pSortingArray[i];
		int begin = 0;
		int end = i - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (val < m_pSortingArray[mid])
				end = mid - 1;
			else
				begin = mid + 1;
		}

		for (int j = i - 1; j >= begin; j--)
		{
			m_pSortingArray[j + 1] = m_pSortingArray[j];
		}

		m_pSortingArray[begin] = val;
	}
}

void Sorts::MixedBubbleSort()
{
	int start = 1;
	int end = m_nSize - 1;
	int k = end;
	do
	{
		for (int j = end; j >= start; j--)
		{
			if (m_pSortingArray[j - 1] > m_pSortingArray[j])
			{
				int temp = m_pSortingArray[j - 1];
				m_pSortingArray[j - 1] = m_pSortingArray[j];
				m_pSortingArray[j] = temp;
				k = j;
			}
		}

		start = k + 1;
		for (int j = start; j <= end; j++)
		{
			if (m_pSortingArray[j - 1] > m_pSortingArray[j])
			{
				int temp = m_pSortingArray[j - 1];
				m_pSortingArray[j - 1] = m_pSortingArray[j];
				m_pSortingArray[j] = temp;
				k = j;
			}
		}

		end = k - 1;
	} while (start < end);
}

void Sorts::HeapSort()
{
	for (int i = m_nSize / 2; i >= 0; i--)
	{
		Update(0, m_nSize - 1);
	}

	for (int i = m_nSize - 1; i > 0; i--)
	{
		int high = m_pSortingArray[0];
		m_pSortingArray[0] = m_pSortingArray[i];
		m_pSortingArray[i] = high;
		Update(0, i - 1);
	}
}

void Sorts::QuickSort()
{
	InnerQuickSort(0, m_nSize - 1);
}

void Sorts::ShuffleArray()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < m_nSize; i++) {
		m_pArray[i] = rand() % m_nSize;
	}
}

double Sorts::MeasureExecutionTime(SortMethod sortMethod)
{
	memcpy(m_pSortingArray, m_pArray, m_nSize * sizeof(int));

	double start = GetTickCount64();
	switch (sortMethod)
	{
	case SortMethod::Bubble:
		BubbleSort();
		break;
	case SortMethod::HalfInsertion:
		HalfInsertionSort();
		break;
	case SortMethod::Insertion:
		InsertionSort();
		break;
	case SortMethod::MixedBubble:
		MixedBubbleSort();
		break;
	case SortMethod::Selection:
		SelectionSort();
		break;
	case SortMethod::Quick:
		QuickSort();
		break;
	case SortMethod::Heap:
		HeapSort();
		break;
	}
	double end = GetTickCount64();

	return (double)((end - start) / CLOCKS_PER_SEC);
}