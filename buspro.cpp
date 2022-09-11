#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bus
{
	private:
		string b_no,b_name,d_name;
		int b_seat;
	public:
	void menu();
	void new_bus();
	void view_bus();
	void single_view_bus();
	void all_bus();
	void update_bus();
	void del_bus();
	void route_bus();
	void detail_bus();
	void booking();
	void renew_bus();
	void search_booking(); 
	void update_booking();
};
void bus::menu()
{
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t____________________Bus Management System__________________";
    cout<<"\n\n__________Main Menu__________";
    cout<<"\n\n 1.ADD BUS RECORD";
    cout<<"\n 2.VIEW BUSES DETAILS";
    cout<<"\n 3 UPDATE BUS DETAIL";
    cout<<"\n 4.DELETE BUS DETAIL";
    cout<<"\n 5.ROUTS OF BUSES";
    cout<<"\n 6.BUS SEATS DETAILS";
    cout<<"\n 7.BOOKING RECORD";
    cout<<"\n 8.SEATS RENEW";
    cout<<"\n 9.SEARCH BOOKING RECORD";
    cout<<"\n 10.UDATE BOOKING RECORD";
    cout<<"\n 11.DELETE BOOKING RECORD";
    cout<<"\n 12.SHOW ALL BOOKING RECORD";
    cout<<"\n 13.EXIT";
    cout<<"\n ENTER YOUR CHOICE\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        	new_bus();
        break;
        case 2:
        	view_bus();
        break;
        case 3:
        	update_bus();
        break;
        case 4:
        	del_bus();
        	
        break;
        case 5:
        	route_bus();
        break;
        case 6:
        	detail_bus();
        break;
        case 7:
        	booking();
        break;
        case 8:
        	renew_bus();
        break;
        case 9:
        	search_booking();
        break;
        case 10:
        	update_booking();
        break;
        case 11:
        break;
        case 12:
        break;
        case 13:
        	cout<<"\nthankyou";
        exit(0);
        default:
        cout<<"INVALID CHOICE...TRY AGAIN";
    }
    getch();
    goto p;

}
void bus::new_bus()
{
	p:
	system("cls");
	fstream file;
	string t_no,tb_name,td_name;
	int tb_seat,found=0;
	cout<<"\n\t\t____________________Bus Management System__________________";
	cout<<"\n\n BUS NO. : ";
	cin>>b_no;
	cout<<"\n\n BUS Name : ";
	cin>>b_name;
	cout<<"\n\n Total Seats : ";
	cin>>b_seat;
	cout<<"\n\n Driver Name : ";
	cin>>d_name;
	file.open("buss1.txt",ios::in);
	if(!file)
	{
		file.open("buss1.txt",ios::app|ios::out);
		file<<b_no<<" "<<b_name<<" "<<b_seat<<" "<<d_name<<"\n";
		file.close();
	}
	else
	{
		file>>t_no>>tb_name>>tb_seat>>td_name;
		while(!file.eof())
		{
			if(b_no == t_no)
			{
				found++;
			}
			file>>t_no>>tb_name>>tb_seat>>td_name;
		}
		file.close();
		if(found==0)
		{
			file.open("buss1.txt",ios::app|ios::out);
		    file<<b_no<<" "<<b_name<<" "<<b_seat<<" "<<d_name<<"\n";
		    file.close();
		}
		else
		{
			cout<<"\n\n BUS already exist....Try new BUS ";
			getch();
			goto p;
		}
	}
	cout<<"\n\n BUS added successfully";
}
void bus::view_bus()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\t\t____________________Bus Management System__________________";
	cout<<"\n\n 1.Single BUS view";
	cout<<"\n\n 2.All BUSES view";
	cout<<"\n\n 3.Go Back"; 
	cout<<"\n\n Enter your choice\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			single_view_bus();
		    break;
		case 2:
			all_bus();
	    	break;
	    case 3:
	    	menu();
	    default :
	    	cout<<"\n\n Invalid input";
	}
	getch();
	goto p;
}
void bus::single_view_bus()
{
	p:
	system("cls");
	string t_no;
	string b_no,b_name,d_name;
	int b_seat,found=0;
	fstream file;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("buss1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n file opening error";
	}
	else
	{
		cout<<"\n\n BUS no : ";
    	cin>>t_no;
		file>>b_no>>b_name>>b_seat>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				cout<<"BUS NO.\t\tBUS NAME\t\tNO. OF SEATS\t\tDRIVER NAME";
				cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seat<<"\t\t"<<d_name;
				found++;
			}
			file>>b_no>>b_name>>b_seat>>d_name;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n Invalid BUS no.";
			getch();
			goto p;
		}
		
	}
	
}
void bus::all_bus()
{
	system("cls");
	string t_no;
	string b_no,b_name,d_name;
	int b_seat,found=0;
	fstream file;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("buss1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n file opening error";
	}
	else
	{
		cout<<"\n\nBUS NO.\t\tBUS NAME\t\tNO. OF SEATS\t\tDRIVER NAME";
		file>>b_no>>b_name>>b_seat>>d_name;
		while(!file.eof())
		{
			cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t\t"<<b_seat<<"\t\t\t"<<d_name;
			found++;
			file>>b_no>>b_name>>b_seat>>d_name;	
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n No BUS Available";
		}
		
	}
}
void bus::update_bus()
{
	system("cls");
	fstream file,file1;
	string t_no,no,tb_name,td_name;
	int tb_seat,found=0;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("buss1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n file opening error";
	}
	else
	{
		cout<<"\n\n BUS No. : ";
		cin>>t_no;
		file1.open("bus11.txt",ios::app|ios::out);
		file>>b_no>>b_name>>b_seat>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				cout<<"\n\n New BUS no : ";
				cin>>no;
				cout<<"\n\n BUS name : ";
				cin>>tb_name;
				cout<<"\n\n No of seats : ";
				cin>>tb_seat;
				cout<<"\n\n Driver name : ";
				cin>>td_name;
				file1<<no<<" "<<tb_name<<" "<<tb_seat<<" "<<td_name<<"\n";
				cout<<"\n\n\n BUS updated successfully";
				found++;
			}
			else
			{
				file1<<b_no<<" "<<b_name<<" "<<b_seat<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seat>>d_name;
		}
		file.close();
		file1.close();
		remove("buss1.txt");
		rename("bus11.txt","buss1.txt");
		if(found==0)
		{
			cout<<"\n\n invalid BUS no.";
		}
	}
}
void bus::del_bus()
{
	system("cls");
	int found=0;
	string t_no;
	fstream file,file1;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("buss1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n file opening error";
	}
	else
	{
		cout<<"\n\n BUS No. : ";
		cin>>t_no;
		file1.open("bus11.txt",ios::out|ios::app);
		file>>b_no>>b_name>>b_seat>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				cout<<"\n\n\n BUS deleted successfully";
				found++;
			}
			else
			{
				file1<<b_no<<" "<<b_name<<' '<<b_seat<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seat>>d_name;
		}
		file.close();
		file1.close();
		remove("buss1.txt");
		rename("bus11.txt","buss1.txt");
		if(found==0)
		{
			cout<<"\n\n invalid BUS no.";
		}
	}
}
void bus::route_bus()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\t\t____________________Bus Management System__________________";
	cout<<"\n\n 1.1st route details : ";
	cout<<"\n 2.2nd route details ";
	cout<<"\n 3.3rd route details ";
	cout<<"\n 4.4th route details ";
	cout<<"\n 5.5th route details ";
	cout<<"\n\n Enter your choice ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			cout<<"\n\n 1st route details : ";
			cout<<"\n\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			break;
		case 2:
			system("cls");
			cout<<"\n\n 2nd route details : ";
			cout<<"\n\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			break;
		case 3:
			system("cls");
			cout<<"\n\n 3rd route details : ";
			cout<<"\n\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			break;
		case 4:
			system("cls");
			cout<<"\n\n 4th route details : ";
			cout<<"\n\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
		    break;
		case 5:
			system("cls");
			cout<<"\n\n5th route details : ";
			cout<<"\n\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			cout<<"\n from A to B";
			break;
		default :
		cout<<"\ninvalid choice ...try again";
		getch();
		goto p;
	}
}
void bus::detail_bus()
{
	system("cls");
	fstream file,file1;
	string t_no,s_no,s_b_no;
	int count=0,found=0;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file1.open("seats.txt",ios::app|ios::out);//for reserved seats
	file1<<"a"<<" "<<5<<"\n";
	file1<<"a"<<" "<<6<<"\n";
	file1<<"a"<<" "<<7<<"\n";
	file1.close();
	file.open("buss1.txt",ios::in);//for all seats
	file1.open("seats.txt",ios::in);
	if(!file||!file1)
	{
		cout<<"\n\n file opening error";
	}
	else
	{
		cout<<"\n\n BUS no : ";
		cin>>t_no;
		file1>>s_b_no>>s_no;
		while(!file1.eof())
		{
			if(s_b_no==t_no)
			{
				count++;
			}
			file1>>s_b_no>>s_no;
		}
		file1.close();
		file>>b_no>>b_name>>b_seat>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				system("cls");
				cout<<"\n\t\t____________________Bus Management System__________________";
				cout<<"\n\n Total no. of seats : "<<b_seat;
				cout<<"\n\n Reserved no. of seats : "<<count;
				cout<<"\n\n Available seats : "<<b_seat-count;
				found++;
			}
			file>>b_no>>b_name>>b_seat>>d_name;
		}
		file.close();
		if(found==0)
		cout<<"\n\n BUS no. is invalid";
	}
	
}
void bus::booking()
{
	p:
	system("cls");
	fstream file;
	string t_no,s_b_no,customer_name,from,to,phone;
	char x;
	int found=0,s_no,seats,count=0,s_s_no,ss_no[25],i=0,s_amount,total_amount=0,r_amount;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("buss1.txt",ios::in);
	if(!file)
	{
		cout<<"file opening error...";
	}
	else
	{
		cout<<"\n\n BUS no. : ";
		cin>>t_no;
		file.close();
		file.open("seats.txt",ios::in);
		if(file)
		{
	     	file>>s_b_no>>s_s_no;
	    	while(!file.eof())
	    	{
	    		if(t_no==s_b_no)
	    		{
	    			count++;
	    		}
		    	file>>s_b_no>>s_s_no;
	    	}
	    	file.close();
    	}
    	file.open("buss1.txt",ios::in);
	    file>>b_no>>b_name>>b_seat>>d_name;
		while(!file.eof())
		{
			if(t_no==b_no)
			{
				seats=b_seat;
				found++;
			}
			file>>b_no>>b_name>>b_seat>>d_name;
		}
		file.close();
		if(seats-count==0)
		{
			cout<<"\n\n All seats reserved.....";
		}
		else if(found==1)
		{
			do{
				h:
				cout<<"\n\n Enter seat no. : ";
				cin>>s_no;
				if(s_no>seats)
				{
					cout<<"\n\n Invalid Seat no.....please try again";
					getch();
					goto h;
				}
				file.open("seats.txt",ios::in);
				if(!file)
				{
					file.open("seats.txt",ios::app|ios::out);
					file<<t_no<<" "<<s_no<<"\n";
					file.close();
				}
				else
				{
					file>>s_b_no>>s_s_no;
					while(!file.eof())
			    	{
			    		if(t_no==s_b_no&&s_no==s_s_no)
			    		{
			    			cout<<"\n\n Seat already resereved...please try again ";
			    			file.close();
			    			goto h;
						}
			    		file>>s_b_no>>s_s_no;
			    	}
			    	file.close();
			    	file.open("seats.txt",ios::app|ios::out);
					file<<t_no<<" "<<s_no<<"\n";
					file.close();
				}
				ss_no[i]=s_no;
				i++;
				cout<<"\n\n Booking another seat ? : (Y,N)";
				cin>>x;	
			}while(x=='Y'||x=='y');
			system("cls");
			cout<<"\n\t\t____________________Bus Management System__________________";
			cout<<"\n\n customer name : ";
			cin>>customer_name;
			cout<<"\n\n Phone no : "; 
			cin>>phone;
			cout<<"\n\n From : ";
			cin>>from;
			cout<<"\n\n To : ";
			cin>>to;
			cout<<"\n\n Fare of 1 seat : ";
			cin>>s_amount;
			total_amount=i*s_amount;
			cout<<"\n\n Total amount : "<<total_amount;
			cout<<"\n\n Recievd Amount : ";
			cin>>r_amount;
			file.open("customer.txt",ios::app|ios::in);
			file<<customer_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";
			file.close();
			system("cls");
			cout<<"\n\t\t____________________Bus Management System__________________";
			cout<<"\n\n\t\t***********************************************************";
			cout<<"\n\t\t____________________BOOKINH INFORMATION__________________";
			cout<<"\n\n\t\t***********************************************************";
			cout<<"\n\n\t\tNAME :                  "<<customer_name;
			cout<<"\n\t\tFROM :                  "<<from;
			cout<<"\n\t\tTO :                    "<<to;
			cout<<"\n\t\tTotal seats :           "<<i;  
			cout<<"\n\t\tReserved seats          ";
			for(int a=0;a<i;a++)
			{
				if(a!=0)
				cout<<",";
				cout<<ss_no[a];	
			}     
			cout<<"\n\t\tFare of 1 seat          "<<s_amount;
			cout<<"\n\t\tTotal Amount            "<<total_amount;   
			cout<<"\n\t\tRecievd Amount          "<<r_amount;
			cout<<"\n\t\tReturned Amount         "<<r_amount-total_amount;    
			cout<<"\n\n\t\t***********************************************************";
			cout<<"\n\n\t\t*****************Thank You for BOOKING*********************";
			cout<<"\n\n\t\t***********************************************************";
		}
		
		else
		{
			cout<<"\n\n Invalid BUS no....."; 
			goto p;
		}
	}
}
void bus::renew_bus()
{
	system("cls");
	fstream file;
	char x;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("seats.txt",ios::in);
	if(!file)
	{
		cout<<"file opening error";
	}
	else
	{
		cout<<"\n\n Do you want to renew all seats (y,n) : ?"
		cin>>x;
		if(x=='y'||x=='Y')
		{
			remove("seats.txt");
			cout<<"\n\n\t\t\t All seats of all buses are empty";
		}
		else
		{
			cout<<"\n\n\t\t\t All seats reservation saved";
		}
	}
}
void bus::search_booking()
{
	system("cls");
	fstream file;
	string name,no,phone,t_name;
	int t_amount,t_seats,found=0;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("customer.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File opening error...";
	}
	else
	{
		cout>>"\n\n Customer name : ";
		cin>>t_name;
		file>>name>>no>>phone>>t_seats>>t_amount;
		whiile(!file.eof())
		{
			if(t_name==name)
			{
				if(found==0)
				{
					system("cls");
		        	cout<<"\n\t\t____________________Bus Management System__________________";
				}
				cout<<"\n\n\n Customer name : "<<name;
				cout<<"\n\n Bus no : "<<no;
				cout<<"\n\n Phone no : "<<phone;
				cout<<"\n\n Reserved Seats : "<<t_seats;
				cout<<"\n\n Total Amount : "<<t_amount;
				cout<<"\n\n =================================";
				found++;
			}
			file>>name>>no>>phone>>t_seats>>t_amount;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n Customer does not exist.....";
		}
	}
}
void bus::update_booking()
{
	system("cls");
	fstream file,file1;
	string name,no,phone,t_name,t_phone,del_no;
	int t_amount,t_seats,found=0,del_seats,i=0;
	cout<<"\n\t\t____________________Bus Management System__________________";
	file.open("customer.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File opening error...";
	}
	else
	{
		cout<<"\n\n Phoneno : ";
		cin>>t_phone;
		file>>name>>no>>phone>>t_seats>>t_amount;
		while(!file.eof())
		{
			if(phone==t_phone)
			{
				file.close();
				file.open("customer.txt",ios::in)
				file1.open("customer1.txt",ios::app|ios::out);
				file>>name>>no>>phone>>t_seats>>t_amount;
				while(!file.eof())
				{
					if(phone==t_phone)
					{
						del_no=no;
						del_seats=t_seats;
					}
					if(phone!=t_phone)
					{
						file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amount<<\n;
					}
					file>>name>>no>>phone>>t_seats>>t_amount;
				}
				file.close();
				file.close();
				remove("customer.txt");
				rename("customer1.txt","customer.txt");
				file.open("seats.txt",ios::in);
				file1.open("seats1.txt",ios::app|ios::out);
				file>>no>>t_seats;
				while(!file.eof())
				{
					if(del_no==no&&i<)
				}
				found++;
				goto h;
			}
			file>>name>>no>>phone>>t_seats>>t_amount;
		}
		file.close();
		h:
		if(found==0)
		{
			cout<<"\n\n invalid phone no...";
		}	
	}
}
main()
{
    bus b;
    string email,pass;
    p:
    system("cls");
    char ch;
    cout<<"\n\t\t____________________Bus Management System__________________";
    cout<<"\n\t\t*******User Verification******"; 
    cout<<"\n\nEmail : ";
    cin>>email;
    cout<<"\n\nPassword : ";
    for(int i=0;i<1
	;i++)
    {
        ch=getch();
        pass+=ch;
        cout<<"*";
    }
    getch();
    if(email == "s" && pass == "s")
    {
        cout<<"\n\n\n\t\t\tLoading";
        for(int i=1;i<=5;i++)
        {
            Sleep(500);
            cout<<".";
        }
        b.menu();
    }
    else
    {
        cout<<"\n\n Invalid credentials....";
        getch();
        goto p;
    }
}
