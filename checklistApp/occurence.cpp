#include "occurence.h"
//compile command (for testing purposes): g++ -std=c++20 -o testprogram occurence.cpp

Occurence::Occurence(string nameI, string descI, int* dateTime)
{
    check = false;
    name = nameI;
    desc = descI;
    resetTime = DecodeDateTime(dateTime);
    pos = -1;
}

void Occurence::CheckTime()
{
    const auto now = sys_days{floor<days>(system_clock::now())};

    if (resetTime < now) // if reset time is in the past
    {
        //decode the code to get next time 
        //set resetTime to new date
        check = false;
    }
}

bool Occurence::GetCheck()
{
    return check;
}

string Occurence::GetName()
{
    return name;
}

string Occurence::GetDesc()
{
    return desc;
}


string Occurence::GetCode()
{
    return code;
}

int* Occurence::GetTime()
{
    int *outArray = new int[3];

    year_month_day ymd = floor<days>(resetTime);
    outArray[0] = int(ymd.year());
    outArray[1] = unsigned(ymd.month());
    outArray[2] = unsigned(ymd.day());

    return outArray;
} //you must use delete afterwards!

sys_time<minutes> Occurence::DecodeDateTime(int* dateTime)
{
    year_month_day ymd{
        year(dateTime[0]), 
        month(dateTime[1]), 
        day(dateTime[2])};
    sys_days date = sys_days{ymd};
    return date;
}

/*
int main() {
    int dateTime[3] = {2024, 5, 6};
    Occurence test1("test_name", "", dateTime);
    int* test2 = test1.GetTime();
    cout << test2[0];
    cout << "\n";
    cout << test2[1];
    cout << "\n";
    cout << test2[2];
    cout << "\n";
    test1.CheckTime();
    delete test2;
}
*/