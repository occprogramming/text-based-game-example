#ifndef DIALOGUE_CPP
#define DIALOGUE_CPP


#include "dialogue.h"

// Gameplay is expressed using dialogues, which present a piece of
// information and some responses, and the ask the user to pick one. If
// they do not pick a valid one then the dialogue loops until they do


	// Initial piece of information that the dialogue displays
	//std::string description;

	// A vector of choices that will be outputted. No numbering is
	// necessary, the dialogue does that automatically
	//std::vector<std::string> choices;

	// Run the dialogue

Dialogue::Dialogue() {}


Dialogue::Dialogue(const string& setUp, const string& question, const vector<string>& choices)
{
    this->setUp = setUp;
    this->question = question;
    this->choices = choices;
}


int Dialogue::activate() const
{
    // Output the information
	cout << setUp << endl;
	cout << question << endl;
    cout << endl;

    // Output and number the choices
    for(int i = 0; i < this->choices.size(); ++i)
    {
        cout << i+1 << ": " << this->choices[i] << endl;
    }

    int userInput = -1;

    // Repeatedly read input from stdin until a valid option is
    // chosen
    while(true)
    {
        cin >> userInput;
        // 'Valid' means within the range of numbers outputted
		if (userInput >= 0 && userInput <= choices.size())
		{
			return userInput;
		}
		else
			cout << "Please enter a number between 1 and "
				 << choices.size() << endl;
    }

    return 0;
}

void Dialogue::handler(int choiceNumber)
{
    switch (choiceNumber)
    {
        case 1:
            cout << "Because technically atoms from the...." << endl;
            //choicesAndOutcomes[0].activate();
            break;
        case 2:
            cout << "I know right... Did you know that Michaelangelo was the first..." << endl;
            //choicesAndOutcomes[1].activate();
            break;
        case 3:
            cout << "I don't know..." << endl;
            //choicesAndOutcomes[2].activate();
            break;
    }
}


Outcome::Outcome()
{
    
}

Outcome::Outcome(OutcomeType outcomeType, const string& textToDisplay)
{
    
}

void Outcome::printType()
{
    
}

#endif /* DIALOGUE_CPP */
