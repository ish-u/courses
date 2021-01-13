#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;



int main(void)
{
	int n;
	cout<<"Enter The Number Of Rows you want>>> ";
	cin>>n;
	int space = n;
	n = n * 2;


	for (int i = 1,a = 1; i <= n; i = i + 2 ,a++)
	{
	    for (int k = 0; k < space -a;k++)
        {
            cout<<" ";
        }
		for (int  j = 1; j <=i; j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}
