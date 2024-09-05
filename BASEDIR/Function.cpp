#include <C:\Users\����\source\repos\BASEDIR\BASEDIR\Functoin.h>


void FieldBaseDirEntry(FieldBaseDir*& inputData, int& dataStreamSize) {
	ds::Initials tempPerson;
	ds::Date tempRegistrationPeriod;
	ds::Address tempPlaceOfResidence;

	std::cout << "������� ������� ����� ������ �� ������ ������: ";
	std::cin >> dataStreamSize;

	inputData = new FieldBaseDir[dataStreamSize];

	for (int i = 0; i < dataStreamSize; i++) {
		std::cout << "������� ���: ";
		std::cin >> tempPerson.surname >> tempPerson.name >> tempPerson.patronymic;

		std::cout << "������� ����(DDMMYY): ";
		std::cin >> tempRegistrationPeriod.day >> tempRegistrationPeriod.month >> tempRegistrationPeriod.year;

		std::cout << "������� ��� �����: ";
		std::cin >> tempPlaceOfResidence.city;

		std::cout << "������� ����� ������ ����(��������): ";
		std::cin >> tempPlaceOfResidence.houseNumber;

		inputData[i].DataEntry(tempPerson, tempRegistrationPeriod, tempPlaceOfResidence);
	}
}


void FieldBaseDirReading(FieldBaseDir* inputData, int& dataStreamSize, std::string fileName) {
	std::ifstream readingData(fileName);

	if (readingData) {
		ds::Initials tempPerson;
		ds::Date tempRegistrationPeriod;
		ds::Address tempPlaceOfResidence;

		readingData >> dataStreamSize;

		delete[] inputData;
		inputData = new FieldBaseDir[dataStreamSize];

		for (int i = 0; i < dataStreamSize; i++) {
			readingData >> tempPerson.surname >> tempPerson.name >> tempPerson.patronymic;
			readingData >> tempRegistrationPeriod.day >> tempRegistrationPeriod.month >> tempRegistrationPeriod.year;
			readingData >> tempPlaceOfResidence.city >> tempPlaceOfResidence.houseNumber;

			inputData[i].DataEntry(tempPerson, tempRegistrationPeriod, tempPlaceOfResidence);
		}

		std::cout << "������ �������!" << std::endl;
	}
	else {
		std::cout << "������ �������� �����. ������ �����, �� ������� ������� ���" << std::endl;
	}

	readingData.close();
}

void FieldBaseDirPrint(FieldBaseDir* inputData, int dataStreamSize) {
	for (int i = 0; i < dataStreamSize; i++) {
		std::cout << "������: " << i + 1 << std::endl;
		inputData[i].Print();
	}
}

void FieldBaseDirChange(FieldBaseDir* inputData, int dataStreamSize) {
	ds::Initials tempPerson;
	ds::Date tempRegistrationPeriod;
	ds::Address tempPlaceOfResidence;
	int numberSelection = 0;

	std::cout << "������� ����� ���� ������� ����� �������� �� 1 ��" << dataStreamSize << ": ";
	std::cin >> numberSelection;
	numberSelection--;

	if (numberSelection >= 0 && numberSelection < dataStreamSize) {
		std::cout << "������� ����� ���: ";
		std::cin >> tempPerson.surname >> tempPerson.name >> tempPerson.patronymic;

		std::cout << "������� ����� ����(DDMMYY): ";
		std::cin >> tempRegistrationPeriod.day >> tempRegistrationPeriod.month >> tempRegistrationPeriod.year;

		std::cout << "������� ����� �����: ";
		std::cin >> tempPlaceOfResidence.city;

		std::cout << "������� ����� ����� ������ ����(��������): ";
		std::cin >> tempPlaceOfResidence.houseNumber;

		inputData[numberSelection].DataEntry(tempPerson, tempRegistrationPeriod, tempPlaceOfResidence);
	}
	else {
		std::cout << "�� �������� �� ������� ����� ��" << std::endl;
	}
}

