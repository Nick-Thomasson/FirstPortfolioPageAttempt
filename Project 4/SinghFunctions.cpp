#include "SinghFunctions.h"

#include <fstream>
#include <string>
using namespace std;

vector<Recipe> LoadRecipes()
{
    vector<Recipe> recipes;
    ifstream input( "recipe-data.txt" );

    Recipe new_recipe;
    Ingredient new_ing;
    string buffer;

    while ( getline( input, buffer ) )
    {
        if ( buffer == "RECIPE END" )
        {
            recipes.push_back( new_recipe );
            new_recipe.ingredients.clear();
        }
        else if ( buffer == "INGREDIENT END" )
        {
            new_recipe.ingredients.push_back( new_ing );
        }
        else if ( buffer == "RECIPE NAME" )
        {
            getline( input, new_recipe.name );
        }
        else if ( buffer == "RECIPE URL" )
        {
            getline( input, new_recipe.url );
        }
        else if ( buffer == "INGREDIENT NAME" )
        {
            getline( input, new_ing.name );
        }
        else if ( buffer == "INGREDIENT UNIT" )
        {
            getline( input, new_ing.unit );
        }
        else if ( buffer == "INGREDIENT AMOUNT" )
        {
            input >> new_ing.amount;
            input.ignore();
        }
    }

    return recipes;
}

void SaveRecipes( vector<Recipe>& recipes )
{
    ofstream output( "recipe-data.txt" );

    for ( auto& rec : recipes )
    {
        output << "RECIPE BEGIN" << endl << endl;

        output << "RECIPE NAME" << endl << rec.name << endl;
        output << "RECIPE URL"  << endl << rec.url << endl;

        output << string( 40, '-' ) << endl;
        for ( auto& ing : rec.ingredients )
        {
            output << "INGREDIENT BEGIN" << endl << endl;

            output << "INGREDIENT NAME"   << endl << ing.name << endl;
            output << "INGREDIENT UNIT"   << endl << ing.unit << endl;
            output << "INGREDIENT AMOUNT" << endl << ing.amount << endl;

            output << endl << "INGREDIENT END"   << endl;
            output << string( 40, '-' ) << endl;
        }

        output << endl << "RECIPE END" << endl;
        output << string( 80, '-' ) << endl;
    }

    output.close();
}
