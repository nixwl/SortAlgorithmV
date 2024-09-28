#include "bubbleSortClass.h"
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
 * @return
 */
bubbleSortClass::bubbleSortClass(testData* data){
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
bubbleSortClass::~bubbleSortClass(){
	delete this->dataGenPtr;
}

/**
 * bubbleSort 类启动计时器
 * @author 
 * @param
 * @return
 */
void bubbleSortClass::beginAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> bubble sort opened timer" << std::endl;
	this->getRunTimeImpl()->setBeginTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * bubbleSort 类关闭计时器
 * @author 
 * @param
 * @return
 */
void bubbleSortClass::endAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> bubble sort closed timer" << std::endl;
	this->getRunTimeImpl()->setEndTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * bubbleSort 类运行时间
 * @author 
 * @param
 * @return
 */
double bubbleSortClass::getRunTime(){
	setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	double time = this->getRunTimeImpl()->getRunTime().count();
	std::cout << "  @timer >> after bubble sort, got timer value:" <<  time <<" ms" << std::endl;
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	return time;
}

/**
 * 获取dataGenPtr
 * @author 
 * @param
 * @return
 */
dataGenerator* bubbleSortClass::getDataGenPtr(){
	return this->dataGenPtr;
}

/**
 * 获取searchCnt
 * @author 
 * @param
 * @return
 */
int bubbleSortClass::getCompareCnt(){
	return this->compareCnt;
}
	

/**
 * 获取exchageCnt
 * @author 
 * @param
 * @return
 */	
int bubbleSortClass::getExchageCnt(){
	return this->exchageCnt;
}


/**
 * 启动 action
 * @author 
 * @param
 * @return
 */
double bubbleSortClass::run_action(){
	long long int* data = this->dataGenPtr->getTestData();			// 数据容器
	int size = this->dataGenPtr->getTestDataClass()->getSize();		// 数据规模
	this->beginAccord();											// 启动计时器
	action(data, size);												// 执行冒泡排序
	this->endAccord();												// 关闭计时器
	return this->getRunTime();										// 获取执行时间			
}

/**
 * 清除计数器
 * @author 
 * @param
 * @return
 */
void bubbleSortClass::cleanCnt(){
	this->compareCnt = 0;
	this->exchageCnt = 0;
}
	

/**
 * bubbleSort 实现, 从小到大排序
 * @author 
 * @param
 * @return
 */
void bubbleSortClass::action(long long int* data, int size){
	int temp;														// 用于交换的寄存器
	for(int i = 0; i < size -1; i++){								// 交换从后到前进行
		bool flag = false;											// 标识是否存在交换行为
		for(int j = size - 1; j > i ; j--){
			if(data[j-1] > data[j]){								// 交换并设置标志
				temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
				flag = true;
				this->exchageCnt += 1;								// 交换计数器自增
			}
			this->compareCnt += 1;									// 比较计数器自增
		}
		if(!flag){
			return;
		}
	}
}

/**
 * bubble 排序的有效性验证
 * @author 
 * @param
 * @return
 */
void bubbleSortClass::validTest(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: begin bubble sort validation test: " << std::endl;
	std::cout << "  @before bubble sort: " << std::endl << "\t";
	// 填充有效性验证数据，生成一个倒序序列数据
	long long int* testStorge = new long long int[20];
	for(int i = 0, begin=20; i < 20; i++){
		testStorge[i] = begin--;
		std::cout << testStorge[i] << "  ";
	}
	// 执行 bubble 排序
	action(testStorge, 20);
	// 输出排序后的结果
	std::cout << std::endl << "  @after bubble sort: " << std::endl << "\t";
	for(int i = 0; i < 20; i++){
		std::cout << testStorge[i] << "  ";
	}
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}
