#include "MyVector.h"
#include "MyVector.cpp"
#include <string>

using namespace std;

int main()
{
	MyVector<string> vector;
	cout << "l = " << vector.GetLength() << endl;
	for (int i = 0; i < 10; i++)
	{
		vector.AddElement(to_string(i));
	}
	cout << "New l = " << vector.GetLength() << endl;

	cout << "First: \n";
	for (int i = 0; i < vector.GetLength(); i++)
	{
		cout << vector.GetElement(i) << endl;
	}

	MyVector<string> vector2 = vector;
	vector2.AddElement("111");

	cout << "Second: \n";
	for (int i = 0; i < vector2.GetLength(); i++)
	{
		cout << vector2.GetElement(i) << endl;
	}
	return 0;
}