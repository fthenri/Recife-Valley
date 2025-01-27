TARGET = Recife-Valley

SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib_raylib
RELEASE_DIR = release

SOURCES = $(wildcard $(SRC_DIR)/*.c)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    CC = gcc
    CFLAGS = -Wall -std=c99 -I$(INCLUDE_DIR)
    LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    EXE_EXT =
else ifeq ($(UNAME_S), Darwin)
    CC = gcc
    CFLAGS = -Wall -std=c99 -I$(INCLUDE_DIR)
    LIBS = -L$(LIB_DIR) -lraylib -lm -lpthread -framework OpenGL -framework Cocoa -framework IOKit
    EXE_EXT =
else
    CC = gcc
    CFLAGS = -Wall -std=c99 -I$(INCLUDE_DIR) -mwindows
    LIBS = -L$(LIB_DIR) -lraylib -lopengl32 -lgdi32 -lwinmm
    EXE_EXT = .exe
endif

$(TARGET)$(EXE_EXT): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)$(EXE_EXT) $(LIBS)

release: $(TARGET)$(EXE_EXT)
	@echo "Criando release..."
	@mkdir -p $(RELEASE_DIR)
	@cp $(TARGET)$(EXE_EXT) $(RELEASE_DIR)/
	@test -d static && cp -r static $(RELEASE_DIR)/ || { echo "Erro: pasta 'static' não encontrada."; exit 1; }
	@echo "Release criada em: $(RELEASE_DIR)"

clean:
	rm -f $(TARGET)$(EXE_EXT)

	@echo "Limpeza concluida!"