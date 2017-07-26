// DO NOT MODIFY THIS FILE.

#include <exception>
#include <iostream>
#include "ArrayList.h"
#include "TestCase.h"

using namespace std;

//##############################################################################
//###   Constructor tests
//##############################################################################

/**************************************/
void ConstructorBasic()
{
    TestCase tc("Make a new instance of ArrayList.");

    try
    {
        ArrayList list;
        tc.LogResult(true, "Make an instance of an ArrayList");
    }
    catch (exception ex)
    {
        tc.LogException(ex);
    }
}


/**************************************/
void ConstructorCheckCount()
{
	TestCase tc("After creating a new ArrayList, GetCount() returns 0.");

	try
	{
		ArrayList list;
		tc.LogResult(true, "Make an instance of an ArrayList.");

		tc.AssertEquals(0, list.GetCount(), "Make sure GetCount() returns a 0 for a new ArrayList.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


/**************************************/
void ConstructorCheckCapacity()
{
	TestCase tc("After creating a new ArrayList, GetCapacity() returns 10.");

	try
	{
		ArrayList list;
		tc.LogResult(true, "Make an instance of an ArrayList.");

		tc.AssertEquals(10, list.GetCapacity(), "Make sure GetCapacity() returns 10.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   Append 
//##############################################################################

/**************************************/
void AppendItemsAndCheckCount()
{
	TestCase tc("Append items to the list and check the count.");

	try
	{
		ArrayList list;
		tc.AssertEquals(0, list.GetCount(), "GetCount returns 0 on empty list.");
		list.Append(5);
		tc.AssertEquals(1, list.GetCount(), "Append, then make sure GetCount returns 1.");
		list.Append(3);
		tc.AssertEquals(2, list.GetCount(), "Append, then make sure GetCount returns 2.");
		list.Append(7);
		tc.AssertEquals(3, list.GetCount(), "Append, then make sure GetCount returns 3.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void AppendReturnsTrueOnSuccess()
{
	TestCase tc("Append returns true on success.");

	try
	{
		ArrayList list;
		tc.AssertEquals(true, list.Append(5), "Append value of 5 returns true.");
		tc.AssertEquals(true, list.Append(3), "Append value of 3 returns true.");
		tc.AssertEquals(true, list.Append(7), "Append value of 7 returns true.");

		tc.AssertEquals(3, list.GetCount(), "Make sure GetCount returns 3 items.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void AppendBeyondCapacity()
{
	TestCase tc("Append fails properly when ArrayList is full.");

	try
	{
		ArrayList list;
		tc.AssertEquals(true, list.Append(5), "Append value of 5 returns true.");
		tc.AssertEquals(true, list.Append(3), "Append value of 3 returns true.");
		tc.AssertEquals(true, list.Append(7), "Append value of 7 returns true.");
		tc.AssertEquals(true, list.Append(1), "Append value of 1 returns true.");
		tc.AssertEquals(true, list.Append(4), "Append value of 4 returns true.");
		tc.AssertEquals(true, list.Append(2), "Append value of 2 returns true.");
		tc.AssertEquals(true, list.Append(6), "Append value of 6 returns true.");
		tc.AssertEquals(true, list.Append(9), "Append value of 9 returns true.");
		tc.AssertEquals(true, list.Append(8), "Append value of 8 returns true.");
		tc.AssertEquals(true, list.Append(0), "Append value of 0 returns true.");
		tc.AssertEquals(false, list.Append(100), "Append value of 100 returns false.");
		tc.AssertEquals(false, list.Append(101), "Append value of 101 returns false.");

		tc.AssertEquals(10, list.GetCount(), "Make sure GetCount returns 10 items.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   GetValue
//##############################################################################

/**************************************/
void GetValueAfterAppend()
{
	TestCase tc("Use GetValue to get a value after appending.");

	try
	{
		ArrayList list;
		list.Append(5);
		tc.AssertEquals(5, list.GetValue(0), "Add 5, read 5 at position 0.");
		list.Append(3);
		tc.AssertEquals(3, list.GetValue(1), "Add 3, read 3 at position 1.");
		list.Append(7);
		tc.AssertEquals(7, list.GetValue(2), "Add 7, read 7 at position 2.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void GetValueBeyondCurrentCount()
{
	TestCase tc("Verify that GetValue beyond the current count returns 0.");

	try
	{
		ArrayList list;
		tc.AssertEquals(0, list.GetValue(0), "GetValue(0) on an empty list returns 0.");
		
		list.Append(5);
		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) after inserting 1 item returns the item.");
		
		list.Append(3);
		list.Append(7);

		tc.AssertEquals(3, list.GetCount(), "Verify GetCount returns 3, after inserting 3 items.");
		tc.AssertEquals(7, list.GetValue(2), "Value at list[2] = 7");
		tc.AssertEquals(0, list.GetValue(3), "Value at list[3] = 0");
		tc.AssertEquals(0, list.GetValue(1000), "Value at list[1000] = 0");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   InsertAt
//##############################################################################

/**************************************/
void InsertAtBeginning()
{
	TestCase tc("Verify that InsertAt to the beginning inserts properly.");

	try
	{
		ArrayList list;
		tc.AssertEquals(0, list.GetCount(), "Starting count is 0.");

		tc.AssertEquals(true, list.InsertAt(0, 5), "Inserting 5 at pos 0 returns success.");
		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) returns 5.");
		tc.AssertEquals(1, list.GetCount(), "New count is 1.");

		tc.AssertEquals(true, list.InsertAt(0, 3), "Inserting 3 at pos 0 returns success.");
		tc.AssertEquals(3, list.GetValue(0), "GetValue(0) returns 3.");
		tc.AssertEquals(2, list.GetCount(), "New count is 2.");

		tc.AssertEquals(true, list.InsertAt(0, 7), "Inserting 7 at pos 0 returns success.");
		tc.AssertEquals(7, list.GetValue(0), "GetValue(0) returns 7.");
		tc.AssertEquals(3, list.GetCount(), "New count is 3.");
		tc.AssertEquals(3, list.GetValue(1), "GetValue(1) returns 3.");
		tc.AssertEquals(5, list.GetValue(2), "GetValue(2) returns 5.");
		tc.AssertEquals(0, list.GetValue(3), "GetValue(3) returns 0.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtMiddle()
{
	TestCase tc("Verify that InsertAt to the middle inserts properly.");

	try
	{
		ArrayList list;
		tc.Assert(list.Append(5), "Insert 5");
		tc.Assert(list.Append(3), "Insert 3");
		tc.Assert(list.Append(7), "Insert 7");
		tc.AssertEquals(3, list.GetCount(), "Count is 3.");
		tc.AssertEquals(true, list.InsertAt(1, 8), "Inserting 8 at pos 1 returns success.");
		tc.AssertEquals(4, list.GetCount(), "New count is 4.");

		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) returns 5.");
		tc.AssertEquals(8, list.GetValue(1), "GetValue(1) returns 8.");
		tc.AssertEquals(3, list.GetValue(2), "GetValue(2) returns 3.");
		tc.AssertEquals(7, list.GetValue(3), "GetValue(3) returns 7.");
		tc.AssertEquals(0, list.GetValue(4), "GetValue(4) returns 0.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtEnd()
{
	TestCase tc("Verify that InsertAt to the end inserts properly.");

	try
	{
		ArrayList list;
		tc.AssertEquals(true, list.InsertAt(0, 5), "Inserting 5 at pos 0 returns success.");
		tc.AssertEquals(5, list.GetValue(0), "GetValue(0) returns 5.");

		tc.AssertEquals(true, list.InsertAt(1, 3), "Inserting 3 at pos 1 returns success.");
		tc.AssertEquals(3, list.GetValue(1), "GetValue(1) returns 3.");

		tc.AssertEquals(true, list.InsertAt(2, 7), "Inserting 7 at pos 2 returns success.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtEndingHandlesOverflow()
{
	TestCase tc("Verify that InsertAt errors out beyond 10 items (ending).");

	try
	{
		ArrayList list;
		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);
		list.Append(80);
		list.Append(90);
		tc.AssertEquals(9, list.GetCount(), "List starts out with 9 items.");
		tc.AssertEquals(true, list.InsertAt(9, 100), "Inserting a value at position 9 returns success.");
		tc.AssertEquals(false, list.InsertAt(10, 101), "Inserting a value at position 10 fails.");
		tc.AssertEquals(false, list.InsertAt(11, 102), "Inserting a value at position 11 fails.");
		tc.AssertEquals(10, list.GetCount(), "List has only 10 items.");
		tc.AssertEquals(90, list.GetValue(8), "check value at data[8]");
		tc.AssertEquals(100, list.GetValue(9), "check value at data[9]");
		tc.AssertEquals(0, list.GetValue(10), "check value at data[10]");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void InsertAtBeginningHandlesOverflow()
{
	TestCase tc("Verify that InsertAt errors out beyond 10 items (beginning).");

	try
	{
		ArrayList list;
		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);
		list.Append(80);
		list.Append(90);
		tc.AssertEquals(9, list.GetCount(), "List starts out with 9 items.");
		tc.AssertEquals(true, list.InsertAt(0, 100), "Inserting a value at position 0 returns success.");
		tc.AssertEquals(false, list.InsertAt(0, 101), "Inserting another value at position 0 fails.");
		tc.AssertEquals(false, list.InsertAt(0, 102), "Inserting another value at position 0 fails.");
		tc.AssertEquals(10, list.GetCount(), "List has only 10 items.");
		tc.AssertEquals(100, list.GetValue(0), "check value at data[0]");
		tc.AssertEquals(10, list.GetValue(1), "check value at data[1]");
		tc.AssertEquals(90, list.GetValue(9), "check value at data[9]");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   RemoveAt
//##############################################################################

/**************************************/
void RemoveAtEmptyList()
{
	TestCase tc("Verify that RemoveAt from an empty list returns false.");

	try
	{
		ArrayList list;
		tc.Assert(!list.RemoveAt(0), "Verify calling RemoveAt() on an empty list fails.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void RemoveAtOneItem()
{
	TestCase tc("Verify that RemoveAt for one item in list.");

	try
	{
		ArrayList list;
		list.Append(10);
		tc.AssertEquals(1, list.GetCount(), "Count starts with 1 item.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0), removes one item from list.");
		tc.AssertEquals(0, list.GetCount(), "Count is now zero.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void RemoveAtMaxList()
{
	TestCase tc("Verify RemoveAt with a full list.");

	try
	{
		ArrayList list;
		list.Append(10);
		list.Append(20);
		list.Append(30);
		list.Append(40);
		list.Append(50);
		list.Append(60);
		list.Append(70);
		list.Append(80);
		list.Append(90);
		list.Append(100);
		tc.AssertEquals(10, list.GetCount(), "Start out with a list of 10 elements.");
		tc.Assert(!list.RemoveAt(10), "Verify we can't call RemoveAt(10)");
		tc.Assert(!list.RemoveAt(11), "Verify we can't call RemoveAt(11)");
		tc.Assert(list.RemoveAt(9), "RemoveAt(9) succeeds.");
		tc.Assert(!list.RemoveAt(9), "RemoveAt(9) fails on the second try.");
		tc.AssertEquals(9, list.GetCount(), "The array has 9 elements");
		tc.Assert(list.RemoveAt(7), "RemoveAt(7) succeeds once.");
		tc.Assert(list.RemoveAt(7), "RemoveAt(7) succeeds twice.");
		tc.Assert(!list.RemoveAt(7), "RemoveAt(7) fails on the third try.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0) succeeds on the first try.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0) succeeds on the second try.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0) succeeds on the third try.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0) succeeds on the fourth try.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0) succeeds on the fifth try.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0) succeeds on the sixth try.");
		tc.Assert(list.RemoveAt(0), "RemoveAt(0) succeeds on the seventh try.");
		tc.Assert(!list.RemoveAt(0), "RemoveAt(0) fails on the eighth try.");
		tc.AssertEquals(0, list.GetCount(), "The array is now empty.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   SetValue
//##############################################################################

/**************************************/
void SetValueOnEmptyList()
{
	TestCase tc("Try calling SetValue on an empty list fails.");

	try
	{
		ArrayList list;
		tc.AssertEquals(0, list.GetCount(), "We're starting with an empty list.");
		tc.Assert(!list.SetValue(0, 100), "Can't call SetValue(0) on an empty list.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void SetValueOnData()
{
	TestCase tc("Try calling SetValue on data in a list.");

	try
	{
		ArrayList list;
		list.Append(5);
		list.Append(3);
		list.Append(7);
		tc.AssertEquals(3, list.GetCount(), "We're starting with three items in the list.");
		tc.Assert(list.SetValue(0, 10), "SetValue(0, 10) succeeds.");
		tc.Assert(list.SetValue(1, 20), "SetValue(1, 20) succeeds.");
		tc.Assert(list.SetValue(2, 30), "SetValue(2, 30) succeeds.");
		tc.Assert(!list.SetValue(3, 99), "SetValue(3, 99) fails.");
		tc.AssertEquals(10, list.GetValue(0), "GetValue(0) returns 10.");
		tc.AssertEquals(20, list.GetValue(1), "GetValue(1) returns 20.");
		tc.AssertEquals(30, list.GetValue(2), "GetValue(2) returns 30.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}



//##############################################################################
//###   main
//##############################################################################

/**************************************/
int main()
{
	// Constructor tests
	ConstructorBasic();
	ConstructorCheckCount();
	ConstructorCheckCapacity();

	// Append
	AppendItemsAndCheckCount();
	AppendReturnsTrueOnSuccess();
	AppendBeyondCapacity();

	// GetValue
	GetValueAfterAppend();
	GetValueBeyondCurrentCount();

	// InsertAt
	InsertAtBeginning();
	InsertAtMiddle();
	InsertAtEnd();
	InsertAtEndingHandlesOverflow();
	InsertAtBeginningHandlesOverflow();

	// RemoveAt
	RemoveAtEmptyList();
	RemoveAtMaxList();

	// SetValue
	SetValueOnEmptyList();
	SetValueOnData();

    TestCase::PrintSummary();
}