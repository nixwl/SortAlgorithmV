#include "mergeSortClass.h"

namespace{
	/**
	 * 设置输出颜色
	 * @author 
	 * @param
	 * @return
	 */
	void setConsoleColor(int colorCode) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, colorCode);
	}
}
/**
 * 构造函数
 * @author 
 * @param
 * 	- testData* data: 数据容器指针
 * @return
 */
mergeSortClass::mergeSortClass(testData* data){
	this->assistantArr = nullptr;
	this->dataGenPtr = new dataGenerator(data);
	this->exchageCnt = 0;
	this->compareCnt = 0;
}

/**
 * 析构函数
 * @author 
 * @param
 * @return
 */
mergeSortClass::~mergeSortClass(){
	delete this->dataGenPtr;
}

/**
 * 启动计时器
 * @author 
 * @param
 * @return
 */
void mergeSortClass::beginAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> merge sort opened timer" << std::endl;
	this->getRunTimeImpl()->setBeginTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * 关闭计时器
 * @author 
 * @param
 * @return
 */
void mergeSortClass::endAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> merge sort closed timer" << std::endl;
	this->getRunTimeImpl()->setEndTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * mergeSortClass 类运行时间
 * @author 
 * @param
 * @return time
 */
double mergeSortClass::getRunTime(){
	setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	double time = this->getRunTimeImpl()->getRunTime().count();
	std::cout << "  @timer >> after merge sort, got timer value:" <<  time <<" ms" << std::endl;
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	return time;
}

/**
 * 获取dataGenPtr
 * @author 
 * @param
 * @return dataGenPtr
 */
dataGenerator* mergeSortClass::getDataGenPtr(){
	return this->dataGenPtr;
}

/**
 * 获取CompareCnt
 * @author 
 * @param
 * @return
 */
long long int mergeSortClass::getCompareCnt(){
	return this->compareCnt;
}

/**
 * 获取 ExchageCnt
 * @author 
 * @param
 * @return
 */
long long int mergeSortClass::getExchageCnt(){
	return this->exchageCnt;
}	

/**
 * 清除计数器
 * @author 
 * @param
 * @return
 */
void mergeSortClass::cleanCnt(){
	this->exchageCnt = 0;
	this->compareCnt = 0;
}



/**
 * 配置不同的数据并启动排序
 * @author 
 * @param
 * @return
 */
double mergeSortClass::run_action(){
	long long int* data = this->dataGenPtr->getTestData();			// 数据容器
	int size = this->dataGenPtr->getTestDataClass()->getSize();		// 数据规模
	this->assistantArr = new long long int[size];					// 创建辅助数组
	this->beginAccord();											// 启动计时器
	action(data, 0, size - 1);										// 执行归并排序
	this->endAccord();												// 关闭计时器
	delete this->assistantArr;
	return this->getRunTime();										// 获取执行时间	
}



/**
 * mergeSort 的实现,主函数
 * @author 
 * @param
 * @return
 */
void mergeSortClass::action(long long int* data, int low, int high){
	if( low < high){
		int mid = (low + high) / 2;					// 取数据中间下标索引
		action(data, low, mid);						// 切[low, mid] 间的数据
		action(data, mid+1, high);					// 切[mid, high] 间的数据
		merge(data, low, mid, high);				// 合并数据
	}
}

	
/**
 * 归并函数
 * @author 
 * @param
 * @return
 */
void mergeSortClass::merge(long long int* data, int low, int mid, int high){
	int i, j, k;
	for(k = 0; k <= high; k++){				
		this->assistantArr[k] = data[k];	// 将原数组的数据拷贝到辅助数组
	}
	// i 指针控制左半部分, j 指针控制右半部分, 小的先插入原数组
	for(i = low, j = mid + 1, k = i;i <= mid && j <= high; k++){
		if(this->assistantArr[j] >= this->assistantArr[i]){
			data[k] = this->assistantArr[i++];
		}
		else
			data[k] = this->assistantArr[j++];
		this->compareCnt += 1;				// 比较计数器自增
	}
	// 将剩余的按序插入
	while(i <= mid){
		data[k++] = this->assistantArr[i++];
		this->exchageCnt += 1;				// 交换计数器自增
	} 
	while(j <= high){ 
		data[k++] = this->assistantArr[j++];
		this->exchageCnt += 1;				// 交换计数器自增
	}
}


/**
 * 归并排序的有效性验证
 * @author 
 * @param
 * @return
 */
void mergeSortClass::validTest(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: begin merge sort validation test: " << std::endl;
	std::cout << "  @before merge sort: " << std::endl << "\t";
	// 填充有效性验证数据，生成一个倒序序列数据
	long long int* testStorge = new long long int[20];
	for(int i = 0, begin=20; i < 20; i++){
		testStorge[i] = begin--;
		std::cout << testStorge[i] << "  ";
	}
	// 执行排序
	this->assistantArr = new long long int[20];
	action(testStorge, 0, 19);
	// 输出排序结果
	std::cout << std::endl << "  @after merge sort: " << std::endl << "\t";
	for(int i = 0; i < 20; i++){
		std::cout << testStorge[i] << "  ";
	}
	delete this->assistantArr;
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

