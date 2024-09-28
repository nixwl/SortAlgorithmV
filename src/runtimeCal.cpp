#include "runtimeCal.h"

/**
 * 构造函数
 * @author 
 * @param
 * @return
 */
runTimeCal::runTimeCal(){
	
}

/**
 * 析构函数
 * @author 
 * @param
 * @return
 */
runTimeCal::~runTimeCal(){
	
}

/**
 * 设置启动时间，即启动计时器
 * @author 
 * @param
 * @return
 */
void runTimeCal::setBeginTime(){
	this->beginTime = std::chrono::high_resolution_clock::now();
}

/**
 * 设置结束时间，即结束计时器
 * @author 
 * @param
 * @return
 */
void runTimeCal::setEndTime(){
	this->endTime = std::chrono::high_resolution_clock::now();
	this->calRunTime();
}

/**
 * 计算持续时间
 * @author 
 * @param
 * @return
 */
void runTimeCal::calRunTime(){
	std::chrono::duration<double, std::milli> elapsed = this->endTime - this->beginTime;
	this->runTime = elapsed;
}

/**
 * 获取启动时间
 * @author 
 * @param
 * @return
 */
std::chrono::time_point<std::chrono::high_resolution_clock> runTimeCal::getBeginTime(){
	return this->beginTime;
}

/**
 * 获取结束时间
 * @author 
 * @param
 * @return
 */
std::chrono::time_point<std::chrono::high_resolution_clock> runTimeCal::getEndTime(){
	return this->endTime;
}

/**
 * 获取运行时间
 * @author 
 * @param
 * @return
 */
std::chrono::duration<double, std::milli> runTimeCal::getRunTime(){
	return this->runTime;
}
