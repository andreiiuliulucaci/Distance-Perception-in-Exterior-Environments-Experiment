// Fill out your copyright notice in the Description page of Project Settings.

#include "CSV.h"
using namespace std;
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>


CSV::CSV()
{
}

CSV::~CSV()
{
}

string CSV::Float2String(float Number, int Precision)
{
	ostringstream Out;
	Out.precision(Precision);
	Out << fixed << Number;
	return Out.str();
}

string CSV::CSVFormat(vector<float> Row)
{
	string Csv;
	for (float Element : Row)
	{
		Csv += Float2String(Element) + ";";
	}

	return Csv;
}

void CSV::AddRow(vector<float> Row)
{
	Data.push_back(CSVFormat(Row));
}

void CSV::AddRow(string Row)
{
	Data.push_back(Row);
}

void CSV::WriteCSVFile(string Filename, string Path)
{
	ofstream File;
	File.open(Path + "CSV_Files/" + Filename + ".csv");
	File << "X;Y;Z;Pitch;Yaw;Roll;Time" << endl;
	for (string Row : Data)
	{
		File << Row << endl;
	}
	File.close();
}


vector<string> CSV::Float2String(vector<float> Row, int Precision)
{
	vector<string> StringRow;

	for (float Element : Row)
	{
		ostringstream Out;
		Out.precision(Precision);
		Out << fixed << Element;
		StringRow.push_back(Out.str());
	}

	return StringRow;
}
