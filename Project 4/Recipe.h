#ifndef _RECIPE
#define _RECIPE

#include <vector>
#include <string>
using namespace std;

#include "Ingredient.h"

struct Recipe
{
  string name;
  string url;

  vector<Ingredient> ingredients;
};

#endif
