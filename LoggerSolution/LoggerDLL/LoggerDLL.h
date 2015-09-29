#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<mutex>

namespace LoggerDLL
{
	class __declspec(dllimport) Logger
	{
	public:
		enum loglevel{ LOGWARN, LOGERROR, LOGINFO };
		std::ofstream _fhnd;

		void SetDateFormat(char*);
		void WriteFile(loglevel, std::string);
		void WriteConsol(loglevel, std::string);

		//Constructor & Destructors
		Logger();
		Logger(char*);
		~Logger();

	private:
		char *_dt_fmt;
		std::mutex _msemaphore;
		const std::vector<std::string>_loglevel_text;
		std::string GetTimeStamp();
		std::string GetLoglevelString(int);
		void WriteLog(loglevel, std::string, bool);
	};
}