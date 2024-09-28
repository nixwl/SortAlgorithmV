#include "test.h"

namespace {
	// 填充验证数据，数据写死
	struct Element {
		int value;
		int id; 			// 用于区分相同值的元素
	};
	
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
	
	/**
	 * 制表函数，输出运行时间表
	 * @author 
	 * @param
	 * @return
	 */
	void cntOutput(double runTime, long long int exchangCnt, long long int compareCnt){
		setConsoleColor(FOREGROUND_RED| FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		std::cout << std::endl<<"\t"<< "+------------+------------+------------+\n";
		std::cout << " \t "<< std::left << std::setw(13) << "Runtime" << std::setw(13) << "Exchange" << std::setw(13) << "Compare" << std::endl;
		std::cout << "\t"<< "+------------+------------+------------+\n";
		std::cout << " \t " << std::left << std::setw(13) << std::to_string(runTime) + "ms" << std::setw(13) << exchangCnt << std::setw(13) << compareCnt << std::endl;
		std::cout << "\t"<< "+------------+------------+------------+\n";
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	
	/**
	 * 输出计数器统计值表
	 * @author 
	 * @param
	 * @return
	 */
	void cleanCntOutput(std::string id){
		setConsoleColor(FOREGROUND_GREEN| FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		std::cout << " @task-"+ id + ">> clean test data in container" << std::endl;
		std::cout << " @task-"+ id + ">> clean exchange & compare counter\n\n";
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	
	/**
	 * 输出 task 相关情况
	 * @author 
	 * @param
	 * @return
	 */
	void taskInfo(std::string taskType, std::string dataType, std::string id){
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);						// 设置蓝色输出
		std::cout << " @task-"+ id + ">> " + taskType + "sort with [" + dataType + "] data" << std::endl;
		std::cout << " @task-"+ id + ">> loading [" + dataType + "] test data" << std::endl;
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	}
	
	/**
	 * 输出稳定性测试前相关情况
	 * @author 
	 * @param
	 * @return
	 */
	void beforeinfo(std::vector<Element>& arr){
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);						// 设置蓝色输出
		std::cout << "   ##data before sort: " << std::endl << "\t";
		std::cout << "value: "<< std::endl << "\t\t";
		setConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);		// 设置黄色输出
		for(auto i : arr){
			std::cout  << std::left << std::setw(4) << i.value << " ";
		}std::cout << std::endl << "\t";
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);						// 设置蓝色输出
		std::cout << "id: "<< std::endl << "\t\t";
		setConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);		// 设置黄色输出
		for(auto i : arr){
			std::cout << std::left << std::setw(4)  << i.id << " ";
		}std::cout << std::endl;
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	}
	
	/**
	 * 输出稳定性测试后相关情况
	 * @author 
	 * @param
	 * @return
	 */
	void aferinfo(std::vector<Element>& arr){
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);						// 设置蓝色输出
		std::cout << "   ##data after sort: " << std::endl << "\t";
		std::cout << "value:"<< std::endl << "\t\t";
		setConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);		// 设置黄色输出
		for(auto i : arr){
			std::cout  << std::left << std::setw(4) << i.value << " ";
		}std::cout << std::endl << "\t" ;
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);						// 设置蓝色输出
		std::cout << "id:"<< std::endl << "\t\t";
		setConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);		// 设置黄色输出
		for(auto i : arr){
			std::cout  << std::left << std::setw(4) << i.id << " ";
		}std::cout << std::endl;
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	}
}

/**
 * 测试冒泡函数对不同序列的数据排序的运行时间性能
 * @author 
 * @param
 * 	- scope: 输入数据的规模
 * @return
 */
