#include "menu/menu.h"
using namespace sf;

int main(int argc, const char* argv[])
{
    if(argc > 2)
    {
        std::cout<<"Invalid number of args to program\n";
        return 1;
    }

    RenderWindow window(VideoMode(850, 580), "Voronin's hackers", Style::Default);
    SoundBuffer buffer;            
    Sound sound;

    PlaySound(&sound, &buffer, "menu/start.wav");
    OpenMenu(&window, "menu/start0.png", 1);

    bool right_button = OpenMenu(&window, "menu/middle.png", 2);
    if(right_button)
    {
        Hack((argc == 2) ? (argv[1]) : "HACKME.COM");
    }

    PlaySound(&sound, &buffer, right_button ? "menu/end.wav" : "menu/gachi.wav");
    OpenMenu(&window, right_button ? "menu/end.png" : "menu/titty.png", 3);

    return 0;
}