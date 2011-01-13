//Author:			David Kilford
//Date:				1st January 2010
//Description:		Program that calculates texture coordinates from texture size and other info
//
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main () 
//{
//	ofstream myfile ("MC Texture Coords.txt");
//	if (myfile.is_open())
//	{
//		string blockName;
//		double textureSize = 512;
//		double blockSize = 16;
//		double offsetx;
//		double offsety;
//
//		double calculatedOffsetx = 0;
//		double calculatedOffsety = 0;
//		double textureCoordx = 0;
//		double textureCoordy = 0;
//
//		double topRightx;
//		double bottomRightx, bottomRighty;
//		double bottomLefty;
//
//		cout <<"Welcome to the Minecraft texture coordinate calculator";
//		cout <<"\nPlease enter the block's name.\n";
//		cin >> blockName;
//
//		cout <<"Please type in the x blocks offset\n";
//
//		cin >>offsetx;
//		cout<<"Please type in the y blocks offset\n";
//		cin>>offsety;
//
//		calculatedOffsetx = 16*offsetx;
//		calculatedOffsety = 16*offsety;
//
//		textureCoordx = calculatedOffsetx/textureSize;
//		textureCoordy = calculatedOffsety/textureSize;
//
//		topRightx = (textureCoordx+(16.0/textureSize));
//		bottomRightx = (textureCoordx+(16.0/textureSize));
//		bottomRighty = (textureCoordy+(16.0/textureSize));
//		bottomLefty = (textureCoordy+(16.0/textureSize));
//
//		myfile <<blockName;
//		myfile <<"\nThe texture coordinates are:\n\nTop left: \n" << textureCoordx;
//		myfile <<", " << textureCoordy;
//		myfile <<"\n\nTop right: \n" << topRightx;
//		myfile <<", " << textureCoordy;
//		myfile <<"\n\nBottom right: \n" << bottomRightx; 
//		myfile <<", " << bottomRighty;
//		myfile <<"\n\nBottom left: \n"  <<textureCoordx; 
//		myfile << ", " <<bottomLefty <<"\n\n";
//		cout << "Contents saved to MC Texture Coords.txt\n";
//		system("pause");
//		myfile.close();
//	}
//	else cout << "Unable to open file";
//	return 0;
//}