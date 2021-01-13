#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string remainCRC(string ddend, string generator)
{
    int i,temp=0,lg=generator.length(),ld=ddend.length();

    while(lg <= ld)
    {
        i=0;
        for(int j=0; j<lg; j++)
        {
            temp=(ddend[i]^generator[j]);
            switch(temp)
            {
                case 1:
                    ddend[i] = '1'; break;
                case 0:
                    ddend[i] = '0'; break;
                default:
                    break;
            }
        i++;
        }
        while((lg<=ld) && (ddend[0]!='1'))
        {
            ddend = ddend.substr(1);
        }
    }
    return ddend;
}

int main()
{
    cout<<"CRC SIMULATION\n\n";
    string msg,gen,ddend,crc,errMSg,transMsg;
    cout<<setw(20)<<"Enter the message : ";
    cin>>ddend;
    cout<<setw(20)<<"Enter the Generator Function G(x) : ";
    cin>>gen;
    msg=ddend;
    int lg=gen.length(),ld=ddend.length();
    for(int i=0;i<lg-1;i++)
        ddend+="0";
    if((ld<lg) || (gen[0]!='1' && gen[lg-1]!='1'))
        return -1;
    crc = remainCRC(ddend,gen);
    cout<<"Transmitted Message : "<<transMsg<<"\n\n";
    cout<<"ERROR SIMULATION";
    int flipBits=0, i=0;
    errMSg=transMsg;
    cout<<"\nHow many bits you want to flip : ";
    cin>>flipBits;
    for(int x=0;x<flipBits;x++)
    {
        cout<<"Position of Bit to be flipped : ";
        cin>>x;
        errMSg[x-1] = (errMSg[x-1]=='1'? '0' : '1');
    }
    crc = remainCRC(errMSg, gen);
    for(int i=0;i<crc.length();i++)
        if(crc[i]=='1')
        {
            cout<<"Error During Transmission\nCRC : "<<crc;
            return 1;
        }
    cout<<"No Error \n";
    return 0;
}