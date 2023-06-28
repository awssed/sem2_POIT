#include<iostream>
using namespace std;
 double fmax(int i, ...);
void main() {
	cout << double(4)<<endl;
	cout << fmax(5, 3, 2.1, 0.7, 3.0, 0.4)<<endl;
	cout << fmax(3, 1.6, 2.9, 0.1)<<endl;
	cout << fmax(4, 5, 4, 2.0, 7.0)<<endl;
}
    double fmax(int n, ...)
    {
        int* p = &n;
        double min = 0;
        if (*p == 2)
        {
            p++;
            double* pp = (double*)p;
            pp++;
            cout << *pp << endl;
            min = *pp;
            for (; *pp; pp++)
            {
                if (min > *pp && *pp != 0)
                {

                    min = *pp;
                }
            }

        }
        if (*p == 1)
        {
            p++;
            min = *p;
            for (; *p; p++)
            {
                cout << *p << endl;
                if (min > *p && *p != 0)
                {
                    min = *p;
                }
            }
        }
        return min;
    }