void test::testBuddleSortRunTime(long long int scope){
	testData* data = new testData(scope, "testBuddleSortRunTime, size=" + std::to_string(scope));
	bubbleSortClass* testObj = new bubbleSortClass(data);
	double runTime;
	
	/* task 1: bubble sort with ordered data*/
	taskInfo("bubble", "ordered", "1");
		/* run task 1*/																	// 控制台输出
	testObj->getDataGenPtr()->genTestDataOrd();										// 设置顺序数据
	runTime = testObj->run_action();												// 运行
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());			// 结果输出
		/* clean task 1*/
	testObj->getDataGenPtr()->cleanTestData();										// 清除容器中的数据
	testObj->cleanCnt();															// 清除计数器
	cleanCntOutput("1");																// 控制台输出
	
	
	/* task 2: bubble sort with reordered data*/
	taskInfo("bubble", "reordered", "2");											// 控制台输出
		/* run task 2*/
	testObj->getDataGenPtr()->genTestDataRord();									// 填充逆序数据
	runTime = testObj->run_action();												// 运行
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());			// 控制台输出结果
		/* clean task 2*/
	testObj->getDataGenPtr()->cleanTestData();										// 清除容器中的数据
	testObj->cleanCnt();															// 清除计数器
	cleanCntOutput("2");															// 控制台输出
	
	/* task 3: bubble sort with random data*/
	taskInfo("bubble", "random", "3");													// 控制台输出
	testObj->getDataGenPtr()->genTestDataRadomU(scope); 							// 填充随机数据
	runTime = testObj->run_action();												// 运行
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());			// 控制台输出
}

/**
 * 测试堆排序函数对不同序列的数据排序的运行时间性能
 * @author 
 * @param
 * 	- scope: 输入数据的规模
 * @return
 */
void test::testHeapSortRunTime(long long int scope){
	testData* data = new testData(scope, "testHeapSortRunTime, size=" + std::to_string(scope));
	heapSortClass* testObj = new heapSortClass(data);
	double runTime;
	
	/*task 1: heap sort with ordered data*/
	taskInfo("heap", "ordered", "1");												// 控制台输出
		/* run task 1*/
	testObj->getDataGenPtr()->genTestDataOrd();										// 填充顺序数据
	runTime = testObj->run_action();												// 运行
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());			// 控制台输出
		/* clean task 1*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("1");															// 控制台输出
	
	/* task 2: heap sort with reordered data*/
	taskInfo("heap", "reordered", "2");												// 控制台输出
		/* run task 2*/
	testObj->getDataGenPtr()->genTestDataRord();									// 填充逆序数据
	runTime = testObj->run_action();												// 运行
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());			// 控制台输出
		/* clean task 2*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("2");																	
	
	/* task 3: heap sort with random data*/
	taskInfo("heap", "random", "3");														// 控制台输出
	testObj->getDataGenPtr()->genTestDataRadom(scope);								// 填充随机数据
	runTime = testObj->run_action();												// 运行
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());			// 控制台输出
}

/**
 * 测试归并排序函数对不同序列的数据排序的运行时间性能
 * @author 
 * @param
 * 	- scope: 输入数据的规模
 * @return
 */
void test::testMergeSortRunTime(long long int scope){
	testData* data = new testData(scope, "testMergeSortRunTime, size=" + std::to_string(scope));
	mergeSortClass* testObj = new mergeSortClass(data);
	double runTime;
	
	/*task 1: merge sort with ordered data*/
	taskInfo("merge", "ordered", "1");												// 控制台输出
		/* run task 1*/
	testObj->getDataGenPtr()->genTestDataOrd();										// 填充顺序数据
	runTime = testObj->run_action();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());			
		/* clean task 1*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("1");
	
	/*task 2: merge sort with reordered data*/
	taskInfo("merge", "reordered", "2");											// 控制台输出
		/* run task 2*/
	testObj->getDataGenPtr()->genTestDataRord();									// 填充逆序数据
	runTime = testObj->run_action();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
		/* clean task 2*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("2");
	
	/*task 3: merge sort with radom data*/
	taskInfo("merge", "random", "3");												// 控制台输出
	testObj->getDataGenPtr()->genTestDataRadom(scope);				 				// 填充随机数据
	runTime = testObj->run_action();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
}

/**
 * 测试快速排序函数对不同序列的数据排序的运行时间性能
 * @author 
 * @param
 * 	- scope: 输入数据的规模
 * @return
 */
