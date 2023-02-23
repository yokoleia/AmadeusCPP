#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int DateParser(string month)
{
    int monthInt = 0;

    if (month == "January")
        monthInt = 1;
    else if (month == "February")
        monthInt = 2;
    else if (month == "March")
        monthInt = 3;
    else if (month == "April")
        monthInt = 4;
    else if (month == "May")
        monthInt = 5;
    else if (month == "June")
        monthInt = 6;
    else if (month == "July")
        monthInt = 7;
    else if (month == "August")
        monthInt = 8;
    else if (month == "September")
        monthInt = 9;
    else if (month == "October")
        monthInt = 10;
    else if (month == "November")
        monthInt = 11;
    else if (month == "December")
        monthInt = 12;
    return monthInt;
}

int main()
{

    // TODO: Read dates from input, parse the dates to find the ones
    //       in the correct format, and output in m-d-yyyy format
    string str;

    getline(cin, str);
    while (str != "-1")
    {
        // can only match this: March 1, 1990
        if (isalpha(str[0]) && (str.find(",") != string::npos))
        {
            int commaIndx = str.find(",");
            str.erase(str.begin() + commaIndx);
            int Year;
            int Date;
            string strMonth;
            int intMonth;
            // string Month = str.substr(0, commaIndx);
            // string Year = str.substr(commaIndx+1, str.size()-1);

            istringstream inSS(str);
            inSS >> strMonth >> Date >> Year;

            intMonth = DateParser(strMonth);
            if (intMonth != 0)
            {
                cout << intMonth << "-" << Date << "-" << Year << endl;
            }
            // cout << Month << " " << Year << endl;
        }

        getline(cin, str);
    }
}
