#include <iostream>
#include <unordered_map>
#include "dataGenerator.h"
#include "runtimeCal.h"
#include "bubbleSortClass.h"
#include "heapSortClass.h"
#include "mergeSortClass.h"
#include "quickSortClass.h"
#include "test.h"

using namespace std;
namespace {
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

	
	// global varibles
	int p1result = 0, p2result = 0;
	string p1 = "";
	string p2 = "";
	string command = "";
	unordered_map<string, int> p1Switch;
	unordered_map<string, int> p2Switch;
	unordered_map<int, string> errSwitch;
	
	void init(){
		errSwitch[0] = "parameter p1 value error";
		errSwitch[1] = "parameter p2 value error";
		errSwitch[2] = "error/no command error";
		errSwitch[3] = "no parameter p1 error";
		errSwitch[4] = "no parameter p2 error";
		
		p1Switch["bubble"] = 1;
		p1Switch["heap"] = 2;
		p1Switch["merge"] = 3;
		p1Switch["quick"] = 4;
		p1Switch["unquick"] = 5;		// 非递归quick sort
		p1Switch["upquick"] = 6;		// 改进的quick sort
		
	}
	

	void errFormatOutput(string err, string type){
		setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "##ERROR:type=" << type << ":" << err << endl;
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
	}
	
	void errorhandler(int codeid){
		if(codeid == 1){
			errFormatOutput(errSwitch[2], "2");	// "error/no command error"
		}else if(codeid == 2){
			errFormatOutput(errSwitch[3], "3"); // no parameter p1 error
		}else if(codeid == 3){
			errFormatOutput(errSwitch[4], "4"); // no parameter p2 error
		}else if(codeid == 4){
			errFormatOutput(errSwitch[0], "0");	// parameter p1 value error
		}else if(codeid == 5){
			errFormatOutput(errSwitch[1], "1");	// parameter p2 value error
		}
	}
	
	bool inputparse(int argc, char** argv){
		// 获取命令并捕获错误
		command = argv[1];
		if(command.empty()){
			errorhandler(1);
			return false;
		}
		// 获取参数值并捕获错误
		for(int i = 1; i < argc; i++){
			if (std::string(argv[i]) == "-p1") {
				if (i + 1 < argc) {
					p1 = argv[i + 1];
				}
			}else if(std::string(argv[i]) == "-p2"){
				if (i + 1 < argc) {
					p2 = argv[i + 1];
				}
			}
		}
		if(command == "help" || command == "exit"){
			return true;
		}else{
			if(p1.empty() &&(command == "valid" || command == "stable")){
				errorhandler(2);
				return false;
			}
			if(command == "runtime"){
				if(p1.empty())
					errorhandler(2);
				
				if(p2.empty())
					errorhandler(3);
				if(!p1.empty() && !p2.empty()){
					return true;
				}
				return false;
			}
		}
		return true;
	}
}



int main(int argc, char** argv) {
	init();
	if(!inputparse(argc,argv)){
		return 0;
	}
	// 手动解析参数
	if(command == "exit"){
		return 0;
	}
	else if (command == "help"){
		setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << " -- usage: <command> -p1 <p1 value> -p2 <p2 value>\n" \
		" -- examples:\n" \
		" ----@ help: get usage\n"\
		" ----@ exit: exit program\n"\
		" ----@ valid -p1 <sort type>: valid test\n" \
		" --------#sort type => bubble , means bubble sort\n" \
		" --------#sort type => heap , means heap sort\n" \
		" --------#sort type => merge , means merge sort\n" \
		" --------#sort type => quick , means recursion quick sort\n"\
		" --------#sort type => unquick , means unrecursion quick sort\n"\
		" --------#sort type => upquick , means updated quick sort\n"\
		" ----@ runtime -p1 <sort type> -p2 <data size>: run time test\n" \
		" --------#sort type: use 'sort type' in 'valid' command\n"\
		" --------#data size: an interger to describe data scale\n" \
		" ----@ stable -p1 <sort type>: run stability test\n" \
		" --------#sort type: use 'bubble' 'heap' 'merge' 'quick'\n";
		setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);			// 设置默认输出
		
	}else if(command == "valid"){
		// testData* data = new testData();
		int result = (p1Switch.find(p1)!= p1Switch.end()) ? p1Switch.find(p1)->second : -1;
		if(result == -1){
			errorhandler(4);
		}
		test *p = new test();
		switch (result){
			case 1:{//bubble
				p->testValidBubbleSort();
				break;
			}
			case 2:{//heap
				p->testValidHeapSort();
				break;
			}
			case 3:{//merge
				p->testValidMergeSort();
				break;
			}
			case 4:{//quick
				p->testValidQuickSort();
				break;
			}
			case 5:{//unquick
				p->testValidUnQuickSort();
				break;
			}
			case 6:{//upquick
				p->testValidUpQuickSort();
				break;
			}
			default:{
				break;
			}
		}
		delete p;
	}
	else if(command == "runtime"){
		p1result = (p1Switch.find(p1)!= p1Switch.end()) ? p1Switch.find(p1)->second : -1;	// 检查参数 p1 value 是否合法
		p2result = (!p2.empty()) ? std::stoi(p2) : -1;										// 检查参数 p2 value 是否合法
		if(p1result == -1){
			errorhandler(4);
		}
		if(p2result == -1){
			errorhandler(5);
		}
		test *p = new test();
		switch (p1result) {
			case 1:{ // bubble
				p->testBuddleSortRunTime(std::stoi(p2));
				break;
			}
			case 2:{ // heap
				p->testHeapSortRunTime(std::stoi(p2));
				break;
			}
			case 3:{ // merge
				p->testMergeSortRunTime(std::stoi(p2));
				break;
			}
			case 4:{ // quick
				p->testQuicSortRunTime(std::stoi(p2));
				break;
			}
			case 5:{ // unquick
				p->testQuicSortNonRecursionAction(std::stoi(p2));
				break;
			}
			case 6:{ // upquick
				p->testQuicSortUpdateAction(std::stoi(p2));
				break;
			}
			default:{
				break;
			}
		}
		delete p;
	}
	else if(command == "stable"){
		p1result = (p1Switch.find(p1)!= p1Switch.end()) ? p1Switch.find(p1)->second : -1;	// 检查参数 p1 value 是否合法
		if(p1result == -1){
			errorhandler(4);
		}
		test *p = new test();
		switch (p1result) {
			case 1:{ // bubble
				p->testStableBubbleSort();
				break;
			}
			case 2:{ // heap
				p->testStableHeapSort();
				break;
			}
			case 3:{ // merge
				p->testStableMergeSort();
				break;
			}
			case 4:{ // quick
				p->testStableQuickSort();
				break;
			}
			default:
				break;
		}
		delete p;
	}
	return 0;
}