void test::testQuicSortRunTime(long long int scope){
	testData* data = new testData(scope, "testQuicSortRunTime, size=" + std::to_string(scope));
	quickSortClass* testObj = new quickSortClass(data);
	double runTime;
	
	/*task 1: quick sort with ordered data*/
	taskInfo("quick", "ordered", "1");												// 控制台输出
	testObj->getDataGenPtr()->genTestDataOrd();										// 填充顺序数据
		/* run task 1*/
	runTime = testObj->run_recursionAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
		/* clean task 1*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("1");
	
	/*task 2: quick sort with reordered data*/
	taskInfo("quick", "reordered", "2");	
	testObj->getDataGenPtr()->genTestDataRord();									// 填充逆序数据
		/* run task 2*/
	runTime = testObj->run_recursionAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
		/* run task 2*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("2");
	
	/*task 3: quick sort with random data*/
	taskInfo("quick", "random", "3");	
	testObj->getDataGenPtr()->genTestDataRadom(scope);				 				// 填充随机数据
	runTime = testObj->run_recursionAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
}

/**
 * 测试快速排序（非递归）对不同序列的数据排序的运行时间性能
 * @author 
 * @param
 * 	- scope: 输入数据的规模
 * @return
 */
void test::testQuicSortNonRecursionAction(long long int scope){
	testData* data = new testData(scope, "testQuicSortRunTime, size=" + std::to_string(scope));
	quickSortClass* testObj = new quickSortClass(data);
	double runTime;
	
	/*task 1: unrecursion quick sort with ordered data*/
	taskInfo("unrecursion quick", "ordered", "1");
		/* run task 1*/
	testObj->getDataGenPtr()->genTestDataOrd();										// 填充顺序数据
	runTime = testObj->run_NonRecursionAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
		/* clean task 1*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("1");
	
	/*task 2: unrecursion quick sort with reordered data*/
	taskInfo("unrecursion quick", "reordered", "2");	
	testObj->getDataGenPtr()->genTestDataRord();									// 填充逆序数据
		/* run task 2*/
	runTime = testObj->run_NonRecursionAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
		/* clean task 2*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("2");
	
	/*task 3: unrecursion quick sort with random data*/
	taskInfo("unrecursion quick", "random", "3");	
	testObj->getDataGenPtr()->genTestDataRadom(scope);								// 填充随机数据
	runTime = testObj->run_NonRecursionAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());	
}

/**
 * 测试快速排序（改进的）对不同序列的数据排序的运行时间性能
 * @author 
 * @param
 * 	- scope: 输入数据的规模
 * @return
 */
void test::testQuicSortUpdateAction(long long int scope){
	testData* data = new testData(scope, "testQuicSortRunTime, size=" + std::to_string(scope));
	quickSortClass* testObj = new quickSortClass(data);
	double runTime;
	
	/*task 1: updated quick sort with ordered data*/
	taskInfo("updated quick", "ordered", "1");	
	testObj->getDataGenPtr()->genTestDataOrd();										// 填充顺序数据
		/* run task 1*/
	runTime = testObj->run_udateAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
		/* run task 1*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("1");
	
	/*task 2: updated quick sort with reordered data*/
	taskInfo("updated quick", "reordered", "2");	
	testObj->getDataGenPtr()->genTestDataRord();									// 填充逆序数据
		/* run task 2*/
	runTime = testObj->run_udateAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());
		/* clean task 2*/
	testObj->getDataGenPtr()->cleanTestData();
	testObj->cleanCnt();
	cleanCntOutput("2");
	
	/*task 3: updated quick sort with random data*/
	taskInfo("updated quick", "random", "3");	
	testObj->getDataGenPtr()->genTestDataRadom(scope);								// 填充随机数据
	runTime = testObj->run_udateAction();
	cntOutput(runTime, testObj->getExchageCnt(), testObj->getCompareCnt());	
}


/**
 * bubble 排序的稳定性验证
 * @author 
 * @param
 * @return
 */
void test::testStableBubbleSort(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: begin bubble sort stability test: " << std::endl;
	std::cout << "  @before bubble sort: " << std::endl;
	
	std::vector<Element> arr = { {10, 1},{9, 2},{8, 3},{2, 4},{6, 5},{5, 6},{4, 7},{2, 8}, {1, 9}, {11, 10}};
	beforeinfo(arr);
	// run bubble sort
	int n = (int)arr.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j].value > arr[j + 1].value) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	aferinfo(arr);
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
}

/**
 * heap 排序的稳定性验证
 * @author 
 * @param
 * @return
 */
