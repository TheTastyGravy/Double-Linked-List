#include "raylib.h"
#include "DLList.h"
#include "ButtonClass.h"
#include "TextboxClass.h"


// A more general purpose function. PosX is the center, not left side
void drawTextNew(std::string text, int posX, int posY, int fontSize = 15, Color color = BLACK);
// Draw the lables and values of the current and adjasent nodes
void drawNodeValues(DLListNode* node);


int main()
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HIGHT = 450;

	InitWindow(SCREEN_WIDTH, SCREEN_HIGHT, "Double-Linked List demo");
	SetTargetFPS(60);


	// The list of data, and the current node
	DLList list;
	DLListNode* current = nullptr;

	// Used to get input for new node values
	TextboxClass textBox(Rectangle{ 325, 350, 150, 50 }, 9, 23);

	// Navigation buttons
	ButtonClass goToFirstBtn(Rectangle{ 25, 50, 100, 30 }, "go to first", 15);
	ButtonClass goToLastBtn(Rectangle{ 675, 50, 100, 30 }, "go to last", 15);
	ButtonClass previousBtn(Rectangle{ 150, 50, 100, 30 }, "previous", 15);
	ButtonClass nextBtn(Rectangle{ 550, 50, 100, 30 }, "next", 15);
	// Add and remove buttons
	ButtonClass delFirstBtn(Rectangle{ 125, 200, 150, 30 }, "delete first", 15);
	ButtonClass delLastBtn(Rectangle{ 525, 200, 150, 30 }, "delete last", 15);
	ButtonClass delCurrentBtn(Rectangle{ 325, 200, 150, 30 }, "delete current", 15);
	ButtonClass addFirstBtn(Rectangle{ 125, 250, 150, 30 }, "add to start", 15);
	ButtonClass addLastBtn(Rectangle{ 525, 250, 150, 30 }, "add to end", 15);
	ButtonClass addCurrentBtn(Rectangle{ 325, 250, 150, 30 }, "insert at current", 15);
	// Sort button
	ButtonClass sortBtn(Rectangle{ 350, 50, 100, 30 }, "sort", 15);


	// Game loop
	while (!WindowShouldClose())
	{
		// Get input for textbox
		textBox.update();


		// First and last buttons
		if (goToFirstBtn.isClicked())
			current = list.getFirst();
		else if (goToLastBtn.isClicked())
			current = list.getLast();
		// Previous and next buttons
		if (current != nullptr)
		{
			if (previousBtn.isClicked() && current->previous != nullptr)
				current = current->previous;
			else if (nextBtn.isClicked() && current->next != nullptr)
				current = current->next;
		}

		// Delete buttons
		// Note: Where current is also first, it will be removed and current is left as 
		// a dangling pointer, not a null pointer. To get around this, current is set 
		// to a null pointer every time a node is deleted.
		if (delFirstBtn.isClicked())
		{
			list.popFront();
			current = nullptr;
		}
		else if (delLastBtn.isClicked())
		{
			list.popEnd();
			current = nullptr;
		}
		else if (delCurrentBtn.isClicked())
		{
			list.remove(current);
			current = nullptr;
		}
			
		// Add buttons. There must be text to create a node
		if (!textBox.isEmpty())
		{
			if (addFirstBtn.isClicked())
				list.pushFront(std::stoi(textBox.getTextAndClear()));
			if (addLastBtn.isClicked())
				list.pushEnd(std::stoi(textBox.getTextAndClear()));
			if (addCurrentBtn.isClicked() && current != nullptr)
				list.insert(std::stoi(textBox.getTextAndClear()), current);
		}

		// Sort button. List cant be empty when sort
		if (sortBtn.isClicked() && !list.isEmpty())
		{
			list.sort();
			// Current may have been moved, in which case it is now dangling
			current = nullptr;
		}



		// Draw to screen
		BeginDrawing();
		ClearBackground(RAYWHITE);


		// Display list values
		drawNodeValues(current);

		// Display the lists size and if it's empty
		drawTextNew("Size: " + std::to_string(list.count()), 200, 20, 20);
		std::string res = list.isEmpty() ? "Yes" : "No";
		drawTextNew("Is empty? " + res, 600, 20, 20);
		
		// Display the input text box
		drawTextNew("Value:", 400, 320, 20);
		textBox.draw();

		// Display buttons
		goToFirstBtn.draw();
		goToLastBtn.draw();
		previousBtn.draw();
		nextBtn.draw();
		delFirstBtn.draw();
		delLastBtn.draw();
		delCurrentBtn.draw();
		addFirstBtn.draw();
		addLastBtn.draw();
		addCurrentBtn.draw();
		sortBtn.draw();


		EndDrawing();
	}

	CloseWindow();
	return 0;
}


void drawTextNew(std::string text, int posX, int posY, int fontSize, Color color)
{
	DrawText(text.c_str(), posX - MeasureText(text.c_str(), fontSize) / 2, posY, fontSize, color);
}

void drawNodeValues(DLListNode* node)
{
	drawTextNew("Previous:", 100, 100, 17);
	drawTextNew("Current:", 400, 100, 17);
	drawTextNew("Next:", 700, 100, 17);

	// If current is null, the other two dont exist
	if (node == nullptr)
	{
		drawTextNew("NA", 100, 125, 30);
		drawTextNew("nullptr", 400, 125, 30);
		drawTextNew("NA", 700, 125, 30);
	}
	else
	{
		// Check if the adjasent nodes are nullptrs
		drawTextNew( (node->previous == nullptr) ? 
					 "nullptr" : std::to_string(node->previous->value),
					 100, 125, 30);

		drawTextNew( std::to_string(node->value), 400, 125, 30);

		drawTextNew( (node->next == nullptr) ? 
					 "nullptr" : std::to_string(node->next->value), 
					 700, 125, 30);
	}
}