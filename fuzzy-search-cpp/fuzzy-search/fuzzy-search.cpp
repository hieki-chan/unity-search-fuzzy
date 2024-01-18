// fuzzy-search by hieki-chan
// https://github.com/hieki-chan
// Note: we cannot use std:string c ++ are passed from c#. see more: https://stackoverflow.com/questions/28061637/how-to-pass-string-parameters-between-c-and-c?fbclid=IwAR3O15A_jKYSkFGwR56ZcXaJbeKAZQa0bd2yRpVoIzrKScNWfDEASnkLWfo#:~:text=For%20strings%20that%20are%20input,strings%20from%20C%2B%2B%20to%20C%23

#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "fuzzy-search.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int gramSize = 2;

/// <summary>
/// Remove all spaces and convert to lowercase
/// </summary>
/// 
///<example>
/// "fuzzy search" -> "fuzzysearch"
///</example>
string cleanString(string str)
{
    // Replace all spaces with empty string
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    // Convert the string to lowercase
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str;
}

/// <summary>
/// Get n grams
/// </summary>
/// 
/// <example>
/// "fuzzysearch" -> {"fu", "uz", "zz", "zy", "ys", "se", "ea", "ar", "rc", "ch"}
/// </example>
map<string, double> nGrams(string str)
{
    // key is ngram, value is the count of that ngram
    map<string, double> n_grams;
    auto length = str.length() - gramSize;

    for (int i = 0; i <= length; i++)
    {
        //get n-gram string
        string s = str.substr(i, gramSize);

        // if value is null, we count it is 1
        // if the value is not null (duplicate keys) so we add 1 to it as the cout++
        // and then we will get cout of the key
        if (n_grams[s] == NULL)
        {
            n_grams[s] = 1.0f;
        }
        else
            n_grams[s]++;
    }

    return n_grams;
}

/// <summary>
/// Get magnitude of the ngram
/// </summary>
/// <param name="map"></param>
/// <returns></returns>
double magnitude(map<string, double> ngram)
{
    double total = 0;
    for (const auto& pair : ngram)
    {
        total += ngram[pair.first] * ngram[pair.first];
    }

    return total / 2;
}

/// <summary>
/// Count number of occurrences of a given substring in a string
/// </summary>
int count(const char* str, const char* val)
{
    int _count = 0;

    const char* tmp = str;

    while (tmp = strstr(tmp, val)) {
        ++_count;
    }
    return _count;
}

/// <summary>
/// Calculate the similarity between two strings
/// </summary>
/// <returns> the similarity value in range [0,1]</returns>
double ratio(const char* str1, const char* str2)
{
    if (str1 == str2)   //the same string
        return 1.0;

    auto str1Size = strlen(str1);
    auto str2Size = strlen(str2);

    //both strings are too short (shorter than gramSize)
    if (str1Size < gramSize || str2Size < gramSize)
    {
        return str1Size > str2Size ? static_cast<double>(count(str1, str2)) / str1Size : static_cast<double>(count(str2, str1)) / str2Size;
    }

    map<string, double> ngramsStr1 = nGrams(cleanString(str1));
    map<string, double> ngramsStr2 = nGrams(cleanString(str2));

    double matchedCount = 0;

    for (const auto& pair : ngramsStr1)
    {
        if (ngramsStr2[pair.first])
        {
            //calculate matched count
            matchedCount += ngramsStr1[pair.first] * ngramsStr2[pair.first];
        }
    }

    //the result is matched count / total magnitude of 2 ngram strings
    return matchedCount / (magnitude(ngramsStr1) + magnitude(ngramsStr2));
}

int main()
{
    //TEST CASES
    std::cout << ratio("ths is the test", "this is the test") << std::endl;
    std::cout << ratio("apple", "apkhj") << std::endl;
    std::cout << ratio("ana", "banana") << std::endl;
    std::cout << ratio("coconutt", "coconut") << std::endl;
    std::cout << ratio("coconut", "coconut") << std::endl;
    std::cout << ratio("something went wrong", "smthing go wrog") << std::endl;
    std::cout << ratio("game", "start-game") << std::endl;
    std::cout << ratio("start", "start-game") << std::endl;
    std::cout << ratio("g", "start-game") << std::endl;
    std::cout << ratio("gaaa", "aa") << std::endl;

    return 0;
}


