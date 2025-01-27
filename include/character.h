#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

typedef struct Character {
    Vector2 position;
    Texture2D texture;
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    int lastDirection; 
} Character;

Character InitCharacter(const char *texturePath, Vector2 position, float frameWidth, float frameHeight, int framesSpeed);
void UpdateCharacterAnimation(Character *character, int direction);
void MoveCharacter(Character *character, Vector2 direction);

#endif