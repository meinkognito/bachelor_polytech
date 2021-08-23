# Russian — English dictionary
This is a Russian to English (and, moreover, English to Russian) dictionary, that was made, using self-written BinarySearchTree.

## Dictionary’s structure
**Key — word** -> **Value — std::unique_ptr to list with translations of this word**

## What it can do?
1. Add a new pair of *word* -> *translation* to the dictionary
2. Remove the *word* from the dictionary
3. Find the *word* and it’s *translation* (or *translations*) in the dictionary
4. Print all *words* in the dictionary

## What was the purpose to made it?
It can be used when you need to have a frequent access to all your words in a dictionary.

## Was the writing process helpful to you?
Sure, I’ve mastered ways to work with BST and correct Cyrillic letters processing using `std::wstring` constructions.

## How to use it?
1. Run an application
2. Choose Manual or Demonstration mode (in Demonstration mode program shows you what it can do)
3. Enter your pairs of “word” and “translation”
4. Print it
5. Enjoy!
