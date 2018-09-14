#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    string a{"2141"};
    cout << *a.erase(a.begin()) << endl;
    string b{"xyz"};
    a.append(b);
    cout << a << endl;
    a.insert(a.begin(), string("some"));
    return 0;

}
