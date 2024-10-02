#include "quickSortClass.h"
namespace {
	/**
	 * 用于 bfprt 的直接插排
	 * @author 
	 * @param
	 * @return
	 */
	int insertSort(long long int* arr, int low, int high){
		long long int temp;
		
		for (int i = low + 1; i <= high; i++) {
			temp= arr[i];
			int j = i - 1;
			while(j >= low && arr[j] > temp){
				arr[j + 1] = arr[j];
				j -= 1;
			}
			arr[j + 1] = temp;
		}
		return low + (high - low) / 2;
	}
	
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
quickSortClass::quickSortClass(testData* data){
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
quickSortClass::~quickSortClass(){
	delete[] this->dataGenPtr;
	delete[] this->assistantArr;
}

/**
 * 启动计时器
 * @author 
 * @param
 * @return
 */
void quickSortClass::beginAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> quic sort opened timer" << std::endl;
	this->getRunTimeImpl()->setBeginTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * 关闭计时器
 * @author 
 * @param
 * @return
 */
void quickSortClass::endAccord(){
	setConsoleColor(FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @timer >> quick sort closed timer" << std::endl;
	this->getRunTimeImpl()->setEndTime();
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * mergeSortClass 类运行时间
 * @author 
 * @param
 * @return time
 */
double quickSortClass::getRunTime(){
	setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	double time = this->getRunTimeImpl()->getRunTime().count();
	std::cout << "  @timer >> after quick sort, got timer value:" <<  time <<" ms" << std::endl;
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	return time;
}

/**
 * 获取dataGenPtr
 * @author 
 * @param
 * @return dataGenPtr
 */
dataGenerator* quickSortClass::getDataGenPtr(){
	return this->dataGenPtr;
}

/**
 * 获取CompareCnt
 * @author 
 * @param
 * @return
 */
long long int quickSortClass::getCompareCnt(){
	return this->compareCnt;
}

/**
 * 获取 ExchageCnt
 * @author 
 * @param
 * @return
 */
long long int quickSortClass::getExchageCnt(){
	return this->exchageCnt;
}	

/**
 * 清除计数器
 * @author 
 * @param
 * @return
 */
void quickSortClass::cleanCnt(){
	this->exchageCnt = 0;
	this->compareCnt = 0;
}


/**
 * 配置不同的数据并启动排序，用于递归类
 * @author 
 * @param
 * @return
 */
double quickSortClass::run_recursionAction(){
	long long int* data = this->dataGenPtr->getTestData();			// 数据容器
	int size = this->dataGenPtr->getTestDataClass()->getSize();		// 数据规模
	this->beginAccord();											// 启动计时器
	recursionAction(data, 0, size - 1);								// 执行快速排序
	this->endAccord();												// 关闭计时器
	return this->getRunTime();										// 获取执行时间		
}


/**
 * quick sort 的实现,主函数，用于递归类
 * @author 
 * @param
 * @return
 */
void quickSortClass::recursionAction(long long int* data, int low, int high){
	if( low < high){
		// 区间划分，将【low,high】拆分为【low,piv-1】【piv+1,high】
		// 同时，piv 位置的元素即最终排序结果的元素
		int piv = partiation(data, low, high);
		recursionAction(data, low, piv - 1);
		recursionAction(data, piv + 1, high);
	}
}

/**
 * 区间划分函数，用于递归类
 * @author 
 * @param
 * @return
 */
int quickSortClass::partiation(long long int* data, int low, int high){
	int piv = data[low];							// 选取数组最低位作为枢轴
	while( low < high){
		// 右指针比枢轴大，向左移动右指针
		// 遇到比枢轴小的元素停止
		while( low < high && data[high] >= piv){	
			high -= 1;
			this->compareCnt += 1;				// 比较计数器自增
		}
		// 枢轴右边全是比枢轴大的元素了
		// 将比枢轴小的元素换到左指针的位置
		data[low] = data[high];						
		// 左指针比枢轴小，向右移动左指针
		// 遇到比枢轴大的元素停止
		while( low < high && data[low] <= piv){		
			low += 1;
			this->compareCnt += 1;				// 比较计数器自增
		}
		// 枢轴左边全是比枢轴小的元素了
		// 将比枢轴大的元素换到右指针的位置
		data[high] = data[low];
		this -> exchageCnt += 2;				// 交换计数器自增
	}
	// 最后左指针指位置就是枢轴值
	data[low] = piv;
	return low;
}

/**
 * 配置不同的数据并启动排序,非递归的
 * @author 
 * @param
 * @return
 */
double quickSortClass::run_NonRecursionAction(){
	long long int* data = this->dataGenPtr->getTestData();			// 数据容器
	int size = this->dataGenPtr->getTestDataClass()->getSize();		// 数据规模
	this->beginAccord();											// 启动计时器
	this->NonRecursionAction(data, 0, size - 1);					// 执行排序
	this->endAccord();												// 关闭计时器
	return this->getRunTime();										// 获取执行时间		
}


/**
 * quick sort 的实现,主函数，用于非递归类
 * @author 
 * @param
 * @return
 */
void quickSortClass::NonRecursionAction(long long int* data, int low, int high){
	std::stack<std::pair<int, int>> st;		// 栈存储区间范围
	st.push({low, high});					// 初始区间范围为[low, high], 入栈					
	while(!st.empty()){
		// 从栈中取出区间
		low = st.top().first;
		high = st.top().second;
		st.pop();
		// 区间划分，将【low,high】拆分为【low,piv-1】【piv+1,high】
		// 同时，piv 位置的元素即最终排序结果的元素
		if ( low < high){
			int piv = partiation(data, low, high);
			st.push({low, piv - 1});		// [low, piv - 1]区间入栈	
			st.push({piv + 1, high});		// [piv + 1, high]区间入栈
		}
	}
}

/**
 * 新的区间划分函数
 * @author 
 * @param
 * @return
 */
int quickSortClass::updatePartiation(long long int* data, int low, int high, int pivIndex){
	int pivotValue = data[pivIndex];			// 获取枢轴值
	std::swap(data[pivIndex], data[high - 1]);
	int storeIndex = low;						// 记录小于枢轴元素的元素的边界索引
	for (int i = low; i < high - 1; ++i) {
		this->compareCnt += 1;
		if (data[i] < pivotValue) {				// 如果当前元素小于枢轴元素
			//将当前元素与 storeIndex 位置的元素交换，确保小于枢轴的元素都在左边
			std::swap(data[i], data[storeIndex]);	
			storeIndex++;
			this->exchageCnt += 1;
		}
	}
	// 将枢轴元素交换到正确的位置
	std::swap(data[high - 1], data[storeIndex]);
	return storeIndex;
}

/**
 * bfprt 算法，寻找最优枢轴值（选择第 k 小的元素）
 * @author 
 * @param
 * @return
 */
int quickSortClass::bfprt(long long int* data, int low, int high){
	int size = high - low + 1;
	// 长度小于 5，直接返回中位数
	if( size <= 5){	
		return insertSort(data, low, high);
	}
	
	int start = low;
	int mediumNum = low;
	// 从 start 开始, 每 5 个为一组, 找中位数
	while(start + 5 < high){
		insertSort(data, start, start + 4);
		std::swap(data[mediumNum], data[start + 2]);
		mediumNum += 1;
		start += 5;
	}
	
	if(start < high){
		insertSort(data, start, high);
		int _low = high - start;
		std::swap(data[mediumNum], data[start + _low / 2]);
		mediumNum += 1;
	}
	
	return bfprt(data, low, mediumNum);
}	


/**
 * 改进的quick Sort 的实现
 * @author 
 * @param
 * @return
 */
void quickSortClass::updateAction(long long int* data, int low, int high){
	if (high - low > 1) {
		int pivotIndex = bfprt(data, low, high);
		pivotIndex = updatePartiation(data, low, high, pivotIndex);
		updateAction(data, low, pivotIndex);
		updateAction(data, pivotIndex + 1, high);
	}
}

/**
 *  配置不同的数据并启动排序,优化的quick sort
 * @author 
 * @param
 * @return
 */
double quickSortClass::run_udateAction(){
	long long int* data = this->dataGenPtr->getTestData();			// 数据容器
	int size = this->dataGenPtr->getTestDataClass()->getSize();		// 数据规模
	this->beginAccord();											// 启动计时器
	updateAction(data, 0, size - 1);								// 执行快速排序
	this->endAccord();												// 关闭计时器
	return this->getRunTime();										// 获取执行时间		
}


/**
 * 递归的quick Sort的有效性验证
 * @author 
 * @param
 * @return
 */
void quickSortClass::validTestRecursionAction(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: quick sort validation test: " << std::endl;
	std::cout << "  @before quick sort: " << std::endl << "\t";
	long long int* testStorge = new long long int[20];
	// 填充有效性验证数据，生成一个倒序序列数据
	for(int i = 0, begin=20; i < 20; i++){
		testStorge[i] = begin--;
		std::cout << testStorge[i] << "  ";
	}
	// 执行 quick sort
	recursionAction(testStorge, 0, 19);
	// 输出排序结果
	std::cout << std::endl << "  @after quick sort: " << std::endl << "\t";
	for(int i = 0; i < 20; i++){
		std::cout << testStorge[i] << "  ";
	}
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * 非递归的quick Sort的有效性验证
 * @author 
 * @param
 * @return
 */
void quickSortClass::validTestNonRecursionAction(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: unrecursion quick sort validation test: " << std::endl;
	std::cout << "  @before unrecursion quick sort: " << std::endl << "\t";
	long long int* testStorge = new long long int[20];
	// 填充有效性验证数据，生成一个倒序序列数据
	for(int i = 0, begin=20; i < 20; i++){
		testStorge[i] = begin--;
		std::cout << testStorge[i] << "  ";
	}
	// 执行 unrecursion quick sort
	NonRecursionAction(testStorge, 0, 19);
	// 输出排序结果
	std::cout << std::endl << "  @after unrecursion quick sort: " << std::endl << "\t";
	for(int i = 0; i < 20; i++){
		std::cout << testStorge[i] << "  ";
	}
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * 改进的quick Sort 的有效性验证
 * @author 
 * @param
 * @return
 */
void quickSortClass::validUpdateAction(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: updated quick sort validation test: " << std::endl;
	std::cout << "  @before updated quick sort: " << std::endl << "\t";
	long long int* testStorge = new long long int[20];
	// 填充逆序数据
	for(int i = 0, begin=20; i < 20; i++){
		testStorge[i] = begin--;
		std::cout << testStorge[i] << "  ";
	}
	// 执行 updated quick sort
	updateAction(testStorge, 0, 19);
	// 输出排序结果
	std::cout << std::endl << "  @after updated quick sort: " << std::endl << "\t";
	for(int i = 0; i < 20; i++){
		std::cout << testStorge[i] << "  ";
	}
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}


