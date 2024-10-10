#ifndef _PROGRAM
#define _PROGRAM

#include <vector>
#include <string>
using namespace std;

#include "Recipe.h"

class Program
{
    public:
    void Run();

    void Menu_Main();
    void Menu_RecipesList();
    void Menu_ViewOneRecipe( Recipe recipe, float batches );
    void Menu_AddNewRecipes();
    void Menu_SaveRecipes();
    void Menu_SearchForRecipe();

    private:
    vector<Recipe> recipes;

    int GetChoice( int min, int max );
    void DisplayHeader( string text );
    void PressEnterToContinue();
};

#endif
