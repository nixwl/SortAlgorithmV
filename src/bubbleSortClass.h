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
	void action(ll*, ll);			// bubbleSort 的实现
	
	dataGenerator* getDataGenPtr();				// 获取dataGenPtr
	ll getCompareCnt();						// 获取searchCnt
	ll getExchageCnt();						// 获取exchageCnt
	
	bubbleSortClass(testData* data);			// 构造
	~bubbleSortClass();							// 析构
private:
	dataGenerator* dataGenPtr;
	ll compareCnt;
	ll exchageCnt;
};

#endif
