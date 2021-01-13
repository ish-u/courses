#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    //VARIABLE THAT WILL STORE NUMBER OF TERMS IN SERIES
    int n;

    //IF THE USER DOESN'T PROVIDE A COMMAND LINE ARG ,
    //WE WILL PROMPT HIM TO ENTER THE VALUE OF n
    if (argc < 2)
    {
        cout<<"Enter the number of terms in the series:\t\n";
        cin>>n;
    }
    else
    {
        n = atoi(argv[1]);
    }

    //VAR TO HOLD SUM
    float sum = 0;

    //LOOP TO CALCULATE THE SUM OF n DIGITS IN SERIES
    for (int i = 1; i <= n; i++)
    {
        if (i%2 == 1)
        {
            sum += (float)1/(i*i); //TYPE CONVERSION TO float
        }
        else if (i%2 == 0)
        {
            sum -= (float)1/(i*i);
        }
    }

    cout<<"\t The sum of the given series \n";
    cout<<"\t\t1 - 1 / (2 ^ 2) + 1 / (3 ^ 3) - ... 1 / (n ^ n)"<<"is: "<<sum;
    return 0;
}
