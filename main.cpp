#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class start {

	protected:
		
			
		
		/***
	
		* OOP
		* try catch throw
		* if else
		* switch
		* pointer for class object defination
		* Dot operator for class object defination
		* 1D array
		* This pointer
		* Fstream(ifstream and ofstream)
		* system("pause") ****from <iostream> header to stop the control on the screen untill detects a key press
		* Sleep() ****from <windows.h> header to stop the control on the screen for limmited time
		
		*/

		//_____________________________General Data collection Members____________________________

			
			int choice;
			string className , path , eventTitle , Event;
			string DataHolder[10];
			char decisionHolder;

		//_____________________________General Data collection Members____________________________



	public:

	//___________________________________________________BANNER SECTION_______________________________________________________________
	start(){


			cout <<"------------------------------------------------------------------------------"<<endl;
			cout <<"------------------------------------------------------------------------------"<<endl;
			cout <<"<<<<<<<<<<<<<<<<<<<<<<<<<--SCHOOL MANAGEMENT SYSTEM-->>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
			cout <<"------------------------------------------------------------------------------"<<endl;
			cout <<"------------------------------------------------------------------------------"<<endl;
			cout <<"\n\t\t\t\t\t        ~By Tech Virus"<<endl<<endl;		
			
			
			
			ifstream displayEvent("Events/Event.txt");
			try
			{
				if(!displayEvent.is_open())
				{
					throw "  **NO EVENT FOR NOW\n";
				}//end of if(can't oepn file)
				else
				{
					string data;
					while(getline(displayEvent,data))
					{
						cout <<"  **" <<data;
					}//end of while
				}//end of else(file opened)
			}//end of try
			catch(const char * ch)
			{
				cout <<ch;
			}//end of catch
			
									
	}//end of constructor
	//__________________________________________________END BANNER SECTION____________________________________________________________




	//__________________________________________________MAIN DISPLAY PANEL____________________________________________________________
	int mainDisplayPanel(){
			cout <<endl<<endl;
			cout <<"Please make a choice from the following given options."<<endl<<endl;
			cout <<"1 For Students related operations"<<endl<<"2 For Teachers related operations"<<endl<<"3 For Event options"<<endl<<"4 to exit"<<endl<<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<"\n";
			return choice;
	}//end of mainDisplayPanel
	//_______________________________________________END OF MAIN DISPLAY PANEL___________________________________________________________



};//end of 'start' class






/*SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>STUDENT SECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS*/
class student : public start {
	public:

	//_______________________________________________STUDENT DISPLAY PANEL_______________________________________________________________

		int studentDisplayPanel(){
			cout<<"\n\n";
			cout <<"Choose one from the following options."<<endl<<endl;
			cout <<"1 To add a new student record"<<endl<<"2 To display student data"<<endl<<"3 To go back to Main Panel"<<endl<<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<endl;
			return choice;

		}//end of studentDisplayPanel

	//__________________________________________END OF STUDENT DISPLAY PANEL______________________________________________________________


	//_______________________________________________STUDENT FILE DISPLAY PANEL_______________________________________________________________

		int classDispalyPanel(){
			cout<<"\n\n";
			cout <<"Please select a class Nursery-5."<<endl<<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<endl;
			return choice;

		}//end of studentDisplayPanel

	//__________________________________________END OF STUDENT FILE DISPLAY PANEL ______________________________________________________________



	//_________________________________________________STUDENT GET DATA___________________________________________________________________________

	void getStudentData(){
	
		cout << "Enter your First Name  , Last Name , RegistrationID , Class , Address and PhoneNumber"<<endl<<endl;
		cout << "First Name : ";
		cin >> DataHolder[0];
		cout<< endl;
		cout<<"Last Name : ";
		cin >> DataHolder[1];
		cout << endl;
		cout << "Registration ID : ";
		cin >> DataHolder[2];
		cout << endl;
		cout << "Class : ";
		cin >> DataHolder[3];
		cout << endl;
		cout << "City : ";
		cin >> DataHolder[4];
	
	
	}//end of getData function
	


	//_________________________________________________END OF GET STUDENT DATA____________________________________________________________________


	//____________________________________________________SAVE STUDENT RECORDS____________________________________________________________________

