#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
using namespace std;

struct node
{
	// variables for employee's information
	string E_ID; 
	string E_Name;
	string Salary; 
	string Phone;
	string Address;
	string D_ID;
	string D_Name;
	string Performance;
	node *prev, *next, *data, *head; 
};

class Employee // employee class 
{
private:
	node *head;
	char choice;
	
public:
	Employee()
	{
		head = NULL;
	}

	void menu() //main menu 
	{
		cout << "\n\t\t\t\t ====================================";
		cout << "\n\t\t\t\t     Employee Management system";
		cout << "\n\t\t\t\t ====================================" << endl;
		cout << "\n\t\t\t\t Select an option : " << endl;
		cout << "\n\t\t\t\t 1- Add an employee record" << endl;
		cout << "\n\t\t\t\t 2- Display all records" << endl;
		cout << "\n\t\t\t\t 3- Search employee ID" << endl;
		cout << "\n\t\t\t\t 4- Search employee overall performance" << endl;
		cout << "\n\t\t\t\t 5- Sort and display by Employee ID in ascending order" << endl;
		cout << "\n\t\t\t\t 6- Sort and display by Employee Salary in ascending order" << endl;
		cout << "\n\t\t\t\t 7- Sort and display by Employee Overall Performance in ascending order" << endl;
		cout << "\n\t\t\t\t 8- Modify an Employee Record" << endl;
		cout << "\n\t\t\t\t 9- Delete an Employee Record" << endl;
		cout << "\n\t\t\t\t 10- Calculate salary package of an employee" << endl;
		cout << "\n\t\t\t\t 0- Exit" << endl;
		return;
	}

	void Add_Employee() //function to add employee
	{
		node *temp;
		temp = new node;
		cout << "\n\t Enter Employee ID : ";
		cin >> temp->E_ID;
		fflush(stdin);
		cout << "\n\t Enter the full name of employee : ";
		cin >> temp->E_Name;
		fflush(stdin);
		cout << "\n\t Enter the salary of employee : ";
		cin >> temp->Salary;
		fflush(stdin);
		cout << "\n\t Enter the phone number of employee : ";
		cin >> temp->Phone;
		fflush(stdin);
		cout << "\n\t Enter the address of employee : ";
		cin >> temp->Address;
		fflush(stdin);
		cout << "\n\t Enter the department ID : ";
		cin >> temp->D_ID;
		fflush(stdin);
		cout << "\n\t Enter the department name : ";
		cin >> temp->D_Name;
		fflush(stdin);
		cout << "\n\t Enter the performance of employee : ";
		cin >> temp->Performance;
		
		temp->next = head;
		temp->prev = NULL;
		if (head != NULL)
		{
			head->prev = temp;
		}
		head = temp;
		cout << "\t__________________________________________________" << endl;
		cout << "\n\t\t Record is added successfully" << endl;
	}

	void display() //function to display all employee records 
	{
			node*temp = head;
			cout << "===================================================================================================================" << endl;
			cout << std::setw(13) << "Employee ID | " << std::setw(14) << "Employee Name |" << std::setw(10) << "Salary |" << std::setw(13) << " Phone Number |" << std::setw(18) << "Home Address |" << std::setw(14) << "Department ID |" << std::setw(16) << "Department Name |" << std::setw(11) << "Performance" << endl;
			cout << "===================================================================================================================" << endl;
			while (temp != NULL)
			{
				
				cout << left << std::setw(14) << setfill(' ') << temp->E_ID;
				cout << left << std::setw(17) << setfill(' ') << temp->E_Name;
				cout << left << std::setw(9) << setfill(' ') << temp->Salary;
				cout << left << std::setw(14) << setfill(' ') << temp->Phone;
				cout << left << std::setw(22) << setfill(' ') << temp->Address;
				cout << left << std::setw(12) << setfill(' ') << temp->D_ID;
				cout << left << std::setw(19) << setfill(' ') << temp->D_Name;
				cout << left << std::setw(3) << setfill(' ') << temp->Performance;

				temp = temp->next;
				cout << endl;
			}
	}

