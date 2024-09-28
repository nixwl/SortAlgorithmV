#ifndef BUBBLESORTCLASS_H
#define BUBBLESORTCLASS_H

#include "sortClass.h"


class bubbleSortClass : public sortClass {
public:
	void beginAccord();			// 启动计时器
	void endAccord();			// 关闭计时器
	double getRunTime();		// 获取执行时间
	
	void validTest();			// 有效性测试

	double run_action(); 						// 配置不同的数据并启动排序
	void cleanCnt();							// 清除若干计数器
	void action(long long int*, int);			// bubbleSort 的实现
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	int getCompareCnt();						// 获取searchCnt
	int getExchageCnt();						// 获取exchageCnt
	
	bubbleSortClass(testData* data);			// 构造
	~bubbleSortClass();							// 析构
private:
	dataGenerator* dataGenPtr;
	long long int compareCnt;
	long long int exchageCnt;
};

#endif