	void saveStudentRecord(){
		try
		{
			string tempClass = DataHolder[3]; //temporary varibale to hold class(level)
			ofstream data;//out Stream variable;
			if(tempClass == "nursery" || tempClass == "Nursery")	
				{
					data.open("Student_Records/ClassNursery.txt" , ios::app);
				}//end of if nursery
				else if(tempClass == "prep" || tempClass == "Prep")
				{
					data.open("Student_Records/ClassPrep.txt" , ios::app);
				}//end of if prep 
				else if(tempClass == "one" || tempClass == "One"|| tempClass == "1")
				{
						data.open("Student_Records/ClassOne.txt" , ios::app);
				}//end of if
				else if(tempClass == "two" || tempClass == "Two"|| tempClass == "2")
				{
						data.open("Student_Records/ClassTwo.txt" , ios::app);
				}//end of if 
				else if(tempClass == "three" || tempClass == "Three"|| tempClass == "3")
				{
						data.open("Student_Records/ClassThree.txt" , ios::app);
				}//end of if three
				else if(tempClass == "four" ||  tempClass == "Four"|| tempClass == "4")
				{
						data.open("Student_Records/ClassFour.txt" , ios::app);
				}//end of if four
				else if(tempClass == "five" || tempClass == "Five"|| tempClass == "5")
				{
						data.open("Student_Records/ClassFive.txt" , ios::app);
				}//end of if five
				else
				{
					cout << "Our School is limited to 5th standard please enter the class value 1-5 ";
				}//end of else
		
			if(!data.is_open())
			{
				throw "Unable to write data into the the file ,  please try again ...\n";
				
			}//end of if (fileOpenSFailure)
			
				data << "Name = " + DataHolder[0] +" "+ DataHolder[1] << "\nRegistration Number = " + DataHolder[2];
				data << "\nClass = "+ DataHolder[3] << "\nCity = " + DataHolder[4];
				data <<"\n\n";
				cout << "\nRecord saved Successfully :)";
				data.close();
				Sleep(2000);
				system("cls");
				
		}
		catch(const char * ex)
		{
			cout<<"Error occured while connecting to the stream\n"<<ex;
			system("pause");
		}
		
	}//end of 'saveStudentRecord method'

	//___________________________________________________END OF SAVE STUDENT RECORDS______________________________________________________________




	//_______________________________________________________SET DATA PATH_______________________________________________________________________

	void setDataPath(string className){
		
		this -> className = className; 
		
		if(className == "classNursery" || className == "classPrep" || className == "classOne" || className == "classTwo" || className == "classThree" || className == "classFour" || className == "classFive")
		{
			path = "Student_Records/" + className + ".txt";
		}//end of if (fileName checking)
		else
		{
			cout << "Invalid class name entered"<<endl;
		}
		
	}//end of class displayStudentData
	
	//___________________________________________________END OF SET DATA PATH_____________________________________________________________________



	//___________________________________________________STUDENT DISPLAY DATA_____________________________________________________________________

	void displayStudentData(){

		string getLine;
		ifstream file(path.c_str() , ios::app);
		//file.open("Student_Records/Records.txt", ios::in | ios::app);
		
	
		try
		{
		
			if(!file.is_open() || file.bad())
			{
	
				throw "unable to open the file\n";
				
			}//end of if(To check if file is open)
			
			while(getline(file,getLine))
				{
					cout << getLine<<endl;
				}//end of while
				
		
			file.close();//closing the file from stream
		}//end of try
		
		catch(const char* ch)
		{
			
			cout << "unknown error occured while dealing with the file , please be patient and try again....."<<endl<<endl<<ch;	
		}//end of catch	
		
			 
	
	}//end of display data
	//________________________________________________END OF STUDENT DISPLAY DATA_________________________________________________________________

};//end of student class

/*SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END OFSTUDENT SECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS*/




//------------------------------------------------------------------------------------------------------------------------------------------------------------------------




/*TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>TEACHER SECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT*/




class teacher : public start{

		public:
	//_______________________________________________TEACHER DISPLAY PANEL_______________________________________________________________
		int teacherDisplayPanel(){
			cout<<"\n\n";
			cout <<"Choose one frome the following options."<<endl<<endl;
			cout <<"1 To add a new record record"<<endl<<"2 To display techer data"<<endl<<"3 To go back to Main Panel"<<endl<<endl;
			cout <<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<"\n";
			return choice;

		}//end of teacherDisplayPanel
	//__________________________________________END OF TEACHER DISPLAY PANEL______________________________________________________________

