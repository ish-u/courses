#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string remainderCRC(string dividend, string generator)
{
    //Findiing the Remainder
    int i = 0;
    int temp = 0;
    while(generator.length() <= dividend.length())
    {
        i = 0;  
        for(int j = 0; j < generator.length();j++)
        {
            temp = (dividend[i] ^ generator[j]);
            switch(temp)
            {
            case 1:
                dividend[i] = '1';
                break;
            case 0:
                dividend[i] = '0';
                break;
            default:
                break;
            }
            i++;
        }
        while((generator.length() <= dividend.length()) && (dividend[0] != '1'))
        {
            dividend = dividend.substr(1);
        }
    }
    return dividend;
}

int main()
{
    cout<<"CRC SIMULATION\n\n";
    //taking input from the user
    string message,generator,dividend,crc,transmittedMessage,errorMessage;
    cout<<setw(20)<<"Enter the Message : "; cin>>dividend;
    cout<<setw(20)<<"Enter the Generator Function G(x) : "; cin>>generator;
    message = dividend;
    for(int i = 0; i < generator.length()-1; i++)
    {
        dividend += "0";
    }
    if((dividend.length() < generator.length()) || (generator[0] != '1' && generator[generator.length()-1] != '1'))
    {
        return -1;
    }
    //crc is the remainder.
    crc = remainderCRC(dividend,generator);
    transmittedMessage = message + crc;
    cout<<"Transmitted Message : "<<transmittedMessage<<"\n\n";
    //simulating Error Detetction
    cout<<"ERROR SIMULATION";
    int flipBits = 0;
    int index = 0;
    errorMessage = transmittedMessage;
    cout<<"\nHow many bits you want to flip : "; cin>>flipBits;
    for(int i = 0; i < flipBits; i++)
    {
        cout<<"Position of Bit to be flipped : ";  cin>>index;
        errorMessage[index-1] = (errorMessage[index-1] == '1') ? '0' : '1';
    }
    crc = remainderCRC(errorMessage,generator);
    for(int i = 0; i < crc.length(); i++)
    {
        if(crc[i] == '1')
        {
            cout<<"Error During Transmission\n"<<"CRC : "<<crc;
            return 1;
        }
    } 
    cout<<"No Error \n";
    return 0;
}