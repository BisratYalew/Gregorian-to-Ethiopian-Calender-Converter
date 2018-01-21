/**
    eth_cal.h

    Purpose: Converts Gregorian Calender to Ethiopian Calender

    @author  -  Bisrat Yalew

    @version    1.0
    @date       Jan 5, 2018 G.C
*/


#include <iostream>
#include <map>
#include <tuple>


using namespace std;

bool isLeapYear(int year);
int get_month(string month);
int get_year(int year, int month, int day);
int get_day(int year, string month, int day);

//Gregorian's Month Days Length from Sep - Aug
int gregorial_month_days_length[] = { 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31 };

// Ethiopian's Month Days Length from Mes - Pua
int ethiopian_month_days_length[13] = { 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5 };

// Month day's difference between gregorians_month[0] and ethiopians_month[0] up-to [12]
int month_days_difference[12] = { 10, 10, 9, 9, 8, 7, 9, 8, 8, 7, 7, 9 };

string gregorian_month[12] = {
                                    "Sep", "Oct", "Nov", "Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug"
                            };

string ethiopian_month[13] = {
                                  "Mes", "Tik", "Hid", "Tah", "Tir", "Yek", "Meg", "Miy", "Gin", "Sen", "Ham", "Neh", "Pau"

                             };



/**
      @param  { int }  year => gregorian year
      @return { isLeapYear ? true : false }
      @throw  { Invalid Year ERROR }

 */

bool isLeapYear(int year) {

    if(year % 4 == 0) {

        if(year % 100 == 0) {

            if(year % 400 == 0) {}

                return true;
        }

    } else {

        return false;

    }

}



/**
    @param { int } year
    @param { int } month
    @param { int } day
    @return year
    @throw { Invalid Year ERROR }

*/

int get_year(int year, int month, int day) {

    if (!month >= 5 && !month <= 12) {

        if (month == 1 && day <= 11) {

            cout<<"Year -- "<<endl;

            return year - 8;

       } else {

            return year - 9;

       }


    } else {

         return year - 8;

    }

}




/**

   @param { string } month => shortened_gregorian_month_name
   @return the month number
   @throw { Can't Find Month ERROR }


  */

int get_month(string month) {

    int monthNumber;

    for (int i=0; i<12; ++i) {

        if(gregorian_month[i] == month) {

                monthNumber = i + 1;

        }

    }

    return monthNumber;

}




/**
     @param  { string } month - The month name
     @return { int } day_to_r - day number
     @throw Invalid Month Error

  */

pair<string, int> map_month(string month, int day_to_r) {

    typedef map<string, string> MapMonth;

    MapMonth gregorian_to_ethiopian;

    int monthNumber, day_f;


    if(day_to_r < 1) {

        for(int i=1; i<=11; ++i) {

             gregorian_to_ethiopian[gregorian_month[i]] = ethiopian_month[i-1];

        }

        monthNumber = get_month(month);

        day_f = (gregorial_month_days_length[monthNumber-1]) + day_to_r;

    }  else if(day_to_r > 0 && day_to_r < 45) {

        day_f = day_to_r;

        for(int i=1; i<=11; ++i) {

             gregorian_to_ethiopian[gregorian_month[i]] = ethiopian_month[i];

        }


    }

        return make_pair(gregorian_to_ethiopian[month], day_f);
}


/**
      @param  { int } year
      @param  { string } month => shortened_gregorian_month_name
      @param  { int } day
      @return { int } day - converted day
      @throw  { Invalid Year, Month, Day => Error }

  */

int get_day(int year, string month, int day) {

    int monthIndex;
    int day_to_r;

    if(isLeapYear(year) == true) {
        /**
         *   Handle Leap Years
         */

        monthIndex = get_month(month);

        switch(monthIndex) {
            case 12:
                day_to_r = day - month_days_difference[monthIndex - 1];
            default:
                day_to_r = day - month_days_difference[monthIndex - 1];
        }



    } else {
        // Handle Non Leap Years

        monthIndex = get_month(month);

        switch(monthIndex) {
            case 12:
                day_to_r = day - month_days_difference[monthIndex - 1];
            default:
                day_to_r = day - month_days_difference[monthIndex - 1];
        }

    }

    return day_to_r;
}


/**
    @param  { int } year - gregorian_year
    @param  { string } month - shortened_gregorian_month_name
    @param  { int }  day
    @return { year_converted, month_converted, day_converted }
    @throw  { Invalid Year, Month, Day => Error }

  */

tuple<int, string, int> to_ethiopian_date(int year, string month, int day) {

        string month_conv;
        int day_conv, year_conv, monthNumber, day_to_ret;

        monthNumber = get_month(month);

        day_to_ret = get_day(year, month, day);

        pair<string, int> mapped_month = map_month(month, day_to_ret);

        month_conv = mapped_month.first;
        day_conv = mapped_month.second;

        year_conv = get_year(year, monthNumber, day);

        return make_tuple(year_conv, month_conv, day_conv);

}
