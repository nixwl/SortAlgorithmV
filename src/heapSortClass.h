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
	void action(ll*, ll);			// heapSort 的实现,主函数
	void buildHeap(ll*, ll);		// 建堆函数
	void adjustHeap(ll*, ll, ll);	// 调整堆
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	ll getCompareCnt();				// 获取compareCnt
	ll getExchageCnt();				// 获取exchageCnt
	
	heapSortClass(testData* data);				// 构造
	~heapSortClass();							// 析构
	
private:
	dataGenerator* dataGenPtr;
	ll compareCnt;
	ll exchageCnt;
	ll* globalRegister;
};

#endif
