#include<vector>
#include<iostream>
#include"EditDistance.h"

typedef vector<string>::const_iterator Iter;
using namespace std;

int main()
{	string fileName = "american-english";
	EditDistance ed(fileName);
	string word;
	cout<<"search for word to spell correct: "<<endl;
	cin>>word;
	vector<string> v = ed.getMatchingWords(word);
	for(Iter iter = v.begin(); iter != v.end(); ++iter)
	{
		cout<<(*iter)<<endl;
	}
	return 0;
}
