#include <iostream>       // Provides input and output stream functionalities (e.g., std::cout for printing to the console and std::cin for user input)
#include <ctime>          // Contains functions for time and date operations (e.g., time() for getting the current time and localtime() for formatting time)
#include <cstdlib>        // Includes general utilities such as rand() and srand() for random number generation, as well as memory management functions
#include <vector>         // Provides the std::vector container, a dynamic array that can grow and shrink in size, useful for handling collections of elements
#include <algorithm>      // Contains common algorithms like find() for searching elements in containers and count() for counting occurrences
#include <windows.h>      // Windows-specific library that includes system functions like Sleep(), which pauses program execution for a specified time in milliseconds
#include <fstream>        // Provides file input and output classes such as std::ifstream (input file stream) and std::ofstream (output file stream) for file handling
#include <sstream>        // Allows manipulation of strings using stream functionality (e.g., std::stringstream for converting numbers to strings or parsing text)
#include <string>         // Defines the std::string class for handling and manipulating text as a series of characters
#include <limits>          // It is just for input validation for integers (Users can enter positive numbers only)

using namespace std;

void GameRules() 
{
    // Displaying the title for game rules
    cout << "Lottery Rules:" << endl;
    Sleep(1000);  // Short pause to improve the user experience
    
    // Rule 1: Age requirement
    cout << "1). Age Requirement: Players must be 18 or older." << endl;
    cout << endl;
    Sleep(1000);  // Short pause between each rule for readability

    // Rule 2: Ticket purchase
    cout << "2). Ticket Purchase: Players can buy one or more tickets at a time." << endl;
    cout << endl;
    Sleep(1000);

    // Rule 3: Number selection
    cout << "3). Number Selection: Choose 7 unique numbers between 1 and 49." << endl;
    cout << "\t - The 7th number is your Bonus Number." << endl;
    cout << "\t - The system will generate a set of 6 random numbers for each ticket." << endl;
    cout << endl;
    Sleep(1000);

    // Rule 4: Draw schedule
    cout << "4). Draw Schedule: Draws are conducted immediately after ticket purchase and saved to your ticket receipt file." << endl;
    cout << endl;
    Sleep(1000);

    // Displaying prize categories and rewards
    cout << "--------------------------------------" << endl;
    cout << "       LOTTO 6/49 LOTTERY PRIZES           " << endl;
    cout << "--------------------------------------" << endl;
    cout << " - 6 of 6 matches = Jackpot of $5,000,000.00" << endl;
    cout << " - 5 of 6 matches + Bonus Number = $75,236.00" << endl;
    cout << " - 5 of 6 matches = $1,064.00" << endl;
    cout << " - 4 of 6 matches = $91.00" << endl;
    cout << " - 3 of 6 matches = $10.00" << endl;
    cout << " - 2 of 6 matches + Bonus Number = $5.00" << endl;
    cout << " - 2 of 6 matches = FREE PLAY" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    Sleep(1000);

    // Encore game rules section
    cout << "6). Encore Rules:" << endl;
    cout << "\t - Encore is an optional 7-digit number generated for each ticket." << endl;
    cout << "\t - Players can play multiple Encore numbers if desired." << endl;
    cout << "\t - To win, the generated Encore number must match the player's Encore number from left to right." << endl;
    cout << endl;
    Sleep(1000);

    // Encore game prize categories section
    cout << "--------------------------------------" << endl;
    cout << "       ENCORE LOTTERY PRIZES           " << endl;
    cout << "--------------------------------------" << endl;
    Sleep(1000);
    
    // Right-to-left matching prizes
    cout << "Prizes for Matching from Right to Left:" << endl;
    cout << "Match 7 digits      : $1,000,000" << endl;
    cout << "Match last 6 digits : $100,000" << endl;
    cout << "Match last 5 digits : $1,000" << endl;
    cout << "Match last 4 digits : $100" << endl;
    cout << "Match last 3 digits : $10" << endl;
    cout << "Match last 2 digits : $5" << endl;
    cout << "Match last digit    : $2" << endl;
    cout << "Overall odds of winning any prize: 1 in 9.17" << endl;
    cout << endl;
    Sleep(1000);

    // Left-to-right matching prizes
    cout << "Prizes for Matching from Left to Right:" << endl;
    cout << "Match first 6 digits : $10,000" << endl;
    cout << "Match first 5 digits : $500" << endl;
    cout << "Match first 4 digits : $50" << endl;
    cout << "Match first 3 digits : $10" << endl;
    cout << "Match first 2 digits : $5" << endl;
    cout << "Overall odds of winning any prize: 1 in 9.17" << endl;
    cout << endl;
    Sleep(1000);

    // Combination prize categories
    cout << "Combination Prizes:" << endl;
    cout << "Match first 5 digits + last digit      : $502" << endl;
    cout << "Match first 4 digits + last 2 digits   : $55" << endl;
    cout << "Match first 4 digits + last digit      : $52" << endl;
    cout << "Match first 3 digits + last 3 digits   : $20" << endl;
    cout << "Match first 3 digits + last 2 digits   : $15" << endl;
    cout << "Match first 3 digits + last digit      : $12" << endl;
    cout << "Match first 2 digits + last 4 digits   : $105" << endl;
    cout << "Match first 2 digits + last 3 digits   : $15" << endl;
    cout << "Match first 2 digits + last 2 digits   : $10" << endl;
    cout << "Match first 2 digits + last digit      : $7" << endl;
    cout << "--------------------------------------" << endl;
    Sleep(1500);

    // Prize claiming and responsible play
    cout << "7). Prize Claim: Visit our website to claim your winnings." << endl;
    cout << endl;
    Sleep(1500);

    cout << "8). Responsible Play: Play within your budget and enjoy responsibly." << endl;
    cout << endl;
    Sleep(1000);
}


