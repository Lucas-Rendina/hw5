// #ifndef RECCHECK
// // For debugging
// #include <iostream>
// // For std::remove
// #include <algorithm> 
// #include <map>
// #include <set>
// #endif

// #include "wordle.h"
// #include "dict-eng.h"
// using namespace std;


// // Add prototypes of helper functions here


// // Definition of primary wordle function
// std::set<std::string> wordle(
//     const std::string& in,
//     const std::string& floating,
//     const std::set<std::string>& dict)
// {
//     // Add your code here

// }

// // Define any helper functions here


#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here

void helper(const string& in, const string& floating, const set<string>& dict, set<string>& words, size_t idx);


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    set<string> finwords;
    if(in.size()!=0){
        helper(in, floating, dict, finwords,0);
    }
    
    return finwords;
}



// Define any helper functions here

void helper(const string& in, const string& floating, const set<string>& dict, set<string>& finwords, size_t idx){

    if( floating.size()==0){
        while(in[idx] != '-'){
            if(idx== in.size()){
                break;
            }
            idx++;
        }

        if(idx== in.size()){
            if(dict.find(in) != dict.end()){
                finwords.insert(in);
            }
        }
        else{
            for(size_t i=0;i<26;i++){
                string newin = in;
                newin[idx] = i+ 'a';
                helper(newin, floating, dict, finwords, idx+1);
            }
        }
        return;
    }

    for(size_t i=0;i<in.size();i++){
        string newfloating = floating.substr(0,floating.size()-1);
        if(in[i]=='-'){
            string newin = in;
            newin[i] = floating[floating.size()-1];
            helper(newin, newfloating, dict, finwords, 0);
        }
    }
}
