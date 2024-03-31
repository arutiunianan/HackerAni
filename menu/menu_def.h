MENU_DEF(start, 1,
    {
        char picture_path[16] = "";
        strcpy(picture_path, bg_path);
        for(int i = 0; i < 5; i++)
        {
            picture_path[10] = '1' + i;
            WindowWithSleep(window, picture_path, 1);
        }
        return true;
    }
) 
			 	
MENU_DEF(middle, 2,
    {
        if(event.type == Event::Closed)
        {
            window->close();
        }

        if(event.type == Event::MouseButtonPressed) 
        {
            if(IsMouseOver(window, 450, 650, 350, 550)) 
            {
                return true;
            }
            else if(IsMouseOver(window, 460, 560, 270, 370) || IsMouseOver(window, 565, 665, 290, 390)) 
            {
                return false;
            }
        }
        WindowWithSleep(window, bg_path,0);
    }
)
			 	
MENU_DEF(end, 3,
    {
        if(event.type == Event::Closed)
        {
            window->close();
            return true;
        }
        WindowWithSleep(window, bg_path, 0);
    }
)