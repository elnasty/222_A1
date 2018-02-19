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

extern Date GLOBALDATE;
void updateDate(Date&);
void displayDate(Date);
void reverse(char str[], int length);
char* itoa(int num, char* str, int base);

#endif

