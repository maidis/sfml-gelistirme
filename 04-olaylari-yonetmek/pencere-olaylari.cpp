#include <SFML/Window.hpp>

int main()
{
    // Ana pencereyi oluştur
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Olayları");

    // Girdi yöneticisine oluşturduğumuz pencereyle ilişkilendirilmiş bir referans al
    // ve sonraki kullanımlar için sakla
    const sf::Input& Input = App.GetInput();

    // Ana döngüye başla
    while (App.IsOpened())
    {
        // Olayları işle
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Pencereyi kapat: çıkış
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // ESC tuşu: çıkış
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();
        }

        // Kullanılmasa da örnek olması açısından bazı girdi durumları alalım
        bool         LeftKeyDown     = Input.IsKeyDown(sf::Key::Left);
        bool         RightButtonDown = Input.IsMouseButtonDown(sf::Mouse::Right);
        bool         JoyButton1Down  = Input.IsJoystickButtonDown(0, 1);
        unsigned int MouseX          = Input.GetMouseX();
        unsigned int MouseY          = Input.GetMouseY();
        int          JoystickX       = Input.GetJoystickAxis(1, sf::Joy::AxisZ);
        int          JoystickY       = Input.GetJoystickAxis(1, sf::Joy::AxisY);
        int          JoystickPOV     = Input.GetJoystickAxis(1, sf::Joy::AxisPOV);

        // Pencereyi ekranda göster
        App.Display();
    }

    return EXIT_SUCCESS;
}
