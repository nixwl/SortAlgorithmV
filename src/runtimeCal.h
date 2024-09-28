#ifndef RUNTIMECAL_H
#define RUNTIMECAL_H
#include<chrono>

class runTimeCal {
public:
	runTimeCal();
	~runTimeCal();
	void setBeginTime();			// 启动计时器
	void setEndTime();				// 结束计时器
	void calRunTime();				// 计算时间
	std::chrono::time_point<std::chrono::high_resolution_clock> getBeginTime();
	std::chrono::time_point<std::chrono::high_resolution_clock> getEndTime();
	std::chrono::duration<double, std::milli> getRunTime();
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> beginTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
	std::chrono::duration<double, std::milli> runTime;
};

#endif
