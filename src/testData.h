#ifndef TESTDATA_H
#define TESTDATA_H
#include<string>
typedef long long int ll;

class testData {
	friend class dataGenerator;
public:
	testData(ll size, std::string info);		// 测试数据容器支持有参构造
	testData();											// 测试数据容器支持无参构造,可以修改容器内部配置		
	~testData();

	std::string getInfo();								// 返回-测试数据描述
	ll getSize();							// 返回-数据规模
	ll* getStorge();							// 返回-测试数据存储容器
	ll getPos();								// 返回-测试数据存储容器指针
	
	void cleanStorge();									// 清空数据存储容器
	void setStorage(ll item);				// 填充数据存储容器
	void setSize(ll size);					// 设置数据规模
	void setInfo(std::string info);						// 设置数据描述
	void setPos(ll pos);						// 设置容器起始下标
	
	
private:
	std::string info;									// 测试数据描述
	ll size;									// 测试数据规模
	ll pos;									// 测试数据存储容器指针
	ll* storge;								// 测试数据存储容器
};

#endif
