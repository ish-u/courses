#define MAX_PKT 5
typedef unsigned int seq_num;                               //sequence number or ack number
typedef enum {Data, ack, nak} frame_kind;                   //frame kind
typedef enum {frame_arrival,ESTB_CONN,DONE} event_type;     //type of event

//packet class
class Packet{
    public:
        string d;
        Packet()
        {
            d = "";
        }
};

//frame class
class Frame{
    public:
        frame_kind kind;
        seq_num seq;
        seq_num ack;
        Packet p;
        Frame(frame_kind kind,seq_num seq, seq_num ack)
        {
            this->kind = kind;
            this->ack = ack;
            this->seq = seq;
        }
};

Frame *sender_frame = new Frame(Data,0,0);
Frame *reciever_frame = new Frame(ack,0,0);


//sequence number counter
int sender_sequence = 1;
int reciever_sequence = 1;

//event 
event_type event = ESTB_CONN;

void from_network_layer(Packet *p)
{
    cout<<"Encapsulating Packet in the Frame\n";
    sender_frame->kind = Data;
    sender_frame->p = *p;
    sender_frame->seq = sender_sequence++;
}

void to_physical_layer(Frame *f)
{
    if(f->kind == Data)
    {
        cout<<"Sending :"<<f->seq<<" "<<f->p.d<<"\n";
    }
    else if(f->kind == ack)
    {
        cout<<"Recieved :"<<f->ack<<" ACK"<<"\n";
    }
    
}

void from_physical_layer(Frame *f)
{
    if(sender_sequence != reciever_sequence)
    {
        cout<<"Recieved : "<<f->seq<<" "<<f->p.d<<"\n";
    }
    else
    {
        cout<<"Duplicate Frame Recieved\n";
    }
}

void to_network_layer(Packet *p)
{
    cout<<"Decapsulating Recieved Frame\n";
    cout<<"Sending ACK \n";
    reciever_frame->kind = ack;
    reciever_frame->ack = sender_frame->seq;
    reciever_frame->seq = 0;
    reciever_sequence++;
}

