#include "Program.h"

#include "SinghFunctions.h"

#include <iostream>
#include <fstream>
using namespace std;

void Program::Run()
{
    recipes = LoadRecipes();
    Menu_Main();
    SaveRecipes( recipes );
}

void Program::Menu_Main()
{
    bool running = true;
    while ( running )
    {
        DisplayHeader( "RECIPES" );
        for ( size_t i = 0; i < recipes.size(); i++ )
        {
            cout << " " << recipes[i].name << endl;
        }

        DisplayHeader( "MAIN MENU" );

        cout << " 0. Quit program" << endl;
        cout << " 1. View recipe" << endl;
        cout << " 2. Save recipes to text file" << endl;
        cout << " 3. Add new recipe" << endl;
        cout << " 4. Search for a recipe" << endl;

        cout << " --> Where do you want to go? ";
        int choice = GetChoice( 0, 4 );

        switch( choice )
        {
            case 0: running = false; break;
            case 1: Menu_RecipesList() ; break;
            case 2: Menu_SaveRecipes(); break;
            case 3: Menu_AddNewRecipes(); break;
            case 4: Menu_SearchForRecipe(); break;
        }
    }
}

void Program::Menu_RecipesList()
{
    DisplayHeader( "VIEW RECIPE" );

    cout << " 0. GO BACK" << endl;
    for ( size_t i = 0; i < recipes.size(); i++ )
    {
        cout << " " << i+1 << ". " << recipes[i].name << endl;
    }

    cout << endl << " --> Which recipe? ";
    int choice = GetChoice( 0, recipes.size() );
    if ( choice == 0 ) { return; }
    int index = choice - 1;

    float batches;
    cout << " --> How many batches would you like to make? ";
    cin >> batches;

    cout << endl;

    Menu_ViewOneRecipe( recipes[ index ], batches );
    PressEnterToContinue();
}

void Program::Menu_ViewOneRecipe( Recipe recipe, float batches )
{
    DisplayHeader( recipe.name );
    cout << "From " << recipe.url << endl << endl;
    cout << "INGREDIENTS" << endl;

    for ( auto& ing : recipe.ingredients )
    {
        cout << "- " << ing.amount << " "
             << ing.unit << " of "
             << ing.name << endl;
    }
    cout << string( 80, '-' ) << endl;
}

void Program::Menu_AddNewRecipes()
{
    DisplayHeader( "NEW RECIPE" );

    Recipe new_recipe;
    Ingredient new_ing;

    // Ask the user to enter the recipe name and url; store in the appropriate member variables.
    cin.ignore();
    cout << " --> Enter new recipe name: ";
    getline( cin, new_recipe.name );
    cout << " --> Enter URL: ";
    getline( cin, new_recipe.url );

    int total_ings;
    cout << " --> How many ingredients? ";
    cin >> total_ings;
    cin.ignore();

    for (int i = 1; i <= total_ings; i++) {
        cout << "INGREDIENT #" << i << endl;
        cout << "Please enter the ingredient name:" << endl;
        cin >> new_ing.name;
        cout << "Please enter the measurement unit:" << endl;
        cin >> new_ing.unit;
        cout << "Please enter the amount:" << endl;
        cin >> new_ing.amount;
        new_recipe.ingredients.push_back(new_ing);
    }






    recipes.push_back( new_recipe );

    cout << endl << " New recipe added." << endl;
    PressEnterToContinue();
}

void Program::Menu_SaveRecipes()
{
    DisplayHeader( "PRINT RECIPES" );

    cout << " Enter a filename for your output: ";
    string filename;
    cin.ignore();
    getline( cin, filename );

    // Save the recipes out to a file
    ofstream output( filename );

    // Use a for loop to iterate over all your recipes. Use "r" as a counter variable.
    // Start "r" at 0, loop while r < recipes.size(), increment r by 1 each time.
    // Within the loop, output the recipe's number, name, and url. Then display "Ingredients:".
    // Utilize a second for loop that uses "i" as the counter variable.
    // Start "i" at 0, loop while i < recipes[r].ingredients.size(). Increment i by 1 each time.
    // Within the second while loop, output the ingredient's amount, unit, and name.
    for (int i = 0; i < recipes.size(); i++) {
        output << "Recipe Name: " << i << ". " << recipes[i].name << endl;
        output << "Recipe URL: " << i << ". " << recipes[i].url << endl;
        for (int j = 0; j < recipes[i].ingredients.size(); j++) {
            output << "Ingredient name: " << recipes[i].ingredients[j].name << endl;
            output << "Ingredient amount: " << recipes[i].ingredients[j].amount << endl;
            output << "Ingredient Unit: " << recipes[i].ingredients[j].unit << endl;
        }
    }




    output.close();

    cout << " File saved." << endl;
    PressEnterToContinue();
}

void Program::Menu_SearchForRecipe()
{
	DisplayHeader("SEARCH FOR RECIPE");

	cout << "Enter part of recipe name to search for: ";
	string find_me;
	cin.ignore();
	getline(cin, find_me);

	cout << endl << "RESULTS" << endl;

	// Use a for loop with counter variable r. Start at 0 and go while r < recipes.size(), increment r by 1 each time.
	// Inside the loop: `if recioes[r].name.find( find_me ) != string::npos` , then we found the text. Display the recipe name and the ingredients list.

	for (int r = 0; r < recipes.size(); r++) {
		if (recipes[r].name.find(find_me) != string::npos) {
			cout << "Recipe name: " << recipes[r].name << endl;
			cout << "Recipe URL: " << recipes[r].url << endl;
			cout << "Ingredients:" << endl;
            for (int n = 0; n < recipes[r].ingredients.size(); n++) {
                cout << recipes[r].ingredients[n].name;
                cout << recipes[r].ingredients[n].amount;
                cout << recipes[r].ingredients[n].unit;
            }

		}
	}



	PressEnterToContinue();
}

int Program::GetChoice( int min, int max )
{
    int choice;
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection! Try again!" << endl;
        cout << " --> ";
        cin >> choice;
    }

    return choice;
}

void Program::DisplayHeader( string text )
{
    cout << string( 5, '\n' );
    cout << string( 80, '#' ) << endl;
    cout << '#' << " " << text << " " << '#' << endl;
    cout << string( text.size() + 4, '#' ) << endl;
}

void Program::PressEnterToContinue()
{
    cout << endl << endl;
    cout << " --> Press ENTER to continue" << endl;
    string asdf;
    cin.ignore();
    getline( cin, asdf );
}