	void search() //function to add search employee record 
	{
			string value;	
			cout << "\n\t\t Enter employee ID which you want to search :  ";
			cin >> value; //get value from user 
			node *temp = head;
			while (temp != NULL)
			{

				if (temp->E_ID == value)
				{
					cout << "\n\t Employee's information" << endl;
					cout << "\t  _______________________________________" << endl;
					cout << "\n\t ID              :" << "\t\t" << temp->E_ID << endl;
					cout << "\n\t Full Name       :" << "\t\t" << temp->E_Name << endl;
					cout << "\n\t Salary          :" << "\t\t" << temp->Salary << endl;
					cout << "\n\t Phone Number    :" << "\t\t" << temp->Phone << endl;
					cout << "\n\t Address         :" << "\t\t" << temp->Address << endl;
					cout << "\n\t Department ID   :" << "\t\t" << temp->D_ID << endl;
					cout << "\n\t Department Name :""\t\t" << temp->D_Name << endl;
					cout << "\n\t Performance     :" << "\t\t" << temp->Performance << endl;
					cout << "\t  _______________________________________" << endl;
					return; 
					temp = temp->next;
					
				} 
				else {
					cout << "\n\t\t Please enter a valid Employee ID. " << endl; 
					break;
				}
				

				
			}
		

	}

	void Performance_search() //function to search employees based on overall performance 
	{
			string value;
			cout << "\n\t\t Enter overall performance which you want to search:";
			cin >> value; // get value from user 
			node *temp = head;
			cout << "===================================================================================================================" << endl;
			cout << std::setw(13) << "Employee ID | " << std::setw(14) << "Employee Name |" << std::setw(10) << "Salary |" << std::setw(13) << " Phone Number |" << std::setw(18) << "Home Address |" << std::setw(14) << "Department ID |" << std::setw(16) << "Department Name |" << std::setw(11) << "Performance" << endl;
			cout << "===================================================================================================================" << endl;
			while (temp != NULL)
			{

				if (temp->Performance == value)
				{
					cout << left << std::setw(14) << setfill(' ') << temp->E_ID;
					cout << left << std::setw(17) << setfill(' ') << temp->E_Name;
					cout << left << std::setw(9) << setfill(' ') << temp->Salary;
					cout << left << std::setw(14) << setfill(' ') << temp->Phone;
					cout << left << std::setw(22) << setfill(' ') << temp->Address;
					cout << left << std::setw(12) << setfill(' ') << temp->D_ID;
					cout << left << std::setw(19) << setfill(' ') << temp->D_Name;
					cout << left << std::setw(3) << setfill(' ') << temp->Performance;

					temp = temp->next;
					cout << endl;
					break;
				}
				else
				{
					cout << "No employees has that overall performance" << endl;
					break;
				}
			}
		
	}

	void Sort_ID() // function to sort employee ID in ascending order 
	{
		node *temp = head;
		node *next;

		while (temp && temp->next)
		{
			node *next = temp->next;
			while (next)
			{
				if (temp->E_ID > next->E_ID)
				{
					std::swap(next->E_ID, temp->E_ID);
					std::swap(next->E_Name, temp->E_Name);
					std::swap(next->Salary, temp->Salary);
					std::swap(next->Phone, temp->Phone);
					std::swap(next->Address, temp->Address);
					std::swap(next->D_ID, temp->D_ID);
					std::swap(next->D_Name, temp->D_Name);
					std::swap(next->Performance, temp->Performance);
				}
				next = next->next;
			}
			temp = temp->next; 
		}
	}

	void display_ID() // function to display employee ID in ascending order 
	{
			node *temp = head; 
			Sort_ID();
			while (temp != NULL)
			{
				cout << "===================================================================================================================" << endl;
				cout << std::setw(13) << "Employee ID | " << std::setw(14) << "Employee Name |" << std::setw(10) << "Salary |" << std::setw(13) << " Phone Number |" << std::setw(18) << "Home Address |" << std::setw(14) << "Department ID |" << std::setw(16) << "Department Name |" << std::setw(11) << "Performance" << endl;
				cout << "===================================================================================================================" << endl;
				while (temp != NULL)
				{

					cout << left << std::setw(14) << setfill(' ') << temp->E_ID;
					cout << left << std::setw(17) << setfill(' ') << temp->E_Name;
					cout << left << std::setw(9) << setfill(' ') << temp->Salary;
					cout << left << std::setw(14) << setfill(' ') << temp->Phone;
					cout << left << std::setw(22) << setfill(' ') << temp->Address;
					cout << left << std::setw(12) << setfill(' ') << temp->D_ID;
					cout << left << std::setw(19) << setfill(' ') << temp->D_Name;
					cout << left << std::setw(3) << setfill(' ') << temp->Performance;

					temp = temp->next;
					cout << endl;
				}
			}
	}