	//_________________________________________________TEACHER GET DATA___________________________________________________________________________
		void getTeacherData(){
			
			cout << "Enter your First Name , last Name , RegistrationID , Class , City , PhoneNumber , WorkExperience and Subject\n"<<endl;
			cout << "First Name : ";
			cin >>  DataHolder[0];
			cout << endl;
			cout << "Last Name : ";
			cin >> DataHolder[1];
			cout << endl;
			cout << "Registration ID : ";
			cin >> DataHolder[2];
			cout << endl;
			cout << "Class Assighned : ";
			cin >> DataHolder[3];
			cout << endl;
			cout << "City : ";
			cin >> DataHolder[4];
			cout << endl;
			cout << "Phone Number : ";
			cin >> DataHolder[5];
			cout << endl;
			cout << "Work Experience : ";
			cin.ignore();
			getline(cin , DataHolder[6]);
			cout << endl;
			cout << "Specializatoin Subject : ";
			getline(cin , DataHolder[7] );
			cout << endl;
			cout << "Blood Group : ";
			cin >> DataHolder[8];
			cout << endl;
			cout << "CNIC : ";
			cin >> DataHolder[9];
			cout <<endl;
		}//end of getTeacherData function
	//_________________________________________________END OF GET TEACHER DATA____________________________________________________________________


	//____________________________________________________SAVE TEACHER RECORDS____________________________________________________________________

	void saveTeacherRecord(){
		try
		{
			ofstream data("Teacher_Records/Records.txt" , ios::app);
			if(!data.is_open())
			{
				throw "Not able to write data into the file ,  please try again\n";
				
				
			}//end of if (fileOpenFailure)
			
				data << "Name = " + DataHolder[0] +" "+ DataHolder[1] << "\nRegistration Number = " + DataHolder[2];
				data << "\nClass = "+ DataHolder[3] << "\nCity = " + DataHolder[4];
				data << "\nPhone Number = " + DataHolder[5] << "\nWork Experience = " + DataHolder[6];
				data << "\nSubject = " + DataHolder[7] << "\nBlood Group = " + DataHolder[8];
				data << "\nCNIC = " + DataHolder[9];
				data <<"\n\n";
				cout << "Record saved Successfully :) ";
				data.close();
				Sleep(2000);
				system("cls");
				
		}
		catch(const char* ex)
		{
			cout << "Error occured while connceting the stream \n\n"<<ex;
			system("pause");
		}
		
	}//end of 'saveStudentRecord method'

	//___________________________________________________END OF SAVE TEACHER RECORDS______________________________________________________________



	//___________________________________________________TEACHER DISPALY DATA_____________________________________________________________________
		void displayTeacherData(){

			string data;
			ifstream file;
			
			
			file.open("Teacher_Records/Records.txt", ios::in | ios::app);
		
			try
			{
				if(!file.is_open())
				{
					
					throw "unable to open  the file !!!\n";
					
				}//end of if(To check if file is open)
			
				while(getline(file,data))
					{
						cout << data<<endl;
					}//end of while
					
					file.close();//closing the file from stream
			
				
			}//end of try
			
			catch (const char ch)
			{
				cout << "Unknown error occured while opening the file , please be patient and try again......."<<endl<<endl<<ch ;
			}
		}//end of displayTeacherData
	//________________________________________________END OF TEACHER DISPALY DATA_________________________________________________________________
};//end of 'teacher' class




/*TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END TEACHER SECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT*/


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>EVENT DECLARATION SECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/

class event : public start{
		
		public :


	//________________________________________________________________DISPLAY PANEL FOR EVENTS_______________________________________________________________
	
		int eventDisplayPanel()
		{
			cout<<"\n\n";
			cout <<"Choose one from the following options."<<endl<<endl;
			cout <<"1 To declare new event"<<endl<<"2 To delete event"<<endl<<"3 to go back to the Main Panel"<<endl<<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<endl;
			return choice;
		}//end of eventBanner	
	//______________________________________________________________END DISPLAY PANEL FOR EVENTS______________________________________________________________			
	
	
	
	//___________________________________________________________________GET EVENT DETAILS__________________________________________________________________
	
		void getEventDetails()
		{
			restart:
			cout << "Enter the title for event\n\n";
			cout << "Title : ";
			cin.clear();
			cin.ignore();
			getline(cin , eventTitle);
			
	
			if(eventTitle == "")
			{
				
				cout <<"Event title cannot be null";
				Sleep(1000);
				goto restart;
			}
			
				
		}//end of method
	//________________________________________________________________END GET EVENT DETAILS__________________________________________________________________		
	
	
	
	
	//__________________________________________________________________SAVE EVENT DETAILS__________________________________________________________________
		void saveEvent()
		{
			
			try
			{
			   ofstream eventData("Events/Event.txt" , ios::app);
				if(!eventData.is_open())
				{
					throw "Not able to write data into the file ,  please try again\n";
								
				}//end of if (fileOpenFailure)
							
			eventData << "Event Update : " + eventTitle<<endl;
			cout<<endl;
			cout << "Event updated Successfully :) ";
			eventData.close();
			Sleep(2000);
								
			}
			catch(const char* ex)
			{
				cout << "Error occured while connecting the stream \n\n"<<ex;
				system("pause");
			}
		}//end of saveEvent
	//___________________________________________________________________END SAVE EVENT DETAILS__________________________________________________________________
		




