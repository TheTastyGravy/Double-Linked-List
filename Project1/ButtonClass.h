#pragma once
#include "raylib.h"
#include <string>

// Custom button class using raylib
class ButtonClass
{
public:
	ButtonClass(Rectangle bounds, std::string text, int fontSize = 20);


	// Set the position and size of the button
	void setBounds(Rectangle bounds);
	// Set the buttons displayed text
	void setText(std::string text, int fontSize);
	// Set the buttons color when the mouse is not over the button (normal),
	// and when is is within its bounds (mouseOver)
	void setColor(Color normal, Color mouseOver);

	// Is the mouse within the buttons bounds?
	bool isMouseOver();
	// Has the button been clicked?
	bool isClicked();

	// Draw the buton. BeginDrawing() must have been called to do so
	void draw();

private:
	Rectangle bounds;
	std::string text;
	int fontSize;
	Color normalColor;
	Color mouseOverColor;
};