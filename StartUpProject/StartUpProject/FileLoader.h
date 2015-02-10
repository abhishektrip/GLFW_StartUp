#pragma once
#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include "UtilityFunctions.h"

#define FILE_SIZE_UNKNOWN -1
using namespace std;
class FileLoader
{
public:
	char* LoadFile(string filename, int height, int width, int depth);
	char* LoadFile(string filename);
	FileLoader(string filename);
	FileLoader(){};
	~FileLoader();
private:
	void LoadFileInternal(string filename, const int bufferSize);
	char* mFileBuffer;
	ifstream mFileHandle;
};

