#pragma once
#ifndef __EDIT_DISTANCE_
#define __EDIT_DISTANCE_
using namespace std;

#include<vector>
#include<string>

class EditDistance
{
public:
	EditDistance(const string& base);
	const vector<string> getMatchingWords(const string& word);
	int getDistance(string base, string eval);
private:
	string mBase;
	string mCurrent;
	vector<string> mDictionary;

	int min(int a, int b, int c);
	int calcDpOpMin(int prevCell, const char x, const char y);
	
};

#endif

