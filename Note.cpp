#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;


/*

	Задание 1: Заметки
- Добавление заметки (название, текст)
- Удаление заметки
- Редактирование заметки (возможность менять название и текст)
- Вывод всего списка заметок
- Просмотр информации по каждой заметке в отдельности
- Поиск заметок по названию


*/

struct Note
{
	char nameNote[20];
	char text[100];
};


void printAllNote(const Note* arr, const int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		cout << "\n--------------------------------------------------\n";

		cout << i << '\t' << arr[i].nameNote << "\t\t\t";

		cout << arr[i].text << endl;
	}

}

void printSpecificNote(const Note* arr, const int numNote)
{
	for (int i = numNote; i < numNote + 1; i++)
	{
		cout << "\n--------------------------------------------------\n";

		cout << i << '\t' << arr[i].nameNote << "\t\t\t";

		cout << arr[i].text << endl;
	}

}

void addNote(Note*& arr, int& quantiity) {

	Note* tmp = new Note[quantiity + 1];

	for (int i = 0; i < quantiity; i++)
	{
		tmp[i] = arr[i];
	}
	cout << "\nEnter note name\n";
	cin >> tmp[quantiity].nameNote;

	cout << "Enter note text\n";
	cin >> tmp[quantiity].text;

	++quantiity;
	delete[] arr;
	arr = tmp;
}



void deleteNote(Note*& arr, int& quantity, const int deleteNum) {

	Note* tmp = new Note[quantity - 1];

	for (size_t i = 0, b = 0; i < quantity; i++) {

		if (i != deleteNum)
		{
			tmp[b] = arr[i];
			b++;
		}
	}
	quantity--;
	delete[] arr;
	arr = tmp;
}



void editeNote(Note*& arr, const int editeNote)
{
	bool note = true;
	for (size_t i = editeNote; i < editeNote + 1; i++)
	{

		cout << "\nEnter note name\n";
		cin >> arr[editeNote].nameNote;

		cout << "Enter note text\n";
		cin >> arr[editeNote].text;
		note = false;
	}

	if (note)
		cout << "\nYou not have note\n";
}



void serachNote(const Note* arr, const int quantity, const char* nameNote)
{
	for (size_t i = 0; i < quantity; i++)
		if (strcmp(arr[i].nameNote, nameNote) == 0)
		{
			cout << "\n--------------------------------------------------\n";
			cout << i << '\t' << arr[i].nameNote << "\t\t\t";
			cout << arr[i].text << endl;
		}

	if (quantity == 0)
		cout << "-\t-\t\t\t-\n\nThere is no note for such a search\n";
}

enum {
	Exit,
	AddNote,
	DeleteNote,
	EditNote,
	PrintAllNote,
	PrintSpecificNote,
	SearchNote
};

int main()
{
	int quantity, action, deleteNum, editNote, numNote;
	const int ComeBack = -1;
	char note[20];

	do
	{
		cout << "Enter quantity Notes\n";
		cin >> quantity;
		if (quantity < 0)
		{
			cout << "The number of notes must be greater than or equal to zero\n\n";;
		}
		else {
			break;
		}
	} while (true);

	Note* arr = new Note[quantity];

	for (size_t i = 0; i < quantity; i++)
	{
		cout << "Enter note name\n";
		cin >> arr[i].nameNote;

		cout << "Enter note text\n";
		cin >> arr[i].text;
	}


	do
	{
		cout << R"(
 
0  -  Exit
1  -  Add Note
2  -  Delete Note
3  -  Edit Note
4  -  Print All Note 
5  -  Print Specific Note 
6  -  Search Note by name
  
)";
		cin >> action;

		if (action == Exit)
		{
			cout << "You have left the program\n";
			break;

		}
		else if (action == AddNote)
		{
			cout << "\nAdd new note\n\n";
			addNote(arr, quantity);
		}
		else if (action == DeleteNote)
		{

			do
			{
				cout << "Choose note number (#) for delete\n";
				cin >> deleteNum;

				if (deleteNum < quantity)
				{
					cout << "\nYou delete # " << deleteNum << " Name \t" << arr[deleteNum].nameNote << endl;
					deleteNote(arr, quantity, deleteNum);
					break;
				}
				else if (quantity == 0) {
					cout << "You have no notes\n";
					break;
				}
				else {
					cout << "Wrong selection, try again.\n";
				}

			} while (true);
		}
		else if (action == EditNote)
		{
			do
			{
				cout << "Come back   -1\nSelect note num (#) for edition\n";
				cin >> editNote;

				if (editNote == ComeBack) {
					cout << "You come back\n";
					break;
				}
				else if (editNote < quantity && editNote != ComeBack)
				{
					cout << "You edit # " << editNote << "\tname\t\t\t" << arr[editNote].nameNote << endl;
					editeNote(arr, editNote);
					break;
				}
				else if (quantity == 0) {
					cout << "You have no notes\n";
					break;
				}
				else {
					cout << "Wrong selection, try again.\n";
				}
			} while (true);
		}
		else if (action == PrintAllNote)
		{
			cout << "\n\nPrint All List\n\n#\tName\t\t\tText\n\n";
			printAllNote(arr, quantity);
			if (quantity == 0)
			{
				cout << "-\t-\t\t\t-\n\nYou don't have note\n\n";
			}
		}
		else if (action == PrintSpecificNote)
		{

			do
			{
				cout << "Come back   -1\nChoose note number (#) \n";
				cin >> numNote;
				if (numNote < quantity && numNote != ComeBack)
				{
					cout << "Print All List\n\n#\tName\t\t\tText\n\n";
					printSpecificNote(arr, numNote);
					break;
				}
				else if (quantity == 0) {
					cout << "You have no note\n";
					break;
				}
				else if (numNote == ComeBack)
				{
					cout << "You come back\n";
					break;
				}
				else {
					cout << "Wrong selection, try again.\n";
				}
			} while (true);

		}
		else if (action == SearchNote)
		{

			do
			{
				cout << "\n\nSearch for notes by name\n";
				cin >> note;
				cout << "\n#\tName\t\t\tText\n\n";
				serachNote(arr, quantity, note);
				break;
			} while (true);
		}
		else {
			cout << "\nWrong selection, try again.\n";
		}

	} while (true);

}