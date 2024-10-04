#include "heapSortClass.h"

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
heapSortClass::heapSortClass(testData* data){
	this->dataGenPtr = new dataGenerator(data);
	this->globalRegister = new ll[1];
	this->exchageCnt = 0;
	this->compareCnt = 0;
}

/**
 * 析构函数
 * @author 
 * @param
 * @return
 */
heapSortClass::~heapSortClass(){
	delete this->dataGenPtr;
}

/**
 * heapSortClass 类启动计时器
 * @author 
 * @param
 * @return
 */
void heapSortClass::beginAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> help sort opened timer" << std::endl;
	this->getRunTimeImpl()->setBeginTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}


/**
 * heapSortClass 类关闭计时器
 * @author 
 * @param
 * @return
 */
void heapSortClass::endAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> heap sort closed timer" << std::endl;
	this->getRunTimeImpl()->setEndTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * heapSortClass 类运行时间
 * @author 
 * @param
 * @return time
 */
double heapSortClass::getRunTime(){
	setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	double time = this->getRunTimeImpl()->getRunTime().count();
	std::cout << "  @timer >> after heap sort, got timer value:" <<  time <<" ms" << std::endl;
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	return time;
}

/**
 * 获取dataGenPtr
 * @author 
 * @param
 * @return dataGenPtr
 */
dataGenerator* heapSortClass::getDataGenPtr(){
	return this->dataGenPtr;
}

/**
 * 获取searchCnt
 * @author 
 * @param
 * @return
 */
ll heapSortClass::getCompareCnt(){
	return this->compareCnt;
}

/**
 * 获取获取exchageCnt
 * @author 
 * @param
 * @return searchCnt
 */
long long int heapSortClass::getExchageCnt(){
	return this->exchageCnt;
}

/**
 * 清除计数器
 * @author 
 * @param
 * @return
 */
void heapSortClass::cleanCnt(){
	this->compareCnt = 0;
	this->exchageCnt = 0;
}

/**
 * heapSort 的实现,主函数
 * @author 
 * 	- data
 * 	- size
 * @return
 */
void heapSortClass::action(ll* data, ll size){
	ll temp;									// 用于交换的变量
	buildHeap(data, size);						// 建立大根堆
	for(ll i = size; i > 0; i--){				
		temp = data[i];							// 将堆顶元素与数组末尾元素交换（最大的放到后面，实现增序排序）
		data[i] = data[0];
		data[0] = temp;
		this->exchageCnt += 1;					// 交换计数器自增
		adjustHeap(data,0,i-1);					// 换完后调整堆
	}
}

/**
 * 建堆函数
 * @author 
 * @param
 * 	- data
 * 	- size
 * @return
 */
void heapSortClass::buildHeap(ll* data, ll size){
	// 调整范围是 1 ~ size / 2, 树的上半部分
	for(ll i = size / 2; i >= 0; i--){
		adjustHeap(data, i, size);
	}
}

/**
 * 堆调整函数
 * @author 
 * @param
 * 	- data
 * 	- k
 * 	- size
 * @return 
 */
void heapSortClass::adjustHeap(ll* data, ll k, ll size){
	this->globalRegister[0] = data[k];
	ll i;
	for(i = 2 * k;i <= size;i *= 2){
		// 查看，若左孩子小于右孩子，向右孩子下坠（i+=1）得到下坠点data[i]
		if(i < size && data[i] < data[i+1]) {
			i++;
			this->compareCnt += 1;				// 记录比较行为
		}
		 
		// 比较下坠点data[i] 和当前根大小data[0],根小则交换
		if(this->globalRegister[0] >= data[i]) {
			break;
		}
		else{
			data[k] = data[i];
			k = i;						// 修改 k，继续向下下坠，k是下一次对比的根
			this->exchageCnt += 1;		// 记录交换行为
		}
		this->compareCnt++;				// 记录比较行为
	}
	data[k] = this->globalRegister[0];
}

/**
 * 配置不同的数据并启动排序
 * @author 
 * @param
 * @return
 */
double heapSortClass::run_action(){
	ll* data = this->dataGenPtr->getTestData();			// 数据容器
	ll size = this->dataGenPtr->getTestDataClass()->getSize();		// 数据规模
	this->beginAccord();											// 启动计时器
	action(data, size - 1);											// 执行堆排序
	this->endAccord();												// 关闭计时器
	return this->getRunTime();										// 获取执行时间		
}

/**
 * 执行堆排序的有效性验证
 * @author 
 * @param
 * @return
 */
void heapSortClass::validTest(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: begin heap sort validation test: " << std::endl;
	std::cout << "  @before heap sort: " << std::endl << "\t";
	// 填充有效性验证数据，生成一个倒序序列数据
	ll* testStorge = new long long int[20];
	for(int i = 0, begin=20; i < 20; i++){
		testStorge[i] = begin--;
		std::cout << testStorge[i] << "  ";
	}
	// 执行堆排序
	action(testStorge, 19);
	// 输出排序后的结果
	std::cout << std::endl << "  @after bubble sort: " << std::endl << "\t";
	for(int i = 0; i < 20; i++){
		std::cout << testStorge[i] << "  ";
	}
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}



	
	
	
