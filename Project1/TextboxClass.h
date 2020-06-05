#pragma once
#include "raylib.h"
#include <string>

class TextboxClass
{
public:
	TextboxClass(Rectangle bounds, const int MAX_SIZE, int fontSize = 20);


	// Set the position and size of the textbox
	void setBounds(Rectangle bounds);

	// Is there any text currently?
	bool isEmpty();

	// Update the current text using keys pressed
	void update();
	// Get the current text, and clear it
	std::string getTextAndClear();

	// Draw the textbox. BeginDrawing() must have been called to do so
	void draw();

private:
	Rectangle bounds;
	std::string text;
	const int MAX_SIZE;
	int fontSize;
};