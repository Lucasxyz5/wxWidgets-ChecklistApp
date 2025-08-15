#ifndef OCCURENCE_H
#define OCCURENCE_H

#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

class Occurence
{
public:
    Occurence(string, string, int dateTime[]);
    bool GetCheck();
    string GetName();
    string GetDesc();
    string GetCode();
    int* GetTime();
    int GetPos();

    void CheckTime();
 
private:
    sys_time<minutes> DecodeDateTime(int dateTime[3]);

    bool check;
    string name;
    string desc;
    string code;
    sys_time<minutes> resetTime;
    int pos;

};

#endif