#include <iostream>
using namespace std;

int main()
{

    /*
    int num = 18;
    int *ptr = &num;
    *ptr = 9;
    cout << num << endl; // will change the num to 9
    */

    /*
    int num = 16;
    int *p = &num;
    int *q = p;
    (*q)++;
    cout << num << endl;
    // will increase the num by one
    */

    /*
    int first = 8;
    int second = 11;
    int *p = &second;
    first = *p;  // first will become 11
    *p = *p + 2; // second will increase by 2
    cout << first << endl
         << second << endl;
    */

    /*
    float f = 12.5;
    float g = 21.5;
    float *ptr = &f;
    (*ptr)++;            // f will increase by one
    *ptr = g;            // f will become equal to g
    cout << *ptr << endl // will print 21.5
         << f << endl    // will print 21.5
         << g << endl;   // will print 21.5
    */

    /*
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl; // will print 'b'
    */

    /*
    int first = 110;
    int *p = &first;
    int **q = &p;
    int second = ++(**q); // will initialize second by 111 and increase first by one
    int *r = *q;          // will initialize a pointer 'r' having the address stored at 'p', i.e. it will point towards to 'first'
    ++(*r);               // will increase first to 111+1
    cout << first << endl
         << second << endl;
    */
}