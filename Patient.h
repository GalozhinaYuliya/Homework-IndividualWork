#pragma once
#define patient_h

const int N = 100;
class Patient
{
public:

	Patient(){}
	Patient(char*, char*, char*, char*, char*, int, int, char*, int, char*, int, char*, int, char*, int);
	void SetSourname(char*);
	void SetName(char*);
	void SetPatronymic(char*);
	void SetGender(char*);
	void SetNational(char*);
	void SetHeight(int);
	void SetWeight(int);
	void SetBirthday(char*);
	void SetNumberPhone(int);
	void SetAdress(char*);
	void SetNumberOfHospital(int);
	void SetDepartment(char*);
	void SetMedicalCardNumber(int);
	void SetDiagnosis(char*);
	void SetBloodGroup(int);
	void SetHospital(char*, char*, char*, char*, char*, int, int, char*, int, char*, int, char*, int, char*, int);

	char* GetSourname();
	char* GetName();
	char* GetPatronymic();
	char* GetGender();
	char* GetNational();
	int GetHeight();
	int GetWeight();
	char* GetBirthday();
	int GetPhoneNumber();
	char* GetAdress();
	int GetNumberOfHospital();
	char* GetDepartment();
	int GetMedicalCardNumber();
	char* GetDiagnosis();
	int GetBloodGroup();
	void DisplayPatient();
	void EnterPatient();

private:
	char sourname[N]{}, name[N]{}, patronymic[N]{}, gender[N]{}, national[N]{}, birthday[N]{}, adress[N]{}, department[N]{}, diagnosis[N]{};
	int height{}, weight{}, phoneNumber{}, numberOfHospital{}, medicalCardNumber{}, bloodGroup{};
};