	//___________________________________________________________________DELETE EVENT__________________________________________________________________
		void deleteEvent()
		{
			
				int status;
				status = remove("Events/Event.txt");
				if(status == 0)
				{
				
				cout << "\nEvent deleted successfully";
				}
				else
				{
					cout <<"unable to delete file";
				}
		}//end of deleteEvent
		
	//___________________________________________________________________END DELETE EVENT__________________________________________________________________	
	
};//end of event class


/*EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END EVENT DECLARATION SECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/
int main()
{
	int choice001;
	event * Event = new event();
	start s;
    student * st = new student();
    restorationPoint://goto labal to jump on
    system("cls");
    teacher tr;
    choice001=s.mainDisplayPanel();

    if(choice001 == 1)
    {
        
         int choice002;
    	 choice002 = st -> studentDisplayPanel();
		 
	//______________________________conditional statment for student options__________________________
	if(choice002 == 1)
    	 {
    	 	system("cls");
    	 	st -> getStudentData();
    	 	st -> saveStudentRecord();
    	 	goto restorationPoint; //back to panel
		 }//end of inner if(dataEntry)
		 else if(choice002 == 2)
		 {
		 	
			string tempCName;
			cout << "Enter Class Name"<<endl<<endl;
			cout << "Class Name : ";
			cin  >> tempCName;		
			system("cls");
		 	st -> setDataPath(tempCName);
		 	st -> displayStudentData();
		 	system("pause");
		 	goto restorationPoint; //back to panel
		 	
		 }//end of if(displayData)
		 else if(choice002 == 3)
		 {
		 	goto restorationPoint;
		 }//end of if(go back to mainDisplayPanel)

		 else
		 {
		 	cout <<"Invalide Option selected";
		 	
		 }//end of else(exceptional case)


	}//end of if(student)
	
	//_____________________________end conditional statment for student options________________________



//_____________________________conditional statment for teacher options________________________
	else if(choice001 == 2)
	{	
		
		int choice003;
		choice003 = tr.teacherDisplayPanel();
		
		if(choice003 == 1)
		{
			system("cls");
			tr.getTeacherData();
			tr.saveTeacherRecord();
			goto restorationPoint; //back to panel
		}//end of if (to Get Teacher's Data)
		
		else if(choice003 == 2)
		{
			system("cls");
			tr.displayTeacherData();
			system("pause");
			goto restorationPoint; //back to panel
		}//end of if (to Display Teacher's Data)
		
		else if(choice003 == 3)
		{
			goto restorationPoint;
		}//end of if (to back to Main Display Panel)
		
	}//end of if(teacher)
//_____________________________end conditional statment for techer options________________________



//_____________________________conditional statment for event options________________________
	else if(choice001 == 3)
	{

		int choice004 =  Event -> eventDisplayPanel();
		if(choice004 == 1)
		{
			Event -> getEventDetails();
			Event -> saveEvent();
			goto restorationPoint;	   //back to panel
		}//end of if(event declaration)
		
		else if( choice004 == 2)
		{
			char decisionCharacter;
			cout << "Are you sure you want delete this event ? press Y to continue and  N to cancel"<<endl<<endl;
			cout << "choice : ";
			cin >> decisionCharacter;
			switch(decisionCharacter)
			{
				case 'Y':
				case 'y':
					Event -> deleteEvent();
					Sleep(2000);
					goto restorationPoint;
					break;
					
				case 'N':
				case 'n':
					goto restorationPoint;
					break;		
			}//end of switch	
		}//end of if(delete event)
		
		else if(choice004 == 3)
		{
			goto restorationPoint;	
		}//end of of if(back to main panel)
		else
		{
			cout <<"Invalid Option selected";
		}//end of else

//_____________________________end conditional statment for event options________________________
	}//end of if



	else if(choice001== 4)
	{
		exit(0);
	}//end of if(exit)
	
	
	else
	{
		cout <<"Invalide Option selected\n";
		Sleep(2000);
		system("cls");
		goto restorationPoint;
		
	}//end of else(exceptional cases)

    return 0;
}
