#include "dataGenerator.h"
#include <vector>
#include <random>

/**
 * Constructor
 * @author 
 * @param
 * @return
 */
dataGenerator::dataGenerator(testData* data){
	testDataPtr = data;
}

/**
 * 析构
 * @author 
 * @param
 * @return
 */
dataGenerator::~dataGenerator(){
	delete this->testDataPtr;
}


/**
 * 获取测试数据类
 * @author 
 * @param
 * @return
 */
testData* dataGenerator::getTestDataClass(){
	return this->testDataPtr;
}

/**
 * 获取测试数据
 * @author 
 * @param
 * @return
 */
ll* dataGenerator::getTestData(){
	return this->testDataPtr->storge;
}

/**
 * 生成顺序测试数据
 * @author 
 * @param
 * @return
 */
void dataGenerator::genTestDataOrd(){
	ll size = this->testDataPtr->getSize();
	ll item = 1;
	for(ll pos = this->testDataPtr->getPos(); pos < size; pos++){
		this->testDataPtr->setStorage(item++);
	}
}

/**
 * 生成逆序测试数据
 * @author 
 * @param
 * @return
 */
void dataGenerator::genTestDataRord(){
	ll size = this->testDataPtr->getSize();
	ll item = size;
	for(ll pos = this->testDataPtr->getPos(); pos < size; pos++){
		this->testDataPtr->setStorage(item--);
	}
}


/**
 * 生成随机序测试数据, 要求无重复
 * @author 
 * @param	
 * 	- scope: 生成数据的规模
 * @return
 */
void dataGenerator::genTestDataRadomU(ll scope){
	std::vector<ll> result;
	std::random_device rd;						// 随机数设备，用于生成真随机数
	std::default_random_engine engine(rd());
	std::uniform_int_distribution<ll> distribution(1, scope);
	
	ll size = this->testDataPtr->getSize();
	// 生成 size 个数据
	while((ll)result.size() < size){
		ll randNum = distribution(engine);
		bool isUnique = true;
		// 确保数据不重复
		for(auto item : result){
			if(item == randNum){
				isUnique = false;
				break;
			}
		}
		if(isUnique){
			result.push_back(randNum);
		}
	}
	
	// 将数据装入 testData, 从 pos 开始装填
	for(ll item = 0, pos = this->testDataPtr->getPos()
		; pos < size && item < (ll)result.size()
		; pos++){
		this->testDataPtr->setStorage(result[item++]); 
	}
}


/**
 * 生成随机序测试数据, 可能有重复
 * @author 
 * @param	
 * 	- scope: 生成数据的规模
 * @return
 */
void dataGenerator::genTestDataRadom(ll scope){
	std::vector<ll> result;
	std::random_device rd;						// 随机数设备，用于生成真随机数
	std::default_random_engine engine(rd());	// 通过鼠标、键盘等设备获取真随机数
	std::uniform_int_distribution<ll> distribution(1, scope);	// 设置随机数范围（均匀分布）
	
	ll size = this->testDataPtr->getSize();
	// 生成 size 个数据
	while((ll)result.size() < size){
		result.push_back(distribution(engine));
	}
	// 将数据装入 testData, 从 pos 开始装填
	for(ll item = 0, pos = this->testDataPtr->getPos()
		; pos < size && item < (ll)result.size()
		; pos++){
		this->testDataPtr->setStorage(result[item++]); 
	}
}

/**
 * 清除测试数据
 * @author 
 * @param	
 * @return
 */
void dataGenerator::cleanTestData(){
	this->testDataPtr->cleanStorge();
}