// Function to get the current date and time in a string format
string getCurrentDateTime()
{
    time_t now = time(0);  // Get the current time in seconds since epoch
    tm* ltm = localtime(&now);  // Convert to local time format
    stringstream ss;  // Create a string stream to format the date and time
    // Format the date and time as "YYYY-MM-DD HH:MM:SS"
    ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " "
       << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec;
    return ss.str();  // Return the formatted date and time as a string
}

// Function to save Lottery 649 receipt
void saveLottery649Receipt(const vector<std::vector<int>>& allLotteryNumber, const vector<int>& drawNumbers, int lotteryLines) {
    // Open a file named "Lottery649_Receipt.txt" for writing
    time_t now = time(0);
    tm* localTime = localtime(&now);

    // Format the time into a string
    ostringstream filename;
    filename << "LotteryReceipt_"
             << (localTime->tm_year + 1900) << "-"   // Year
             << (localTime->tm_mon + 1) << "-"       // Month
             << localTime->tm_mday << "_"            // Day
             << localTime->tm_hour << "-"            // Hour
             << localTime->tm_min << "-"             // Minute
             << localTime->tm_sec                    // Second
             << ".txt";                              // File extension

    // Open the file in write mode with the unique filename
    ofstream file(filename.str());    if (!file) {  // Check if the file opened successfully
        std::cerr << "Error: Could not open file for writing.\n";
        return;  // Exit function if file could not be opened
    }

    // Header section of the receipt with the game title and current date/time
    file << "LOTTO 6/49 RECEIPT\n";
    file << "Date & Time: " << getCurrentDateTime() << "\n\n";

    // Include a section with basic lottery rules
    file << "Lottery Rules:\n";
    file << "1. Age Requirement: Players must be 18 or older.\n";
    file << "2. Ticket Purchase: Players can buy one or more tickets.\n";
    file << "3. Number Selection: Choose 7 unique numbers between 1 and 49.\n";
    file << "4. Draw Schedule: Draws are conducted after ticket purchase.\n";
    file << "5. Prizes: Jackpot up to $5,000,000.\n\n";

    // Display generated lines for the ticket and mark the bonus number
    file << "Generated Lines and Results:\n";
    for (int line = 0; line < allLotteryNumber.size(); line++) {
        file << "\nLine " << line + 1 << ": ";
        for (int i = 0; i < allLotteryNumber[line].size(); i++) {
            if (i == allLotteryNumber[line].size() - 1)
                file << "(Bonus) ";  // Label the last number in each line as the "Bonus" number
            file << allLotteryNumber[line][i] << " ";  // Write each number
        }
    }

    // Display the draw numbers for comparison
    file << "\nDraw Numbers: ";
    for (int num : drawNumbers) {
        file << num << " ";  // Write each draw number
    }

    // Display the ticket price and total cost based on number of lines
    file << "\n\nTicket Price: $3.00 per line\n\n";
    file << "Total Ticket Price: $" << 3 * lotteryLines << ".00\n\n";

    // Add a note with prize claim information
    file << "Note : You can check and claim prizes on lotto649.com" << endl;

    file.close();  // Close the file to save the content
    cout << "\n\nLottery Receipt ticket saved to " << filename.str() << endl;

}

