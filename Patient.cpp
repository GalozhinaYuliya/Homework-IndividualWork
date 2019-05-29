#define _CRT_SECURE_NO_WARNINGS

#include "Patient.h"
#include <string>
#include <iostream>

using namespace std;

Patient::Patient(char* sourname, char* name, char* patronymic, char* gender, char* national, int  height, int weight, char* birthday, int phoneNumber, char* adress, int numberOfHospital, char* department, int medicalCardNumber, char* diagnosis, int bloodGroup)
{
	this->SetHospital(sourname, name, patronymic, gender, national, height, weight, birthday, phoneNumber, adress, numberOfHospital, department, medicalCardNumber, diagnosis, bloodGroup);
}

void Patient::SetSourname(char * sourname)
{
	strcpy(this->sourname, sourname);
}

void Patient::SetName(char * name)
{
	strcpy(this->name, name);
}

void Patient::SetPatronymic(char * patronymic)
{
	strcpy(this->patronymic, patronymic);
}

void Patient::SetGender(char * gender)
{
	strcpy(this->gender, gender);
}

void Patient::SetNational(char * national)
{
	strcpy(this->national, national);
}

void Patient::SetHeight(int height)
{
	if (height > 0)
	{
		this->height = height;
	}
	else
	{
		this->height = 0;
	}
}

void Patient::SetWeight(int weight)
{
	if (weight > 0)
	{
		this->weight = weight;
	}
	else
	{
		this->weight = 0;
	}
}


void Patient::SetBirthday(char* birthday)
{
	strcpy(this->birthday, birthday);
}

void Patient::SetNumberPhone(int phoneNumber)
{
	if (phoneNumber > 0)
	{
		this->phoneNumber = phoneNumber;
	}
	else
	{
		this->phoneNumber = 0;
	}
}

void Patient::SetAdress(char * adress)
{
	strcpy(this->adress, adress);
}

void Patient::SetNumberOfHospital(int numberOfHospital)
{
	if (numberOfHospital > 0)
	{
		this->numberOfHospital = numberOfHospital;
	}
	else
	{
		this->numberOfHospital = 0;
	}
}

void Patient::SetDepartment(char * department)
{
	strcpy(this->department, department);
}

void Patient::SetMedicalCardNumber(int medicalCardNumber)
{
	if (medicalCardNumber > 0)
	{
		this->medicalCardNumber = medicalCardNumber;
	}
	else
	{
		this->medicalCardNumber = 0;
	}
}

void Patient::SetDiagnosis(char * diagnosis)
{
	strcpy(this->diagnosis, diagnosis);
}

void Patient::SetBloodGroup(int bloodGroup)
{
	if (bloodGroup > 0 && bloodGroup <= 4)
	{
		this->bloodGroup = bloodGroup;
	}
	else
	{
		this->bloodGroup = 0;
	}
}

void Patient::SetHospital(char* sourname, char* name, char* patronymic, char* gender, char* national, int  height, int weight, char* birthday, int phoneNumber, char* adress, int numberOfHospital, char* department, int medicalCardNumber, char* diagnosis, int bloodGroup)
{
	this->SetSourname(sourname);
	this->SetName(name);
	this->SetPatronymic(patronymic);
	this->SetGender(gender);
	this->SetNational(national);
	this->SetHeight(height);
	this->SetWeight(weight);
	this->SetBirthday(birthday);
	this->SetNumberPhone(phoneNumber);
	this->SetAdress(adress);
	this->SetNumberOfHospital(numberOfHospital);
	this->SetDepartment(department);
	this->SetMedicalCardNumber(medicalCardNumber);
	this->SetDiagnosis(diagnosis);
	this->SetBloodGroup(bloodGroup);
}

char * Patient::GetSourname()
{
	return this->sourname;
}

char * Patient::GetName()
{
	return this->name;
}

char * Patient::GetPatronymic()
{
	return this->patronymic;
}

char * Patient::GetGender()
{
	return this->gender;
}

char * Patient::GetNational()
{
	return this->national;
}

int Patient::GetHeight()
{
	return this->height;
}

int Patient::GetWeight()
{
	return this->weight;
}

char* Patient::GetBirthday()
{
	return this->birthday;
}

int Patient::GetPhoneNumber()
{
	return this->phoneNumber;
}

char * Patient::GetAdress()
{
	return this->adress;
}

int Patient::GetNumberOfHospital()
{
	return this->numberOfHospital;
}

char * Patient::GetDepartment()
{
	return this->department;
}

int Patient::GetMedicalCardNumber()
{
	return this->medicalCardNumber;
}

char * Patient::GetDiagnosis()
{
	return this->diagnosis;
}

int Patient::GetBloodGroup()
{
	return this->bloodGroup;
}

void Patient::DisplayPatient()
{
	cout << "Patient: ";
	cout << endl << this->sourname << " " << this->name << " " << this->patronymic << " " << this->gender << " "
		<< this->national << " " << this->height << " " << this->weight << " " << this->birthday << " "
	 << this->phoneNumber << " " << this->adress << " ";
	cout.precision(3);
	cout << "Medical facts: ";
	cout << this->numberOfHospital << " " << this->department << " " << this->medicalCardNumber << " " << this->diagnosis << " " << this->bloodGroup;

}

void Patient::EnterPatient()
{
	const int N = 100;
	char sourname[N] = "", name[N] = "", patronymic[N] = "", gender[N] = "", national[N] = "", adress[N] = "",
		department[N] = "", diagnosis[N] = "", birthday[N]="";
	cout << "Enter sourname: ";
	cin.ignore();
	cin.getline(sourname, N, '\n');
	cout << "Enter name: ";
	cin.getline(name, N, '\n');
	cout << "Enter patronymic: ";
	cin.getline(patronymic, N, '\n');
	cout << "Enter gender: ";
	cin.getline(gender, N, '\n');
	cout << "Enter national: ";
	cin.getline(national, N, '\n');
	cout << "Enter height: ";
	cin >> height;
	cout << "Enter weight: ";
	cin >> weight;
	cout << "Enter birthday: ";
	cin.ignore();
	cin.getline(national, N, '\n');
	cout << "Enter phone number: ";
	cin >> phoneNumber;
	cout << "Enter adress: ";
	cin.ignore();
	cin.getline(adress, N, '\n');
	cout << "Enter number of hospital: ";
	cin >> numberOfHospital;
	cout << "Enter department: ";
	cin.ignore();
	cin.getline(department, N, '\n');
	cout << "Enter medical card number: ";
	cin >> medicalCardNumber;
	cout << "Enter diagnosis: ";
	cin.ignore();
	cin.getline(diagnosis, N, '\n');
	cout << "Enter blood group: ";
	cin >> bloodGroup;
	cout << endl;
	system("cls");
	this->SetHospital(sourname, name, patronymic, gender, national, height, weight, birthday, phoneNumber, adress, numberOfHospital, department, medicalCardNumber,diagnosis, bloodGroup);
}

