#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<cstdlib>

using namespace std;
class bookstore
{
	public:
		void control_panel();
		void add_book();
		void show_books();
		void check_book();
		void update_book();
		void del_book();
};

	void bookstore::control_panel()
	{
		system("cls");
		cout<<"\n\t\t*******************************************";
		cout<<"\n\t\t\tBookstore Management System";
		cout<<"\n\t\t*******************************************";
		cout<<"\n\n 1. Display Books";
		cout<<"\n 2. Add New Book";
		cout<<"\n 3. Check For Specific Book";
		cout<<"\n 4. Update Books";
		cout<<"\n 5. Delete Book";
		cout<<"\n 6. Exit";
	}

	void bookstore::add_book()
	{
		system("cls");
		fstream file;
		int no_copy;
		string b_name,a_name,b_id;
		cout<<"\n\n\t\t\t\t Add New Book";
		cout<<"\n\n Book ID : ";
		cin>>b_id;
		cout<<"\n\n\ Book Name : ";
		cin>>b_name;
		cout<<"\n\n Author Name : ";
		cin>>a_name;
		cout<<"\n\n\ No. of Copies : ";
		cin>>no_copy;
		file.open("C://Bookstore management.txt",ios::out|ios::app);
		file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
		file.close();
	}

	void bookstore::show_books()
	{
		system("cls");
		fstream file;
		int no_copy;
		string b_name,b_id,a_name;
		cout<<"\n\t\t\t*****************************";
		cout<<"\n\t\t\t\t Show All Books";
		cout<<"\n\t\t\t*****************************";
		file.open("C://Bookstore management.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n\t Book ID         Book       Author         No. of Copies\n\n";
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				cout<<"  \t  "<<b_id<<" \t\t "<<b_name<<"     "<<a_name<<"\t\t"<<no_copy<<"\n\n";
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
		}
	}

	void bookstore::check_book()
	{
		system("cls");
		fstream file;
		int no_copy,count=0;
		string b_id,b_name,a_name,b_idd;
		cout<<"\n\n\t\t\t*****************************";
		cout<<"\n\n\t\t\t\tCheck Specific Book";
		cout<<"\n\n\t\t\t*****************************";
		file.open("C://Bookstore management.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\t Check Specific Book";
					cout<<"\n\n Book ID : "<<b_id;
					cout<<"\n\n\t\t\tName : "<<b_name;
					cout<<"\n\n Author : "<<a_name;
					cout<<"\n\n\t\t\tNo. of Copies : "<<no_copy;
					count++;
					break;
				}
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
	}

	void bookstore::update_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,no_co,count=0;
		string b_name,b_na,a_name,a_na,b_idd,b_id;
		cout<<"\n\n\t\t\t*****************************";
		cout<<"\n\n\t\t\t\tUpdate Book Record";
		cout<<"\n\n\t\t\t*****************************";
		file1.open("C://Bookstore management1.txt",ios::app|ios::out);
		file.open("C://Bookstore management.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Book Record";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n\t\t\tAuthor Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("C://Bookstore management.txt");
		rename("C://Bookstore management1.txt","C://Bookstore management.txt");
	}

	void bookstore::del_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n\t\t\t*****************************";
		cout<<"\n\n\t\t\t\tDelete Book Record";
		cout<<"\n\n\t\t\t*****************************";
		file1.open("C://Bookstore management1.txt",ios::app|ios::out);
		file.open("C://Bookstore management.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("C://Bookstore management.txt");
		rename("D://book1.txt","D://book.txt");
	}


main()
{
	int choice;
	char x;
	bookstore b;
	p:
	b.control_panel();
	cout<<"\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			b.show_books();
			break;

		case 2:
			do
			{
			b.add_book();
			cout<<"\n\n Do You Want to Add another Book (Y,N) : ";
			cin>>x;
		    }while(x == 'Y');
			break;

		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;
		case 5:
			b.del_book();
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\n \aInvalid Value...Please Try Again...";
	}
	getch();
	goto p;
}
