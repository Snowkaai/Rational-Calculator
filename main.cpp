// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Rational Number Calculator.cpp
// Program Description: Takes two rational numbers and perform operations on it
// Last Modification Date: 14/3/2022
// Author1 and ID and Group: Mohamed Waleed Mohamed / 20210362 / Group A
// Author2 and ID and Group: Mohamed Nabil / xxxxx / Group A
// Author3 and ID and Group: Hatem Mostafa / xxxxx / Group B
// Teaching Assistant: xxxxx xxxxx
// Purpose: Handles calculations of two rational +ve or -ve numbers and performs a selected operation on it


//need to add negative : done
// defense : fixed but have to enter a space before and after the operator  ?done?
// fix the division case: done
// divsion by zero : done


#include <bits/stdc++.h>

using namespace std;


// calculate the greatest common divisor so we can simplify 16/256 to 1/16 using recursion & euclidean algorithm
int GreatestCommonDivisor(int a, int b) {
    long long biggest = max(a, b);
    long long smallest = min(a, b);
    long long temp = biggest;
    biggest = smallest;
    smallest = temp % smallest;
    if (smallest == 0)
        return biggest;
    else
        GreatestCommonDivisor(smallest, biggest);
}


int main() {
    while (true) {
        string input, rational_1, rational_2; // stores the whole expression such as 15/5
        string numer_1, numer_2, denom_1, denom_2; // seperates the expression 15/5 to numerator 15 and denom 5
        long long numerator_1, numerator_2, denominator_1, denominator_2; // makes the denominator and numerator as integers
        long long totalNumerator, totalDenominator, remainder, gcd, size; // for cleaner look in switch cases
        char operatorType; // to find which switch case to use


        /* for example  1/4 + 3/4  if the operation counter = 1 (odd) then 1/4 and store it
         the  '+' between the 2 numbers gives counter = 2 (even) then this is our selected operation
        */
        int operatorCounter = 0;
        bool isValid = false;
        cout << "Please indicate the operator with a leading and a trailing space like \"1/5 + 1/5\" \n\n";
        cout << "Please enter a rational number operations (or exit): ";


        // check for invalid or bad input
        while (!isValid) {

            getline(cin, input);
            // helps identifying if there is another operator at the end 5 + 5 +

            if (input == "exit")
                return 0;
            operatorCounter = 0;
            size = input.size();
            for (int i = 0; i < size; i++) {
                // checks if input is a letter
                if (isalpha(input[i]))
                    isValid = false;

                // check if it doesnt have any reoccuring symbols like 5 ++ 5
                if (i < size - 1 && input[i] == input[i + 1])
                    if (input[i] == '/' || input[i] == '+' || input[i] == '-' || input[i] == '%' || input[i] == '*')
                        isValid = false;
            }
            //  check if 5+5 , 5 +5 , 5+ 5
            // i.e. user has to input 2 spaces, one before and one after the operator
            for (int i = 0; i < size - 2; i++)
                if (isspace(input[i]) &&
                    (input[i + 1] == '/' || input[i + 1] == '+' || input[i + 1] == '-' || input[i + 1] == '%' ||
                     input[i + 1] == '*') && isspace(input[i + 2]))
                    operatorCounter++;

            if (operatorCounter == 1)
                isValid = true;

            // check if it has any special character at the beginning or the end thgat is not a negative sign
            if ((!isdigit(input[0]) && (input[0] != '-') || !isdigit(input[size - 1])))
                isValid = false;

            if (!isValid)
                cout << "Invalid input, try again!\n" << endl;
        }


        // loop over the whole input
        size = input.size();
        operatorCounter = 0;
        for (int i = 0; i < size; i++) {
            if (isspace(input[i]) && operatorCounter == 0) {
                operatorCounter++;

                // get operator
                operatorType = input[i + 1];
                //cout << input[i+1];

                // get 1st rational number
                for (int j = 0; j < i; j++)
                    rational_1 += input[j];

                // get 2nd rational number
                for (int j = i + 3; j < size; j++)
                    rational_2 += input[j];
            }

        }


        // get the numerator and denominator if exists in the 1st rational.
        operatorCounter = 0;
        size = rational_1.size();
        for (int i = 0; i < size; ++i) {
            if (rational_1[i] == '/')
                operatorCounter++;

            if (operatorCounter == 0 &&
                (isdigit(rational_1[i]) || rational_1[i] == '-')) // if operator counter = 0 then numerator
                numer_1 += rational_1[i];

            else if (operatorCounter == 1 &&
                     (isdigit(rational_1[i]) || rational_1[i] == '-'))// if operator counter = 1 then denominator
                denom_1 += rational_1[i];
        }
        if (operatorCounter == 0) // if there wasn't denominator in expression like 5  then we assume it is 5/1
            denom_1 = "1";

        // get the numerator and denominator if exists in the 2nd rational.
        operatorCounter = 0;
        size = rational_2.size();
        for (int i = 0; i < size; ++i) {
            if (rational_2[i] == '/')
                operatorCounter++;
            if (operatorCounter == 0 &&
                (isdigit(rational_2[i]) || rational_2[i] == '-'))// if operator counter = 0 then numerator
                numer_2 += rational_2[i];

            else if (operatorCounter == 1 &&
                     (isdigit(rational_2[i]) || rational_2[i] == '-'))// if operator counter = 1 then denominator
                denom_2 += rational_2[i];
        }
        if (operatorCounter == 0) // if there wasn't denominator in expression like 5  then we assume it is 5/1
            denom_2 = "1";

        // assign the numer and denom for both rationals to integers using stoi built-in function
        numerator_1 = stoi(numer_1);
        numerator_2 = stoi(numer_2);
        denominator_1 = stoi(denom_1);
        denominator_2 = stoi(denom_2);



        //                                      used for testing                                                     //
        //cout << numerator_1 << "\n" << numerator_2 << "\n" <<denominator_1 << "\n" << denominator_2 << "\n" << endl;
        //cout << numer_1 << "\n" << numer_2 << "\n" <<denom_1 << "\n" << denom_2 << "\n" << endl;
        //cout << rational_1 << endl;
        //cout << rational_2 << endl;
        //cout << numerator_1 << endl;
        //cout << operatorType << endl;




        switch (operatorType) {
            case '+': // case works, (needs updates to make 16/16 =  1 , 17/16 = 1 1/16, 544/289 = 32/17)

                totalDenominator = denominator_1 * denominator_2;
                totalNumerator = numerator_1 * denominator_2 + numerator_2 * denominator_1;

                if (totalDenominator == 0) // check for division by zero error
                    cout << "Invalid input, Division by zero!\n" << endl;

                else  // calculates the remainder here to avoid the division by zero error
                    remainder = totalNumerator % totalDenominator;

                if (remainder == 0) // to print 16/16 as 1
                    cout << " = " << totalNumerator / totalDenominator << endl;

                else if (totalNumerator > totalDenominator) { // to simplify 5/3 to 1 2/3
                    gcd = GreatestCommonDivisor(remainder, totalDenominator);
                    cout << " = " << totalNumerator / totalDenominator << " " << remainder / gcd << "/"
                         << totalDenominator / gcd
                         << endl;

                } else { // to print the number as fraction without changes if it is smaller than 1
                    gcd = GreatestCommonDivisor(totalDenominator, totalNumerator);
                    cout << " = " << totalNumerator / gcd << "/" << totalDenominator / gcd << endl;
                }
                break;

            case '-': // case works
                totalDenominator = denominator_1 * denominator_2;
                totalNumerator = numerator_1 * denominator_2 - numerator_2 * denominator_1;

                if (totalDenominator == 0) // check for division by zero error
                    cout << "Invalid input, Division by zero!\n" << endl;

                else // calculates the remainder here to avoid the division by zero error
                    remainder = totalNumerator % totalDenominator;

                if (remainder == 0) // to print 16/16 as 1
                    cout << " = " << totalNumerator / totalDenominator << endl;

                else if (totalNumerator > totalDenominator) { // to simplify 5/3 to 1 2/3
                    gcd = GreatestCommonDivisor(remainder, totalDenominator);
                    cout << " = " << totalNumerator / totalDenominator << " " << remainder / gcd << "/"
                         << totalDenominator / gcd
                         << endl;

                } else { // to print the number as fraction without changes if it is smaller than 1
                    gcd = GreatestCommonDivisor(totalDenominator, totalNumerator);
                    cout << " = " << totalNumerator / gcd << "/" << totalDenominator / gcd << endl;
                }
                break;

            case '/': // case doesnt work, needs updates
                totalDenominator = numerator_2 * denominator_1;
                totalNumerator = numerator_1 * denominator_2;

                if (totalDenominator == 0) // check for division by zero error
                    cout << "Invalid input, Division by zero!\n" << endl;

                else // calculates the remainder here to avoid the division by zero error
                    remainder = totalNumerator % totalDenominator;

                if (remainder == 0) // to print 16/16 as 1
                    cout << " = " << totalNumerator / totalDenominator << endl;

                else if (totalNumerator > totalDenominator) { // to simplify 5/3 to 1 2/3
                    gcd = GreatestCommonDivisor(remainder, totalDenominator);
                    cout << " = " << totalNumerator / totalDenominator << " " << remainder / gcd << "/"
                         << totalDenominator / gcd
                         << endl;
                } else { // to print the number as fraction without changes if it is smaller than 1
                    gcd = GreatestCommonDivisor(totalDenominator, totalNumerator);
                    cout << " = " << totalNumerator / gcd << "/" << totalDenominator / gcd << endl;
                }
                break;

            case '*': // case works
                totalDenominator = denominator_1 * denominator_2;
                totalNumerator = numerator_1 * numerator_2;

                if (totalDenominator == 0) // check for division by zero error
                    cout << "Invalid input, Division by zero!\n" << endl;

                else // calculates the remainder here to avoid the division by zero error
                    remainder = totalNumerator % totalDenominator;

                if (remainder == 0) // to print 16/16 as 1
                    cout << " = " << totalNumerator / totalDenominator << endl;

                else if (totalNumerator > totalDenominator) { // to simplify 5/3 to 1 2/3
                    gcd = GreatestCommonDivisor(totalDenominator, remainder);
                    cout << " = " << totalNumerator / totalDenominator << " " << remainder / gcd << "/"
                         << totalDenominator / gcd
                         << endl;
                } else { // to print the number as fraction without changes if it is smaller than 1
                    gcd = GreatestCommonDivisor(totalDenominator, totalNumerator);
                    cout << " = " << totalNumerator / gcd << "/" << totalDenominator / gcd << endl;
                }
                break;

            case '%': // case works

                if (denominator_1 == 1 && denominator_2 == 1 && numerator_2 != 0)
                    cout << " = " << numerator_1 % numerator_2 << endl;
                else
                    cout << "\nInvalid operands. Try again.\n" << endl;
                break;

            default:
                cout << "\nInvalid operation. Try again.\n" << endl;
                break;
        }
    }

    cout << "Thank you for using rational number calculator";
    return 0;

}
