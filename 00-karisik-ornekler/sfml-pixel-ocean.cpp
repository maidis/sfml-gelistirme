
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
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML Pixel Ocean");

    // Limit to 60 frames per second
    App.SetFramerateLimit(60);

    // Define and initialize some variables
    float counter, k = 0.0;

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
        }

        // Add 0.029 to our counter
        counter = counter + 0.029f;

        // Lets make some 8bit looking waves out of rectangles
        for(int i = 0; i < App.GetView().GetSize().x; i += 50)
        {
            // Lets get a unique height for our 'wave' using sine
            float height = sin(counter + k);

            // sin produces -1 to 1 values, lets add 1 to make sure the height is always positive
            height += 1.0;

            // Now it is going from 0 to 2 but we want it to be taller than that.
            // Lets make it go from 0 - 100 by multiplying 50
            height *= 50;

            // Lets draw it!
            sf::Shape Rect3 = sf::Shape::Rectangle(0, 0, 50, -height, sf::Color(0, 90, 170, 128));
            Rect3.Move(i, App.GetView().GetSize().y);
            Rect3.SetBlendMode(sf::Blend::Alpha);
            App.Draw(Rect3);

            // This variable makes sure that each rect has a unique height otherwise
            // they would all be moving up and down at the same time
            k+=0.7;
        }

        // This is doing it again but for a different color
        k = 0;

        for(int i = 0; i < App.GetView().GetSize().x; i+= 50)
        {
            sf::Shape Rect4 = sf::Shape::Rectangle(0, 0, 50, -50 * (sin(1.4 * counter - k) + 1.0), sf::Color(0, 120, 190, 128));
            Rect4.Move(i + 5, App.GetView().GetSize().y);
            Rect4.SetBlendMode(sf::Blend::Alpha);
            App.Draw(Rect4);
            k += 0.4;
        }

        // Display waves and then clear screen
        App.Display();
        App.Clear();
    }

    return EXIT_SUCCESS;
}
