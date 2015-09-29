# cpp-logger
A Logger class project in c++ with dll, app and unit test sample

Logger Project - Documentation
=====================================================
A project to develop a Logger class.

Features
* Write to File/Console
* Multithread safe using mutex semaphore for writing to file/console
* No third party dependencies or platform specific api calls

Logger Solution Structure
-------------------------
	|---LoggerDLL Project
	|---LoggerMainApp Project
	|---LoggerUnitTest Project


LoggerDLL Project
-----------------
A Logger DLL class implementation for DLL and LIB

LoggerMainApp Project
---------------------
* A Logger sample executable implementation using Logger DLL and testing multithreading.
* Log file destination is set to "d:\unittest.log"

LoggerUnitTest Project
----------------------
A Logger Unit Test implemention with two unit testcases
	- LoggerFileCreated
	- LoggerFileWriteSuccess

Future Enhancements
-------------------
* Logger date format can be user defined such as locale, date format 
* Configurable Log levels

Known Issues
------------
* No runtime errors yet detected :)