// Function to save Encore receipt
void saveEncoreReceipt(const vector<int>& encoreNumbers, const vector<int>& encoreDraw) {
    // Open a file named "Encore_Receipt.txt" for writing
    time_t now = time(0);
    tm* localTime = localtime(&now);

    // Format the time into a string
    std::ostringstream filename;
    filename << "EncoreReceipt_"
             << (localTime->tm_year + 1900) << "-"   // Year
             << (localTime->tm_mon + 1) << "-"       // Month
             << localTime->tm_mday << "_"            // Day
             << localTime->tm_hour << "-"            // Hour
             << localTime->tm_min << "-"             // Minute
             << localTime->tm_sec                    // Second
             << ".txt";                              // File extension

    // Open the file in write mode with the unique filename
    ofstream file(filename.str());
    // Header section of the receipt with the Encore title and current date/time
    file << "ENCORE RECEIPT\n";
    file << "Date & Time: " << getCurrentDateTime() << "\n\n";

    // Include a section with basic Encore game rules
    file << "Encore Rules:\n";
    file << "1. 7-digit number generated for each ticket.\n";
    file << "2. Players can play multiple Encore numbers.\n";
    file << "3. Match from left to right for prizes.\n\n";

    // Display the generated Encore number chosen by the player
    file << "Generated Encore Number: ";
    for (int num : encoreNumbers) {
        file << num;  // Write each digit of the Encore number
    }

    // Display the Encore draw number for comparison
    file << "\n\nEncore Draw Number: ";
    for (int num : encoreDraw) {
        file << num;  // Write each digit of the drawn Encore number
    }

    // Display the Encore ticket price and add note for prize claim information
    file << "\n\nEncore Ticket Price: $1.00 + line charge\n";
    file << "\nNote : You can check and claim prizes on lotto649.com" << endl;

    file.close();  // Close the file to save the content

    cout << "\n\nEncore Receipt ticket saved to " << filename.str() << endl;
}
    

