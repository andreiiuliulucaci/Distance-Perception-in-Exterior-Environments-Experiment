// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
using namespace std;

#include<vector>
#include<string>
#include "CoreMinimal.h"

/**
 *
 */
class MYPROJECT2_API CSV
{
private:
	vector<string> Data;

public:
	CSV();
	~CSV();

public:
	void AddRow(vector<float>);
	void AddRow(string);
	string CSVFormat(vector<float>);
	void WriteCSVFile(string, string Path);
	string Float2String(float, int Precision = 1);
	vector<string> Float2String(vector<float>, int Precision = 1);


};
