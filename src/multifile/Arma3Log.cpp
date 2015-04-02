/*
Author: Arkensor

Copytight and license can be viewed here: https://github.com/Arkensor/Arma3Log/blob/master/LICENSE
*/

#include "stdafx.h"
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>

extern "C"
{
	__declspec (dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function);
};

using namespace std;

void __stdcall RVExtension(char *output, int outputSize, const char *function)
{
	//Output it as the .dll resulkt to arma 3
	strncpy_s(output, outputSize, "done", _TRUNCATE);

	//Get current Server Time for loggin
	time_t currentTime;
	struct tm *localTime;

	time(&currentTime);                   // Get the current time
	localTime = localtime(&currentTime);  // Convert the current time to the local time

	//Convert them to strings
	string Day = to_string(localTime->tm_mday);
	string Month = to_string(localTime->tm_mon + 1);
	string Year = to_string(localTime->tm_year + 1900);
	string Hour = to_string(localTime->tm_hour);
	string Min = to_string(localTime->tm_min);
	string Sec = to_string(localTime->tm_sec);

	//Create Dir for Logging
	CreateDirectoryA("@Arma3Log/Arma3Logs", NULL);

	//convert const Cahr function to string funcname and find the : and remove content before
	std::string funcname = function;
	std::size_t pos = funcname.find("|");
	std::string outputstring = funcname.substr(pos + 1);
	std::string funcindex = funcname.substr(0, pos);

	stringstream strValue;
	strValue << funcindex;
	int intValue;
	strValue >> intValue;
	string lognamepref = "";
	//Create the dir for logging in the mod folder
	string Dirname = string("@Arma3Log/Arma3Logs/") + Day + "-" + Month + "-" + Year;
	CreateDirectoryA(Dirname.c_str(), NULL);

	//Switch the log file via the int from function name
	switch (intValue)
	{
	case 1:
	{
		//Setup the filename
		lognamepref = string("/Arma3Log-Money.txt");
		break;
	}
	case 2:
	{

		//Setup the filename
		lognamepref = string("/Arma3Log-Kills.txt");
		break;
	}
	case 3:
	{
		//Setup the filename
		lognamepref = string("/Arma3Log-Messages.txt");
		break;
	}
	case 4:
	{
		//Setup the filename
		lognamepref = string("/Arma3Log-Tradelog.txt");
		break;
	}
	case 5:
	{
		//Setup the filename
		lognamepref = string("/Arma3Log-Interactionlog.txt");
		break;
	}
	default:
	{
		//Setup the filename
		lognamepref = string("/Arma3Log-General.txt");
		break;
	}
	};
	//define log and do it
	string logname = string("") + Dirname + lognamepref;
	std::ofstream log(logname, std::ios_base::app | std::ios_base::out);
	log << Day << "-" << Month << "-" << Year << " - " << Hour << ":" << Min << ":" << Sec << " :: " << outputstring << "\n";
};