// FUNCTION WHICH GREETS THE USER AND STARTS THE GAME
// Whole game is completed in a single function as multiple function were creating bugs and complication to the game.
void LotteryGame()
{
    //GREETINGS
    string userName;
    string userPastPlayed;
    cout << "Please Enter your name to begin: ";
    getline(cin, userName); // Take input of whole line instead of just first word. Reduces the chances of getting a bug or an error

    cout << "Hello " << userName << "! Hope you are doing well. Let's play LOTTO 6/49!" << endl;
    cout << "Have you played LOTTO 6/49 before?(yes/no)" << endl;
    getline(cin, userPastPlayed);

    for(int i = 0; i < userPastPlayed.size(); i++) //Convert user input to lower case for case-insensitive comparison
    {
        userPastPlayed[i] = tolower(userPastPlayed[i]);
    }
    
    while(userPastPlayed != "yes" && userPastPlayed != "no") //input validation
    {
        cout << "Please enter 'yes' or 'no' only!" << endl;
        cin >> userPastPlayed;

        for(int i = 0; i < userPastPlayed.size(); i++) //Convert user input to lower case for case-insensitive comparison 
        {
            userPastPlayed[i] = tolower(userPastPlayed[i]);
        }
    }
    if (userPastPlayed == "yes") //if-else condition to show rules according to user's answer
    {
        cout << "That's great! Still lets take a look at rules." <<  endl;
        Sleep(500);
        GameRules();
    }
    else
    {
        cout << "No problem, here's the list of rules you need to keep in mind." << endl;
        Sleep(500);
        GameRules();
    }


    int lotteryLines;
cout << "Let's start LOTTO 6/49!" << endl;

Sleep(500);  // Short pause for a better user experience
    while (true) {
        cout << "How many lines would you like to play?" << endl;
        cin >> lotteryLines;

        // Check if the input is a valid integer and in an acceptable range (e.g., greater than 0)
        if (cin.fail() || lotteryLines <= 0) {
            cout << "Invalid input. Please enter a positive number." << endl;

            // Clear the error flag on cin so further input can be processed
            cin.clear();

            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break; // Valid input; exit the loop
        }
    }

cout << "Okay! you need to pay $" << lotteryLines * 3 << ".00" << endl;
cout << "Let's generate your Lottery Numbers!" << endl;

// FOR LOOP TO SHOW LOADING ANIMATION
for(int i = 0; i < 4; i++) {
    cout << ".";  // Print dots to show loading effect
    Sleep(350);  // Short pause between each dot
}
cout << endl << endl;

srand(static_cast<unsigned int>(time(0)));  // Set a random seed based on the current time to get different results each time

vector<vector<int>> allLotteryNumber;  // Main vector to store all lines generated

// GENERATE NUMBERS FOR EACH LINE
for(int line = 0; line < lotteryLines; line++) {   
    vector<int> lotteryNumbers;  // Temporary vector to store numbers for each line

    // GENERATE 7 UNIQUE NUMBERS FOR THE LINE
    for(int i = 0; i < 7; i++) {
        int count;
        do {
            count = 1 + rand() % 49;  // Generate a number between 1 and 49
        } while (find(lotteryNumbers.begin(), lotteryNumbers.end(), count) != lotteryNumbers.end()); // Check if number is already in line
        lotteryNumbers.push_back(count);  // Add unique number to the line
    }

    allLotteryNumber.push_back(lotteryNumbers); // Add this line of numbers to the main vector
}

// DISPLAY THE GENERATED NUMBERS
for(int line = 0; line < allLotteryNumber.size(); line++) {
    Sleep(300);  // Pause before printing each line for effect
    cout << "\nLottery Numbers for line " << line + 1 << " are : ";
    for(int numIndex = 0; numIndex < allLotteryNumber[line].size(); numIndex++) {
        if(numIndex == (allLotteryNumber[line].size() - 1)) {  // Check if this is the last number (the bonus number)
            cout << "Bonus Number : ";
        }
        cout << allLotteryNumber[line][numIndex] << " ";
        Sleep(400);  // Pause between numbers for effect
    }
    cout << endl;
}

// ENCORE PLAY STARTS HERE
string playEncore;
cout << "\nDo you wanna play Encore?" << endl; // Ask if the user wants to play Encore
getline(cin, playEncore); // Get the user's answer
vector<int> encoreNumbers;  // Vector to store the Encore number

// VALIDATE INPUT FOR ENCORE GAME
while(playEncore != "yes" && playEncore != "no") { // Check for valid answer
    cout << "Please enter 'yes' or 'no' only!" << endl;
    cin >> playEncore;

    for(int i = 0; i < playEncore.size(); i++) {  // Convert answer to lowercase to avoid case issues
        playEncore[i] = tolower(playEncore[i]);
    }
}

if(playEncore == "yes") {  // If the user wants to play Encore
    int encoreDigit;
    Sleep(300);
    cout << "\nLet's generate your Encore number." << endl;
    
    for(int i = 0; i < 7; i++) {  // Generate a 7-digit Encore number
        encoreDigit = rand() % 10;  // Get a digit from 0-9
        encoreNumbers.push_back(encoreDigit); 
    }

    // FOR LOOP TO SHOW A LOADING ANIMATION
    for(int i = 0; i < 4; i++) {
        cout << ".";
        Sleep(350);  // Pause between each dot
    }
    cout << endl;

    // DISPLAY THE GENERATED ENCORE NUMBER
    cout << "Your Encore Number is : ";
    for(int i : encoreNumbers) {
        cout << i;
        Sleep(300);  // Pause between digits
    }
    cout << endl;
}
else if(playEncore == "no") {  // If the user does not want to play Encore
    cout << "No Worries!\n" << endl;
}

// MOVING FORWARD TO THE DRAW FOR WINNING NUMBERS
cout << "\nLet's move toward the PRIZES!" << endl;
Sleep(500);  // Short pause
cout << "\nLet's draw the lottery numbers!" << endl;

// LOADING ANIMATION
for(int i = 0; i < 4; i++) {
    cout << ".";
    Sleep(350);  // Pause between each dot
}
Sleep(500);

vector<int> drawNumbers;  // Vector to store drawn numbers

// GENERATE 6 UNIQUE DRAW NUMBERS
for(int i = 0; i < 6; i++) {
    int count;
    do {
        count = 1 + rand() % 49;  // Generate a number between 1 and 49
    } while (find(drawNumbers.begin(), drawNumbers.end(), count) != drawNumbers.end()); // Ensure unique numbers
    drawNumbers.push_back(count);
}

// DISPLAY THE DRAWN NUMBERS
cout << "\nDraw Numbers are : ";
for(int i : drawNumbers) {
    cout << i << " ";
    Sleep(300);  // Pause between each number for effect
}
cout << endl;

// DRAWING THE ENCORE WINNING NUMBER
Sleep(300);
cout << "Let's draw the Encore Winning Number : ";
vector<int> encoreDraw;  // Vector to store the drawn Encore number

for(int i = 0; i < 7; i++) {  // Generate 7 digits for the Encore draw number
    int drawEncoreDigit;
    drawEncoreDigit = rand() % 10;
    encoreDraw.push_back(drawEncoreDigit); 
}
for(int i : encoreDraw) {
    cout << i;
    Sleep(300);  // Pause between each digit
}
cout << endl << endl;

// STARTING TO COMPARE DRAW NUMBERS WITH GENERATED NUMBERS
cout << "\nLet's Compare the generated Lottery Numbers and the Draw numbers." << endl;

// SHOWING USER'S NUMBERS AND DRAW NUMBERS FOR EASY COMPARISON
cout << "\nDraw Numbers are : ";
for(int i : drawNumbers) {
    cout << i << " ";
}
cout << endl;

for(int line = 0; line < allLotteryNumber.size(); line++) {  // Display each line of user's numbers for comparison
    Sleep(300);
    cout << "\nLottery Numbers for line " << line + 1 << " are : ";
    for(int numIndex = 0; numIndex < allLotteryNumber[line].size(); numIndex++) {
        if(numIndex == (allLotteryNumber[line].size() - 1)) {
            cout << "Bonus : ";  // Label last number as Bonus
        }
        cout << allLotteryNumber[line][numIndex] << " ";
    }
    cout << endl;
}

// FOR LOOP TO CHECK IF USER HAS WON ANY PRIZES
for(int line = 0; line < allLotteryNumber.size(); line++) {
    Sleep(400);
    int mainMatches = 0;  // Counter for main matches
    bool bonusMatch = false;  // Flag for bonus match

    // COUNT MAIN MATCHES
    for(int numIndex = 0; numIndex < (allLotteryNumber[line].size() - 1); numIndex++) {
        if(find(drawNumbers.begin(), drawNumbers.end(), allLotteryNumber[line][numIndex]) != drawNumbers.end()) {
            mainMatches++;
        }
    }

    // CHECK IF BONUS NUMBER MATCHES
    int bonusNumber = allLotteryNumber[line].back();
    bonusMatch = find(drawNumbers.begin(), drawNumbers.end(), bonusNumber) != drawNumbers.end();
             
    // DISPLAY NUMBER OF MATCHES
    cout << endl << mainMatches << " main numbers matched in line " << line + 1;
    if(bonusMatch) {
        cout << " with a Bonus Number!";
    }
    cout << endl;

    // DETERMINE PRIZE BASED ON MATCHES
    if (mainMatches == 6) {
        cout << "Jackpot! You win $5,000,000.00" << endl;
    } else if (mainMatches == 5 && bonusMatch) {
        cout << "5 of 6 matches + Bonus Number! You win $75,236.00" << endl;
    } else if (mainMatches == 5) {
        cout << "5 of 6 matches! You win $1,064.00" << endl;
    } else if (mainMatches == 4) {
        cout << "4 of 6 matches! You win $91.00" << endl;
    } else if (mainMatches == 3) {
        cout << "3 of 6 matches! You win $10.00" << endl;
    } else if (mainMatches == 2 && bonusMatch) {
        cout << "2 of 6 matches + Bonus Number! You win $5.00" << endl;
    } else if (mainMatches == 2) {
        cout << "2 of 6 matches! You get a FREE PLAY" << endl;
    } else {
        cout << "No prize this time for line " << line + 1 << ". Better luck next draw!" << endl << endl;
    }
}

// CHECK ENCORE MATCHES
int encoreMatch = 0;

for (int i = 0; i < 7; i++) {
    if (encoreNumbers[i] == encoreDraw[i]) {
        encoreMatch++;  // Count matching digits
    }
}

cout << "Let's check your Encore winnings" << endl;

cout << encoreMatch << " Numbers Match. " << endl;  // Display number of matching Encore digits

// DETERMINE PRIZE BASED ON ENCORE MATCHES
switch (encoreMatch) {
case 1:
    cout << "Congrats, you won $2.00" << endl;
    break;
case 2:
    cout << "Congrats, you won $5.00" << endl;
    break;
case 3:
    cout << "Congratulations, you won $10.00" << endl;
    break;
case 4:
    cout << "Congratulations, you won $100.00" << endl;
    break;
case 5:
    cout << "Congratulations, you won $5000.00" << endl;
    break;
case 6:
    cout << "Congratulations, you won $100,000.00" << endl;
    break;
case 7:
    cout << "Congratulations, you won $1,000,000.00" << endl;
    break;
default:
    cout << "Sorry, No prize. Better Luck Next Time!" << endl; 
    break;
}

// Save LOTTO 6/49 receipt
saveLottery649Receipt(allLotteryNumber, drawNumbers, lotteryLines);

// Save Encore receipt
saveEncoreReceipt(encoreNumbers, encoreDraw);
}

int main()
{
    string userPlayAgain;  // Variable to store user's decision to play again or not
    LotteryGame();  // Start the lottery game once

    cout << "\n\nDo you want to play again?(yes/no)" << endl;
    getline(cin, userPlayAgain);  // Get user's response as a full line (handles spaces if present)

    // Convert user input to lowercase for consistent, case-insensitive comparison
    for(int i = 0; i < userPlayAgain.size(); i++) {
        userPlayAgain[i] = tolower(userPlayAgain[i]);
    }

    // Loop to validate the input, ensuring the user enters only "yes" or "no"
    while(userPlayAgain != "yes" && userPlayAgain != "no") {
        cout << "Please enter 'yes' or 'no' only!" << endl;
        getline(cin, userPlayAgain);  // Get the input again if invalid

        // Convert the response to lowercase again after re-entry
        for(int i = 0; i < userPlayAgain.size(); i++) {
            userPlayAgain[i] = tolower(userPlayAgain[i]);
        }
    }

    // If the user chose "yes", play the game again
    if (userPlayAgain == "yes") {
        LotteryGame();
    }
    else {  // Otherwise, thank the user and end the game
        cout << "No problem, Have a nice day!" << endl;
        Sleep(500);  // Small delay before closing for better user experience
    }
}