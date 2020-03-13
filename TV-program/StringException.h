#pragma once
#include<iostream>
#include<string>
using namespace std;
class StringException :
	public exception
{
private:

public:
	string message();
};

