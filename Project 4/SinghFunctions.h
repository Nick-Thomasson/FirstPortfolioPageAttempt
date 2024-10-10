#ifndef _SINGHFUNCTIONS
#define _SINGHFUNCTIONS

#include <vector>
using namespace std;

#include "Ingredient.h"
#include "Recipe.h"

vector<Recipe> LoadRecipes();
void SaveRecipes( vector<Recipe>& recipes );

#endif
