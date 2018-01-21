# ethiopian-calender-api
This will allow you to convert Gregorian Calender to Ethiopian Calender and vice versa


## How to use it?

**If your compiler is not c++11 mode, you have to add <b>-std=c++11 or -std=gnu++11</b> on your compiler settings/compiler flags**


The usage is really simple.
<p> Create a main.cpp file and add the following </p>

```cpp
#include <iostream>
#include "eth_cal.h" /** Include the header file */

int main() {

      string month, month_conv;
      int year, day, year_conv, day_conv;


      cout<<"Enter the Gregorian Date that you want to convert eg -> (Jun 15 2017) \n";
      cin>>month>>day>>year;

      tie(year_conv, month_conv, day_conv) = to_ethiopian_date(year, month, day);
      
      /** Now the year_conv, month_conv and day_conv - variables holds
        * the converted year, converted month and the converted day respectively
        */

      cout<<month_conv<<" "<<day_conv<< " " << year_conv << " E.C";

    return 0;

}

```

## Contributions

Feel free to create issues / pull requests.

## License

```
The MIT License (MIT)

Gregorian to Ethiopian Calender Convertor library
Copyright (c) 2018 Bisrat Yalew (http://github.com/bisratyalew).

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
