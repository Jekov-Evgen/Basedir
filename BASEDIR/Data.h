#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <C:\Users\Æåíÿ\source\repos\BASEDIR\BASEDIR\Functoin.h>



namespace dataStructure {
	struct Initials
	{
		std::string surname, name, patronymic;
	};

	struct Date
	{
		int day, month, year;
	};

	struct Address
	{
		std::string city;
		int houseNumber;
	};
}

namespace ds = dataStructure;

class FieldBaseDir
{
public:
	FieldBaseDir();

	FieldBaseDir(ds::Initials person,
		ds::Date registrationPeriod,
		ds::Address placeOfResidence);

	~FieldBaseDir();


	void Print();
	void DataEntry(ds::Initials person,
		ds::Date registrationPeriod,
		ds::Address placeOfResidence);

	ds::Initials GetInitials() {
		return person;
	}

	ds::Date GetDate() {
		return registrationPeriod;
	}

	ds::Address GetAddress() {
		return placeOfResidence;
	}

	FieldBaseDir& operator = (FieldBaseDir otherData);

private:
	ds::Initials person;
	ds::Date registrationPeriod;
	ds::Address placeOfResidence;
};