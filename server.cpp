#include <ctime>
#include <fstream>
#include <iostream>

char timeBuffer[256];
time_t rawtime;
struct tm* currentTime;

int main()
{
	std::string str; 
	std::ifstream serialInput; 
	std::ofstream fileOutput;
	serialInput.open("/dev/cu.usbmodem411"); 
	fileOutput.open("WaterData", std::fstream::app);
	while (serialInput >> str)
	{
		time(&rawtime);
		currentTime = localtime(&rawtime);
		std::strftime(timeBuffer, sizeof(timeBuffer), "%d/%m/%y-%H:%M:%S", currentTime);
		fileOutput << timeBuffer << " " << str << '\n';
	}
}
