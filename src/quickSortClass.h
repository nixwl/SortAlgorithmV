#ifndef QUICKSORTCLASS_H
#define QUICKSORTCLASS_H

#include "sortClass.h"
#include <iostream>
#include <vector>
#include <error.h>
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
	void recursionAction(ll*, ll, ll);		// 递归的 quick Sort 的实现主函数
	ll partiation(ll*, ll, ll);				// 区间划分函数
	
	double run_NonRecursionAction(); 						// 配置不同的数据并启动排序,非递归的
	void NonRecursionAction(ll*, ll, ll);		// 非递归的 quick Sort 的实现主函数
	
	ll bfprt(ll*, ll, ll);					// bfprt 算法，寻找最优枢轴值（选择第 k 小的元素）
	ll updatePartiation(ll*, ll, ll, ll);	// 新的区间划分函数
	void updateAction(ll*, ll, ll);			// 改进的quick Sort 的实现
	double run_udateAction(); 								// 配置不同的数据并启动排序,优化的quick sort
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	ll getCompareCnt();				// 获取compareCnt
	ll getExchageCnt();				// 获取exchageCnt
	
	quickSortClass(testData* data);		
	~quickSortClass();
	
private:
	dataGenerator* dataGenPtr;
	ll* assistantArr;
	ll compareCnt;
	ll exchageCnt;
};

#endif
