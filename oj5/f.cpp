#include <iostream>
#include <astring>
using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int hour = stoi(a);
    int rate = stoi(b);

    if(hour < 0){
        hour = 10.0;
    }

    if(rate < 0){
        rate = 10.0;
    }

    double income = hour * rate;
    cout << income;

    return 0;
}
