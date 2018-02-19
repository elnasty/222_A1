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

#include "date.h"

void updateDate(Date& date)
{
    time_t tt = time(0);
    tm * tp = localtime(&tt);
    date.day = tp->tm_mday;
    date.month = tp->tm_mon + 1;
    date.year = tp->tm_year + 1900;
}

void displayDate(Date date)
{
    cout << setfill('0') << setw(2) << date.day << "-" << setw(2) << date.month 
         << "-" << date.year << endl;
}

