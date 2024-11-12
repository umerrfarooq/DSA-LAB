#include <iostream>
#include <cctype>
using namespace std;

struct Person {
    int age;
    double height;
    double weight;
    char gender;
    char activityLevel;
    char weightGoal;
    double activityMultiplier;
    double bmr;
    double tdee;
    double protein;
    double fats;
    double carbs;
};

void calculateNutrition(Person& person) {
    // Calculate BMR (Basal Metabolic Rate) using Mifflin-St Jeor Equation
    person.gender = toupper(person.gender);

    bool validInput = true;  

    if (person.gender != 'M' && person.gender != 'F') {
        cout << "\t\t       Invalid gender selection. Exiting." << endl;
        validInput = false;  
    }

    if (validInput) {
        if (person.gender == 'M') {
            person.bmr = 10 * person.weight + 6.25 * person.height - 5 * person.age + 5;
        }
        else if (person.gender == 'F') {
            person.bmr = 10 * person.weight + 6.25 * person.height - 5 * person.age - 161;
        }
    }

    if (validInput) {
        cout << "\t\t+--------------------------------------------------------------------------+\n";
        cout << "\t\t|                    Choose Your Activity Level                            |\n";
        cout << "\t\t+--------------------------------------------------------------------------+\n";
        cout << "\t\t| Press (S) For sedentary (little or no exercise)                          |\n";
        cout << "\t\t| Press (L) Lightly active (light exercise/sports 1-3 days/week)           |\n";
        cout << "\t\t| Press (M) For Moderately active (moderate exercise/sports 3-5 days/week) |\n";
        cout << "\t\t| Press (V) For Very active (hard exercise/sports 6-7 days a week)         |\n";
        cout << "\t\t+--------------------------------------------------------------------------+\n";
        cout << "\t\t                       Choose an option: ";
        cin >> person.activityLevel;


        // Adjust BMR based on activity level
        person.activityLevel = toupper(person.activityLevel);
        if (person.activityLevel != 'S' && person.activityLevel != 'L' && person.activityLevel != 'M' && person.activityLevel != 'V') {
            cout << "\t\t           Invalid activity level. Exiting." << endl;
            validInput = false;  
        }
        else {
            switch (person.activityLevel) {
            case 'S':
                person.activityMultiplier = 1.2;
                break;
            case 'L':
                person.activityMultiplier = 1.375;
                break;
            case 'M':
                person.activityMultiplier = 1.55;
                break;
            case 'V':
                person.activityMultiplier = 1.725;
                break;
            default:
                break;
            }
        }
    }

    if (validInput) {
        cout << "\t\t +------------------------------------------------------------------+\n";
        cout << "\t\t |                   Choose Your Weight Goal                        |\n";
        cout << "\t\t +------------------------------------------------------------------+\n";
        cout << "\t\t | Press (G) For weight gain                                        |\n";
        cout << "\t\t | Press (L) For weight loss                                        |\n";
        cout << "\t\t | Press (M) For weight maintenance                                 |\n";
        cout << "\t\t +------------------------------------------------------------------+\n";
        cout << "\t\t                     Choose an option: ";
        cin >> person.weightGoal;


        // Adjust BMR based on weight goal
        person.weightGoal = toupper(person.weightGoal);
        if (person.weightGoal != 'G' && person.weightGoal != 'L' && person.weightGoal != 'M') {
            cout << "\t\t            Invalid weight goal. Exiting." << endl;
            validInput = false;  
        }
        else {
            if (person.weightGoal == 'G') {
                // To gain weight, add a calorie surplus
                person.tdee = person.bmr * person.activityMultiplier + 500;
            }
            else if (person.weightGoal == 'L') {
                // To lose weight, create a calorie deficit
                person.tdee = person.bmr * person.activityMultiplier - 500;
            }
            else if (person.weightGoal == 'M') {
                person.tdee = person.bmr * person.activityMultiplier;
            }

            // Calculate total daily calories based on activity level
            person.protein = 2.2 * person.weight;                                          // 2.2g of protein per kg of body weight
            person.fats = 0.3 * person.tdee / 9;                                           // 30% of total calories from fats
            person.carbs = (person.tdee - (person.protein * 4) - (person.fats * 9)) / 4;  // Remaining calories from carbs
        }
    }
}

