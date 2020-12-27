// Simple program to read and display Sparse Matrices. 

#include <iostream>
using namespace std;

// Class of Elements to store their coordinates
class Element
{
public:
    int rowOfElem;
    int colOfElem;
    int elem;
};

class Sparse
{
private:
    int nrows;
    int ncols;
    int numOfElems;
    Element* eleArr;

public:
    Sparse(int nrows, int ncols, int numOfElems)
    {
        this->nrows = nrows;
        this->ncols = ncols;
        this->numOfElems = numOfElems;
        this->eleArr = new Element[this->numOfElems];
    }
    void set();
    void display();
    ~Sparse();
};

int main()
{
    int nrows, ncols, numOfElems;

    cout << "Enter dimensions (row by col): ";
    cin >> nrows >> ncols;
    cout << "Enter number of Elements: ";
    cin >> numOfElems;

    // Exception Handling (for fun purposes only)
    try
    {
        if (numOfElems > nrows * ncols)
        {
            throw 1;
        }
        Sparse* s = new Sparse(nrows, ncols, numOfElems);
        s->set();
        s->display();
        delete s;
    }
    catch (int e)
    {
        cout << "Error " << e << ". Please enter valid number of elements and execute program again.";
    }
}

void Sparse::set()
{
    cout << "Enter " << this->numOfElems << " non-zero elements (with row and col before):" << endl;
    int i = 0, row, col, elem;
    while (i < this->numOfElems)
    {
        cin >> row >> col >> elem;
        if (row >= this->nrows || col >= this->ncols)
        {
            cout << "Out of bounds! Try again." << endl;
        }
        else
        {
            eleArr[i].rowOfElem = row;
            eleArr[i].colOfElem = col;
            eleArr[i].elem = elem;
            i++;
        }
    }
}

void Sparse::display()
{
    // Flag so that users can input elements in any order
    bool found = false;

    cout << "Here is your Sparse Matrix." << endl;
    for (int i = 0; i < this->nrows; i++)
    {
        for (int j = 0; j < this->ncols; j++)
        {
            for (int k = 0; k < this->numOfElems; k++)
            {
                if (i == eleArr[k].rowOfElem && j == eleArr[k].colOfElem)
                {
                    cout << eleArr[k].elem << " ";
                    found = true;
                    break;
                }
            }
            if (found == true)
            {
                found = false; // For the next iteration
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

Sparse::~Sparse()
{
    delete[] eleArr;
    eleArr = NULL;
}