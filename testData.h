#ifndef TESTDATA_H
#define TESTDATA_H
#include<string>


class testData {
	friend class dataGenerator;
public:
	testData(long long int size, std::string info);		// 测试数据容器支持有参构造
	testData();											// 测试数据容器支持无参构造,可以修改容器内部配置		
	~testData();

	std::string getInfo();								// 返回-测试数据描述
	long long int getSize();							// 返回-数据规模
	long long int* getStorge();							// 返回-测试数据存储容器
	long long int getPos();								// 返回-测试数据存储容器指针
	
	void cleanStorge();									// 清空数据存储容器
	void setStorage(long long int item);				// 填充数据存储容器
	void setSize(long long int size);					// 设置数据规模
	void setInfo(std::string info);						// 设置数据描述
	void setPos(long long int pos);						// 设置容器起始下标
	
	
private:
	std::string info;									// 测试数据描述
	long long int size;									// 测试数据规模
	long long int pos;									// 测试数据存储容器指针
	long long int* storge;								// 测试数据存储容器
};

#endif
