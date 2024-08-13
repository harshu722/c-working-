#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
     
    cout << "Printing deque in forward direction: \n";
    deque<int>::const_iterator it;
    for(it = dq.begin(); it != dq.end(); ++it)
    {
        cout << *it << " ";
    }
     
    cout << "\n";
     
    cout << "Printing deque in reverse direction: \n";
    deque<int>::const_reverse_iterator rit;
    for(rit = dq.rbegin(); rit != dq.rend(); ++rit)
    {
        cout << *rit << " ";
    }
     
    return 0;
}

