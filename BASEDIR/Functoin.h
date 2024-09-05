#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Data.h"

void FieldBaseDirEntry(FieldBaseDir*& inputData, int& dataStreamSize);
void FieldBaseDirReading(FieldBaseDir* inputData, int& dataStreamSize, std::string fileName);
void FieldBaseDirPrint(FieldBaseDir* inputData, int dataStreamSize);
void FieldBaseDirChange(FieldBaseDir* inputData, int dataStreamSize);
void FieldBaseDirCopy(FieldBaseDir* newData, FieldBaseDir* oldData, int dataStreamSize);
void FieldBaseDirAddData(FieldBaseDir* inputData, int& dataStreamSize);
void FieldBaseDirDeleteData(FieldBaseDir* inputData, int& dataStreamSize);
void FieldBaseDirSorting(FieldBaseDir* inputData, int dataStreamSize);
void FieldBaseDirSaveData(FieldBaseDir* inputData, int dataStreamSize, std::string fileName);