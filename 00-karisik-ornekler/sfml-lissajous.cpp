
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>

////////////////////////////////////////////////////////////
/// Entry point of application
/// Ported from openFrameworks advancedGraphicsExample
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Create main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML Lissajous");

    // Limit to 60 frames per second
    App.SetFramerateLimit(60);

    // Define and initialize some variables
    float x, y, spin, spinPct, prevMY, prevMX = 0;
    bool bFirstMouseMove = 1;

    // Start game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.PollEvent(Event))
        {
            // Pencere kapandığında veya Escape tuşuna basıldığında : çıkış
            if ((Event.Type == sf::Event::Closed) ||
               ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Escape)))
            {
                App.Close();
                break;
            }
            // MouseMove event : adjust spinPct
            if (Event.Type == sf::Event::MouseMoved)
            {
                // Update spinPct by the distance the mouse moved in x and y.
                // We use abs so it always spins in the same direction

                // We use the "bFirstMouseMove" flag so that we calculate only
                // after we have the first prevMY and prevMX stored;
                if (bFirstMouseMove == false)
                    {
                    spinPct += (float)abs(y - prevMY) * 0.03;
                    spinPct += (float)abs(x - prevMX) * 0.03;
                    } else bFirstMouseMove = false;

                // Store the x and y so we can get the prev value
                // next time the mouse is moved
                prevMY = y;
                prevMX = x;
            }
        }

        // Reduce the spinPct by a small amount so that the spinning eventually stops
        spinPct *= 0.99f;

        // Update the spin -which is storing the total rotation- by spinPct
        spin += spinPct;

        // Lets make the curves out of a series of points
        for(int i = 0; i < 800; i++)
        {
            // Lets use the mouse x and y position to affect the x and y paramters of the curve.
            // These values are quite large, so we scale them down by 0.0001
            float xPct = (float)(i * sf::Mouse::GetPosition().x) * 0.0001;
            float yPct = (float)(i * sf::Mouse::GetPosition().y) * 0.0001;

            // Lets also use the spin to transform the curve over time
            xPct += spin * 0.002;
            yPct += spin * 0.003;

            // Lets feed these two values to sin and cos functions and multiply
            // by how large we want it to be. Because the sin function is producing
            // -1 to 1 results the total width in this case will be double what we specify.
            x =  800.0  * sin(xPct) * 0.5;
            y =  600.0  * cos(yPct) * 0.5;

            // We draw the rects as small 2 pixel by 2 pixel squares and
            // add the position we want them to be osicalting around
            sf::Shape Rect2 = sf::Shape::Rectangle(0, 0, 2, 2, sf::Color::Green);
            Rect2.Move(x + 400, y + 300);
            App.Draw(Rect2);
        }

        // Display current Lissajous curve and then clear screen
        App.Display();
        App.Clear();
    }

    return EXIT_SUCCESS;
}
