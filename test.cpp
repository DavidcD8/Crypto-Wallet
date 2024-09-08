#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
std::vector<std::string> tokenise(std::string csvLine, char separator)
{

    // string vector tokens ## stores tokens
    std::vector<std::string> tokens;

    // int start, end ## used to delineate the position of the tokens
    signed int start, end;
    std::string token;

    // start = csvLine.find_first_not_of(separator)
    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        // end = next 'separator' after start
        end = csvLine.find_first_of(separator, start);

        // ## nothing more to find
        if (start == std::string::npos || start == end)
            break;

        // ## we found the separator
        if (end >= 0)
            token = csvLine.substr(start, end - start);
        else
            token = csvLine.substr(start, csvLine.length() - start);

        // tokens.push_back(token) ## save the token
        tokens.push_back(token);

        // start = end + 1 ## move past this token
        start = end + 1;

        // while (end > 0) ## continue loop condition
    } while (end > 0);

    return tokens;
}

 
 
int sum(int num1, int num2){
   return num1 + num2;
}

int main(){



 
 
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    sort(arr, arr);

    cout << "\nArray after sorting using "
            "default sort is : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}


 