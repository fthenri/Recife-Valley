#include "raylib.h"
#include "character.h"

Character InitCharacter(const char *texturePath, Vector2 position, float frameWidth, float frameHeight, int framesSpeed) {
    Character character = {0};
    character.position = position;
    character.texture = LoadTexture(texturePath);
    character.frameRec = (Rectangle){0.0f, 0.0f, frameWidth, frameHeight};
    character.currentFrame = 0;
    character.framesCounter = 0;
    character.framesSpeed = framesSpeed;
    character.lastDirection = 0;
    return character;
}

void UpdateCharacterAnimation(Character *character, int direction) {
    character->framesCounter++;
    if (character->framesCounter >= (60 / character->framesSpeed)) {
        character->framesCounter = 0;
        character->currentFrame++;
        if (character->currentFrame > 3) character->currentFrame = 0;
    }
    character->frameRec.x = (float)character->currentFrame * character->frameRec.width;
    character->frameRec.y = (float)direction * character->frameRec.height;
    character->lastDirection = direction;
}

void MoveCharacter(Character *character, Vector2 direction) {
    character->position.x += direction.x;
    character->position.y += direction.y;
}