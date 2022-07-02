#include <stdio.h>

#include "SystemFunctions.h"

#ifdef __linux__

	#include <unistd.h>

#elif _WIN32

	#include <windows.h>

#else

#endif

void clearWindow(){

	#ifdef __linux__
	
		system("clear");
	
	#elif _WIN32
	
		system("cls");
	
	#else
	
	#endif

}

void mySleep(int tempoMs){

	#ifdef __linux__
	
		usleep(tempoMs);
	
	#elif _WIN32
	
		Sleep(tempoMs);
	
	#else
	
	#endif

}