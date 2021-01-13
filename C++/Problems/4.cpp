#include <iostream>

using namespace std;

int main()
{


    int n;
	cout<<"Enter The number of rows you want :";
    cin>>n;

    int z = n + 3;
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < z; k++)
        {
            cout<<"&";
        }
        z = z - 2;
        cout<<endl;
        for(int j = 0; j <=i; j++)
        {
            cout<<" ";
        }


    }
}