void test::testStableHeapSort(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: begin heap sort stability test: " << std::endl;
	std::cout << "  @before heap sort: " << std::endl;
	std::vector<Element> arr = {{10, 1}, {22, 2}, {8, 3}, {2, 4}, {2, 5}, {6, 6}, {5, 7}, {4, 8}, {1, 9}, {11, 10}};
	beforeinfo(arr);
	class innerheap{
		public:
			void action(std::vector<Element>& arr, int size){
				buildheap(arr, size);						// 建立大根堆
				for(int i = size; i > 0; i--){
					std::swap(arr[0], arr[i]);
					adjustheap(arr,0,i-1);
				}
			};
			void buildheap(std::vector<Element>& arr, int size){
				for(int i = size / 2; i >= 0; i--){
					adjustheap(arr, i, size);
				}
			};
			void adjustheap(std::vector<Element>& arr, int k, int size){
				Element temp = arr[k];
				int i;
				for(i = 2 * k;i <= size;i *= 2){
					// 查看，若左孩子小于右孩子，向右孩子下坠（i+=1）得到下坠点data[i]
					if(i < size && arr[i].value < arr[i+1].value) {
						i++;
					}
					if(temp.value >= arr[i].value) {
						break;
					}
					else{
						arr[k] = arr[i];
						k = i;						// 修改 k，继续向下下坠，k是下一次对比的根
					}
				}
				arr[k] = temp;
			}
	};
	innerheap *p = new innerheap();
	p->action(arr, (int)arr.size()-1);
	aferinfo(arr);
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	delete p;
}


/**
 * merge 排序的稳定性验证
 * @author 
 * @param
 * @return
 */
void test::testStableMergeSort(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: beign merge sort stability test: " << std::endl;
	std::cout << "  @before merge sort: " << std::endl;
	std::vector<Element> arr = {{10, 1}, {22, 2}, {8, 3}, {2, 4}, {2, 5}, {6, 6}, {5, 7}, {4, 8}, {1, 9}, {11, 10}};
	beforeinfo(arr);
	class innermerge{
	public:
		std::vector<Element> innerassiant;
		void action(std::vector<Element>& arr, int low, int high){
			if(low < high){
				int mid = (low + high) / 2;
				action(arr, low, mid);
				action(arr, mid+1, high);
				merge(arr, low, mid, high);
			}
		}
		void merge(std::vector<Element>& arr, int low, int mid, int high){
			innerassiant = arr;
			int i, j ,k;
			// i 指针控制左半部分, j 指针控制右半部分, 小的先插入原数组
			for(i = low, j = mid + 1, k = i;i <= mid && j <= high; k++){
				if(innerassiant[j].value >= innerassiant[i].value){
					arr[k] = innerassiant[i++];
				}
				else
					arr[k] = innerassiant[j++];
			}
			// 将剩余的按序插入
			while(i <= mid){
				arr[k++] = innerassiant[i++];
			} 
			while(j <= high){ 
				arr[k++] = innerassiant[j++];
			}
		}
	};
	innermerge *p = new innermerge();
	p->action(arr, 0, (int)arr.size() - 1);
	aferinfo(arr);
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	delete p;
}

/**
 * quick 排序的稳定性验证
 * @author 
 * @param
 * @return
 */
void test::testStableQuickSort(){
	setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "  @valid test: begin quick sort stability test: " << std::endl;
	std::cout << "  @before quick sort: " << std::endl;
	std::vector<Element> arr = {{10, 1}, {22, 2}, {8, 3}, {2, 4}, {2, 5}, {6, 6}, {5, 7}, {4, 8}, {1, 9}, {11, 10}};
	beforeinfo(arr);
	class innerquick{
	public:
		void action(std::vector<Element>& arr, int low, int high){
			if( low < high){
				int piv = partiation(arr, low, high);
				action(arr, low, piv - 1);
				action(arr, piv + 1, high);
			}
		}
		int partiation(std::vector<Element>& arr, int low, int high){
			Element piv = arr[low]; 
			while( low < high){
				while( low < high && arr[high].value >= piv.value){
					high -= 1;
				}
				arr[low] = arr[high];
				
				while( low < high && arr[low].value <= piv.value){
					low += 1;
				}
				arr[high] = arr[low];
			}
			arr[low] = piv;
			return low;
		}
	};
	innerquick *p = new innerquick();
	p->action(arr, 0, (int)arr.size() - 1);
	aferinfo(arr);
	setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	delete p;
	
}
