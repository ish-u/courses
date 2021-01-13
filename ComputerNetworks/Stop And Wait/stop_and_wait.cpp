#include <iostream>
#include <string>
using namespace std;
#include "protocol.h"

Packet *packet;
int Error = 0; //Error Flag

class StopAndWait
{
    public:
        string s;
        int length;
        int cursor;
        string r;
        StopAndWait(string s)
        {
            this->s = s;
            length = s.length();
            cursor = 0;
            r = "";
        }
        void sender();
        void reciever();
};

void StopAndWait :: sender()
{
    cout<<"SENDER\n";
    if(length <= 0)
    {
        to_physical_layer(reciever_frame);
        event = DONE;
        cout<<"\n";
        reciever();
        return;
    }
    while(length > 0)
    {
        if(event == frame_arrival)
        {
            if(sender_frame->seq == reciever_frame->ack)
            {
                to_physical_layer(reciever_frame);
                packet = new Packet();
                //creating the packet
                for(int i = 0; i < MAX_PKT; i++, cursor++)
                {
                    packet->d += s[cursor]; 
                }
                from_network_layer(packet);
                to_physical_layer(sender_frame);
                cout<<"\n";
            }
            else
            {
                cout<<"ACK Error\nResending....\n\n";
                Error = 0;
            }
        }
        else if(event == ESTB_CONN)
        {
            cout<<"Establishing Connection\n\n";
        }
        reciever();
    }

}

void StopAndWait :: reciever()
{
    cout<<"RECIEVER\n";
    if(event == frame_arrival)
    {
        if(!Error)
        {
            if(sender_frame->seq == reciever_sequence)
            {
                from_physical_layer(sender_frame);
                to_network_layer(packet);
                length -= MAX_PKT;
                r += packet->d;
                cout<<"\n";
                if(reciever_sequence%2 == 0)
                {
                    Error = 1;
                }
            }
        }
        else
        {
            from_physical_layer(sender_frame);
            cout<<"Decapsulating Recieved Frame\n";
            cout<<"Sending ACK \n\n";
        }
        
        sender();
    }
    else if(event == ESTB_CONN)
    {
        cout<<"Connection Estblished\n";
        event = frame_arrival;
        cout<<"\n";
        sender();
    }
    else if(event == DONE)
    {
        cout<<"Done\n";
        cout<<"\nDATA RECIEVED : "<<r; 
        return;
    }
}


int main()
{
    cout<<"     STOP AND WAIT PROTOCOL FOR NOISY CHANNEL\n";
    cout<<"(Every Frame with the Even Sequence Number has ACK Error)\n\n";
    cout<<"Enter the message to be sent : ";
    string s;
    getline(cin,s);
    StopAndWait *z = new StopAndWait(s);
    z->sender();
}