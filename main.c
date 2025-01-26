#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

typedef struct Character {
    Vector2 position;
    Texture2D texture;
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
} Character;

Character InitCharacter(const char *texturePath, Vector2 position, float frameWidth, float frameHeight, int framesSpeed){
    Character character = {0};
    character.position = position;
    character.texture = LoadTexture(texturePath);
    character.frameRec = (Rectangle){0.0f, 0.0f, frameWidth, frameHeight};
    character.currentFrame = 0;
    character.framesCounter = 0;
    character.framesSpeed = framesSpeed;
    return character;
}

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Recife Valley");

    Texture2D mainCharacter = LoadTexture("content/Characters/Abigail.png");

    Vector2 position = {(float)screenWidth/2, (float)screenHeight/2};
    Rectangle frameRec = { 0.0f, 0.0f, 16.0f, 32.0f};
    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 6;

    //--------------------------------------------------------------------------------------
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //---------------------------------------------------------------------------------
        framesCounter++;

        if (IsKeyDown(KEY_D)){ // RIGHT
            if(framesCounter > (60/framesSpeed)){
                framesCounter = 0;

                currentFrame++;

                if(currentFrame > 3) currentFrame = 0;

                frameRec.y = 1.0f*frameRec.height;
                frameRec.x = (float)currentFrame*frameRec.width;
            }
            position.x += 2.0f;
        } 
        if (IsKeyDown(KEY_A)){ // LEFT
            if(framesCounter > (60/framesSpeed)){
                framesCounter = 0;

                currentFrame++;

                if(currentFrame > 3) currentFrame = 0;

                frameRec.y = 3.0f*frameRec.height;
                frameRec.x = (float)currentFrame*frameRec.width;
            }
            position.x -= 2.0f;
        }
        if (IsKeyDown(KEY_W)){ // UP
            if(framesCounter > (60/framesSpeed)){
                framesCounter = 0;

                currentFrame++;

                if(currentFrame > 3) currentFrame = 0;

                frameRec.y = 2.0f*frameRec.height;
                frameRec.x = (float)currentFrame*frameRec.width;
            }
            position.y -= 2.0f;  
        } 
        if (IsKeyDown(KEY_S)){ // DOWN
            if(framesCounter > (60/framesSpeed)){
                framesCounter = 0;

                currentFrame++;

                if(currentFrame > 3) currentFrame = 0;

                frameRec.y = 0.0f*frameRec.height;
                frameRec.x = (float)currentFrame*frameRec.width;
            }
            position.y += 2.0f;
        }
        else if(framesCounter > (60/framesSpeed)){
            framesCounter = 0;
        } 
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTextureRec(mainCharacter, frameRec, position, WHITE);

            
        EndDrawing(); 
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(mainCharacter);

    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}