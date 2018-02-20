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
    cout << right;
    cout << setfill('0') << setw(2) << date.day << "/" << setw(2) << date.month 
         << "/" << date.year << setfill(' ') << "";
    cout << left;
}

int monthToInt(char* c)
{
    if(!strcmp(c, "Jan"))
        return 1;
    else if(!strcmp(c, "Feb"))
        return 2;
    else if(!strcmp(c, "Mar"))
        return 3;
    else if(!strcmp(c, "Apr"))
        return 4;
    else if(!strcmp(c, "May"))
        return 5;
    else if(!strcmp(c, "Jun"))
        return 6;
    else if(!strcmp(c, "Jul"))
        return 7;
    else if(!strcmp(c, "Aug"))
        return 8;
    else if(!strcmp(c, "Sep"))
        return 9;
    else if(!strcmp(c, "Oct"))
        return 10;
    else if(!strcmp(c, "Nov"))
        return 11;
    else if(!strcmp(c, "Dec"))
        return 12;
}

void incrementDate(Date& date)
{
    date.day += 1;
    
    if (!(date.year % 4)) // leap year
    {
        if (date.day > DAYS_LEAP [date.month - 1])
        {
            date.day = 1;
            date.month += 1;
        }
        
        if (date.month > 12)
        {
            date.month = 1;
            date.year += 1;
        }
    }
    else
    {
        if (date.day > DAYS_NOLEAP [date.month - 1])
        {
            date.day = 1;
            date.month += 1;
        }
        
        if (date.month > 12)
        {
            date.month = 1;
            date.year += 1;
        }
    }   
}

bool sameDate(Date date1, Date date2)
{
    if(date1.day == date2.day)
        if(date1.month == date2.month)
            if(date1.year == date2.year)
                return true;
    
    return false;
}

bool dateEarlierDate(Date date1, Date date2)
{
    if(date1.year > date2.year) // date1 year later
        return false;
    else if (date1.year < date2.year) //date1 year earlier
        return true;
    
    // means years are equal
    if(date1.month > date2.month) // date1 month later
        return false;
    else if (date1.month < date2.month) // date1 month earlier
        return true;
    
    // means months are equal
    if(date1.day >= date2.day) // date1 day later OR EQUALS
        return false;
    else if (date1.day < date2.day) // date1 day earlier
        return true;    
}

int daysBetween(Date date1, Date date2)
{
    int i = 0;
    
    if(dateEarlierDate(date1, date2))
        while (!sameDate(date1, date2))
        {             
            incrementDate(date1);
            i++;
        }
    else // date 2 is the earlier date
        while (!sameDate(date2, date1))
        {
            incrementDate(date2);
            i++;
        }
    return i;
}

bool dateWithin(Date within, Date date1, Date date2)
{
    while(!sameDate(date1, date2))
    {
        incrementDate(date1);
        if(sameDate(within, date1))
            return true;
    }
    return false;
}

void inputDates(Date& date1, Date& date2)
{
    cout << "Please enter day of first date: ";
    cin >> date1.day;
    cout << "Please enter month of first date: ";
    cin >> date1.month;
    cout << "Please enter year of first date: ";
    cin >> date1.year;
    
    cout << endl << "Please enter day of second date: ";
    cin >> date2.day;
    cout << "Please enter month of second date: ";
    cin >> date2.month;
    cout << "Please enter year of second date: ";
    cin >> date2.year;
}

bool validDate(Date date)
{
    if((date.year < 2000) || (date.year > 2018))
    {
        return false;
    }
    
    if((date.month < 0) || (date.month > 12))
    {
        return false;
    }
    
    if(!(date.year%4)) // leap
    {
        if((date.day < 0) ||(date.day > DAYS_LEAP[date.month -1]))
            return false;
    }
    else // not leap
    {
        if((date.day < 0) || (date.day > DAYS_NOLEAP[date.month -1]))
            return false;
    }
    
    if (!dateEarlierDate(date, GLOBALDATE))
    {
        if(sameDate(date, GLOBALDATE))
            return true;
        else
            return false;
    }
    return true;
}

/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}
 
// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}




