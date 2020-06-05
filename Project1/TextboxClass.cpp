#include "TextboxClass.h"

TextboxClass::TextboxClass(Rectangle bounds, const int MAX_SIZE, int fontSize) :
	bounds(bounds),
	text(""),
	MAX_SIZE(MAX_SIZE),
	fontSize(fontSize)
{
}


void TextboxClass::setBounds(Rectangle bounds)
{
	this->bounds = bounds;
}


bool TextboxClass::isEmpty()
{
	return (text.length() == 0);
}


void TextboxClass::update()
{
	int key = GetKeyPressed();

	// 0 is a null terminator
	while (key > 0)
	{
		// Keys within this range are printable
		if ((key >= 32) && (key <= 125) && (text.length() < MAX_SIZE))
		{
			// In this case, we only want ints
			if ((key >= 48) && (key <= 57))
			{
				text += (char)key;
			}
		}

		// Get next key in queue
		key = GetKeyPressed();
	}

	if (IsKeyPressed(KEY_BACKSPACE))
		text.pop_back();

}

std::string TextboxClass::getTextAndClear()
{
	// Return text after clearing it
	std::string temp = text;
	text = "";
	return temp;
}


void TextboxClass::draw()
{
	// Draw white rectangle with black outline
	DrawRectangleRec(bounds, WHITE);
	DrawRectangleLinesEx(bounds, 2, BLACK);
	// Draw the current text
	DrawText(text.c_str(), bounds.x + 5, bounds.y + bounds.height / 2 - fontSize / 2, fontSize, BLACK);
}