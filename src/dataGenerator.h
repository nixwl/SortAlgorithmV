#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H
#include "testData.h"

class dataGenerator {
public:
	
	dataGenerator(testData *data);		//构造
	~dataGenerator();					//析构
	
	testData *getTestDataClass();		// 获取测试数据类
	long long int* getTestData();		// 获取测试数据
	void cleanTestData();				// 清除测试数据
	
	void genTestDataOrd();				// 生成顺序测试数据
	void genTestDataRord();				// 生成逆序测试数据
	void genTestDataRadomU(long long int scope = LONG_LONG_MAX);	// 生成随机序测试数据, 无重复
	void genTestDataRadom(long long int scope = LONG_LONG_MAX);		// 生成随机序测试数据, 可能有重复
	
private:
	testData* testDataPtr;
};

#endif
