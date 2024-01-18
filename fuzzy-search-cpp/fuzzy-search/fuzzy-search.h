// fuzzy-search.h - Contains declarations of functions
#pragma once

#ifdef FUZZYSEARCH_EXPORTS
#define FUZZYSEARCH_API __declspec(dllexport)
#else
#define FUZZYSEARCH_API __declspec(dllimport)
#endif


//for export functions initiation
extern "C" FUZZYSEARCH_API double ratio(const char* str1, const char* str2);

