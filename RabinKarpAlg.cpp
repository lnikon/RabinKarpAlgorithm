// RabinKarpAlg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


// We're all gonna die
void calcVector(vector<long long> pVec, const string& rStr)
{
	const int p = 599;	// prime number

	pVec[0] = 1;
	for (auto i = 1; i < pVec.size(); i++)
	{
		pVec[i] = pVec[i - 1] * p;
	}
}

// Function that will calculate and return hash of the string @str
long long CalcHash(string str)
{
	vector<long long> p_pow(str.length());	// a vector that contains this [p^0 ... p^str.length()] range
	calcVector(p_pow, str);

	long long hash = 0;
	for (auto i = 0; i < str.length(); i++)
	{
		hash += (str[i] - 'a' + 1)*p_pow[i];
	}

	return hash;
}

// Rabin-Karp algrorithm
void StringMatch(string str, string pattern)
{
	const auto sLen = str.length();
	const auto pLen = pattern.length();

	long long hpat = CalcHash(pattern);		// hash of pattern

	for (auto i = 0; i <= sLen - pLen; i++)
	{
		long long hstr = CalcHash(str.substr(i, pLen));
		if (hpat == hstr)
		{
			if (str.substr(i, pLen) == pattern)
			{
				cout << "Aloha! Index = " << i << endl;
			}
		}
	}
}

int main()
{
	string str;
	string pattern;

	cin >> str;
	cin >> pattern;

	StringMatch(str, pattern);

	return 0;
}

