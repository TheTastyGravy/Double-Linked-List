#include "ButtonClass.h"

ButtonClass::ButtonClass(Rectangle bounds, std::string text, int fontSize) :
	bounds(bounds),
	text(text),
	fontSize(fontSize),
	normalColor(RAYWHITE),
	mouseOverColor(LIGHTGRAY)
{
}


void ButtonClass::setBounds(Rectangle bounds)
{
	this->bounds = bounds;
}

void ButtonClass::setText(std::string text, int fontSize)
{
	this->text = text;
	this->fontSize = fontSize;
}

void ButtonClass::setColor(Color normal, Color mouseOver)
{
	normalColor = normal;
	mouseOverColor = mouseOver;
}


bool ButtonClass::isMouseOver()
{
	return (CheckCollisionPointRec(GetMousePosition(), bounds));
}

bool ButtonClass::isClicked()
{
	return (this->isMouseOver() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}


void ButtonClass::draw()
{
	// Draw the box using the appropriate color and with an outline
	DrawRectangleRec(bounds, (isMouseOver()) ? mouseOverColor : normalColor);
	DrawRectangleLinesEx(bounds, 2, BLACK);
	
	// Draw the text inside the box
	DrawText(text.c_str(), bounds.x + bounds.width/2 - MeasureText(text.c_str(), fontSize)/2, bounds.y + bounds.height/2 - fontSize/2, fontSize, BLACK);
	// bounds.x + bounds.width/2 - MeasureText(...)/2 is used to center the text
}