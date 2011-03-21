// başlıklar
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML Shapes");

    while (App.IsOpened())
    {
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }

        App.Clear();

        // Öntanımlı şekiller çiz
        App.Draw(sf::Shape::Line(10, 10, 710, 100, 15, sf::Color::Red));
        App.Draw(sf::Shape::Circle(200, 200, 100, sf::Color::Yellow, 10, sf::Color::Blue));
        App.Draw(sf::Shape::Rectangle(350, 200, 600, 350, sf::Color::Green));

        // Özel bir çokgen oluştur
        sf::Shape Polygon;
        Polygon.AddPoint(0, -50,  sf::Color(255, 0, 0),     sf::Color(0, 128, 128));
        Polygon.AddPoint(50, 0,   sf::Color(255, 85, 85),   sf::Color(0, 128, 128));
        Polygon.AddPoint(50, 50,  sf::Color(255, 170, 170), sf::Color(0, 128, 128));
        Polygon.AddPoint(0, 100,  sf::Color(255, 255, 255), sf::Color(0, 128, 128));
        Polygon.AddPoint(-50, 50, sf::Color(255, 170, 170), sf::Color(0, 128, 128));
        Polygon.AddPoint(-50, 0,  sf::Color(255, 85, 85),   sf::Color(0, 128, 128));

        // Çokgenin ana hattı genişliğini ayarla
        Polygon.SetOutlineThickness(5);

        // İç doldurmayı devre dışı bırak, ana hat çizimini aktifleştir
        Polygon.EnableFill(false);
        Polygon.EnableOutline(true);

        // Şekillerimizle oynayalım biraz
        Polygon.SetColor(sf::Color(255, 255, 255, 200));
        Polygon.Move(300, 300);
        Polygon.Scale(3, 2);
        Polygon.Rotate(45);

        App.Draw(Polygon);

        App.Display();
    }

    return EXIT_SUCCESS;
}
