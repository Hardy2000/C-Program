
  #include<fstream.h>
  #include<conio.h>
  #include<stdio.h>
  #include<process.h>
  #include<dos.h>

  class employ
{ int empno;
  int dd,mm,yy;
  char name[30];
  char grade;
  char desig[20];
  char pno[10];
  int hno;
  char city[10];
  char state[10];
  float salary;
  public:
  void getdata();
  void showdata();
  int empn()
{ return empno;
}
  void getname()
{ cout<<"\nEnter new name:";
  gets(name);
}
  void getsal()
{ cout<<"Enter new Salary:\n";
  cin>>salary ;
}
  void getdate()
{ cout<<"\nEnter the new date of joining:\n";
  cin>>dd>>mm>>yy;
}
  void getdeg()
{ cout<<"\nEnter new Designation:\n";
  gets(desig);
}
  void getgd()
{ cout<<"\nEnter new grade:\n";
  cin>>grade;
}
  void gethn()
{ cout<<"\nEnter house new no:\n";
  cin>>hno;
}
  void getcity()
{ cout<<"Enter new city:\n";
  gets(city);
}
  void getpno()
{ cout<<"Enter new contact no:\n";
  gets(pno);
}
  void getst()
{ cout<<"Enter new state:\n";
  gets(state);
}
 }e;
  void welcome();
  void app();
  void showdata();
  void modify();
  void dlt();
  void employ::getdata()
{ clrscr();
  cout<<"Enter the details of the Employee.";
  gotoxy(1,4);
  cout<<"Enter the Employee Number:\n";
  cin>>empno;
  gotoxy(1,7);
  cout<<"Enter Name:\n";
  gets(name);
  gotoxy(1,10);
  cout<<"Enter designation:\n";
  gets(desig);
  gotoxy(1,13);
  cout<<"Enter grade:\n";
  cin>>grade;
  gotoxy(1,16);
  cout<<"Enter Salary:\n";
  cin>>salary;
  gotoxy(1,19);
  cout<<"\nEnter date of joining:(dd/mm/yy)\n";
  cin>>dd>>mm>>yy;
  gotoxy(1,22);
  cout<<"\nEnter contact no:\n";
  cin>>pno;
  clrscr();
  gotoxy(29,2);
  cout<<"Address.";
  gotoxy(1,4);
  cout<<"Enter house no:\n";
  cin>>hno;
  gotoxy(1,7);
  cout<<"Enter city:\n";
  gets(city);
  gotoxy(1,10);
  cout<<"Enter state:\n";
  gets(state);
}

  void employ::showdata()
{ textbackground(BLUE+BLACK);  textcolor(WHITE);
  clrscr();
  cout<<"\n=====================================DETAILS====================================\n";  gotoxy(2,3);
  cout<<"Employee Number: "<<empno;
  gotoxy(2,5);
  cout<<"Name: ";
  puts(name);
  gotoxy(42,5);
  cout<<"Designation: "  ;
  puts(desig);
  gotoxy(2,7);
  cout<<"Grade:"<<grade;
  gotoxy(42,7);
  cout<<"Salary: "<<salary;
  gotoxy(2,9);
  cout<<"Date:"<<dd<<mm<<yy;
  gotoxy(29,11);
  cout<<"ADDRESS";
  gotoxy(2,12);
  cout<<"Contact no:"<<pno;
  gotoxy(42,12);
  cout<<"House no:"<<hno;
  gotoxy(2,14);
  cout<<"City:";
  puts(city);
  gotoxy(42,14);
  cout<<"State:";
  puts(state);
}
  void welcome()
{
  clrscr();
  gotoxy(34,8);
  delay(1000); cout<<"W "; delay(150); cout<<"E "; delay(150); cout<<"L "; delay(150); cout<<"C ";
  delay(150); cout<<"O "; delay(150); cout<<"M "; delay(150); cout<<"E ";
  gotoxy(2,21);
  cout<<"Loading";
  for(int i=0;i<70;i++)
{ delay(60); cout<<".";}
 }

  void app()
{ clrscr() ;
  cout<<"=====================================APPEND====================================";
  p:
  e.getdata();
  ofstream file;
  file.open("employ.dat",ios::app,ios::binary);
  file.write((char *)& e,sizeof(e));
  file.close();
  cout<<"\nWant to enter more employee record !(y/n)\n";
  char ch;
  cin>>ch;
  if(ch=='y'||ch=='Y')
  goto p;
}

  void dlt()
{ clrscr();
  cout<<"\n=====================================DELETE====================================";
  cout<<"\nEnter employee no to be deleted\n";
  int t;
  cin>>t;
  fstream file,fin;
  file.open("employ.dat",ios::in|ios::out|ios::binary);
  fin.open("temp.dat",ios::out|ios::in|ios::binary);
  char found='n', confirm='n';
  while(file)
{ file.read((char*)& e,sizeof(e));
  if(file.eof())
  break;
  if(t==e.empn())
{ found='y';
  e.showdata();
  cout<<"\nDo you want to delete this record ?(y/n)\n";
  cin>>confirm;
  if(confirm=='n')
  fin.write((char*)& e,sizeof(e));
}
  else
  fin.write((char*)& e,sizeof(e));
}
  if(found=='n')
{ cout<<"Record not found!!!!!";
}
  file.close();
  fin.close();
  remove("employ.dat");
  rename("temp.dat","employ.dat");
  cout<<"\nRecord successfully manupulated.\n";
  getch();

}


  void modify()
{ cout<<"=====================================MODIFY====================================";
  cout<<"\nEnter the employee no whose record is to be modified\n";
  int t;
  cin>>t;
  fstream file,fin;
  file.open("employ.dat",ios::in|ios::out|ios::binary);
  fin.open("temp.dat",ios::out|ios::in|ios::binary);
  char found='n';
  int c;
  while(file)
{ file.read((char*)& e,sizeof(e));
  if(file.eof())
  break;
  if(t==e.empn())
{ found='y';
  e.showdata();
  l:
  cout<<"\n\n\nYou have 10 second to read the old record.";
  delay(15000);
  clrscr();
  cout<<"\nWhat do you want to Modify\n";
  cout<<"\n1.Name\n2.Grade\n3.Disignation\n4.Salary\n";
  cout<<"5.Date of joining\n6.House no\n7.Contact no\n8.City\n";
  cout<<"9.State\n";
  cin>>c;
  if(c==1)
  e.getname();
  else if(c==2)
  e.getgd();
  else if(c==3)
  e.getdeg();
  else if(c==4)
  e.getsal();
  else if(c==5)
  e.getdate();
  else if(c==6)
  e.gethn();
  else if(c==7)
  e.getpno();
  else if(c==8)
  e.getcity();
  else if(c==9)
  e.getst();
  else
{ cout<<"Wrong input.Try Again\n";
  goto l;
}
  fin.write((char*)& e,sizeof(e));
}
  fin.write((char*)& e,sizeof(e));
}
  if(found=='n')
{ cout<<"No such Record!!!!!!!";
}
  file.close();
  fin.close();
  remove("employ.dat");
  rename("temp.dat","employ.dat");
  cout<<"\nRecord succesfully modified\n";
  getch();
}
  void main()
{ welcome();
  p:
  clrscr();
  fstream file;
  cout<<"Enter your choice\n";
  cout<<"1.Create new file\n2.Display Record\n3.Append data\n4.Delete data\n5.Modify record\n6.Exit\n";
  char ch;
  char found='n';
  cin>>ch;
  switch(ch)
{
  case '1':{ e.getdata();
	   file.open("employ.dat",ios::out|ios::binary);
	   file.write((char *)&e,sizeof(e));
	   file.close();
	   }
	   break;
  case '2' : {  clrscr();
		file.open("employ.dat",ios::in|ios::binary);
		file.seekg(0);
		while(file)
		{file.read((char*)&e,sizeof(e));
		if(file.eof())
		break;
		e.showdata();
		getch();
		found='f';
		file.close();
		}
		if(found=='n')
		{clrscr();
		 cout<<"\nRecord not found!!!!!";
		 }}
		break;
  case '3' :       app();
		break;
  case '4' :    dlt();
		break;
  case '5' :    modify();
		break;
  case '6' :    clrscr();
		delay(500);
		gotoxy(29,12);
		cout<<"!!!!THANK YOU!!!!";
		getch();
		exit(0);
		break;
  default :     cout<<"No such Entry!!!!!";
}
   cout<<"\nDo you want to conitnue ?(y/n)\n";
   char ch1;
   cin>>ch1;
   if(ch1=='y'||ch1=='Y')
   goto p;
}