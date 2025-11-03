// Tourism Management Program
// Developed by: Sarah Alotaibi
// Course: CS221 - Fundamentals of Programming
// Imam Abdulrahman Bin Faisal University


#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void convert(float amountsar, int convertusd ,float convertsar);
int childcount(int children, int childCount);
int adultcount(int adults, int adultCount);
void displaych(int restaurant, int transport, int hotel);
void displayMenu(int &choice);
void DISPLAY(int);
int check(int);
void rateService(int rating) {
    if (rating < 1 || rating > 5) {
        cout << "Please enter a valid rating between 1 and 5." <<endl;
    } else {
        cout << "Thank you for rating the service with " << rating << " stars" <<endl;
        
    }
}

struct Userbooking{
    char firstName[20];
    char lastName[20];
    string email;
    int phone;
};
void writeFile(const Userbooking& userinfo);
void readfile(); 



void booking(Userbooking& userinfo){
	cout << "________________________________________"<<endl;
	cout << "please provide the following information "<<endl;
	cout << "________________________________________"<<endl;
    cout << "\nEnter your first name: "<<endl;
    cin >> userinfo.firstName;
    
    cout << "\nEnter your last name: "<<endl;
    cin >> userinfo.lastName;
    
    cout << "\nEnter your email: "<<endl;
    cin >> userinfo.email;
    
    cout << "\nEnter your phone number: "<<endl;
    cin >> userinfo.phone;

    writeFile(userinfo);
}


void writeFile(const Userbooking& userinfo) {
    ofstream outFile("user_booking.txt", ios::app);
    if (!outFile) {
        cerr << "Failed!" << endl;
        return;
    }

    outFile << userinfo.firstName << " " << userinfo.lastName << " "  << userinfo.email << " " << userinfo.phone << endl;

    outFile.close();
}

void readFile() {
    ifstream inFile("user_booking.txt");
    if (!inFile) {
        cerr << "Failed!" << endl;
        return;
    }

    int phone;
    char firstName[20], lastName[20];
    string email;

    cout << "User booking:" << endl;
    while (inFile >> firstName >> lastName >> email >> phone) {
        cout << ", Name: " << firstName << " " << lastName << ", Email: " << email << ", Phone: " << phone << endl;
    }

    inFile.close();
}


const char*A[10]={"park","water park","outlet","museum","beach","zip line","sky diving","sightseeing","theater","kite surfing"};

struct Spent {    
	
int restaurant;
int transport;
int hotel;
string activities;
};
void choice(Spent cho);

