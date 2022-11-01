#include "texture.h"

texture textures[2];

//texture textureVariable;

void textureInit()
{
    textures[0].Create("girl.bmp");
	textures[1].Create("smurf.bmp");
	//textureVariable.Create("google.bmp");
}



/**
How to use texture image:

1. in TextureList.h: declare texture type variables as needed. For every image, you need to declare one texture type variable.

Example:

texture textureVariable;


2. in TextureList.h: in the function textureInit(): initialize the texture variable that you declared in step 1 with the name
of the image file.

Example: suppose you have an image file named: "google.bmp"
then, you initialize as follows:

textureVariable.Create("google.bmp");


3. in the main cpp file in iDraw function: use drawTexture function to draw the image. drawTexture takes three arguments.

-> first argument   : lower left x-coordinate of the image
-> second argument  : lower left y-coordinate of the image
-> third argument   : name of the textureVariable declared in step 1


Example:

drawTexture(100, 200, textureVariable);
**/