	void Sort_Salary() // function to sort employee salary in ascending order 
	{
		node *temp = head;
		node *next;

		while (temp && temp->next)
		{
			node *next = temp->next;
			while (next)
			{
				if (temp->Salary > next->Salary)
				{
					std::swap(next->E_ID, temp->E_ID);
					std::swap(next->E_Name, temp->E_Name);
					std::swap(next->Salary, temp->Salary);
					std::swap(next->Phone, temp->Phone);
					std::swap(next->Address, temp->Address);
					std::swap(next->D_ID, temp->D_ID);
					std::swap(next->D_Name, temp->D_Name);
					std::swap(next->Performance, temp->Performance);
				}
				next = next->next;
			}
			temp = temp->next;
		}
	}

	void Display_Salary() // function to display employee's salary in ascending order 
	{
			node *temp = head;
			Sort_Salary();
			while (temp != NULL)
			{
				cout << "===================================================================================================================" << endl;
				cout << std::setw(13) << "Employee ID | " << std::setw(14) << "Employee Name |" << std::setw(10) << "Salary |" << std::setw(13) << " Phone Number |" << std::setw(18) << "Home Address |" << std::setw(14) << "Department ID |" << std::setw(16) << "Department Name |" << std::setw(11) << "Performance" << endl;
				cout << "===================================================================================================================" << endl;
				while (temp != NULL)
				{

					cout << left << std::setw(14) << setfill(' ') << temp->E_ID;
					cout << left << std::setw(17) << setfill(' ') << temp->E_Name;
					cout << left << std::setw(9) << setfill(' ') << temp->Salary;
					cout << left << std::setw(14) << setfill(' ') << temp->Phone;
					cout << left << std::setw(22) << setfill(' ') << temp->Address;
					cout << left << std::setw(12) << setfill(' ') << temp->D_ID;
					cout << left << std::setw(19) << setfill(' ') << temp->D_Name;
					cout << left << std::setw(3) << setfill(' ') << temp->Performance;

					temp = temp->next;
					cout << endl;
				}
			}
	}

	void Sort_Performance() // function to sort employee's performance in ascending order
	{
		node *temp = head;
		node *next;

		while (temp && temp->next)
		{
			node *next = temp->next;
			while (next)
			{
				if (temp->Performance > next->Performance)
				{
					std::swap(next->E_ID, temp->E_ID);
					std::swap(next->E_Name, temp->E_Name);
					std::swap(next->Salary, temp->Salary);
					std::swap(next->Phone, temp->Phone);
					std::swap(next->Address, temp->Address);
					std::swap(next->D_ID, temp->D_ID);
					std::swap(next->D_Name, temp->D_Name);
					std::swap(next->Performance, temp->Performance);
				}
				next = next->next;
			}
			temp = temp->next;
		}
	}

	void Display_Performance() // function to display employee's performance in ascending order 
	{
			node *temp = head;
			Sort_Performance();
			while (temp != NULL)
			{
				cout << "===================================================================================================================" << endl;
				cout << std::setw(13) << "Employee ID | " << std::setw(14) << "Employee Name |" << std::setw(10) << "Salary |" << std::setw(13) << " Phone Number |" << std::setw(18) << "Home Address |" << std::setw(14) << "Department ID |" << std::setw(16) << "Department Name |" << std::setw(11) << "Performance" << endl;
				cout << "===================================================================================================================" << endl;
				while (temp != NULL)
				{

					cout << left << std::setw(14) << setfill(' ') << temp->E_ID;
					cout << left << std::setw(17) << setfill(' ') << temp->E_Name;
					cout << left << std::setw(9) << setfill(' ') << temp->Salary;
					cout << left << std::setw(14) << setfill(' ') << temp->Phone;
					cout << left << std::setw(22) << setfill(' ') << temp->Address;
					cout << left << std::setw(12) << setfill(' ') << temp->D_ID;
					cout << left << std::setw(19) << setfill(' ') << temp->D_Name;
					cout << left << std::setw(3) << setfill(' ') << temp->Performance;

					temp = temp->next;
					cout << endl;
				}
			}
	}

