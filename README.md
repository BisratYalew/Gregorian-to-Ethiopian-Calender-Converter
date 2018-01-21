# ethiopian-calender-api
This will allow you to convert Gregorian Calender to Ethiopian Calender and vice versa


## How do I use it?

**If your compiler is not c++11 mode, you have to add <b>-std=c++1 or -std=gnu++11</b> on your compiler settings/compiler flags**


The usage is really simple.
<p> Create a main.cpp file and add the following </p>

```cpp
#include <iostream>
#include "eth_cal.h" /** Include the header file */

int main() {

      string month, month_conv;
      int year, day, year_conv, day_conv;


      cout<<"Enter the Gregorian Date that you want to print the Calender eg -> (Jun 15 2017) \n";
      cin>>month>>day>>year;

      tie(year_conv, month_conv, day_conv) = get_converted_date(year, month, day);
      
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
Gregorian to Ethiopian Calender Convertor library
Copyright (c) 2018 Bisrat Yalew (http://github.com/bisratyalew).

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```
