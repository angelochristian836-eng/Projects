#include<iostream>

using namespace std;

string name[20], roll_number[20], course[20], class_name[20], contact[20]; 
// Arrays storing student details: name, roll, course, class, contact
int total = 0;
// Tracks total number of student records currently stored

void enter()
{
int number_of_students = 0;
cout<<"How many students do you want to enter??"<<endl;
cin>>number_of_students;
if(total==0)
{
total = number_of_students + total;
for(int i=0; i<number_of_students; i++)
{
cout<<"¥nEnter the Data of student "<<i+1<<endl<<endl;
cout<<"Enter name ";
cin>>name[i];
cout<<"Enter roll no ";
cin>>roll_number[i];
cout<<"Enter course ";
cin>>course[i];
cout<<"Enter class ";
cin>>class_name[i];
cout<<"Enter contact ";
cin>>contact[i];
}
}
else
{
for(int i=total; i<number_of_students+total; i++)
{
cout<<"¥nEnter the Data of Student"<<i+1<<endl<<endl;
cout<<"Enter name ";
cin>>name[i];
cout<<"Enter roll no ";
cin>>roll_number[i];
cout<<"Enter course ";
cin>>course[i];
cout<<"Enter class ";
cin>>class_name[i];
cout<<"Enter contact ";
cin>>contact[i];
}
total = number_of_students + total;
}
}

void show()
{
if(total==0)
{
cout<<"No data is entered"<<endl;
}
else
{
for(int i=0; i<total; i++)
{
cout<<"¥nData of Student "<<i+1<<endl<<endl;
cout<<"Name "<<name[i]<<endl;
cout<<"Roll no "<<roll_number[i]<<endl;
cout<<"Course "<<course[i]<<endl;
cout<<"Class "<<class_name[i]<<endl;
cout<<"Contact "<<contact[i]<<endl;
}
}
}

void search()
{
if(total==0)
{
cout<<"No data is entered"<<endl;
}
else
{
string number_roll;
cout<<"Enter the roll no of student"<<endl;
cin>>number_roll;
for(int i=0; i<total; i++)
{
if(number_roll==roll_number[i])
{
cout<<"Name "<<name[i]<<endl;
cout<<"Roll no "<<roll_number[i]<<endl;
cout<<"Course "<<course[i]<<endl;
cout<<"Class "<<class_name[i]<<endl;
cout<<"Contact "<<contact[i]<<endl;
}
}
}
}

void update()
{
if(total==0)
{
cout<<"No data is entered"<<endl;
}
else
{
string number_roll;
cout<<"Enter the roll no of students which you want to update"<<endl;
cin>>number_roll;
for(int i=0; i<total; i++)
{
if(number_roll==roll_number[i])
{
cout<<"¥nPrevious data"<<endl<<endl;
cout<<"Data of Student"<<i+1<<endl;
cout<<"Name "<<name[i]<<endl;
cout<<"Roll no "<<roll_number[i]<<endl;
cout<<"Course "<<course[i]<<endl;
cout<<"Class "<<class_name[i]<<endl;
cout<<"Contact "<<contact[i]<<endl;
cout<<"¥nEnter new data"<<endl<<endl;
cout<<"Enter name";
cin>>name[i];
cout<<"Enter Roll no";
cin>>roll_number[i];
cout<<"Enter course";
cin>>course[i];
cout<<"Enter class";
cin>>class_name[i];
cout<<"Enter contact";
cin>>contact[i];
}
}
}
}

void delete_record()
{
if(total==0)
{
cout<<"No data is entered"<<endl;
}
else
{
int a;
cout<<"Press 1 to delete all record"<<endl;
cout<<"Press 2 to delete specific record"<<endl;
cin>>a;
if(a==1)
{
total=0;
cout<<"All record is deleted..!!"<<endl;
}
else if(a==2)
{
string number_roll;
cout<<"Enter the roll no of student which you wanted to delete"<<endl;
cin>>number_roll;
for(int i=0; i<total; i++)
{
if(number_roll==roll_number[i])
{
for(int j=0; j<total; j++)
{
name[j] = name[j+1];
roll_number[j] = roll_number[j+1];
course[j] = course[j+1];
class_name[j] = class_name[j+1];
contact[j] = contact[j+1];
}
total--;
cout<<"Your required record is deleted"<<endl;
}
}
}
else
{
cout<<"Invalid input";
}
}
}

main()
{
int value;
while(true)
{
cout<<"¥nPress 1 to enter data"<<endl;
cout<<"Press 2 to show data"<<endl;
cout<<"Press 3 to search data"<<endl;
cout<<"Press 4 to update data"<<endl;
cout<<"Press 5 to delete data"<<endl;
cout<<"Press 6 to exit"<<endl;
cin>>value;
switch(value)
{
case 1:
enter();
break;
case 2:
show();
break:
case 3:
search();
break;
case 4:
update();
break;
case 5:
delete_record();
break;
case 6:
exit(0);
break;
default:
cout<<"Invalid input"<<endl;
break;
}
}
}