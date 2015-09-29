// LoggerDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include<ctime>
#include "LoggerDLL.h"

using namespace std;

//ofstream Logger::_fhnd;

namespace LoggerDLL
{
	Logger::Logger()
	{

	}

	Logger::Logger(char *filename)
	{

		try{
			if (!_fhnd.is_open())
			{
				_fhnd.open(filename, ofstream::out | ofstream::app);
				_dt_fmt = { "[%Y-%m-%d %H:%M:%S]" };
			}
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}

	Logger::~Logger()
	{
		_fhnd.close();
	}

	void Logger::SetDateFormat(char *fmt)
	{
		_dt_fmt = fmt;
	}

	//GetTimeStamp obtains the current timestamp and formats to "[2014-09-28 22:12:59]" form
	string Logger::GetTimeStamp()
	{
		char buff[100];
		time_t t = time(nullptr);
		tm tm;
		localtime_s(&tm, &t);
		strftime(buff, sizeof(buff), _dt_fmt, &tm);
		return string(buff);
	}

	//GetLogleveString returns enum value to string name
	string Logger::GetLoglevelString(int level)
	{
		string lvlstr{};
		switch (level){
		case 0: lvlstr = "WARN: "; break;
		case 1: lvlstr = "ERROR: "; break;
		case 2: lvlstr = "INFO: "; break;
		}
		return lvlstr;
	}

	//WriteFile writes logs to file
	void Logger::WriteFile(loglevel level, string message)
	{
		WriteLog(level, message, true);
		// Write to file
	}

	//WriteConsole writes logs console
	void Logger::WriteConsol(loglevel level, string message)
	{
		WriteLog(level, message, false);
	}

	//WriteLog function writes formatted log to File or Console
	void Logger::WriteLog(loglevel level, string message, bool file)
	{
		try{
			_msemaphore.lock();
			if (file)
			{
				_fhnd << GetTimeStamp() << " " << GetLoglevelString(level) << message << endl;
			}
			else {
				cout << GetTimeStamp() << " " << GetLoglevelString(level) << message << endl;
			}
			_msemaphore.unlock();
		}
		catch (std::exception& e){
			throw e;
		}
	}

}