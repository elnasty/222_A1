/* 
 * Name         : date.h
 * Author       : Stanley
 * Sub Authors  :
 *
 * Created on   : 140217
 *
 * Purpose      : contains the global variables DAY MONTH YEAR, a function to
 *                initialize those variables and the struct Date;
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 * 190217       Stanley         Added a lot of date functions
 */

#ifndef GLOBAL_
#define GLOBAL_

#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

int DAYS_NOLEAP [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int DAYS_LEAP [12] = {31,29,31,30,31,30,31,31,30,31,30,31};

extern Date GLOBALDATE;
void updateDate(Date&);
void displayDate(Date);
int daysBetween(Date, Date);
bool dateEarlierDate(Date, Date);
bool sameDate(Date, Date);
void incrementDate(Date&);
void inputDates(Date&, Date&);
bool validDate(Date);
bool dateWithin(Date, Date, Date);
int monthToInt(char*);

void reverse(char str[], int length);
char* itoa(int num, char* str, int base);

#endif

