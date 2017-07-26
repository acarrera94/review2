#include "TestCase.h"

#include <iostream>

using namespace std;
int TestCase::_totalCount = 0;
int TestCase::_totalPassing = 0;

TestCase::TestCase(const char *msg)
{
    _isPassing = true;
    _totalCount ++;
    cout << "********************************************************************************" << endl;
    cout << "*** " << msg << endl;
    cout << "********************************************************************************" << endl;
}

TestCase::~TestCase()
{
    cout << "--------------------" << endl;
    if (_isPassing)
    {
        _totalPassing++;
        cout << "passed" << endl;
    }
    else
        cout << "FAILED" << endl;

    cout << endl << endl;
}

void TestCase::LogResult(bool passed, const char *msg)
{
    if (passed)
    {
        cout << "Pass    " << msg << endl;
    }
    else
    {
        _isPassing = false;
        cout << "FAILED  " << msg << endl;
    }
}

void TestCase::Assert(bool condition, const char *msg)
{
    cout << (condition? "Pass    ": "FAILED  ") << "ASSERT: " << msg << endl;
    if (!condition)
        _isPassing = false;
}


void TestCase::AssertEquals(bool expected, bool actual, const char *msg)
{
	if (expected == actual)
		cout << "Pass    " << msg << "  Expected=" << expected << endl;
	else
	{
		_isPassing = false;
		cout << "FAIL    " << msg << "  Expected=" << expected << "  Actual=" << actual << endl;
	}
}


void TestCase::AssertEquals(int expected, int actual, const char *msg)
{
	if (expected == actual)
		cout << "Pass    " << msg << "  Expected=" << expected << endl;
	else
	{
		_isPassing = false;
		cout << "FAIL    " << msg << "  Expected=" << expected << "  Actual=" << actual << endl;
	}
}


void TestCase::LogException(std::exception ex)
{
    string msg = "EXCEPTION: ";
    msg += ex.what();

    LogResult(false, msg.c_str());
}


void TestCase::PrintSummary()
{
    int percentage = (int)((double)_totalPassing / (double)_totalCount * 100);

    cout << "TOTALS" << endl;
    cout << "    Total tests:   " << _totalCount << endl;
    cout << "    Total passing: " << _totalPassing << endl;
//    cout << "    Percentage:    " << percentage << "%" << endl;
    cout << endl;
    cout << "Your grade: " << 20.0 + (double)percentage * 0.80 << "%";

    cout << endl;
    cout << "Press [Enter] to continue...";
    std::cin.get();
}

bool TestCase::IsPassing()
{
	return _isPassing;
}