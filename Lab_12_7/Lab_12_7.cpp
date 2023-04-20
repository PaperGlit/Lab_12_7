#include <iostream>
#include <fstream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->link = NULL; // 3
    if (last != NULL)
        last->link = tmp; // 4
    last = tmp; // 5
    if (first == NULL)
        first = tmp; // 6
}

void print(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << ' ';
        first = first->link;
    }
    cout << endl;
}

bool areEqual(Elem* first1, Elem* first2)
{
    while (first1 != NULL && first2 != NULL)
    {
        if (first1->info != first2->info)
            return false;
        first1 = first1->link;
        first2 = first2->link;
    }
    return (first1 == NULL && first2 == NULL);
}

void concat(Elem* first1, Elem* first2)
{
    while (first2 != NULL)
    {
        while (first1->link != NULL)
            first1 = first1->link;
        Elem* tmp = new Elem; // 1
        tmp->info = first2->info; // 2
        tmp->link = first1->link; // 3
        first1->link = tmp; // 4
        first2 = first2->link;
    }
}

void add(Elem* first1, Elem*& first3, Elem*& last3)
{
    while (first1 != NULL)
    {
        enqueue(first3, last3, first1->info);
        enqueue(first3, last3, first1->info);
        first1 = first1->link;
    }   
}

int main()
{
    Elem* first1 = NULL, * first2 = NULL, * last1 = NULL, * last2 = NULL, * first3 = NULL, * last3 = NULL; 
    bool kb; int imax1, imax2; Info value, n1, n2;
    cout << "Text document or keyboard input? (0-1) : "; cin >> kb;
    if (kb)
    {
        cout << "Enter the amount of values (#1) : ";
        cin >> imax1;
        for (int i = 0; i < imax1; i++)
        {
            cout << "Enter the value : ";
            cin >> value;
            enqueue(first1, last1, value);
        }
        cout << "Enter the amount of values (#2) : ";
        cin >> imax2;
        for (int i = 0; i < imax2; i++)
        {
            cout << "Enter the value : ";
            cin >> value;
            enqueue(first2, last2, value);
        }
    }
    else
    {
        ifstream fin1("file1.txt"), fin2("file2.txt");
        while (fin1 >> n1)
            enqueue(first1, last1, n1);
        while (fin2 >> n2)
            enqueue(first2, last2, n2);
    }
    print(first1);
    print(first2);
    if (areEqual(first1, first2))
    {
        add(first1, first3, last3); print(first3);
    }
    else
    {
        concat(first1, first2); print(first1);
    }
}