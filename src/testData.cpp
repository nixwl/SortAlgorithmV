#include "testData.h"

/**
 * no-parm Constructor
 * @author 
 * @param
 * @return
 */
testData::testData():info("default testDataStorage, size=10\n"), size(10), pos(0){
	this->storge = new long long int[size];
	
}

/**
 * all-parm Constructor
 * @author 
 * @param
 * @return
 */
testData::testData(long long int size, std::string info): info(info), size(size), pos(0){
	this->storge = new ll[size];
}

/**
 * 析构函数
 * @author 
 * @param
 * @return
 */
testData::~testData(){
	delete this->storge;
}

/**
 * 获取测试数据描述
 * @author 
 * @param
 * @return
 */
std::string testData::getInfo(){
	return this->info;
}

/**
 * 获取测试数据
 * @author 
 * @param
 * @return
 */
ll* testData::getStorge(){
	return this->storge;
}

/**
 * 获取测试数据规模
 * @author 
 * @param
 * @return
 */
ll testData::getSize(){
	return this->size;
}

/**
 * 获取测试数据指针
 * @author 
 * @param
 * @return
 */
ll testData::getPos(){
	return this->pos;
}


/**
 * 设置测试数据描述
 * @author 
 * @param
 * @return
 */
void testData::setInfo(std::string info){
	this->info = info;
}


/**
 * 设置测试数据规模
 * @author 
 * @param
 * @return
 */
void testData::setSize(ll size){
	this->size = size;
}


/**
 * 设置测试数据
 * @author 
 * @param
 * @return
 */
void testData::setStorage(ll item){
	this->storge[pos] = item;
	pos++;
}

/**
 * 清空数据存储容器
 * @author 
 * @param
 * @return
 */
void testData::cleanStorge(){
	for(ll i = 0; i < this->size; i++){
		this->storge[i] = 0;
	}
	pos = 0;
}

/**
 * 设置容器起始下标
 * @author 
 * @param
 * @return
 */
void testData::setPos(ll pos){
	this->pos = pos;
}
	
	
