// File Name : John Cris S. San Jose
// Author : John Cris S. San Jose
// Email Address : jcsanjose@gbox.adnu.edu.ph
// ProgAss Number : 4
// Description : Password Validation
// Last Changed :   || November 1, 2023 || 5:42 PM ||

#include <iostream>
#include <string>
#include <cctype>

/*Validates the Password*/
bool PassValid(std::string Password)
{
    std::string SpecialCharacters = "$#@";
    bool HasLowCase = false, HasUpperCase = false, HasDigits = false, HasSpecialCharacter = false;
    /*Checks the length of the password from 6 to 12 characters*/
    if (Password.length() < 6 || Password.length() > 12)
    {
        std::cout << "Invalid. Password must contain 6 to 12 characters\n";
        return false;
    }
    /*Checks the password if it contains lower/high cases, digits and special characters */
    for (char p : Password)
    {
        if (islower(p)) // checks the lower case
        {
            HasLowCase = true;
        }
        else if (isupper(p)) // checks the upper case
        {
            HasUpperCase = true;
        }
        else if (isdigit(p)) // checks if the password has digit
        {
            HasDigits = true;
        }
        else if (SpecialCharacters.find(p) != std::string::npos) // npos was used to scan the string if it contains special characters from start to end
        {
            HasSpecialCharacter = true;
        }
    }

    if (HasLowCase && HasUpperCase && HasDigits && HasSpecialCharacter) // tracks all the elements to detect if the password is invalid
    {
        return true;
    }
    else
    {
        std::cout << "Invalid. Password must have at least 1 lower/upper case, digit, and special character (@,#,$)\n";
        return false;
    }
}

int main()
{
    std::string Password;
    std::cout << "===Create Password===\n";
    std::cout << "Enter Your Password\n";

    std::getline(std::cin, Password);

    if (PassValid(Password))
    {
        std::cout << "Password Accepted\n";
    }
    return 0;
}
