#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{

    clsDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 1337);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 42);

    cout << "\nIs Empty?  " << MyDynamicArray.IsEmpty() ;
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    cout << "\nArray Items: \n";

    MyDynamicArray.PrintList();

    MyDynamicArray.DeleteFirstItem();
    cout << "\nArray Items after deleting FirstItem: \n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();

    MyDynamicArray.DeleteLastItem();
    cout << "\nArray Items after deleting LastItem: \n";
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    MyDynamicArray.PrintList();


}