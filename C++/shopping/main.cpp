#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int numberOfItems;
	float  unitPrice, discountRate,tax,discount,total,subTotal,discountedTotal;

	cout<<left<<"Enter The Number Of Sold Items"<<setw(21)<<"";
	cin>>numberOfItems;
	cout<<left<<"Enter The Unit Price"<<setw(30)<<"";
	cin>>unitPrice;
	cout<<left<<"Enter The Discount %"<<setw(30)<<"";
	cin>>discountRate;

	subTotal = unitPrice*numberOfItems;
	discount = (discountRate/100)*subTotal;
	discountedTotal = subTotal - discount;
	tax = (8.5/100)*discountedTotal;
	total = discountedTotal + tax;

	cout<<'\n';
	cout<<'\n';
	cout<<"Quantity Sold"<<setw(10)<<setprecision(5)<<":  "<<numberOfItems<<endl;
	cout<<"Price Of Each Item"<<setw(5)<<setprecision(5)<<":  "<<unitPrice<<endl;
	cout<<setw(30)<<right<<"---------"<<endl;
	cout<<"Subtotal"<<setw(15)<<setprecision(5)<<":  "<<subTotal<<endl;
	cout<<"Discount"<<setw(15)<<setprecision(5)<<":  "<<"-"<<discount<<endl;
	cout<<setw(30)<<right<<"---------"<<endl;
	cout<<"Discounted Total"<<setw(7)<<setprecision(5)<<":  "<<discountedTotal<<endl;
	cout<<"Sales Tax"<<setw(14)<<setprecision(5)<<":  "<<"+"<<tax<<endl;
	cout<<setw(30)<<right<<"---------"<<endl;
	cout<<"Total Sale"<<setw(13)<<setprecision(5)<<":  "<<total;






	return 0;

}
