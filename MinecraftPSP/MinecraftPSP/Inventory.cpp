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

float iconScaley = 0.0043;
float iconOffsetz = -0.106;
float iconOffset= 0.01072;
float iconOffsety = -0.038;
float iconOffsetx = -0.0424;

float selectedOffsetz = -0.1065;
float selectedOffset= 0.01072;

int selectedItemx = 3;
int selectedItemy = 3;

float xTextureOffset = 0.03125;
float yTextureOffset = 0.03125;

int selectedItem = 1;
float itemArray[45][3];

	Inventory::Inventory(float itemIDArray[45])		//Going to make constructor take in information about the contents of the inventory
	{
		
		for (int i=0; i<45; i++)
		{
			//printf("Inventory Constructor used\n");
			itemArray[i][0]=itemIDArray[i];
			int temp = itemArray[i][0];

			switch((int) itemArray[i][0])  //turning itemID into an icon texture
			{
			case 1:
				itemArray[i][1]=0.625  + xTextureOffset*5;
				itemArray[i][2]=0.59375  + xTextureOffset*5;
				break;
			case 2:
				itemArray[i][1]=0.625  + xTextureOffset*3;
				itemArray[i][2]=0.59375  + yTextureOffset*5;
				break;
			case 3:
				itemArray[i][1]=0.625  + xTextureOffset*4;
				itemArray[i][2]=0.59375  + yTextureOffset*4;
				break;
			case 4:
				itemArray[i][1]=0.625  + xTextureOffset*4;
				itemArray[i][2]=0.59375  + yTextureOffset*5;
				break;
			case 5:
				itemArray[i][1]=0.625  + xTextureOffset*2;
				itemArray[i][2]=0.59375  + yTextureOffset*5;
				break;
			case 12:
				itemArray[i][1]=0.625  + xTextureOffset*1;
				itemArray[i][2]=0.59375  + yTextureOffset*5;
				break;
			case 13:
				itemArray[i][1]=0.625  + xTextureOffset*5;
				itemArray[i][2]=0.59375  + yTextureOffset*3;
				break;
			case 14:
				itemArray[i][1]=0.625  + xTextureOffset*3;
				itemArray[i][2]=0.59375  + yTextureOffset*1;
				break;
			case 15:
				itemArray[i][1]=0.625  + xTextureOffset*3;
				itemArray[i][2]=0.59375  + yTextureOffset*3;
				break;
			case 16:
				itemArray[i][1]=0.625  + xTextureOffset*7;
				itemArray[i][2]=0.59375  + yTextureOffset*1;
				break;
			default:
				itemArray[i][1]=0.625  + xTextureOffset*1;
				itemArray[i][2]=0.59375  + yTextureOffset*1;
				break;
			}
			
			//printf("ID is %f, 1 is %f, 2 is %f\n",itemArray[i][0], itemArray[i][1], itemArray[i][2]);
		}

	}

	void Inventory::drawInventory(bool displayInventory)
	{

		glBegin(GL_QUADS);

		glColor3f(1, 1, 1);

		//Drawing the selected item
		glTexCoord2f(1, 0.951171875);							glVertex3f(-0.04772+selectedItem*selectedOffset,  -0.033, selectedOffsetz); //Top-Right Corner
		glTexCoord2f(0.951171875, 0.951171875);					glVertex3f(-0.05972+selectedItem*selectedOffset,  -0.033, selectedOffsetz); //Top-Left Corner
		glTexCoord2f(0.951171875, 0.90429875);					glVertex3f(-0.05972+selectedItem*selectedOffset,  -0.045, selectedOffsetz); //Bottom-Left Corner
		glTexCoord2f(1, 0.90429875);							glVertex3f(-0.04772+selectedItem*selectedOffset,  -0.045, selectedOffsetz); //Bottom-Right Corner

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(1, 1, 1);

		//Drawing the inventory bar
		glTexCoord2f(1, 0.95703125);							glVertex3f( scalex,  scaley+offsety, offsetz+0.001); //Top-Right Corner
		glTexCoord2f(0.64453125, 0.95703125);					glVertex3f(-scalex,  scaley+offsety, offsetz+0.001); //Top-Left Corner
		glTexCoord2f(0.64453125, 1);							glVertex3f(-scalex, -scaley+offsety, offsetz+0.001); //Bottom-Left Corner
		glTexCoord2f(1, 1);										glVertex3f( scalex, -scaley+offsety, offsetz+0.001); //Bottom-Right Corner

		glEnd();

		if(displayInventory==true)
		{

			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);

			//Drawing the inventory
			glTexCoord2f(1, 0.2421875);								glVertex3f( 0.045,  0.045, offsetz+0.001); //Top-Right Corner
			glTexCoord2f(0.65625, 0.2421875);						glVertex3f(-0.045,  0.045, offsetz+0.001); //Top-Left Corner
			glTexCoord2f(0.65625, 0.56640625);						glVertex3f(-0.045, -0.033, offsetz+0.001); //Bottom-Left Corner
			glTexCoord2f(1, 0.56640625);							glVertex3f( 0.045, -0.033, offsetz+0.001); //Bottom-Right Corner

			glEnd();

			drawSelectedIcon(selectedItemx,selectedItemy);

			for(int i=0; i<5; i++)
			{
				for(int j=1; j<10; j++)
				{
					drawInventoryIcon(j, i, itemArray[10][0], itemArray[10][1], itemArray[10][2]);
				}
			}

			
		}
		
		//drawing icons
		for(int i=0; i<9; i++)
		{
			drawInventoryBarIcon(i, itemArray[i][0], itemArray[i][1], itemArray[i][2]);
		}

	}

	int Inventory::getInventory()
	{
		return selectedItem;
	}
	void Inventory::setInventoryNumber(int inventoryPosition)
	{
		selectedItem=inventoryPosition;
	}

	void Inventory::drawInventoryBarIcon(int position, int itemID, float textureCoordx, float textureCoordy) //Method for drawing items in the inventory bar
	{
		glBegin(GL_QUADS);		//Drawing icon

		glColor3f(1, 1, 1);

		glTexCoord2f(textureCoordx+0.03125, textureCoordy);					glVertex3f( -0.038844 + position*0.0106828,  iconScaley*0.95+iconOffsety, iconOffsetz); //Top-Right Corner
		glTexCoord2f(textureCoordx,			textureCoordy);					glVertex3f( -0.046756 + position*0.0106828,  iconScaley*0.95+iconOffsety, iconOffsetz); //Top-Left Corner
		glTexCoord2f(textureCoordx,			textureCoordy+0.03125);			glVertex3f( -0.046756 + position*0.0106828, -iconScaley*0.95+iconOffsety, iconOffsetz); //Bottom-Left Corner
		glTexCoord2f(textureCoordx+0.03125, textureCoordy+0.03125);			glVertex3f( -0.038844 + position*0.0106828, -iconScaley*0.95+iconOffsety, iconOffsetz); //Bottom-Right Corner

		glEnd();
	}

	void Inventory::drawInventoryIcon(int positionx, int positiony, int itemID, float textureCoordx, float textureCoordy)		//Method for drawing items for the inventory
	{
		if(positiony==0)			//Inventory bar icons in inventory
		{
			float fpositiony=3.17;
			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);

			glTexCoord2f(textureCoordx+0.03125, textureCoordy);					glVertex3f( -0.040844 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, iconOffsetz); //Top-Right Corner
			glTexCoord2f(textureCoordx,			textureCoordy);					glVertex3f(	-0.048756 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, iconOffsetz); //Top-Left Corner
			glTexCoord2f(textureCoordx,			textureCoordy+0.03125);			glVertex3f(	-0.048756 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, iconOffsetz); //Bottom-Left Corner
			glTexCoord2f(textureCoordx+0.03125, textureCoordy+0.03125);			glVertex3f( -0.040844 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, iconOffsetz); //Bottom-Right Corner

			glEnd();
		}
		else if(positiony<4)		//Main inventory items
		{
			positiony--;
			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);

			glTexCoord2f(textureCoordx+0.03125, textureCoordy);					glVertex3f( -0.040844 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, iconOffsetz); //Top-Right Corner
			glTexCoord2f(textureCoordx,			textureCoordy);					glVertex3f(	-0.048756 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, iconOffsetz); //Top-Left Corner
			glTexCoord2f(textureCoordx,			textureCoordy+0.03125);			glVertex3f(	-0.048756 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, iconOffsetz); //Bottom-Left Corner
			glTexCoord2f(textureCoordx+0.03125, textureCoordy+0.03125);			glVertex3f( -0.040844 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, iconOffsetz); //Bottom-Right Corner

			glEnd();
		}
		else if(positionx<=4)		//Armour items
		{
			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);
			glTexCoord2f(textureCoordx+0.03125, textureCoordy);					glVertex3f( -0.040844 + 0.0089528,  iconScaley*0.85+0.045-positionx*0.0083528, iconOffsetz); //Top-Right Corner
			glTexCoord2f(textureCoordx,			textureCoordy);					glVertex3f(	-0.048756 + 0.0089528,  iconScaley*0.85+0.045-positionx*0.0083528, iconOffsetz); //Top-Left Corner
			glTexCoord2f(textureCoordx,			textureCoordy+0.03125);			glVertex3f(	-0.048756 + 0.0089528, -iconScaley*0.85+0.045-positionx*0.0083528, iconOffsetz); //Bottom-Left Corner
			glTexCoord2f(textureCoordx+0.03125, textureCoordy+0.03125);			glVertex3f( -0.040844 + 0.0089528, -iconScaley*0.85+0.045-positionx*0.0083528, iconOffsetz); //Bottom-Right Corner

			glEnd();
		}
		else if(positionx>4 && positionx<7)	//Crafting items
		{
			glBegin(GL_QUADS);	

			glColor3f(1, 1, 1);
			glTexCoord2f(textureCoordx+0.03125, textureCoordy);					glVertex3f( -0.040844 + positionx*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-0.0083528, iconOffsetz); //Top-Right Corner
			glTexCoord2f(textureCoordx,			textureCoordy);					glVertex3f(	-0.048756 + positionx*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-0.0083528, iconOffsetz); //Top-Left Corner
			glTexCoord2f(textureCoordx,			textureCoordy+0.03125);			glVertex3f(	-0.048756 + positionx*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-0.0083528, iconOffsetz); //Bottom-Left Corner
			glTexCoord2f(textureCoordx+0.03125, textureCoordy+0.03125);			glVertex3f( -0.040844 + positionx*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-0.0083528, iconOffsetz); //Bottom-Right Corner

			glEnd();
		}
		else if(positionx>=7 && positionx!=9)	//Crafting items
		{
			glBegin(GL_QUADS);		//Drawing icon

			glColor3f(1, 1, 1);
			glTexCoord2f(textureCoordx+0.03125, textureCoordy);					glVertex3f( -0.040844 + (positionx-2)*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-2*0.0083528, iconOffsetz); //Top-Right Corner
			glTexCoord2f(textureCoordx,			textureCoordy);					glVertex3f(	-0.048756 + (positionx-2)*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-2*0.0083528, iconOffsetz); //Top-Left Corner
			glTexCoord2f(textureCoordx,			textureCoordy+0.03125);			glVertex3f(	-0.048756 + (positionx-2)*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-2*0.0083528, iconOffsetz); //Bottom-Left Corner
			glTexCoord2f(textureCoordx+0.03125, textureCoordy+0.03125);			glVertex3f( -0.040844 + (positionx-2)*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-2*0.0083528, iconOffsetz); //Bottom-Right Corner

			glEnd();
		}
		else									//Crafted item
		{
			glBegin(GL_QUADS);		//Drawing icon

			glColor3f(1, 1, 1);
			glTexCoord2f(textureCoordx+0.03125, textureCoordy);					glVertex3f( -0.040844 + (positionx-1)*0.0089528+0.0358112/7,  iconScaley*0.85+0.037-1.6*0.0083528, iconOffsetz); //Top-Right Corner
			glTexCoord2f(textureCoordx,			textureCoordy);					glVertex3f(	-0.048756 + (positionx-1)*0.0089528+0.0358112/7,  iconScaley*0.85+0.037-1.6*0.0083528, iconOffsetz); //Top-Left Corner
			glTexCoord2f(textureCoordx,			textureCoordy+0.03125);			glVertex3f(	-0.048756 + (positionx-1)*0.0089528+0.0358112/7, -iconScaley*0.85+0.037-1.6*0.0083528, iconOffsetz); //Bottom-Left Corner
			glTexCoord2f(textureCoordx+0.03125, textureCoordy+0.03125);			glVertex3f( -0.040844 + (positionx-1)*0.0089528+0.0358112/7, -iconScaley*0.85+0.037-1.6*0.0083528, iconOffsetz); //Bottom-Right Corner

			glEnd();
		}
	}

