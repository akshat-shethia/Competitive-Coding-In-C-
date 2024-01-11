#include <iostream>
using namespace std;

int getIthBit(int n, int i)
{
    int andNumber = (1 << i);
    return (n & andNumber) == 0 ? 0 : 1;
}

int clearIthBit(int n, int i)
{
    int andNumber = ~(1 << i);
    return (n & andNumber);
}

int setIthBit(int n, int i)
{
    int andNumber = (1 << i);
    return (n | andNumber);
}

int updateIthBit(int n, int i)
{
    clearIthBit(n, i);
    int andNumber = (1 << i);
    return (n | andNumber);
}

int main()
{
    int n;
    cin >> n;
    int i;
    cin >> i;

    // Print the original number
    cout << "Original Number: " << n << endl;

    // Print the ith bit value
    // cout << "Value of ith bit: " << getIthBit(n, i) << endl;

    // Clear the ith bit and print the entire number
    int result = clearIthBit(n, i);
    cout << "Number after clearing ith bit: " << result << endl;
}
