#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10        // Maximum number of questions for the quiz
#define PASSING_SCORE 80.0      // Passing score percentage

// GOAL of the program
// This program will take the input of the user and compare it with the correct answers.
// The program will display the user's grade at the end of each section of the test.
// If the overall grade is determined to be under 80%, the user fails and can choose to retry.
// If the user scores 80% or higher, they pass.
// This program will serve as a G1 practice test for new drivers and can serve as a refresher for older drivers.

// Structure to store question details
typedef struct {
    char question[512];         // Text of the question
    int correct_option;         // The correct answer option number
} Question;

// Function to check the user's answer
// Takes a Question structure and the user's answer as input, returns 1 if correct, 0 otherwise
int checkAnswer(Question q, int user_answer) {
    return (user_answer == q.correct_option);   // Compare user input with the correct option
}

// Function to calculate the percentage score
// Takes the total correct answers (score) as input and returns the percentage
float calculatePercentage(int score) {
    return ((float)score / MAX_QUESTIONS) * 100;    // Calculate percentage score
}

// Display the final score and determine if the user passed or failed
// Takes the user's score as input and prints the score and pass/fail message
void displayResult(int score) {
    float percentage = calculatePercentage(score);  // Calculate percentage score
    printf("Knowledge Section score: %d/%d\n", score, MAX_QUESTIONS);
    printf("Your percentage score: %.2f%%\n", percentage);

    // Check if the percentage score meets or exceeds the passing threshold
    if (percentage >= PASSING_SCORE)
    {
        printf("Congratulations! You passed the test.\n");
    }
    else
    {
        printf("Unfortunately, you did not pass. Try again!\n");
    }
}

// Function to display the main menu options to the user
void displayMenu()
{
    printf("\n=== G1 Driving Test Simulator ===\n");
    printf("1. Start Test\n");
    printf("2. View Instructions\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to display test instructions and allow the user to return to the menu
void displayInstructions()
{
    printf("\nInstructions:\n");
    printf("This test consists of multiple questions. For each question, you must select the correct option by entering the corresponding number.\n");
    printf("Your goal is to answer at least 80%% of the questions correctly to pass the test.\n");

    // Option to return back to the main menu after reading the instructions
    printf("\nPress any key followed by ENTER to return to the main menu: ");
    char temp;
    scanf(" %c", &temp);   // Waits for the user to input a character before returning to the menu
}

// Main function
int main(void) 
{
    int score = 0;           // Set the user's score to zero
    int choice;              // Variable to store the user's choice in the menu
    Question questions[MAX_QUESTIONS] = {    // Array of questions and correct answers
        {"If you are convicted of fleeing a police officer who signaled you to pull over, your licence will be suspended for:\n 1. 2 Years\n 2. 3 Years\n 3. 5 Years\n", 3},
        {"If the signal light changes from green to yellow (amber) as you approach an intersection, what should you do?:\n 1. Speed up to get past the yellow light before it turns red\n 2. Stop. If a stop cannot be made safely, proceed with caution\n", 2},
        {"If you change your name or address, you must notify the Ministry of Transportation within:\n 1. 45 Days\n 2. 16 Days\n 3. 14 Days\n", 3},
        {"Under what circumstances may a driver's licence be cancelled?:\n 1. For failure to attend re-examination\n 2. For possession of an altered driver's licence\n 3. All of the above\n", 3},
        {"At an intersection, the traffic light is red, but a police officer motions you to go through. What should you do?:\n 1. Go through\n 2. Tell the police officer the light is red\n 3. Wait for the light to turn green\n", 1},
        {"While driving on a two-way street, you hear the siren of an approaching emergency vehicle. What does the law require you to do?:\n 1. Signal the driver to pass\n 2. Continue at the same speed\n 3. Speed up and get out of the way\n 4. Pull over and stop\n", 4},
        {"A G2 driver age 19 or younger who has more than 6 months of driving experience may carry unrelated passenger(s) age 19 or younger between midnight and 5:00 a.m.:\n 1. 3\n 2. 4\n 3. 2\n 4. 1\n", 1},
        {"If one of your tires suddenly blows out while you're driving, what should you do?:\n 1. Bring the vehicle to a stop off-road\n 2. Take your foot off the gas pedal\n 3. Concentrate on steering\n 4. Do all of the above\n", 4},
        {"Drivers are prohibited from passing another vehicle within ____ from a pedestrian crossover:\n 1. 40 meters\n 2. 50 meters\n 3. 70 meters\n 4. 30 meters\n", 1},
        {"When you are in a roundabout:\n 1. Drive in a clockwise direction\n 2. You can stop\n 3. Drive in a counter-clockwise direction\n 4. You can change lanes\n", 3}
    };

    // Display the welcome message
    printf("Welcome to the G1 driving test, I am Roman.\n");
    printf("This test is comprised of three sections: knowledge, reaction time, and eyesight.\n");

    // Loop to continuously display the menu until the user chooses to exit
    do
    {
        displayMenu();        // Show the menu options
        scanf("%d", &choice); // Get the user's choice

        switch (choice)
        {
            case 1:
                // Start the test when the user selects option 1
                for (int i = 0; i < MAX_QUESTIONS; i++)
                {
                    int user_answer;
                    printf("%s", questions[i].question);   // Display the current question
                    printf("Enter your answer: ");
                    scanf("%d", &user_answer);             // Get the user's answer

                    // Check if the user's answer is correct and increment the score if so
                    if (checkAnswer(questions[i], user_answer))
                    {
                        score++;
                    }

                    // Confirm the user's answer and display it
                    printf("Your answer: %d\n\n", user_answer);
                }
                // Display the final result after all questions are answered
                displayResult(score);
                score = 0;   // Reset the score for future test attempts
                break;
            
            case 2:
                // Show the instructions when the user selects option 2
                displayInstructions();    // Allow the user to return to the menu afterward
                break;
            
            case 3:
                // Exit the program when the user selects option 3
                printf("Thank you for using the G1 driving test simulator. Goodbye!\n");
                break;

            default:
                // Display an error message for invalid input
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);   // Continue looping until the user selects option 3 to exit

    return 0;
}
