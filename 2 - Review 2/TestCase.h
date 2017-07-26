#pragma once

#include <string>

class TestCase
{
private:
    bool _isPassing;
    static int _totalCount;
    static int _totalPassing;

public:
    TestCase(const char* title);
    ~TestCase();

    void LogResult(bool passed, const char *msg);
    void Assert(bool consition, const char *msg);
	void AssertEquals(bool expected, bool actual, const char *msg);
	void AssertEquals(int expected, int actual, const char *msg);
	void LogException(std::exception ex);
	bool IsPassing();

    static void PrintSummary();
};

