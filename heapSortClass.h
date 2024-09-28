#ifndef HEAPSORTCLASS_H
#define HEAPSORTCLASS_H

#include "sortClass.h"
#include <iostream>

class heapSortClass : public sortClass {
public:
	void beginAccord();			// 启动计时器
	void endAccord();			// 关闭计时器
	double getRunTime();		// 获取执行时间
	
	
	void validTest();							// 清除若干计数器
	void cleanCnt();							// 清除若干计数器
	
	double run_action(); 						// 配置不同的数据并启动排序
	void action(long long int*, int);			// heapSort 的实现,主函数
	void buildHeap(long long int*, int);		// 建堆函数
	void adjustHeap(long long int*, int, int);	// 调整堆
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	long long int getCompareCnt();				// 获取compareCnt
	long long int getExchageCnt();				// 获取exchageCnt
	
	heapSortClass(testData* data);				// 构造
	~heapSortClass();							// 析构
	
private:
	dataGenerator* dataGenPtr;
	long long int compareCnt;
	long long int exchageCnt;
	long long int* globalRegister;
};

#endif
