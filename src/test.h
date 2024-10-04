#ifndef TEST_H
#define TEST_H

#include "dataGenerator.h"
#include "runtimeCal.h"
#include "bubbleSortClass.h"
#include "heapSortClass.h"
#include "mergeSortClass.h"
#include "quickSortClass.h"
#include "sortClass.h"
#include "windows.h"
#include <iomanip>


class test {
public:
	void testBuddleSortRunTime(ll scope);			// 测试冒泡排序对不同序列的数据排序的运行时间性能
	void testHeapSortRunTime(ll scope);				// 测试堆排序对不同序列的数据排序的运行时间性能
	void testMergeSortRunTime(ll scope);				// 测试归并排序对不同序列的数据排序的运行时间性能
	void testQuicSortRunTime(ll scope);				// 测试快速排序（递归）对不同序列的数据排序的运行时间性能
	void testQuicSortNonRecursionAction(ll scope);	// 测试快速排序（非递归）对不同序列的数据排序的运行时间性能
	void testQuicSortUpdateAction(ll scope);			// 测试快速排序（改进的）对不同序列的数据排序的运行时间性能
	
	void testStableBubbleSort();								// 冒泡排序稳定性测试
	void testStableHeapSort();									// 堆排序稳定性测试
	void testStableMergeSort();									// 归并排序稳定性测试
	void testStableQuickSort();									// 快速排序稳定性测试
	
	void testValidBubbleSort();
	void testValidHeapSort();
	void testValidMergeSort();
	void testValidQuickSort();
	void testValidUnQuickSort();
	void testValidUpQuickSort();
	
private:
	
};

#endif
