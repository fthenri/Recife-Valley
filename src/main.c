#include "raylib.h"
#include "character.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Recife Valley");

    // Inicializa o personagem principal
    Character mainCharacter = InitCharacter("content/Characters/Abigail.png", (Vector2){screenWidth / 2, screenHeight / 2}, 16.0f, 32.0f, 6);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Variáveis de direção e animação
        Vector2 direction = {0.0f, 0.0f};
        int animationDirection = -1;

        // Movimentação do personagem
        if (IsKeyDown(KEY_D)) {
            direction.x += 2.0f;
            animationDirection = 1; // Direita
        }
        if (IsKeyDown(KEY_A)) {
            direction.x -= 2.0f;
            animationDirection = 3; // Esquerda
        }
        if (IsKeyDown(KEY_W)) {
            direction.y -= 2.0f;
            animationDirection = 2; // Cima
        }
        if (IsKeyDown(KEY_S)) {
            direction.y += 2.0f;
            animationDirection = 0; // Baixo
        }

        // Atualização de animação ou parada
        if (animationDirection != -1) {
            UpdateCharacterAnimation(&mainCharacter, animationDirection);
        } else {
            mainCharacter.currentFrame = 0;
            mainCharacter.frameRec.x = 0.0f;
            mainCharacter.frameRec.y = (float)mainCharacter.lastDirection * mainCharacter.frameRec.height;
        }

        MoveCharacter(&mainCharacter, direction);

        // Renderização
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextureRec(mainCharacter.texture, mainCharacter.frameRec, mainCharacter.position, WHITE);
        EndDrawing();
    }

    // Descarrega os recursos
    UnloadTexture(mainCharacter.texture);
    CloseWindow();

    return 0;
}