	void del() //function to delete employee record 
	{
			string value;
			cout << "\n\t\t Enter the employee ID that u wish to delete : ";
			cin >> value;
			node*temp = head;
			bool flag = false;
			if (temp->E_ID == value)
			{
				head = temp->next;
				head->prev = NULL;
				flag = true;
				delete temp;
				if (flag == true)
				{
					cout << "\n\t\t Record has been deleted successfully" << endl;
				}
			}
			else
			{
				cout << "\n\t\t Record not found" << endl;
			}
	}

	void update() // function to modify employee record 
	{
			string value;
			cout << "\n\t\t Enter the employee ID that you wish to modify : ";
			cin >> value;
			node *temp = head;	
			while (temp != NULL)
			{
				if (temp->E_ID == value)
				{
					fflush(stdin);
					cout << "\n\t Enter Employee ID : ";
					cin >> temp->E_ID;
					fflush(stdin);
					cout << "\n\t Enter the full name of employee : ";
					cin >> temp->E_Name;
					fflush(stdin);
					cout << "\n\t Enter the salary of employee : ";
					cin >> temp->Salary;
					fflush(stdin);
					cout << "\n\t Enter the phone numeber of employee : ";
					cin >> temp->Phone;
					fflush(stdin);
					cout << "\n\t Enter the address of employee : ";
					cin >> temp->Address;
					fflush(stdin);
					cout << "\n\t Enter the department ID of employee : ";
					cin >> temp->D_ID;
					fflush(stdin);
					cout << "\n\t Enter the department name of employee : ";
					cin >> temp->D_Name;
					fflush(stdin);
					cout << "\n\t Enter the performance of employee : ";
					cin >> temp->Performance;
					fflush(stdin);
					temp = temp->next;
					cout << "\n\t\t Record is modified successfully" << endl;
					break;
				}
				else
				{
					cout << "\n\t\t Please enter a valid employee ID" << endl;
					break;
				}
				
			}
			
	}

	void CalculateSalaryPackage() //function to calculate salary package based on employee's salary 
	{
			string value;
			cout << "\n\t\t Enter employee ID which you want to calculate salary package: ";
			cin >> value;
			fflush(stdin);
			node*temp = head;
			
			while (temp != NULL)
			{
				if (temp->E_ID == value)
				{
					double salary, total;
					salary = stod(temp->Salary);
					total = salary + (salary * 0.5);
					temp = temp->next;
					cout << "\n\t\t Salary package of employee is " << salary << " + " << salary * 0.5 << " = " << total << endl;
					break;
				}
				else
				{
					cout << "\n\t\t Please enter a valid employee ID. " << endl; 
					break;
					
				}
			}
		
	 }

	void Enter(void) {
		cout << "\n\t\t Press enter to go back ";
		cin.get();
		cin.get();
	}
};

	int main()
	{
		node *head;
		int option;
		Employee emp;

	Label1:
		

		emp.menu(); //display main menu 
		cout << "\n\t\t\t Please enter your choice : ";
		cin >> option; // option is based on user's choice 
		if (option == 1)
		{
			emp.Add_Employee(); // call add employee function
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 2)
		{
			emp.display(); // call display function 
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 3)
		{
			emp.search(); // call search function 
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 4)
		{
			emp.Performance_search(); // call search function based on overall performance 
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 5)
		{
			emp.display_ID(); // call display function based on employee ID in asecending order 
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 6)
		{
			emp.Display_Salary(); // call display function based on employee salary in asecending order 
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 7)
		{
			emp.Display_Performance(); // call display function based on employee overall performance in asecending order 
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 8)
		{
			emp.update(); // call update function
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 9)
		{
			emp.del(); // call delete function 
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 10)
		{
			emp.CalculateSalaryPackage(); // call calculte salary package function
			cout << "\n\t\t Go back to main menu?";
			emp.Enter();
			goto Label1; // go back to main menu
		}

		else if (option == 0)
		{
			exit(1); // exit system 
		}

		else
		{
			cout << "\t\t Please enter valid choice";
			goto Label1; // go back to main menu
		}

	}