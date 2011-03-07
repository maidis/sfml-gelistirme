#include <SFML/Window.hpp>
#include <GL/glut.h>

int main()
{
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML OpenGL");

    sf::Clock Clock;

    // Renk ve derinlik temizleme değerlerini ayarla
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Z-buffer'ı okuma ve yazma için aktifleşti
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Bir perspektif izdüşümü ayarla
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 500.f);

    // Ana döngüye başla
    while (App.IsOpened())
    {
        // İşleme olayları
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                App.Close();

            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();

            // Yeniden boyutlandırma olayı: görüş alanını ayarla
            if (Event.Type == sf::Event::Resized)
                glViewport(0, 0, Event.Size.Width, Event.Size.Height);
        }

        // OpenGL komutlarını kullanmandan önce aktif pencereyi ayarlayın
        // Aktif pencere burada her zaman aynı olduğu için gereksizdir
        // Ama çoklu pencere veya kontrol kullandığınızda bunu yapmayı unutmayın
        App.SetActive();

        // Renk ve derinlik ön belleğini temizle
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Biraz dönüştürme uygulayalım
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(Clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
        glRotatef(Clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
        glRotatef(Clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

        // Küpü çizelim
        glBegin(GL_QUADS);

            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f( 50.f,  50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);

            glVertex3f(-50.f, -50.f, 50.f);
            glVertex3f(-50.f,  50.f, 50.f);
            glVertex3f( 50.f,  50.f, 50.f);
            glVertex3f( 50.f, -50.f, 50.f);

            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f(-50.f,  50.f,  50.f);
            glVertex3f(-50.f, -50.f,  50.f);

            glVertex3f(50.f, -50.f, -50.f);
            glVertex3f(50.f,  50.f, -50.f);
            glVertex3f(50.f,  50.f,  50.f);
            glVertex3f(50.f, -50.f,  50.f);

            glVertex3f(-50.f, -50.f,  50.f);
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f,  50.f);

            glVertex3f(-50.f, 50.f,  50.f);
            glVertex3f(-50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f,  50.f);

        glEnd();

        App.Display();
    }

    return EXIT_SUCCESS;
}
