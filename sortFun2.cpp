#include <iostream>
using namespace std;
void sort(int &val1, int &val2, int &val3)
{
	int min = 0, mid = 0, max = 0;
	while ((max < val1) || (max < val2 ) || (max < val3))
	    max++;
	while ((mid =! min) && ((mid < val1) || (mid < val2 ) || (mid < val3)))
	    mid++;
	while ((max > mid) && ((max < val1) || (max < val2 ) || (max < val3)))
	    min++;
	val1 = min;
	val2 = mid;
	val3 = max;
}



int main()
{
	int a, b, c;
	cout << "Please input integer 1: ";
	cin >> a;
	cout << "\nPlease input integer 2: ";
	cin >> b;
	cout << "\nPlease input integer 3: ";
	cin >> c;
	sort(a, b, c);
	cout << "\nSorted: " << a << ", " << b << ", " << c;
	return 0;
}