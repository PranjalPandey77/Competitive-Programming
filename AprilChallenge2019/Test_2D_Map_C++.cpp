#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map < int , map < int , bool > > m;

    m[1][3] =true;
	m[2][4]=true;
    cout << m[1][3] <<endl;
	cout << m[2][4] <<endl;
	cout << m[1][5] <<endl;
    return 0;
}
