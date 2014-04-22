using namespace std;
#include<iostream>
#include "EditDistance.h"
#include<fstream>
#include<cstring>

typedef vector<string>::const_iterator Iter;


EditDistance::EditDistance(const string& base)
{
	ifstream file;
	string fileName = base;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		file.open(fileName.c_str());
		string line;
		while(getline(file, line))
		{
			mDictionary.push_back(line);
		}
		file.close();
	}
	catch(ifstream::failure e)
	{
		mBase = base;
	}
}

const vector<string> EditDistance::getMatchingWords(const string& word)
{
	vector<string> v;
	int minDist = 99999;
	for(Iter iter = mDictionary.begin(); iter != mDictionary.end(); ++iter)
	{
		int dist = getDistance(*iter, word);
		if(dist < minDist)
		{
			v.clear();
			v.push_back(*iter);
			minDist = dist;
		}
		else if(minDist == dist)
		{
			v.push_back(*iter);
		}
	}
	return v;
}

int EditDistance::getDistance(string base, string eval)
{
	int x = base.length() + 1;
	int y = eval.length() + 1;
	int **matrix = new int *[x];
	int minDistance;
	for(int i = 0; i < x; ++i)
	{
		matrix[i] = new int[y];
	}

	for(int i = 0; i < x; ++i)
	{
		matrix[i][0] = i;
	}

	for(int j = 0; j < y; ++j)
	{
		matrix[0][j] = j;
	}

	for(int i = 1; i < x; ++i)
	{
		for(int j = 1; j < y; ++j)
		{
			matrix[i][j] = min( (matrix[i-1][j] + 1), (matrix[i][j-1] + 1), 
							(calcDpOpMin(matrix[i-1][j-1], base[i-1], eval[j-1])) );
		}
	}

	minDistance = matrix[x-1][y-1];
	for(int i = 0; i < x; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	//cout<<minDistance<<endl;
	return minDistance;
}

int EditDistance::min(int a, int b, int c)
{
	//cout<<a<<" "<<b<<" "<<c<<" \n";
	int ret = a <= b ? (a <= c ? a : c) : (b <= c ? b : c);
	//cout<<"after comp: "<<ret<<"\n";
	return ret;
}

int EditDistance::calcDpOpMin(int prevCell, const char x, const char y)
{
	return prevCell + (x == y ? 0 : 2);
}





