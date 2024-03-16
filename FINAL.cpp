#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;
struct gettingdata //TAKING INPUT FROM THE USER (STRUCTURE CALLED)
{	
	char serial, selection;
	double price;
	int quantity;
};

//GLOBAL VARIABLES 
int totala=0;
int totalm=0;
int totaldk=0;
int totalds=0;
int total=0; 

void menu() //MENU
{
cout<<"                          AAO KHAO RESTAURANT                            "<<endl;
cout<<"_________________________________________________________________________"<<endl;
cout<<"-----------------------------MENU SELECTION------------------------------"<<endl;
cout<<"---------------------------APPETIZERS/STARTERS---------------------------"<<endl;
cout<<"a) Plain Fries----------------------------------------Rs.200 (serves 1/2)"<<endl;
cout<<"b) Cheese Fries---------------------------------------Rs.250 (serves 1/2)"<<endl;
cout<<"c) Chicken Wings(6 pieces)------------------------------Rs.500 (serves 2)"<<endl;
cout<<"d) Chicken Corn Soup------------------------------------Rs.450 (serves 2)"<<endl;
cout<<"e) Hot and Sour Soup------------------------------------Rs.500 (serves 2)"<<endl;
cout<<"-------------------------------MAIN COURSE-------------------------------"<<endl;
cout<<"f) Chicken Steak---------------------------------------------------Rs.780"<<endl;
cout<<"g) Beef Steak------------------------------------------------------Rs.800"<<endl;
cout<<"h) Alfredo Pasta---------------------------------------------------Rs.650"<<endl;
cout<<"i) Chicken Lasagna-------------------------------------------------Rs.700"<<endl;
cout<<"j) Chicken Chowmein------------------------------------------------Rs.750"<<endl;
cout<<"k) Mixed Chowmein--------------------------------------------------Rs.800"<<endl;
cout<<"--------------------------------BEVERAGES--------------------------------"<<endl;
cout<<"l) Mixed fruit milkshake---------------------------------Rs.250(serves 1)"<<endl;
cout<<"m) Soda--------------------------------------------------Rs.200(serves 1)"<<endl;
cout<<"n) Water-------------------------------------------------Rs.50(serves 1) "<<endl;
cout<<"--------------------------------DESSERTS---------------------------------"<<endl;
cout<<"o) Moleten lava cake-------------------------------------Rs.350(serves 1)"<<endl;
cout<<"p) Ice cream---------------------------------------------Rs.250(serves 1)"<<endl;
cout<<"q) Eclairs-----------------------------------------------Rs.300(serves 1)"<<endl;
}
int discount(int total) //DISCOUNT FUNCTION TO BE CALLED IN MEMBERSHIP FUNCTION
{
	int DS=0 , newbill=0;
	DS=0.1*total; //10% discount
	newbill= total-DS;
	cout<<"\tDiscounted Bill= "<<newbill<<endl;
	return DS;
}
int membership(int total) //CHECKING WHETHER THE CUSTOMER IS A VALID MEMBER OR NOT
{
	char member;
	int msID [10]={329014,29284,59837,98387,39846,87389,12442,90358,21897,39055};
	int memberID; 
	cout<<"ARE YOU A MEMBER? (Y or N): "<<endl;
	cin>>member; 
	
	//filing 
	ofstream outfile;
	outfile.open("member.txt", ios::out); //open file
	outfile<<"HAFSA"<<endl; 
	outfile<<"AQSA"<<endl;
	outfile<<"MUNEEZA"<<endl;
	outfile<<"HIBA"<<endl;
	outfile<<"HARIS"<<endl;
	outfile<<"HAJRA"<<endl;
	outfile<<"UMER"<<endl;
	outfile<<"AHMED"<<endl;
	outfile<<"SAAD"<<endl;
	outfile<<"AYESHA"<<endl;
	outfile.close(); //close file 

	if (member=='Y' || member=='y') //customer inputs y 
	{
		cout<<"CUSTOMER IS A MEMBER!!!"<<endl;
		cout<<"ENTER MEMBERSHIP ID: "<<endl;
		cin>>memberID;
			
		for (int i=1; i<=10; i++)
		{
			if (msID[i]==memberID && member=='Y'|| member=='y' )  
			{
				cout<<"MEMBER FOUND!!!"<<endl;
				discount(total); //discount function called
				break;
			}
			else 
			{
				cout<<"MEMBER NOT FOUND!!!"<<endl;
			}
		}
    }
	else
	{
		cout<<"CUSTOMER NOT A MEMBER!!!"<<endl; //customer inputs n
	}
	return member;
}

