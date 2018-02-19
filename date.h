/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Name         : date.h
 * Author       : Stanley
 * Sub Authors  :
 *
 * Created on   : 120217
 *
 * Purpose      : contains the global variables DAY MONTH YEAR, a function to
 *                initialize those variables and the struct Date;
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 */

#pragma once
#include <ctime>
using namespace std;

static int DAY, MONTH, YEAR;

struct Date
{
    int day;
    int month;
    int year;
};

void updateDate()
{
    time_t tt = time(0);
    tm * tp = localtime(&tt);
    DAY = tp->tm_mday;
    MONTH = tp->tm_mon + 1;
    YEAR = tp->tm_year + 1900;
}