int main() {
  
  
Userbooking bookings[10];
string food,namef; 
int adultCount = 0, childCount = 0,days,tbud;
float totalCost = 0;
int choice;

double budget,chbudget, Count;
Spent cho;
char city[20];
int gfo, adultC = 0, adults=0 , children=0 , childC=0 ,c;
cout << "              ________________________________"<<endl;
cout << "              Tourism Planner - C++ Project."<<endl;
cout << "              ________________________________"<<endl;
do {
    displayMenu(choice);

switch (choice) {
case 1: {
	cout<<"choose your distination(city):"<<endl;
	cin>>city;
	break;
}
case 2: {

cout<<"Enter '1' if you are group of friends: "<<endl;
cout<<"Enter '2' if you are family:"<<endl;
cout<<"Enter '3' if you are one person:"<<endl;
cin>>gfo;

if(gfo==1)
{
cout << "Enter the number of adults: ";
cin >> adults;
}
else if(gfo==2)
{
cout << "Enter the number of adults ";
cin >> adults;
cout << "Enter the number of children (Ages 10-2): ";
cin >> children;
}
else if(gfo==3)
{
	adults=1;
}
else{

cout<<"wrong input";
break; 

}
break;
}

adultC=adultcount(adults, adultCount);
childC=childcount(children, childCount);

case 3: {
	if(gfo==1){
	cout<<"Enter your budget per person:"<<endl;
	cin>>budget;
}
	else if(gfo==2){
		cout<<"Enter your budget per person:"<<endl;
		cin>>budget;
		cout<<"Enter your budget per child:"<<endl;
		cin>>chbudget;
	}
	else if(gfo==3){
		cout<<"Enter your budget:"<<endl;
		cin>>budget;
	}
	break;
}
case 4:{
	cout<<"for how long are you traveling? enter the number of days please "<<endl;
	cin>>days;
	c=check(days);
	break;
}
case 5: {
   void choic(Spent cho);
	cho.restaurant = 0;
	cho.transport = 0;
	cho.hotel = 0;
	cho.activities;
	
	cout<<"Enter your choice of hotel:"<<endl;
	cout<<"Enter '5' for 5 star hotel."<<endl;
	cout<<"Enter '4' for 4 star hotel."<<endl;
	cout<<"Enter '3' for 3 star hotel."<<endl;
    cin>>cho.hotel;
	
	cout<<"Enter your choice of restaurant:"<<endl;
	cout<<"Enter 1 for italian food."<<endl
	<<"Enter 2 for arabic food."<<endl
	<<"Enter 3 for american food."<<endl
	<<"Enter 4 for indian food."<<endl
	<<"Enter 5 for chinese food."<<endl;
	cin>>cho.restaurant;
	
	cout<<"\nEnter your choice of transport:"<<endl;
	cout<<"Enter 1 for taxi."<<endl;
	cout<<"Enter 2 for rented car."<<endl;
	cout<<"Enter 3 for rented car with driver."<<endl;
	cout<<"Enter 4 for train."<<endl;
	cout<<"Enter 5 for bus."<<endl;
	cout<<"Enter 6 for walking."<<endl;
	cin>>cho.transport;
	
	displaych(cho.restaurant, cho.transport,cho.hotel);
	
break;
}
case 6: {

	if(cho.restaurant==1){
food="italian food";
namef="Da Vittorio Shanghai";
}

else if(cho.restaurant==2){
food="arabic food";
namef="Global bistro";
}

else if(cho.restaurant==3){
food="american food";
namef="chili's";
}

else if(cho.restaurant==4){
food="indian food";
namef="masala";
}

else if(cho.restaurant==5){
food="chinese food";
namef="bfc";
}
if(cho.transport==1)
tbud=(budget*0.20);

else if(cho.transport==2){
tbud=(budget*0.30);
}
else if(cho.transport==3)
tbud=(budget*0.40);

else if(cho.transport==4)
tbud=(budget*0.05);

else if(cho.transport==5)
tbud=(budget*0.10);

else if(cho.transport==6)
tbud=budget;

if(gfo==1)
{
	cout<<"the best airline is: alsaudia -> they have a packge for "<<adultcount(adults, adultCount)<<" passengers it will cost each person "<<(budget*0.20)<<"SR flighing to "<<city<<endl;
	budget=budget-(budget*0.20);
	cout<<"\nbased on your transportation choice it will cost you "<<(tbud/days)<<"SR each day."<<endl;
	budget=budget-tbud;
	cout<<"\nthe best hotel is: holiday inn "<<cho.hotel<<" stars and it will cost you "<<(budget/3)<<"SR for "<<days<<" days"<<endl;
	cout<<"\nthe best "<<food<<" restuarant is "<<namef<<" and it will cost you"<<(budget/3)<<"SR each day for "<<days<<" days"<<endl;
	budget=(budget/3);
	cout<<"\nthe best activites list for you as a group is: "<<endl;
	DISPLAY(days);

}
else if(gfo==2){
	cout<<"\nthe best airline is: fly nass-> they have a packge for "<<(adultcount(adults, adultCount)+childcount(children, childCount))<<" passengers it will cost each person "<<(budget*0.20)<<"SR flighing to "<<city<<endl;
	budget=budget-(budget*0.20);
	cout<<"\nbased on your transportation choice it will cost you "<<(tbud/days)<<"SR each day."<<endl;
	budget=budget-tbud;
	cout<<"\nthe best hotel is: holiday inn "<<cho.hotel<<" stars and it will cost you "<<(budget/3)<<"SR for "<<days<<" days"<<endl;
	cout<<"\nthe best "<<food<<" restuarant is "<<namef<<" and it will cost you"<<(budget/3)<<"SR each day for "<<days<<" days"<<endl;
	budget=(budget/3);
	cout<<"\nthe best activites for you as a group is: "<<endl;
	DISPLAY(days);

}
else if(gfo==3){
	cout<<"the best airline is: wizzo -> it will cost you "<<(budget*0.25)<<"SR flighing to "<<city<<endl;
	budget=budget-(budget*0.25);
	cout<<"\nbased on your transportation choice it will cost you "<<(tbud/days)<<"SR each day."<<endl;
	budget=budget-tbud;
	cout<<"\nthe best hotel is: holiday inn "<<cho.hotel<<" stars and it will cost you "<<(budget/3)<<"SR for "<<days<<" days"<<endl;
	cout<<"\nthe best "<<food<<" restuarant is "<<namef<<" and it will cost you"<<(budget/3)<<"SR each day for "<<days<<" days"<<endl;
	budget=(budget/3);
	cout<<"\nthe best activites for you is:"<<endl;
	DISPLAY(days);
}
break;
}

case 7:{
   	Userbooking userinfo ;
       booking(userinfo);
        cout<< "your trip has been confirmed and booked successfully, wish you a safe and enjoyable journey ! \n" ;
   int rating;
    cout << "\nPlease rate the service (from 1 to 5 stars): ";
    cin >> rating;
    rateService(rating);

    break;
}
case 8:{
   void convert(float amountsar,int convertusd,float convertsar);

	const float convertsar=3.75;
	float convertusd;
	cout<<"ente your amount in us dollars: ";
	cin>>convertusd;
	 float amountsar=convertusd*convertsar;
	cout<< "your amount in SAR:"<<amountsar;
	break;
}
case 0:
cout << "Thank you, Goodbye!" << endl;
break;
default:
cout << "Invalid choice. Please try again." << endl;
}
} while (choice != 0);

return 0;
}

