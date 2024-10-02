#ifndef QUICKSORTCLASS_H
#define QUICKSORTCLASS_H

#include "sortClass.h"
#include <iostream>
#include <vector>
#include <stack>

class quickSortClass : public sortClass {
public:
	void beginAccord();							// 启动计时器
	void endAccord();							// 关闭计时器
	double getRunTime();						// 获取执行时间
	
	void validTestRecursionAction();			// 递归quick Sort的有效性验证
	void validTestNonRecursionAction();			// 非递归quick Sort的有效性验证
	void validUpdateAction();					// 改进的quick Sort 的有效性验证
	
	void cleanCnt();							// 清除若干计数器
	
	double run_recursionAction(); 						// 配置不同的数据并启动排序,递归的
	void recursionAction(long long int*, int, int);		// 递归的 quick Sort 的实现主函数
	int partiation(long long int*, int, int);			// 区间划分函数
	
	double run_NonRecursionAction(); 						// 配置不同的数据并启动排序,非递归的
	void NonRecursionAction(long long int*, int, int);		// 非递归的 quick Sort 的实现主函数
	
	int bfprt(long long int*, int, int);					// bfprt 算法，寻找最优枢轴值（选择第 k 小的元素）
	int updatePartiation(long long int*, int, int, int);	// 新的区间划分函数
	void updateAction(long long int*, int, int);			// 改进的quick Sort 的实现
	double run_udateAction(); 								// 配置不同的数据并启动排序,优化的quick sort
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	long long int getCompareCnt();				// 获取compareCnt
	long long int getExchageCnt();				// 获取exchageCnt
	
	quickSortClass(testData* data);		
	~quickSortClass();
	
private:
	dataGenerator* dataGenPtr;
	long long int* assistantArr;
	long long int compareCnt;
	long long int exchageCnt;
};

#endif
