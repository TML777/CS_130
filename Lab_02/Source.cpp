#include <iostream>
#include <iomanip>
#include <cmath>

long long unsigned checkInput();
void getMatrix(long long unsigned, bool[8][8]);
void display(long long unsigned, long long unsigned, bool[8][8], bool[8][8], int);
void printInteger(long long unsigned, bool[8][8]);
void printBitMatrix(bool[8][8]);
int getInt();

using namespace std;
int main() {
    cout << "Size of a \"long long unsigned\" is " << sizeof(long long unsigned) << " bytes or " << sizeof(long long unsigned) * 8 << " bits." << endl;
    long long unsigned bigIntOne, bigIntTwo;
    bool bitMatrixOne[8][8], bitMatrixTwo[8][8];

    cout << endl << "Please enter the first unsigned integer: ";
    bigIntOne = checkInput();
    cout << endl << "Please enter the second unsigned integer (ensure value is greater than the first integer): ";
    bigIntTwo = checkInput();
    cout << endl;

    getMatrix(bigIntOne, bitMatrixOne);
    getMatrix(bigIntTwo, bitMatrixTwo);

    for (int i = 0; i < 10; i++)
    {
        display(bigIntOne, bigIntTwo, bitMatrixOne, bitMatrixTwo, i);
        cout << endl << endl << endl;
        system("pause");
        system("cls");
    }

    return 0;
}


long long unsigned checkInput()
{
    long long tempSigned;
    long long unsigned tempUnsigned;

    while (!(cin >> tempSigned))
    {
        cin.clear();
        cin.ignore(180, '\n');
        cout << "Not a valid input please try again: ";
    }
    cin.clear();
    cin.ignore(180, '\n');
    if (tempSigned < 0L)
    {
        tempUnsigned = tempSigned * -1L;
        cout << "You entered a negative value; converting to positive: " << tempUnsigned << endl;
    }
    else
        tempUnsigned = tempSigned;
    return tempUnsigned;
}

void getMatrix(long long unsigned bigInt, bool bitMatrix[8][8])
{
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 7; j >= 0; j--)
        {
            bitMatrix[i][j] = (bigInt % 2 == 1);
            bigInt /= 2;
        }
    }
}

void display(long long unsigned bigIntOne, long long unsigned bigIntTwo, bool bitMatrixOne[8][8], bool bitMatrixTwo[8][8], int number)
{
    cout << endl << " First integer: ";
    printInteger(bigIntOne, bitMatrixOne);
    cout << endl << "Second integer: ";
    printInteger(bigIntTwo, bitMatrixTwo);

    if (number != 0)
    {
        bool tempBitMatrix[8][8];
        long long unsigned tempBigInt;
        long long tempBigIntSignedOne;
        int tempInt;
        switch (number) {
        case 1:
            tempBigInt = bigIntOne + bigIntTwo;
            getMatrix(tempBigInt, tempBitMatrix);
            cout << endl << "           Sum: ";
            printInteger(tempBigInt, tempBitMatrix);
            break;
        case 2:
            tempBigIntSignedOne = (long long)bigIntOne - (long long)bigIntTwo;
            getMatrix((long long unsigned)tempBigIntSignedOne, tempBitMatrix);
            cout << endl << "    Difference: ";
            printBitMatrix(tempBitMatrix);
            cout << '\t' << hex << uppercase << setfill('x') << setw(16) << tempBigIntSignedOne << '\t' << setfill(' ') << setw(20) << dec << tempBigIntSignedOne << endl;
            break;
        case 3:
            tempBigInt = bigIntOne & bigIntTwo;
            getMatrix(tempBigInt, tempBitMatrix);
            cout << endl << "   Logical AND: ";
            printInteger(tempBigInt, tempBitMatrix);
            break;
        case 4:
            tempBigInt = bigIntOne | bigIntTwo;
            getMatrix(tempBigInt, tempBitMatrix);
            cout << endl << "    Logical OR: ";
            printInteger(tempBigInt, tempBitMatrix);
            break;
        case 5:
            tempBigInt = bigIntOne ^ bigIntTwo;
            getMatrix(tempBigInt, tempBitMatrix);
            cout << endl << "   Logical XOR: ";
            printInteger(tempBigInt, tempBitMatrix);
            break;
        case 6:
            tempBigInt = ~bigIntOne;
            getMatrix(tempBigInt, tempBitMatrix);
            cout << endl << "   Logical NOT: ";
            printInteger(tempBigInt, tempBitMatrix);
            break;
        case 7: 
            tempBigIntSignedOne = -(long long)bigIntOne;
            getMatrix((long long unsigned)tempBigIntSignedOne, tempBitMatrix);
            cout << endl << "        Negate: ";
            printBitMatrix(tempBitMatrix);
            cout << '\t' << hex << uppercase << setfill('x') << setw(16) << tempBigIntSignedOne << '\t' << setfill(' ') << setw(20) << dec << tempBigIntSignedOne << endl;
            break;
        case 8:
            cout << endl << "Enter a number, between 0 and 64, of places to left shift: ";
            tempInt = getInt();
            tempBigInt = bigIntOne << tempInt;
            getMatrix(tempBigInt, tempBitMatrix);
            cout << endl << "    Left Shift: ";
            printInteger(tempBigInt, tempBitMatrix);
            break;
        case 9:
            cout << endl << "Enter a number, between 0 and 64, of places to right shift: ";
            tempInt = getInt();
            tempBigInt = bigIntOne >> tempInt;
            getMatrix(tempBigInt, tempBitMatrix);
            cout << endl << "   Right Shift: ";
            printInteger(tempBigInt, tempBitMatrix);
            break;
        default:
            break;
        }
    }
}

void printInteger(long long unsigned bigIntOne, bool bitMatrixOne[8][8])
{

    printBitMatrix(bitMatrixOne);
    cout << '\t' << hex << uppercase << setfill('x') << setw(16) << bigIntOne << '\t' << setfill(' ') << setw(20) << dec << bigIntOne << endl;
}

void printBitMatrix(bool bitMatrix[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << bitMatrix[i][j];
        cout << ' ';
    }
}

int getInt()
{
    int temp;
    while (!(cin >> temp) || temp > 64 || temp < 0)
    {
        cin.clear();
        cin.ignore(180, '\n');
        cout << "Not a valid input please try again, Enter a number between 0 and 64: ";
    }
    return temp;
}
