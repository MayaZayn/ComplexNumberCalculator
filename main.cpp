// FCAI - Programming 1 - 2022 - Assignment 2
// Program Name: ComplexNumberCalculator.cpp
// Program Description: Takes two complex numbers in a specified format
// and handles addition/subtraction/multiplication/division on these complex numbers
// Last Modification Date: 03 / 25 / 2022
// Authors: Maya Ayman, Mohamed Rady, Ali Tarek
// ID: 20210508, 20210506, 20210252
// Group: A
// Purpose: To do math operations on complex numbers

#include <bits/stdc++.h>

using namespace std;

// Makes sure the input is only written in the proper format (a+bi) [+-/*] (c+di)
bool isValidComplex(string& complexNumber) {
    string complexNumRegex = "[(][-+]?[0-9]+[.]?[0-9]*[+-][0-9]+[.]?[0-9]*[i][)]";
    regex valid_regex((complexNumRegex + "[+-/*]" + complexNumRegex));
    return regex_match(complexNumber, valid_regex);
}

// Checks through a parameter whether the operation is addition or subtraction.
// Adds the real and the complex parts separately and outputs the result if 'add' parameter is true, otherwise subtracts the real and complex parts separately
// Prints the result
void addOrSubtractComplexNumbers(bool add, float r1, float img1, float r2, float img2) {
    float realNumResult = add ? r1 + r2 : r1 - r2;
    float imgNumResult = add ? img1 + img2 : img1 - img2;
    if (imgNumResult == 0)
        cout << realNumResult << endl;
    else
        cout << realNumResult << (imgNumResult > 0 ? "+" : "") << imgNumResult << "i\n";
}

// Multiplies the 2 complex expressions using FOIL method
void multiplyComplexNumbers(float r1, float img1, float r2, float img2) {
    float realNumResult = r1 * r2;
    float imgNumResult = -img1 * img2;
    float foilResult1 = img2 * r1;
    float foilResult2 = img1 * r2;
    float imaginaryResult = foilResult2 + foilResult1;
    float finalRealResult = realNumResult + imgNumResult;
        if (imaginaryResult == 0)
            cout << finalRealResult << endl;
        else
            cout << finalRealResult << (imaginaryResult > 0 ? "+" : "") << imaginaryResult << "i\n";
}

// Divides the 2 complex expressions by multiplying them by the conjugate of the denominator
void divideComplexNumbers(float r1, float img1, float r2, float img2){/*
    double realNum = (r1 * r2 + img1 * img2) / (pow(r2, 2) + pow(img2, 2));
    double imgNum = (img1 * r2 - img2 * r1) / (pow(r2, 2) + pow(img2, 2));
    cout << realNum << (imgNum > 0 ? "+" : "") << imgNum << "i\n";*/
    float temp = img2;
    img2 = -img2;
    float realNumResult = r1 * r2;
    float imgNumResult = -img1 * img2;
    float foilResult1 = img2 * r1;
    float foilResult2 = img1 * r2;
    float imaginaryResult = foilResult2 + foilResult1;
    float finalRealResult = realNumResult + imgNumResult;
    float temp2 = finalRealResult;
    float temp3 = imaginaryResult;
    img2 = temp;
    img1 = -img2;
    r1 = r2;
    realNumResult = r1 * r2;
    imgNumResult = -img1 * img2;
    finalRealResult = realNumResult + imgNumResult;
    cout << temp2/finalRealResult << (temp3 > 0 ? "+" : "") << temp3/finalRealResult << 'i' << endl;
}

// Finds and assigns the right values in the string to their proper values
void handleOperation(string& operation) {
    int plusSign1 = operation.find_first_of('+', 2);
    int minusSign1 = operation.find_first_of('-', 2);
    int signIndex1 = plusSign1 == -1 ? minusSign1 : minusSign1 == -1 ? plusSign1 : min(plusSign1, minusSign1);
    int iIndex1 = operation.find('i');
    float r1 = stof(operation.substr(1, signIndex1-1));   // value of the first real number
    float img1 = stof(operation.substr(signIndex1, iIndex1 - signIndex1));   // value of the first imaginary number
    int bracketIndex = operation.find('(', iIndex1);
    char op = operation[bracketIndex-1];   // operation (+, -, *, /)

    int plusSign2 = operation.find_first_of('+', bracketIndex+1);
    int minusSign2 = operation.find_first_of('-', bracketIndex+1);
    int signIndex2 = plusSign2 == -1 ? minusSign2 : minusSign2 == -1 ? plusSign2 : min(plusSign2, minusSign2);
    int iIndex2 = operation.find('i', signIndex2);
    float r2 = stof(operation.substr(bracketIndex+1, signIndex2 - bracketIndex-1));  // value of the second real number
    float img2 = stof(operation.substr(signIndex2, iIndex2 - signIndex2));    // value of the second imaginary number

    switch (op) {
        case '+':
        case '-':
            addOrSubtractComplexNumbers(op == '+', r1, img1, r2, img2);
        break;
        case '*':
            multiplyComplexNumbers(r1, img1, r2, img2);
            break;
        case '/':
            divideComplexNumbers(r1, img1, r2, img2);
            break;
        default:
            break;
    }
}

int main() {
    string input;
    cout << "Welcome habipi to FCAI Complex Calculator.\n";

    // A loop that continues unless the user chooses to exit the program
    while (input != "Exit" && input != "exit") {
        cout << "Please enter (a+bi) [+-/*] (c+di): Eg: (5+2i) - (2-5i) or \"Exit\"\n";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        input = regex_replace(input, regex("\\s+"), "");
        if (input == "exit")
            cout << "Thanks habipi for using FCAI Complex Number Calculator.\n Salam.";
        else if (isValidComplex(input)) {
            cout << "The output is: ";
            handleOperation(input);
        }else
            cout << "Invalid operand or missing brackets. Try again.";
    }
}