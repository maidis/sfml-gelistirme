// original code by TheTedinator
// http://sfml-dev.org/forum/viewtopic.php?p=29184
#include <SFML/Graphics.hpp> 
#include <math.h> 


int main() 
{ 
    const float pi=3.141592654; 

    sf::RenderWindow App(sf::VideoMode(1024, 600), "SFML Custom Shapes"); 

    sf::Shape Star; 

    Star.AddPoint((200*cos(((2*pi)/5))), (200*sin(((2*pi)/5))),  sf::Color::Yellow, sf::Color::Red); 
    Star.AddPoint((200*cos(((6*pi)/5))), (200*sin(((6*pi)/5))),  sf::Color::Yellow, sf::Color::Green); 
    Star.AddPoint((200*cos(10*pi/5)), (200*sin(10*pi/5)),  sf::Color::Yellow, sf::Color::White); 
    Star.AddPoint((200*cos(((4*pi)/5))), (200*sin(((4*pi)/5))),  sf::Color::Yellow, sf::Color::Blue); 
    Star.AddPoint((200*cos(((8*pi)/5))), (200*sin(((8*pi)/5))),  sf::Color::Yellow, sf::Color::Magenta);


    sf::Shape Pentagon; 

    Pentagon.AddPoint((200*cos(((2*pi)/5))), (200*sin(((2*pi)/5))),  sf::Color::Yellow, sf::Color::Red); 
    Pentagon.AddPoint((200*cos(((4*pi)/5))), (200*sin(((4*pi)/5))),  sf::Color::Yellow, sf::Color::Green); 
    Pentagon.AddPoint((200*cos(6*pi/5)), (200*sin(6*pi/5)),  sf::Color::Yellow, sf::Color::White); 
    Pentagon.AddPoint((200*cos(((8*pi)/5))), (200*sin(((8*pi)/5))),  sf::Color::Yellow, sf::Color::Blue); 
    Pentagon.AddPoint((200*cos(((10*pi)/5))), (200*sin(((10*pi)/5))),  sf::Color::Yellow, sf::Color::Magenta); 

    Star.Move(250, 300); 
    Star.EnableFill(true); 
    Star.EnableOutline(true); 
    Star.SetOutlineThickness(25);

    Pentagon.Move(750, 300); 
    Pentagon.EnableFill(true); 
    Pentagon.EnableOutline(true); 
    Pentagon.SetOutlineThickness(25);

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
        } 

        // Clear screen 
        App.Clear(); 

        App.Draw(Star); 
        App.Draw(Pentagon); 

        // Finally, display the rendered frame on screen 
        App.Display(); 
       
    } 

    return EXIT_SUCCESS; 
}
