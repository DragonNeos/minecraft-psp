//Author:			David Kilford
//Date:				17th January 2011
//Description:		Class for all of our inventory needs!  TODO Clean up vertex code as it is VERY messy at the moment, will do once the sizes are all figured out

#include "GLLib.h"
#include "Texture.h"
#include "Inventory.h"

float scalex = 0.05;
float scaley = 0.006;
float offsetz = -0.11;
float offsety= -0.039;

float iconScaley = 0.0044;
float iconOffsetz = -0.106;
float iconOffset= 0.01072;
float iconOffsety = -0.038;
float iconOffsetx = -0.043;

float selectedScaley = 0.006;
float selectedOffsetz = -0.105;
float selectedOffset= 0.01072;
float selectedOffsety = -0.037;
float selectedOffsetx = -0.043;

int selectedItem = 1;
int * itemArray;

	Inventory::Inventory(int itemIDArray[8])		//Going to make constructor take in information about the contents of the inventory
	{
		itemArray=itemIDArray;						//Assigning a pointer to inventory info array, more efficient than copying the info over to a new array
		//printf("Testing array %i\n", itemArray[1]);  //Test to make sure you can access the info from the pointer
	}

	void Inventory::displayInventory()
	{

		glBegin(GL_QUADS);

		glColor3f(1, 1, 1);

		//Drawing the selected item
		glTexCoord2f(1, 0.951171875);							glVertex3f( selectedScaley+selectedOffsetx+selectedItem*selectedOffset-selectedOffset,  selectedScaley+selectedOffsety, selectedOffsetz); //Top-Right Corner
		glTexCoord2f(0.951171875, 0.951171875);					glVertex3f(-selectedScaley+selectedOffsetx+selectedItem*selectedOffset-selectedOffset,  selectedScaley+selectedOffsety, selectedOffsetz); //Top-Left Corner
		glTexCoord2f(0.951171875, 0.90429875);					glVertex3f(-selectedScaley+selectedOffsetx+selectedItem*selectedOffset-selectedOffset, -selectedScaley+selectedOffsety, selectedOffsetz); //Bottom-Left Corner
		glTexCoord2f(1, 0.90429875);							glVertex3f( selectedScaley+selectedOffsetx+selectedItem*selectedOffset-selectedOffset, -selectedScaley+selectedOffsety, selectedOffsetz); //Bottom-Right Corner

		glEnd();

		glBegin(GL_QUADS);		//Drawing inventory bar

		glColor3f(1, 1, 1);

		//Drawing the inventory bar
		glTexCoord2f(1, 0.95703125);							glVertex3f( scalex,  scaley+offsety, offsetz+0.001); //Top-Right Corner
		glTexCoord2f(0.64453125, 0.95703125);					glVertex3f(-scalex,  scaley+offsety, offsetz+0.001); //Top-Left Corner
		glTexCoord2f(0.64453125, 1);							glVertex3f(-scalex, -scaley+offsety, offsetz+0.001); //Bottom-Left Corner
		glTexCoord2f(1, 1);										glVertex3f( scalex, -scaley+offsety, offsetz+0.001); //Bottom-Right Corner

		glEnd();
		
		//drawing icons
		drawIcon(1, 1);
		drawIcon(2, 2);
		drawIcon(3, 3);
		drawIcon(4, 4);
		drawIcon(5, 5);
		drawIcon(6, 12);
		drawIcon(7, 13);
		drawIcon(8, 14);
		drawIcon(9, 15);

	}

	int Inventory::getInventory()
	{
		return selectedItem;
	}
	void Inventory::setInventoryNumber(int inventoryPosition)
	{
		selectedItem=inventoryPosition;
	}

	void Inventory::drawIcon(int position, int itemID)  //position is where in the inventory it is (for now 1-9), item(x/y) is the item's position, going to add a switch statement later, testing now
	{
		float itemx;
		float itemy;

		switch(itemID)  //turning itemID into an icon texture
		{
		case 1:
			itemx=5;
			itemy=5;
			break;
		case 2:
			itemx=3;
			itemy=5;
			break;
		case 3:
			itemx=4;
			itemy=4;
			break;
		case 4:
			itemx=4;
			itemy=5;
			break;
		case 5:
			itemx=2;
			itemy=5;
			break;
		case 12:
			itemx=1;
			itemy=5;
			break;
		case 13:
			itemx=5;
			itemy=3;
			break;
		case 14:
			itemx=3;
			itemy=1;
			break;
		case 15:
			itemx=3;
			itemy=3;
			break;
		default:
			itemx=1;
			itemy=1;
			break;
		}

		float xTextureOffset = 0.0546875;
		float yTextureOffset = 0.0625;
		position--;

		glBegin(GL_QUADS);		//Drawing icon

		glColor3f(1, 1, 1);

		glTexCoord2f(0.671875  + xTextureOffset*itemx, 0.5078125 + yTextureOffset*itemy);			glVertex3f( (iconScaley)*0.93+iconOffsetx+selectedOffset*position,  iconScaley+iconOffsety, iconOffsetz); //Top-Right Corner
		glTexCoord2f(0.6171875 + xTextureOffset*itemx, 0.5078125 + yTextureOffset*itemy);			glVertex3f((-iconScaley)*0.93+iconOffsetx+selectedOffset*position,  iconScaley+iconOffsety, iconOffsetz); //Top-Left Corner
		glTexCoord2f(0.6171875 + xTextureOffset*itemx, 0.5703125 + yTextureOffset*itemy);			glVertex3f((-iconScaley)*0.93+iconOffsetx+selectedOffset*position, -iconScaley+iconOffsety, iconOffsetz); //Bottom-Left Corner
		glTexCoord2f(0.671875  + xTextureOffset*itemx, 0.5703125 + yTextureOffset*itemy);			glVertex3f( (iconScaley)*0.93+iconOffsetx+selectedOffset*position, -iconScaley+iconOffsety, iconOffsetz); //Bottom-Right Corner

		glEnd();
	}

//int	getInventoryNumber();
