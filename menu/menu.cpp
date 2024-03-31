#include "menu.h"

Background::Background(const char* image_path)
{
    assert(image_path != nullptr);

    image.loadFromFile(image_path);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}

void Background::Draw(RenderWindow* window)
{
    assert(window != nullptr);

    window->draw(this->sprite);
}


bool IsMouseOver(RenderWindow* window, int x1, int x2, int y1, int y2) 
{
    assert(window != nullptr);

    Vector2i  mouse_position = Mouse::getPosition(*window);
    return (mouse_position.x > x1 && mouse_position.x < x2 && mouse_position.y > y1 && mouse_position.y < y2);
}

void WindowWithSleep(RenderWindow* window, const char* picture_path, double sleep_time)
{
    assert(window       !=  nullptr);
    assert(picture_path !=  nullptr);
    assert(sleep_time   >=  0);

    Background background(picture_path);
    background.Draw(window);
    window->display();
    sleep(seconds(sleep_time));
}

bool OpenMenu(RenderWindow* window, const char* bg_path, int num_of_window)
{
    assert(window  != nullptr);
    assert(bg_path != nullptr);

    while(window->isOpen())
    {
        Event event;
        while(window->pollEvent(event))
        {
            switch(num_of_window)
            {
                #define MENU_DEF(menu_part, menu_num, code)  \
                case menu_num:                                \
                    code;                                      \
                break;

                #include "menu_def.h"
            }
            #undef MENU_DEF
        }
    }
}

void PlaySound(Sound* sound, SoundBuffer* buffer, const char* music_path)
{
    assert(sound != nullptr);
    assert(buffer != nullptr);

    buffer->loadFromFile(music_path);

    sound->setBuffer(*buffer);
    sound->play();
}