
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
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML RGB Circles");

    // Limit to 60 frames per second
    App.SetFramerateLimit(60);

    // Define and initialize some variables
    float y, spin, spinPct, prevMY = 0;
    bool bFirstMouseMove = 1;

    // Clear screen for screenshot
    App.Clear();

    // Create an image
    sf::Image Image1;

    // Draw red, green, and blue circles
    sf::Shape circle1 = sf::Shape::Circle(100, 100, 100, sf::Color(255,0,0));
    sf::Shape circle2 = sf::Shape::Circle(200, 100, 100, sf::Color(0,255,0));
    sf::Shape circle3 = sf::Shape::Circle(150, 200, 100, sf::Color(0,0,255));

    // Set blend mode to add for a nice effect
    circle1.SetBlendMode(sf::Blend::Add);
    circle2.SetBlendMode(sf::Blend::Add);
    circle3.SetBlendMode(sf::Blend::Add);

    // Draw circles
    App.Draw(circle1);
    App.Draw(circle2);
    App.Draw(circle3);

    // Take a screenshot of only circles part, i don't sure about coordinates?
    Image1.CopyScreen(App, sf::IntRect(0, 0, 600, 600));

    // Clear screen for animation
    App.Clear();

    // Create a sprite
    sf::Sprite Sprite(Image1);

    // Set image origin and pozition
    //Sprite.SetOrigin(Sprite.GetSize() * 0.5f);
    Sprite.SetOrigin(150,150);
    Sprite.SetPosition(App.GetView().GetSize() * 0.5f);

    // Start game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // Escape key : exit
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();

            // MouseMove event : adjust spinPct
            if (Event.Type == sf::Event::MouseMoved)
            {
                // Update spinPct by the distance the mouse moved in x and y.
                // We use abs so it always spins in the same direction

                // We use the "bFirstMouseMove" flag so that we calculate only
                // after we have the first prevMY and prevMX stored;
                if (bFirstMouseMove == false)
                    {
                    spinPct += (float)(y - prevMY) * 0.03;
                    } else bFirstMouseMove = false;

                // Store the x and y so we can get the prev value
                // next time the mouse is moved
                prevMY = y;
            }
        }

        // Reduce the spinPct by a small amount so that the spinning eventually stops
        spinPct *= 0.99f;

        // Update the spin -which is storing the total rotation- by spinPct
        spin += spinPct;

        // Lets use the mouse x and y position to affect the x and y paramters of the curve.
        // These values are quite large, so we scale them down by 0.0001
        float yPct = (float)(App.GetInput().GetMouseY());

        // Lets also use the spin to transform the curve over time
        yPct += spin * 0.002;

        // Rotate circles
        Sprite.Rotate(yPct);

        // Draw circles
        App.Draw(Sprite);

        // Display animation and then clear screen
        App.Display();
        App.Clear();
    }

    return EXIT_SUCCESS;
}
