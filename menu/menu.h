#ifndef MENU_H_
#define MENU_H_

#include <assert.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../hack/hack.h"

using namespace sf;

class Background
{
    public:
        Background(const char* image_path);

        void Draw(RenderWindow* window);
        Sprite  sprite;
    private:
        
        Image   image;
        Texture texture;
};

void PlaySound(Sound* sound, SoundBuffer* buffer, const char* music_path);
bool OpenMenu(RenderWindow* window, const char* bg_path, int num_of_window);

#endif // #define MENU_H_