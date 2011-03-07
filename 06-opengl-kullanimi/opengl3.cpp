// opengl.d'den uyarlanmıştır
#include <SFML/Graphics.hpp>
#include <GL/glut.h>

int main()
{
    // Ana pencereyi oluştur
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML OpenGL III");

    sf::Clock Clock;

    // Arkaplan fotoğrafını al
    sf::Image backgroundImage;
    if (!backgroundImage.LoadFromFile("resimler/arkaplan.jpg"))
        return EXIT_FAILURE;

    // Arkaplan için bağımsız görüntü oluştur
    sf::Sprite background(backgroundImage);

    // Bir OpenGL kaplaması oluşturalım
    // Yüklediğimiz resmi doğrudan da OpenGL kaplaması olarak kullanabilirdik
    // ama daha fazla kontrol (mipmap oluşturmak vs.) için resmin piksellerinden yeni bir tane oluşturuyoruz
    GLuint texture = 0;
    {
        sf::Image Image;
        if (!Image.LoadFromFile("resimler/sfml-logo-256.png"))
            return EXIT_FAILURE;

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, Image.GetWidth(), Image.GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, Image.GetPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    }

    // Renk ve derinlik temizleme değerlerini ayarla
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Z-buffer'ı okuma ve yazma için aktifleştir
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Bir perspektif izdüşümü ayarla
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 500.f);

    // Kaplamamızı bağlayalım
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glColor4f(1.f, 1.f, 1.f, 1.f);

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

        // Arkaplan resmini çizdirelim
        App.SaveGLStates();
        App.Draw(background);
        App.RestoreGLStates();

        // Fare pozisyonunu öğrenelim, böylece kutumuza gidebiliriz
        sf::Input Input;
        float x =  Input.GetMouseX() * 200.f / App.GetWidth();
        float y = -Input.GetMouseY() * 200.f / App.GetHeight();

        // Biraz dönüştürme uygulayalım
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(x, y, -200.f);

        glRotatef(Clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
        glRotatef(Clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
        glRotatef(Clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

        // Küpü çizelim
        float size = 50.f;
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
            glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
            glTexCoord2f(1, 1); glVertex3f( size,  size, -size);
            glTexCoord2f(1, 0); glVertex3f( size, -size, -size);

            glTexCoord2f(0, 0); glVertex3f(-size, -size, size);
            glTexCoord2f(0, 1); glVertex3f(-size,  size, size);
            glTexCoord2f(1, 1); glVertex3f( size,  size, size);
            glTexCoord2f(1, 0); glVertex3f( size, -size, size);

            glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
            glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
            glTexCoord2f(1, 1); glVertex3f(-size,  size,  size);
            glTexCoord2f(1, 0); glVertex3f(-size, -size,  size);

            glTexCoord2f(0, 0); glVertex3f(size, -size, -size);
            glTexCoord2f(0, 1); glVertex3f(size,  size, -size);
            glTexCoord2f(1, 1); glVertex3f(size,  size,  size);
            glTexCoord2f(1, 0); glVertex3f(size, -size,  size);

            glTexCoord2f(0, 1); glVertex3f(-size, -size,  size);
            glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
            glTexCoord2f(1, 0); glVertex3f( size, -size, -size);
            glTexCoord2f(1, 1); glVertex3f( size, -size,  size);

            glTexCoord2f(0, 1); glVertex3f(-size, size,  size);
            glTexCoord2f(0, 0); glVertex3f(-size, size, -size);
            glTexCoord2f(1, 0); glVertex3f( size, size, -size);
            glTexCoord2f(1, 1); glVertex3f( size, size,  size);
        glEnd();

        App.Display();
    }

    // Madem oluştuduk yok da edelim kaplamamızı
    glDeleteTextures(1, &texture);

    return EXIT_SUCCESS;
}
