/* Sample main (this file is not a unit test!)

 * This file is for developing your own tests to make sure that your code is
    runnable for different use cases.

 * std::vector is included in the code below to show you how your types should
    behave. Feel free to use that for debugging purposes.


 * Make sure to test your vector with multiple types!!

 * In the main function (or multiple mains) you should write your own
    "unit tests" for each function; one suggestion may be one main per function.
    Multiple Main Methods: http://www.cplusplus.com/forum/beginner/46664/
*/

// USE THIS TO TEST, BUT REMOVE LATER TO VALIDATE YOUR OWN IMPLEMENTAION
#include <vector>

// Uncomment this to test with your own list implementation
#include "MyVector.h"

int main()
{
    // Uncomment this to test with your own list implementation
    MyVector<int> V;
    std::vector<int> v;

    cout << v.size() << endl;
    v.push_back(4000);
    cout << v.at(0) << endl;
    cout << v.capacity() << endl;
    v.reserve(10);
    cout << v.capacity() << endl;
    v.push_back(200);
    v.push_back(100);
    v.insert(v.begin(), 3);
    v.insert(v.end(), 20);

    // These below look like iterators, but are really just integers.
    // We are not making you re-implement iterators themselves.

    int j = 0;

    for(auto i = v.begin(); i < v.end(); i++)
    {
        cout << v.at(j) << endl;
        j++;
    }

    j = 0;

    for(auto i = 0; i < v.size(); i++)
    {
        cout << v[j] << endl;
        j++;
    }

    return 0;
}
