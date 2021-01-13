#include <iostream>
using namespace std;
#include <iomanip>
#include <stdlib.H>
#include <conio.h>



int main(){
	
	int quantityTV,quantityVCR,quantityRemote,quantityCD,quantityTape;
	float priceTV,priceVCR,priceRemote,priceCD,priceTape,subTotal,tax,total;
	
	
	cout<<"How may TVs were sold? "<<setw(15)<<": ";
	cin>>quantityTV;
	cout<<"How may VCRs were sold? "<<setw(14)<<": ";
	cin>>quantityVCR;
	cout<<"How may Remotes were sold? "<<setw(11)<<": ";
	cin>>quantityRemote;
	cout<<"How may CDs were sold? "<<setw(15)<<": ";
	cin>>quantityCD;
	cout<<"How may Tape Recorders were sold? "<<setw(4)<<": ";
	cin>>quantityTape;
	
	priceTV = quantityTV * 400.00;
	priceVCR = quantityVCR * 220.00;
	priceRemote = quantityRemote * 35.20;
	priceCD = quantityCD * 300.00;
	priceTape = quantityTape * 150.00;
	
	subTotal = priceTV + priceVCR + priceRemote + priceCD + priceTape;
	tax = (subTotal * 8.25)/100;
	total = subTotal + tax;
	
	cout<<"QTY  "<<setw(20)<<"DESCRIPTION  "<<setw(20)<<"UNIT PRICE  "<<setw(20)<<"TOTAL PRICE  "<<endl;
	cout<<"\n";
	cout<<"---  "<<setw(20)<<"-----------  "<<setw(20)<<"----------  "<<setw(20)<<"-----------  "<<endl;
	cout<<quantityTV<<setw(20)<<"TV"<<setw(20)<<"400.00"<<setw(20)<<priceTV<<endl;
	cout<<quantityVCR<<setw(20)<<"VCR"<<setw(20)<<"220.00"<<setw(20)<<priceVCR<<endl;
	cout<<quantityRemote<<setw(20)<<"REMOTE CTRLR"<<setw(20)<<"35.20"<<setw(20)<<priceRemote<<endl;
	cout<<quantityCD<<setw(20)<<"CD PLAYER"<<setw(20)<<"300.00"<<setw(20)<<priceCD<<endl;
	cout<<quantityTape<<setw(20)<<"TAPE RECORDER"<<setw(20)<<"150.00"<<setw(20)<<priceTape<<endl;
	cout<<setw(64)<<"----------"<<endl;
	cout<<setw(40)<<"SUBTOTAL"<<setw(22)<<subTotal<<endl;
	cout<<setw(40)<<"TAX"<<setw(22)<<tax<<endl;
	cout<<setw(40)<<"TOTAL"<<setw(22)<<total<<endl;
		
	
	

}