int tax(int total) //TAX GENERATOR FUNCTION 
{
    int tax=0;
	tax = 0.13*total;
    return tax;
}
int luckydraw(int total, char member) //LUCKY DRAW FUNCTION
{
    char choice;
    int luckyno;
	
    if (total > 2500 && member== 'Y' || member == 'y')
    {
        cout<<"You are elligble for a lucky draw!"<<endl;
        cout<<"Would you like to participate??"<<endl; 
        cin>>choice; 

        if(choice == 'y' || choice == 'Y')
        {
			//the randomizer function has been added because in lucky draws not everyone gets the prize, it's on chance
			luckyno = rand() % 10 + 1;
			if(luckyno >= 2)
			{
				cout<<"You won cheeskcake for having a bill greater than 2500!"<<endl;
			}
			
        }
	}
	return 0;
}
int getdata() //TAKING INPUT FROM THE USER (FUNCTION CALLED)
{
	//GETTING DATA STRUCTURE CALLED 
	int total=0;
 	gettingdata gt1;
	//APPETIZERS
	cout <<"Do you want appetizers? (y/n): "<<endl; 
    cin>>gt1.selection;
    while(gt1.selection == 'y'|| gt1.selection == 'Y')
    {
    	cout<<"Enter the serial letter of the Appetizer : "<<endl;
    	cin>>gt1.serial;
		cout<<"Enter the quantity of the Appetizer : "<<endl;
    	cin>>gt1.quantity;

    switch(gt1.serial)
	{
    	case'a':
    	gt1.price = 200;
    	break;
    	case'b':
    	gt1.price = 250;
    	break;
    	case'c':
    	gt1.price = 500;
    	break;
    	case'd':
    	gt1.price = 450;
    	break;
    	case'e':
    	gt1.price = 500;
    	break;
	}
    totala = totala + (gt1.quantity*gt1.price); //total for appetizers 

	cout <<"Do you want MORE Appetizers? (y/n): "<<endl;
    cin>>gt1.selection;
	} 
	
	//MAIN COURSE
	cout <<"Do you want Main Course items? (y/n): "<<endl;
    cin>>gt1.selection;
	while(gt1.selection == 'y' || gt1.selection == 'Y')
    {
        cout<<"Enter the serial letter of the Main Course:"<<endl;
        cin>>gt1.serial;

        cout<<"Enter the quantity of the Main Course :"<<endl;
        cin>>gt1.quantity;

        switch(gt1.serial)
	   {
    		case 'f':
    		gt1.price = 780;
    		break;
    		case 'g':
    		gt1.price=800;
    		break;
    		case 'h':
    		gt1.price= 650;
    		break;
    		case 'i':
    		gt1.price= 700;
    		break;
    		case 'j':
    		gt1.price= 750;
    		break;
    		case 'k':
    		gt1.price=800;
    		break;
	   }
    totalm = totalm + (gt1.quantity*gt1.price); //total for the main course

    cout <<"Do you want MORE main course items? (y/n):"<<endl;
    cin>>gt1.selection;
	}
	
	//DRINKS
	cout <<"Do you want drinks? (y/n): "<<endl;
    cin>>gt1.selection;
	while(gt1.selection == 'y' || gt1.selection == 'Y')
    {
		cout<<"Enter the serial letter of the Drinks:"<<endl;
		cin>>gt1.serial;

		cout<<"Enter the quantity of the Drinks :"<<endl;
		cin>>gt1.quantity;

		switch(gt1.serial)
		{
			case 'l':
			gt1.price = 250;
			break;
			case 'm':
			gt1.price=200;
			break;
			case 'n':
			gt1.price= 50;
			break;
		}
		totaldk = totaldk + (gt1.quantity*gt1.price); //total for drinks

		cout <<"Do you want MORE Drinks? (y/n): "<<endl;
		cin>>gt1.selection;
	}

	//DESSERTS
	cout <<"Do you want desserts? (y/n): "<<endl;
    cin>>gt1.selection;
	while(gt1.selection == 'y' || gt1.selection == 'Y')
    {
        cout<<"Enter the serial letter of the Desserts:"<<endl;
        cin>>gt1.serial;

        cout<<"Enter the quantity of the Desserts :"<<endl;
        cin>>gt1.quantity;

    switch(gt1.serial)
	{
    	case 'o':
    	gt1.price = 350;
    	break;
    	case 'p':
    	gt1.price=250;
    	break;
    	case 'q':
    	gt1.price= 300;
    	break;
	}
    totalds = totalds + (gt1.quantity*gt1.price); //total for desserts

    cout <<"Do you want MORE Desserts? (y/n): "<<endl;
    cin>>gt1.selection;
	}  
     
    total = totala + totaldk + totalds + totalm;
    return total;
}
int main()
{
    int total;
	menu();
	total = getdata();
	char member = membership(total);
	
	//RECEIPT GENERATOR 
    int recipNO = 13874;
    //For the receipt to generate time
    time_t ttime = time(0);
    char *dt = ctime(&ttime); //POINTERS USED 
    cout<<"\t-----------------------------------------"<<endl;
    cout<<"                 AAO KHAO                  "<<endl;
    cout<<""<<"\t"<<dt<<endl;
    cout<<"\t ---------RECIEPT "<<recipNO<<" ----------"<<endl;   
    cout<<"\tTotal: "<<total<<endl; 
    if(member=='y' || member=='Y')
    {
    	cout<<"\tDiscount: "<<discount(total)<<endl;
	}      
    cout<<"\tTax: "<<tax(total)<<endl; 
    total = tax(total) + total;												
    cout<<"\tFINAL TOTAL: "<<total<<endl; 				           
    cout<<"\tThankyou for dining with us!"<<endl;
    cout<<"\tPlease come again"<<endl;
    cout<<"\t-----------------------------------------"<<endl;
    
	luckydraw(total, member);

return 0;
}