void displayNutrition(const Person& person) {
    // Display results
    cout << "\t\t+------------------------------------------------------------------+\n";
    cout << "\t\t|                              Results                             |\n";
    cout << "\t\t+------------------------------------------------------------------+\n";
    cout << "\t\t                 Total Daily Calories: " << person.tdee << " kcal\n";
    cout << "\t\t                 Protein: " << person.protein << " g\n";
    cout << "\t\t                 Carbs: " << person.carbs << " g\n";
    cout << "\t\t                 Fats: " << person.fats << " g\n";
    cout << "\t\t+------------------------------------------------------------------+\n";
}

void menu() {
    cout << "\t\t+----------------------------------------------------------------+\n";
    cout << "\t\t|                       Nutrition Calculator                     |\n";
    cout << "\t\t+----------------------------------------------------------------+\n";
    cout << "\t\t|  Press 1 to Enter Personal Information and Calculate Nutrition |\n";
    cout << "\t\t|  Press 2 to Display Nutrition Information                      |\n";
    cout << "\t\t|  Press 3 to Calculate Again or Display Previous Information    |\n";
    cout << "\t\t|  Press 4 to Exit                                               |\n";
    cout << "\t\t+----------------------------------------------------------------+\n";
    cout << "\t\t                         Choose an option: ";
}

int main() {
    int choice;
    Person person[10] = { 0 };
    int membershipID = 0;
    int subChoice = 0;

    while (true) {
        cout << "\t\t+------------------------------------------------------------------+\n";
        cout << "\t\t|                          Membership ID                           |\n";
        cout << "\t\t+------------------------------------------------------------------+\n";
        cout << "\t\t                                                                    \n";
        cout << "\t\t                        Enter Membership ID: ";


        cin >> membershipID;
        cout << "\t\t                                                                    \n";
        if (membershipID < 0 || membershipID >=10) {
            cout << "\t\t Invalid membership ID. Please enter a valid ID between 0 and 9.\n";
            continue;  
        }
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\t\t+------------------------------------------------------------------+\n";
            cout << "\t\t|                     Enter Personal Information                   |\n";
            cout << "\t\t+------------------------------------------------------------------+\n";
            cout << "\t\t| Enter age:                                                       |\n";
            cout << "\t\t| Enter height (in cm):                                            |\n";
            cout << "\t\t| Enter weight (in kg):                                            |\n";
            cout << "\t\t| Select Your Gender:                                              |\n";
            cout << "\t\t+------------------------------------------------------------------+\n";
            cout << "\t\t               Enter age: ";
            cin >> person[membershipID].age;
            cout << "\t\t               Enter height (in cm): ";
            cin >> person[membershipID].height;
            cout << "\t\t               Enter weight (in kg): ";
            cin >> person[membershipID].weight;
            cout << "\t\t               Press (M) for male or (F) for female (M/F): ";
            cin >> person[membershipID].gender;
            cout << "\t\t+------------------------------------------------------------------+\n";
            calculateNutrition(person[membershipID]);
            break;
        case 2:
            displayNutrition(person[membershipID]);
            break;
        case 3:
            // Option to calculate again or display previous information
            cout << "\t\t+------------------------------------------------------------------+\n";
            cout << "\t\t|        Enter 1 to Calculate Again or 2 to Display Previous       |\n";
            cout << "\t\t+------------------------------------------------------------------+\n";
            cout << "\t\t|                      Information:                                |\n";
            cout << "\t\t+------------------------------------------------------------------+\n";
            cout << "\t\t                         Choose an option: ";
            cin >> subChoice;


            if (subChoice == 1) {
                
                calculateNutrition(person[membershipID]);
            }
            else if (subChoice == 2) {
                
                displayNutrition(person[membershipID]);
            }
            else {
                cout << "Invalid choice.\n";
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    return 0;
}