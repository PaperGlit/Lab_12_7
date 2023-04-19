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
    bool found = true;
    while (first1 != NULL && first2 != NULL && found == true)
    {
        if (first1->info != first2->info)
            found = false;
        first1 = first1->link;
        first2 = first2->link;
    }
    if (first1 != NULL || first2 != NULL)
        return false;
    else
        return found;
}

int main()
{
    Elem* first1 = NULL, *first2 = NULL, * last1 = NULL, *last2 = NULL;
    ifstream fin1("file1.txt"), fin2("file2.txt");
    Info n1, n2;
    while (fin1 >> n1)
        enqueue(first1, last1, n1);
    while (fin2 >> n2)
        enqueue(first2, last2, n2);
    print(first1);
    print(first2);
    cout << areEqual(first1, first2) << endl;
}