#ifndef SORTCLASS_H
#define SORTCLASS_H
#include "runtimeCal.h"
#include "dataGenerator.h"
#include "windows.h"
#include <vector>
#include <iostream>

class sortClass {
public:
	virtual void beginAccord() = 0;		// 纯虚函数, 子类用于启动计时器
	virtual void endAccord() = 0;		// 纯虚函数, 子类用于关闭计时器

	sortClass();						// 构造函数，用于为子类初始化工具类指针
	virtual ~sortClass();				// 抽象类的析构函数
	
	runTimeCal* getRunTimeImpl();		// 获取私有成员 runTimeImpl
	
private:
	runTimeCal* runTimeImpl;			// 计算运行时间的工具类指针
};

#endif
