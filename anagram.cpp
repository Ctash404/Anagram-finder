/*
 * Name: Conner Tash
 * Date Submitted: 10/27/2022
 * Assignment Name: Anagram finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);
/*
int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}
*/
vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    string testWord;
    vector<string> foundGroups;
    

    //pushing the original word to vector
    //foundGroups.push_back(word);
    
    //looping through all the items in wordlist
    for(unsigned i = 0; i < wordlist.size(); ++i)
    {
        //test the element at i point in the list
        testWord = wordlist[i];

        // map for characters and int when setting to one
        unordered_map<char,int> map;

        int wordLen = word.length();
        int testWordLen = testWord.length();

        // Checks the length of the two words to see if they are equal
        if(wordLen != testWordLen)
        {
            continue;
        }
        
        // Sets elements in the map to 1 for the word
        for(int j = 0; j < wordLen; ++j)
        {
            if(map.find(word[j]) == map.end())
            {
                map[word[j]] = 0;
            }
            ++map[word[j]];
        }
        
        for(int j = 0; j < testWordLen; ++j)
        {
            // Checks that the letters are in the map for anagram
            if(map.find(testWord[j]) == map.end())
            {
                break;
            }
            else
            {
                // Reduces the letters that share a type with the chosen 
                // word to 0
                --map[testWord[j]];

                // If any characters are zero then the map becomes empty
                if(map[testWord[j]] == 0)
                {
                    map.erase(testWord[j]);
                }
            }
        }
        //if the map is empty than the two words are anagrams
        if(map.size() == 0)
        {
            foundGroups.push_back(testWord);
        }
    } 
    return foundGroups;
}