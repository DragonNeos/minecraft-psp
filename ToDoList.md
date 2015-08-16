# Introduction #

To start using C++ offers so much flexibility we can't reach it's full potential use as of now, however with our previous coding history the few things we have learned can be applied to C++ with basically using the exact same coding structure we did in Java coding although the efficiency won't be to the highest of possibilities it is still much more efficient than Java due to no Virtual Machine interpreting the code on the fly.

Now a few things I have noticed with PSPGL are:

- It is very easy to understand and syntax is identical to what we previously have learned minus the GL11 prefix.

- There is in a sense some more flexibility with PSPGL as there was with LWJGL with the main and immediate thing being that control of the buffers is much easier to learn due to no singleton class controlling the 'Display'

- PSPGL also comes with a convenient auto-looping function that loops main but this is just for testing purposes as main usually will not hold the game code or running game code so it is good to note this.

# Details #

Now onto the main part of this page, the tasks needed for this project for us to be able to progress in a much easy manor, these are:

Game Engine - A game engine will be needed to be developed in order to much easily understand and utilise PSPGL while also being able to control the game since a lot of control will be needed for this specific type of game due to the constraints given by the platform.

Dynamic Memory Controller - Now this should be incorporated into the Game Engine but it should be developed seperately from it due to it holding the biggest and most vital part of the game being the control, management, and sorting of the memory using pointers/arrays.

Controller - Even though the controller can easily be learned it would be good practice to develop a unique API/Library for this because it is very untidy how the controls are already handled.

Texturizer - Now I seriously think we need to think this carefully as textures will be taking up a lot of memory and we cannot afford to populate most of the memory with texture bitmaps. So textures and how they're handled should be studied carefully and understood so deleting and managing them in memory can be better handled.