#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;

//f() function
int f(int *a,int size,int n)
{
    int sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += (a[i]*pow(n,size-i-1));
    }
    return sum;

}
int main(void)
{
    cout<<setw(30)<<"| FUNCTION |\n\n";
    cout<<setfill('-')<<setw(50)<<"\n";
    //creating a array to store the constants of the polynomial
    int *polynomial;
    int highest_degree;
    int n;
    //getting the highest degree from user
    cout << "Enter the hightest degree of the polynimial : ";
    cin >> highest_degree;
    int size = highest_degree + 1;
    polynomial = new int[size];
    cout << "Polynomial : ";
    for (int i = 0; i < highest_degree; ++i)
    {
        cout << "a" << (highest_degree - i) << "x^" << (highest_degree - i) << " + ";
    }
    cout << "a0\n";
    cout<<setfill('-')<<setw(50)<<"\n";
    //getting constants from user
    cout << "Enter the constants : \n";
    for (int i = 0; i < size; ++i)
    {
        cout << "a" << (size - 1 - i) << " : ";
        cin >> polynomial[i];
    }
    //showing the function
    cout<<setfill('-')<<setw(50)<<"\n";
    cout<<"f(n) = ";
    for(int i = 0; i < size-1; ++i)
    {
        cout<<polynomial[i]<<"x^"<<(size-1-i)<<" + ";
    }
    cout<<polynomial[size-1]<<"\n";
    cout<<setfill('-')<<setw(50)<<"\n";
    cout<<"For what value of \'n\' you want to find f(n) : "; cin>>n;
    cout<<"f("<<n<<") = "<<f(polynomial,size,n);
    cout<<"\n"<<setfill('-')<<setw(50)<<" ";
    return 0;
}