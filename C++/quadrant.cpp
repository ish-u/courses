#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   	float angle;
	cout<<"Welcome To The QuardrantFinder :"<<endl;
	cout<<"Enter The Angle to find in which quadrant it belongs "<<setw(10)<<" :";
	cin>>angle;
	
	
	if(angle == 0.0 || angle == 360.00){
	    cout<<"It lies on +ve x-axis";
	    
	}else if(angle == 90.00){
	    cout<<"It lies on +ve y-axis";
    }else if(angle == 180.00){
        cout<<"It lies on -ve x-axis";
    }else if(angle == 270.00){
        cout<<"It lies on -ve y-axis";
    }else if(angle>0.00 && angle<90.00){
        cout<<"The Angle lies in 1st Quadrant";
    }else if(angle>90.00 && angle<180.00){
        cout<<"The Angle lies in 2nd Quadrant";
    }else if(angle>180.00 && angle<270.00){
        cout<<"The Angle lies in 3rd Quadrant";
    }else if(angle>270.00 && angle<360.00){
        cout<<"The Angle lies in 4th Quadrant";
    }else{
        cout<<"Please enter a valid angle (b/w 0-360 degree).\nThe program is not capable of range greater than (0.00-360.00)";
    }
}