int check(int days){
	if(days>10)
		cout<<"\n YOU CAN ONLY PLAN FOR 10 DAYS TRIP!"<<endl;
	

		return 0;
	
}

void DISPLAY(int days)
{
	if(days>0){	
	cout<<"<";
	for(int i=0;i<days;i++){
		cout<<A[i]<<"\t";
	}
	cout<<">";}
	else
	cout<<"enter duration of travel!"<<endl;
}


int adultcount(int adults, int adultCount){
	adultCount=adultCount+adults;
	return(adultCount);
}

int childcount(int children, int childCount){
	childCount=childCount+children;
	return(childCount);
}

void displayMenu(int &choice) {
    cout << "\n1.Choose your distination. \n"
    << "2. Number of passengers.\n"
    << "3. Enter your budget.\n"
    << "4. Duration of traveling\n"
    << "5. Choice of (hotel, restaurant, transport)\n"
    << "6. show the best(airline, hotel, restaurant, transportation, activities) based on your budget and choice\n"
    << "7. Booking\n "
    << "8. convert money from US to SAR\n"
    << "0. Exit.\n" ;
    cout << "              ________________________________"<<endl;
    cout <<"Enter your choice: " << endl; 
    cin >> choice;
}


void displaych(int restaurant, int transport, int hotel) {
cout<<"your choice of hotel is: "<<hotel<<" star hotel"<<endl;
cout<<"your choice of restaurant is: ";
if(restaurant==1)
cout<<"italian food"<<endl;

else if(restaurant==2)
cout<<"arabic food"<<endl;

else if(restaurant==3)
cout<<"american food"<<endl;

else if(restaurant==4)
cout<<"indian food"<<endl;

else if(restaurant==5)
cout<<"chinese food"<<endl;

cout<<"your choice of transport is: ";
if(transport==1){
cout<<"taxi"<<endl;
}
else if(transport==2){
cout<<"rented car"<<endl;
}
else if(transport==3){
cout<<"rented car with driver"<<endl;
}
else if(transport==4){
cout<<"train"<<endl;
}
else if(transport==5){
cout<<"bus"<<endl;
}
else if(transport==6){
cout<<"walking"<<endl;
}
}

void convert(float amountsar, int convertusd ,float convertsar)
{
	amountsar=convertusd*convertsar;
	 	cout<< "your amount in SAR:"<<amountsar;


}
void calculate(Spent cho){
	cout<<"Enter your choice of hotel:"<<endl;
   	cout<<"Enter your choice of restaurant:"<<endl;
  	cout<<"\nEnter your choice of transport:"<<endl;

	

}
