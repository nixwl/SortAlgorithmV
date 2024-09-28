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
	void action(long long int*, int, int);		// mergeSort 的实现,主函数
	void merge(long long int*, int, int, int);	// 归并函数
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	long long int getCompareCnt();				// 获取compareCnt
	long long int getExchageCnt();				// 获取exchageCnt
	
	mergeSortClass(testData* data);				// 构造
	~mergeSortClass();							// 析构
private:
	dataGenerator* dataGenPtr;
	long long int* assistantArr;
	long long int compareCnt;
	long long int exchageCnt;
};

#endif
