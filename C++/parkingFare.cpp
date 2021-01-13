#include <iostream>
using namespace std;
#include <iomanip>
#include <stdlib.H>
#include <conio.h>



int main(){
	
	int entryHours,exitHours,entryMinutes,exitMinutes,hour,minute,totalTime,initialTime;
	float price,rate1,rate2;
	char ch,more;  //tells the type of vehicle person select
	
	do{
	
	
	system("cls");
	cout<<"Type Of Vechile"<<"\n"<<"C - Car"<<"\n"<<"B - Bus"<<"\n"<<"T - Truck"<<endl;
	cin>>ch;
	
	cout<<"Hour Vechile Entered the Lot  "<<setw(10)<<":";
	cin>>entryHours;
	cout<<"Minute Vehicle Entered The Lot   "<<setw(7)<<":";
	cin>>entryMinutes;
	cout<<"Hour Vehicle Left the Lot  "<<setw(13)<<":";
	cin>>exitHours;
	cout<<"Minute Vehicle Left the Lot  "<<setw(11)<<":";
	cin>>exitMinutes;
	
	if(exitHours < entryHours || exitHours == 0 ){
		cout<<"The Vehicle is Towed !!!";
	}else{
	
	
	cout<<"\nPARKING LOT CHARGE"<<"\n";
	cout<<"Type of Vehicle: "<<setw(10)<<" ";
	
	if(exitMinutes < entryMinutes){
		exitMinutes = exitMinutes + 60;
		exitHours = exitHours - 1;
	}else if(exitMinutes == entryMinutes){
		//cout<<"lol";
	}
	
	
	hour = exitHours - entryHours;
	minute = exitMinutes - entryMinutes;
	
	totalTime = hour;
	
	if(minute > 30){
		totalTime += 1;
	}else if(minute == 0){
		//totalTime -= 1;
	}else{
		totalTime -= 1;

	}
	
	switch(ch){
		
		case 'c':
		case 'C':
			cout<<"Car"<<endl;
			rate1 = 0;
			rate2 = 1.5;
			initialTime = 3;
			break;
		case 'b':
		case 'B':
			cout<<"Bus"<<endl;
			rate1 = 2;
			rate2 = 3.70;
			initialTime = 1;
			break;
		case 't':
		case 'T':
			cout<<"Truck"<<endl;
			rate1 = 1;
			rate2 = 2.30;
			initialTime = 2;
			break;
			
			}
		
	if(totalTime <= initialTime){
		price = rate1*totalTime;
	}
	else{
		price = (rate1*initialTime) + ((totalTime-initialTime)*rate2);
	}
	
	
	
	cout<<"TIME-IN"<<setw(11)<<" ";
    cout<<setw(2)<<setfill('0')<<entryHours<<':';
    cout<<setw(2)<<setfill('0')<<entryMinutes<<endl;
    
	cout<<"TIME-OUT"<<setfill(' ')<<setw(10)<<" ";
	cout<<setw(2)<<setfill('0')<<exitHours<<':';
    cout<<setw(2)<<setfill('0')<<exitMinutes<<endl;
    
    
    cout<<"PARKING-TIME"<<setfill(' ')<<setw(6)<<" ";
    cout<<setw(2)<<setfill('0')<<hour<<':';
    cout<<setw(2)<<setfill('0')<<minute<<':'<<endl;
    
    cout<<"ROUNDED TOTAL"<<setfill(' ')<<setw(7)<<totalTime<<endl;
    cout<<"TOTAL CHARGE"<<setw(10)<<"$"<<price;
    
    cout<<"\n\n TO RESET ENTER Y and TO EXIT ENTER N";
    cin>>more;
    
    
}

	
	}while(more == 'y' || more == 'Y');
}
