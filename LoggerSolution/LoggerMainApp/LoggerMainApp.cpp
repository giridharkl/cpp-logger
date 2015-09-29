// LoggerMainApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LoggerDLL.h"
#include<thread>
#include<string>
using namespace LoggerDLL;

void task(Logger *log, std::string msg)
{
	try{
		log->WriteFile(Logger::LOGWARN, msg);
	}
	catch (std::exception){
		throw;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	try{
		char file[] = "d:\\unittest.log";
		Logger log{ file };
		log.WriteConsol(Logger::LOGWARN, "message");
		log.WriteFile(Logger::LOGINFO, "Log from c++ dll library!");
		std::thread t1(task, &log, "Thread-1");
		std::thread t2(task, &log, "Thread-2");
		t1.join();
		t2.join();
		return 0;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

