#ifndef MERGESORTCLASS_H
#define MERGESORTCLASS_H

#include "sortClass.h"
#include <iostream>

class mergeSortClass : public sortClass {
public:
	void beginAccord();							// 启动计时器
	void endAccord();							// 关闭计时器
	double getRunTime();						// 获取执行时间
	
	void validTest();							// 有效性验证
	void cleanCnt();							// 清除若干计数器
	
	double run_action(); 						// 配置不同的数据并启动排序
	void action(ll*, ll, ll);		// mergeSort 的实现,主函数
	void merge(ll*, ll, ll, ll);	// 归并函数
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	ll getCompareCnt();				// 获取compareCnt
	ll getExchageCnt();				// 获取exchageCnt
	
	mergeSortClass(testData* data);				// 构造
	~mergeSortClass();							// 析构
private:
	dataGenerator* dataGenPtr;
	ll* assistantArr;
	ll compareCnt;
	ll exchageCnt;
};

#endif