void FieldBaseDirCopy(FieldBaseDir* newData, FieldBaseDir* oldData, int dataStreamSize) {
	for (int i = 0; i < dataStreamSize; i++) {
		newData[i] = oldData[i];
	}
}

void FieldBaseDirAddData(FieldBaseDir* inputData, int& dataStreamSize) {
	ds::Initials tempPerson;
	ds::Date tempRegistrationPeriod;
	ds::Address tempPlaceOfResidence;

	FieldBaseDir* tempArray = new FieldBaseDir[dataStreamSize];
	int oldSize = dataStreamSize;
	int newSize = ++dataStreamSize; 

	FieldBaseDirCopy(tempArray, inputData, oldSize);
	delete[] inputData;
	inputData = new FieldBaseDir[newSize];
	FieldBaseDirCopy(inputData, tempArray, oldSize);

	std::cout << "������� ���: ";
	std::cin >> tempPerson.surname >> tempPerson.name >> tempPerson.patronymic;

	std::cout << "������� ����(DDMMYY): ";
	std::cin >> tempRegistrationPeriod.day >> tempRegistrationPeriod.month >> tempRegistrationPeriod.year;

	std::cout << "������� �����: ";
	std::cin >> tempPlaceOfResidence.city;

	std::cout << "������� ����� ������ ����(��������): ";
	std::cin >> tempPlaceOfResidence.houseNumber;

	inputData[oldSize].DataEntry(tempPerson, tempRegistrationPeriod, tempPlaceOfResidence);

	std::cout << "������ ��������� � ��" << std::endl;

	delete[] tempArray;
}

void FieldBaseDirDeleteData(FieldBaseDir* inputData, int& dataStreamSize) {
	FieldBaseDir* tempArray = new FieldBaseDir[dataStreamSize];
	int numberSelection = 0;

	std::cout << "������� ����� ���� ������� ����� ������� �� 1 ��" << dataStreamSize << ": ";
	std::cin >> numberSelection;
	numberSelection--;

	if (numberSelection >= 0 && numberSelection < dataStreamSize) {
		FieldBaseDirCopy(tempArray, inputData, dataStreamSize);
		int q = 0;
		dataStreamSize--;

		inputData = new FieldBaseDir[dataStreamSize];

		for (int i = 0; i <= dataStreamSize; i++) {
			if (i != numberSelection) {
				inputData[q] = tempArray[i];
				q++;
			}
		}

		std::cout << "��������� ������ �������" << std::endl;
	}
	else {
		std::cout << "�� ����� �������� �����!" << std::endl;
	}

	delete[] tempArray;
}


void FieldBaseDirSorting(FieldBaseDir* inputData, int dataStreamSize) {
	FieldBaseDir tempArray;
	int numberSorted = 0;

	for (int i = 0; i < dataStreamSize; i++) {
		for (int j = i + 1; j < dataStreamSize; j++) {
			if (inputData[i].GetInitials().surname > inputData[j].GetInitials().surname) {
				tempArray = inputData[i];
				inputData[i] = inputData[j];
				inputData[j] = tempArray;

				numberSorted++;
			}
		}
	}

	std::cout << "������ ���� �������������. ���������� ����������: " << numberSorted << std::endl;
}

void FieldBaseDirSaveData(FieldBaseDir* inputData, int dataStreamSize, std::string fileName) {
	std::ofstream dataRecording(fileName);

	if (dataRecording) {
		dataRecording << dataStreamSize << std::endl;

		for (int i = 0; i < dataStreamSize; i++) {
			dataRecording << inputData[i].GetInitials().surname << " " << inputData[i].GetInitials().name << " " << inputData[i].GetInitials().patronymic << " ";
			dataRecording << inputData[i].GetDate().day << "." << inputData[i].GetDate().month << "." << inputData[i].GetDate().year << " ";
			dataRecording << inputData[i].GetAddress().city << " " << inputData[i].GetAddress().houseNumber << std::endl;
		}
	}
	else {
		std::cout << "������ �������� �����. ������ �����, �� ������� ������� ���" << std::endl;
	}

	std::cout << "������ �� �� ���� ��������� �: " << fileName << std::endl;

	dataRecording.close();
}