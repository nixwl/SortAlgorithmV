#include "sortClass.h"

/**
 * 构造函数
 * @author 
 * @param
 * @return
 */
sortClass::sortClass(){
	runTimeImpl = new runTimeCal();
}

/**
 * 析构函数
 * @author 
 * @param
 * @return
 */
sortClass::~sortClass(){
	delete this->runTimeImpl;
}

/**
 * 获取RunTimeImpl
 * @author 
 * @param
 * @return
 */
runTimeCal* sortClass::getRunTimeImpl(){
	return this->runTimeImpl;
}

	
	


