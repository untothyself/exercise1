/**
 * @file Lab1_Ahassan124.cpp
 * @author Abass Hassan
 * @date 2026-10-15
 * @brief Checks whether a 12-digit UPC-A barcode has a valid check digit.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Checks that a UPC contains exactly 12 digits.
 * @param upc The UPC entered by the user.
 * @return True for 12 digits, otherwise false.
 */
bool hasTwelveDigits(string upc)
{
    if (upc.length() != 12)
    {
        return false;
    }

    // Check each character so letters cannot be used as barcode digits.
    for (int i = 0; i < 12; i++)
    {
        if (upc[i] < '0' || upc[i] > '9')
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Calculates the UPC-A check digit using the first 11 digits.
 * @param upc A 12-digit UPC stored as a string.
 * @return The expected check digit (0 through 9).
 */
int calculateCheckDigit(string upc)
{
    int oddSum = 0;
    int evenSum = 0;

    // The first digit is at index 0. Leave out index 11 (the check digit).
    for (int i = 0; i < 11; i++)
    {
        int digit = upc[i] - '0';

        if (i % 2 == 0)
        {
            oddSum += digit;
        }
        else
        {
            evenSum += digit;
        }
    }

    int total = (oddSum * 3) + evenSum;
    int remainder = total % 10;

    if (remainder == 0)
    {
        return 0;
    }

    return 10 - remainder;
}

/**
 * @brief Checks whether a UPC is correctly formatted and has the right check digit.
 * @param upc The barcode number to check.
 * @return True if the UPC is valid, otherwise false.
 */
bool isValidUPC(string upc)
{
    if (!hasTwelveDigits(upc))
    {
        return false;
    }

    int enteredCheckDigit = upc[11] - '0';
    int calculatedCheckDigit = calculateCheckDigit(upc);

    return enteredCheckDigit == calculatedCheckDigit;
}

/**
 * @brief Repeatedly asks for UPC codes until the user chooses to quit.
 * @return Zero when the program finishes.
 */
int main()
{
    string answer;
    string upc;

    while (true)
    {
        cout << "Do you have a UPC number to test? (y/n): ";
        if (!getline(cin, answer))
        {
            break;
        }

        if (answer == "n" || answer == "N")
        {
            break;
        }

        if (answer != "y" && answer != "Y")
        {
            cout << "Please enter y or n.\n\n";
            continue;
        }

        cout << "Enter the 12-digit UPC-A code: ";
        if (!getline(cin, upc))
        {
            break;
        }

        if (!hasTwelveDigits(upc))
        {
            cout << "Invalid UPC. Please enter exactly 12 digits.\n\n";
        }
        else if (isValidUPC(upc))
        {
            cout << "UPC code " << upc << " is valid.\n\n";
        }
        else
        {
            cout << "UPC code " << upc << " is invalid.\n\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
