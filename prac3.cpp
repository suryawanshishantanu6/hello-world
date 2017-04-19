#include<iostream>
#include<stdlib.h>
#include <string.h>

#define MAX 100
using namespace std;
class flights						//class for flights
{
	public:
	int n;
	float time[100][100];
	int fuel[100][100];
	char city[10][50];
	flights()
	{
		strcpy(city[0],"bhopal");
		strcpy(city[0],"mumbai");
		strcpy(city[0],"pune");
		strcpy(city[0],"nagpur");
		strcpy(city[0],"panjab");
		strcpy(city[0],"cheeni");				
	}
	
	void read_Flights();				//function for read of flights 	
	void display_Flights();
	void check_flights();				//function for display of flights
};
void flights::read_Flights()
{
	int i,j;
	char ch,Y,y;
	cout<<"BOOKING OF FLIGHTS\n";
	cout<<"enter the total number of cities\n";
	cin>>n;
	cout<<"enter the cities for departure flights\n";
	
		for(i=0;i<n;i++)
		{
		
				cin>>city[i];
		
		}
	cout<<"enter the cities for arrival flights\n";
		for(j=0;j<n;j++)
		{
		
				cin>>city[j];
		
		}
		cout<<"enter the time for flights for respective cities\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{		
				if(i==j)
				{
					time[i][j]=0;
					continue;
				}
				else			
				cin>>time[i][j];			
			}
		}	
		cout<<"enter the fuel consumption for flights for respective cities";
		for(i=0;i<n;i++)
		{
	
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					fuel[i][j]=0;
					continue;
				}
				else	
				cin>>fuel[i][j];
			}
		}
	}

void flights::display_Flights()
{
	int i,j;
	cout<<"DISPLAY OF FLIGHTS\n";
	cout<<"FROM\tTO\tTIME\tFUEL\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
				
			cout<<city[i]<<"\t"<<city[j]<<"\t"<<time[i][j]<<"\t"<<fuel[i][j]<<endl;
			
		}
	}
		
		//cout<<"\t";
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
			
				cout<<fuel[i][j];
			
			}
		}*/	
}

void flights::check_flights()
{
	 int newzealand,india,i;
	 char temp1[100],temp2[100];
	 cout<<"FROM:-\n";
	 cin>>temp1;
	 cout<<"TO:-\n";
	 cin>>temp2;
	 for(i=0;i<n;i++)
	 {
		 if(strcmp(temp1,city[i])==0)
		 {
		 	newzealand=i;
		 }		 
		 if(strcmp(temp2,city[i])==0)
		 {
		 	india=i;
		 }
		if(time[newzealand][india]!=0)
		{
			if(newzealand==1)
			{
				cout<<"there exists a flight between the entered cities\n";
			}
			else
			{
				cout<<"there doesn't exists a flight between the entered cities\n";
			}
		}
	}
}
int main()
{
	int ch;
	cout<<"1.user login\n";
	cout<<"2.admin login\n";
	cout<<"3.exit\n";
	cin>>ch;
	flights obj;
	switch(ch)
	{
	case 1:obj.read_Flights();
		obj.display_Flights();
		break;
	case 2:obj.check_flights();
		break;
	}
	return 0;
}
