#define MAX_PKT 1
#define MAX_SQ_BITS 3
#define MAX_WINDOW_SIZE 5 //the data frames start from 1
typedef unsigned int seq_num;                               //sequence number or ack number
typedef enum {Data, ack, nak} frame_kind;                   //frame kind
typedef enum {frame_arrival,ESTB_CONN,DONE,RESEND} event_type;     //type of event

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
        Frame *copy(Frame *f)
        {
            Frame *temp = new Frame(f->kind,f->seq,f->ack);
            return temp;
        }
};

Frame *sender_frame = 0;
Frame *reciever_frame = new Frame(ack,0,0);

Frame *sending_window[7];
Frame *recieving_window[7];

//sequence number counter
int sender_sequence = 1;
int reciever_sequence = 1;

//event 
event_type event = ESTB_CONN;

void from_network_layer(Packet *p)
{
    cout<<"Encapsulating Packet in the Frame\n";
    sender_frame = new Frame(Data,0,0);
    sender_frame->kind = Data;
    sender_frame->p = *p;
    sender_frame->ack = 0;
    sender_frame->seq = sender_sequence++;
}

void to_physical_layer(Frame *f)
{
    if(f->kind == Data)
    {
        cout<<"Sending :"<<f->seq<<" "<<f->p.d<<"\n";
        if(event != RESEND)
        {
            sending_window[f->seq] = f->copy(f);
            sending_window[f->seq]->p = f->p;
        }
        else
        {
            sender_frame = f;
        }
            
    }
    else if(f->kind == ack)
    {
        cout<<"Recieved :"<<f->ack<<" ACK"<<"\n";
        if(f->ack != 0)
        {
            sending_window[f->ack]->ack = 1;            
        }
    }
}

void from_physical_layer(Frame *f)
{
    if(sender_sequence%2 == 0 || event == RESEND)
    {
        cout<<"Recieved : "<<f->seq<<" "<<f->p.d<<"\n";
    }
    recieving_window[f->seq] = f->copy(f);
    recieving_window[f->seq]->p = f->p;    
}

void to_network_layer(Packet *p)
{
    if(sender_sequence%2 == 0 || event == RESEND)
    {
        cout<<"Decapsulating Recieved Frame\n";
        cout<<"Sending ACK \n";
    }
    else
    {
        cout<<"PACKET LOST\n";
    }
    reciever_frame->kind = ack;
    reciever_frame->ack = sender_frame->seq;
    reciever_frame->seq = 0;
    reciever_sequence++;
}

