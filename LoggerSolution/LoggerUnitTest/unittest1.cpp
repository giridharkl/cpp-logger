#include "stdafx.h"
#include "CppUnitTest.h"
#include<stdio.h>
#include<thread>
#include "..\LoggerDLL\LoggerDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LoggerUnitTest
{
	static class TestHelper
	{
	public:
		void task(LoggerDLL::Logger *log, std::string msg)
		{
			log->WriteFile(LoggerDLL::Logger::LOGWARN, msg);
		}
	};

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod_LoggerFileCreated)
		{	
			char file[] = "d:\\unittest.log";
			remove(file);
			LoggerDLL::Logger Log{file};
			Log.WriteFile(LoggerDLL::Logger::LOGINFO, "unittest - message");
			bool FileExists = std::ifstream(file).good();
			Assert::IsTrue(FileExists == true);
		}

		TEST_METHOD(TestMethod_LoggerFileWriteSucceed)
		{
			char file[] = "d:\\unittest.log";
			std::string line = "";
			remove(file);
			LoggerDLL::Logger Log{ file };
			Log.WriteFile(LoggerDLL::Logger::LOGINFO, "unittest - LoggerFileWriteSucceed");
			std::getline(std::ifstream(file), line);
			Assert::IsTrue(line.length() > 10);
		}
	};
}