#include <C:\Users\Женя\source\repos\BASEDIR\BASEDIR\Data.h>

FieldBaseDir::FieldBaseDir() {
	person.name = "";
	person.surname = "";
	person.patronymic = "";

	registrationPeriod.day = 0;
	registrationPeriod.month = 0;
	registrationPeriod.year = 0;

	placeOfResidence.city = "";
	placeOfResidence.houseNumber = 0;
}

FieldBaseDir::FieldBaseDir(ds::Initials person, ds::Date registrationPeriod, ds::Address placeOfResidence) {
    this->person.name = person.name;
    this->person.surname = person.surname;
    this->person.patronymic = person.patronymic;

    this->registrationPeriod.day = registrationPeriod.day;
    this->registrationPeriod.month = registrationPeriod.month;
    this->registrationPeriod.year = registrationPeriod.year;

    this->placeOfResidence.city = placeOfResidence.city;
    this->placeOfResidence.houseNumber = placeOfResidence.houseNumber; 
}


void FieldBaseDir::DataEntry(ds::Initials person, ds::Date registrationPeriod, ds::Address placeOfResidence) {
	this->person.name = person.name;
	this->person.surname = person.surname;
	this->person.patronymic = person.patronymic;

	this->registrationPeriod.day = registrationPeriod.day;
	this->registrationPeriod.month = registrationPeriod.month;
	this->registrationPeriod.year = registrationPeriod.year;

	this->placeOfResidence.city = placeOfResidence.city;
	this->placeOfResidence.houseNumber = placeOfResidence.houseNumber;
}

FieldBaseDir::~FieldBaseDir() { }

void FieldBaseDir::Print() {
	std::cout << "ФИО: " << person.surname << ", " << person.name << ", " << person.patronymic << std::endl;
	std::cout << "Дата: " << registrationPeriod.day << "." << registrationPeriod.month << "." << registrationPeriod.year << std::endl;
	std::cout << "Место проживания: " << placeOfResidence.city << " " << "Номер дома(квартиры): " << placeOfResidence.houseNumber << std::endl;
}

FieldBaseDir& FieldBaseDir::operator=(FieldBaseDir otherData) {
	this->person.name = otherData.person.name;
	this->person.surname = otherData.person.surname;
	this->person.patronymic = otherData.person.patronymic;

	this->registrationPeriod.day = otherData.registrationPeriod.day;
	this->registrationPeriod.month = otherData.registrationPeriod.month;
	this->registrationPeriod.year = otherData.registrationPeriod.year;

	this->placeOfResidence.city = otherData.placeOfResidence.city;
	this->placeOfResidence.houseNumber = otherData.placeOfResidence.houseNumber;

	return *this;
}