void Inventory::drawSelectedIcon(int positionx, int positiony)		//Method for drawing items for the inventory
	{
		if(positiony==0)			//Inventory bar icons in inventory
		{
			float fpositiony=3.17;
			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);

			glTexCoord2f(0.84375+0.03125, 0.59375);					glVertex3f( -0.040844 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, offsetz+0.002); //Top-Right Corner
			glTexCoord2f(0.84375,			0.59375);				glVertex3f(	-0.048756 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, offsetz+0.002); //Top-Left Corner
			glTexCoord2f(0.84375,			0.59375+0.03125);		glVertex3f(	-0.048756 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, offsetz+0.002); //Bottom-Left Corner
			glTexCoord2f(0.84375+0.03125, 0.59375+0.03125);			glVertex3f( -0.040844 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-fpositiony*0.0083528, offsetz+0.002); //Bottom-Right Corner

			glEnd();
		}
		else if(positiony<4)		//Main inventory items
		{
			positiony--;
			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);

			glTexCoord2f(0.84375+0.03125, 0.59375);					glVertex3f( -0.040844 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, offsetz+0.002); //Top-Right Corner
			glTexCoord2f(0.84375,			0.59375);				glVertex3f(	-0.048756 + positionx*0.0089528,  iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, offsetz+0.002); //Top-Left Corner
			glTexCoord2f(0.84375,			0.59375+0.03125);		glVertex3f(	-0.048756 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, offsetz+0.002); //Bottom-Left Corner
			glTexCoord2f(0.84375+0.03125, 0.59375+0.03125);			glVertex3f( -0.040844 + positionx*0.0089528, -iconScaley*0.85+iconOffsety+0.04-positiony*0.0083528, offsetz+0.002); //Bottom-Right Corner

			glEnd();
		}
		else if(positionx<=4)		//Armour items
		{
			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);
			glTexCoord2f(0.84375+0.03125, 0.59375);					glVertex3f( -0.040844 + 0.0089528,  iconScaley*0.85+0.045-positionx*0.0083528, offsetz+0.002); //Top-Right Corner
			glTexCoord2f(0.84375,			0.59375);				glVertex3f(	-0.048756 + 0.0089528,  iconScaley*0.85+0.045-positionx*0.0083528, offsetz+0.002); //Top-Left Corner
			glTexCoord2f(0.84375,			0.59375+0.03125);		glVertex3f(	-0.048756 + 0.0089528, -iconScaley*0.85+0.045-positionx*0.0083528, offsetz+0.002); //Bottom-Left Corner
			glTexCoord2f(0.84375+0.03125, 0.59375+0.03125);			glVertex3f( -0.040844 + 0.0089528, -iconScaley*0.85+0.045-positionx*0.0083528, offsetz+0.002); //Bottom-Right Corner

			glEnd();
		}
		else if(positionx>4 && positionx<7)	//Crafting items
		{
			glBegin(GL_QUADS);	

			glColor3f(1, 1, 1);
			glTexCoord2f(0.84375+0.03125, 0.59375);					glVertex3f( -0.040844 + positionx*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-0.0083528, offsetz+0.002); //Top-Right Corner
			glTexCoord2f(0.84375,			0.59375);				glVertex3f(	-0.048756 + positionx*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-0.0083528, offsetz+0.002); //Top-Left Corner
			glTexCoord2f(0.84375,			0.59375+0.03125);		glVertex3f(	-0.048756 + positionx*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-0.0083528, offsetz+0.002); //Bottom-Left Corner
			glTexCoord2f(0.84375+0.03125, 0.59375+0.03125);			glVertex3f( -0.040844 + positionx*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-0.0083528, offsetz+0.002); //Bottom-Right Corner

			glEnd();
		}
		else if(positionx>=7 && positionx!=9)	//Crafting items
		{
			glBegin(GL_QUADS);		//Drawing icon

			glColor3f(1, 1, 1);
			glTexCoord2f(0.84375+0.03125, 0.59375);					glVertex3f( -0.040844 + (positionx-2)*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-2*0.0083528, offsetz+0.002); //Top-Right Corner
			glTexCoord2f(0.84375,			0.59375);				glVertex3f(	-0.048756 + (positionx-2)*0.0089528+0.0358112/9,  iconScaley*0.85+0.037-2*0.0083528, offsetz+0.002); //Top-Left Corner
			glTexCoord2f(0.84375,			0.59375+0.03125);		glVertex3f(	-0.048756 + (positionx-2)*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-2*0.0083528, offsetz+0.002); //Bottom-Left Corner
			glTexCoord2f(0.84375+0.03125, 0.59375+0.03125);			glVertex3f( -0.040844 + (positionx-2)*0.0089528+0.0358112/9, -iconScaley*0.85+0.037-2*0.0083528, offsetz+0.002); //Bottom-Right Corner

			glEnd();
		}
		else									//Crafted item
		{
			glBegin(GL_QUADS);		//Drawing icon

			glColor3f(1, 1, 1);
			glTexCoord2f(0.84375+0.03125, 0.59375);					glVertex3f( -0.040844 + (positionx-1)*0.0089528+0.0358112/7,  iconScaley*0.85+0.037-1.6*0.0083528, offsetz+0.002); //Top-Right Corner
			glTexCoord2f(0.84375,			0.59375);				glVertex3f(	-0.048756 + (positionx-1)*0.0089528+0.0358112/7,  iconScaley*0.85+0.037-1.6*0.0083528, offsetz+0.002); //Top-Left Corner
			glTexCoord2f(0.84375,			0.59375+0.03125);		glVertex3f(	-0.048756 + (positionx-1)*0.0089528+0.0358112/7, -iconScaley*0.85+0.037-1.6*0.0083528, offsetz+0.002); //Bottom-Left Corner
			glTexCoord2f(0.84375+0.03125, 0.59375+0.03125);			glVertex3f( -0.040844 + (positionx-1)*0.0089528+0.0358112/7, -iconScaley*0.85+0.037-1.6*0.0083528, offsetz+0.002); //Bottom-Right Corner

			glEnd();
		}
	}

int Inventory::getSelectedItemPositionx()
{
	return selectedItemx;
}

int Inventory::getSelectedItemPositiony()
{
	return selectedItemy;
}

void Inventory::setSelectedItem(int x, int y)
{
	if(x<=9 && x>0)
	{
		selectedItemx = x;
	}
	else if (x>9)
	{
		selectedItemx=1;
	}
	else
	{
		selectedItemx=9;
	}

	if(y<=5 && y>=0)
	{
		selectedItemy = y;
	}
	else if (y>5)
	{
		selectedItemy=0;
	}
	else
	{
		selectedItemy=5;
	}
	
}

//int	getInventoryNumber();
