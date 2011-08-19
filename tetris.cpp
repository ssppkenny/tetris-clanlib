/*
**  ClanLib SDK
**  Copyright (c) 1997-2011 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
**    Mark Page
*/

#include "precomp.h"
#include "tetris.h"



// The start of the Application
int Tetris::start(const std::vector<CL_String> &args)
{
    quit = false;
    finish = false;

//    leftborderlist = new LeftBordeList();
 //   rightbordelist = new RightBordeList();

    // Set the window
    CL_DisplayWindowDescription desc;
    desc.set_title("Tetris");
    desc.set_size(CL_Size(320, 640), true);
    desc.set_allow_resize(true);

    CL_DisplayWindow window(desc);

    // Connect the Window close event
    CL_Slot slot_quit = window.sig_window_close().connect(this, &Tetris::on_window_close);

    // Connect a keyboard handler to on_key_up()
    CL_Slot slot_input_up = (window.get_ic().get_keyboard()).sig_key_up().connect(this, &Tetris::on_input_up);

    // Get the graphic context
    CL_GraphicContext gc = window.get_gc();

    // Load a sprite from a png-file
    //CL_Sprite spr_logo(gc, "Resources/logo.png");

    float sin_count = 0.0f;
    float ypos = 0.0f;
    float ydir = 0.3f;

    unsigned int last_time = CL_System::get_time();

    CL_Font font(gc, "Utopia", 40);
    linesRemoved = 0;

    // Run until someone presses escape
    while (!quit)
    {
        unsigned int current_time = CL_System::get_time();
        float time_delta_ms = static_cast<float> (current_time - last_time);
        last_time = current_time;
        float shift = time_delta_ms/20;
        shift = 1.0f;

        //std::cout << "shift = " << shift << std::endl;

        // Clear the display in a dark blue nuance
        // The four arguments are red, green, blue and alpha
        gc.clear(CL_Colorf(25.0f,25.0f,25.0f));
        std::string s;
        std::stringstream out;
        out << linesRemoved / 2;
        s = out.str();
        font.draw_text(gc, 250,40, s.c_str(), CL_Colorf::blue);

        int l = bottomborderlist.getLineNumberToDelete();
        while (l != -1)
        {
            l = bottomborderlist.getLineNumberToDelete();

            bottomborderlist.removeLine(l);
            linesRemoved++;

        }



        if (!figlist.checkCollisionDown(bottomborderlist))
        {
            figlist.moveDown(shift);


        }
        else
        {
            FigureList newfl = figlist;
            newfl.setStablePosition();
            bottomborderlist.addList(newfl.getFigureList());
            //leftborderlist.addList(newfl.getFigureList());
            //rightborderlist.addList(newfl.getFigureList());
            if (!finish)
            {
                figlist.reset();
            }


            if (figlist.checkCollisionDown(bottomborderlist))
            {
                std::cout << "Collision detected" << std::endl;
                finish  = true;
            }



        }

        if (finish == true)
        {
            leftborderlist.draw(gc);
            rightborderlist.draw(gc);
            bottomborderlist.draw(gc);

        }
        else
        {
            figlist.draw(gc);
            leftborderlist.draw(gc);
            rightborderlist.draw(gc);
            bottomborderlist.draw(gc);
        }










        // Flip the display, showing on the screen what we have drawed
        // since last call to flip()
        window.flip(1);

        // This call processes user input and other events
        CL_KeepAlive::process(0);
    }
    return 0;
}

// A key was pressed
void Tetris::on_input_up(const CL_InputEvent &key, const CL_InputState &state)
{
    if(key.id == CL_KEY_ESCAPE)
    {
        quit = true;
    }

    if (key.id == CL_KEY_CONTROL)
    {
        figlist.drop(bottomborderlist);

    }


    if(key.id == CL_KEY_LEFT && !figlist.checkCollisionLeftSide(leftborderlist))
    {
        figlist.moveLeft(32.0f);
    }

    //figlist.previewRotationClockwise().checkCollisionRightSide(rightborderlist);

    if(key.id == CL_KEY_RIGHT && !figlist.checkCollisionRightSide(rightborderlist) )
    {

        figlist.moveRight(32.0f);
    }

    if (key.id == CL_KEY_SPACE && !figlist.previewRotationClockwise().checkCollisionRightSide(rightborderlist)  && !figlist.previewRotationClockwise().checkCollisionLeftSide(leftborderlist))
    {
        figlist.rotateClockwise();
    }

}

// The window was closed
void Tetris::on_window_close()
{
    quit = true;
}


