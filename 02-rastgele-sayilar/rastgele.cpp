#include <SFML/System.hpp>
#include <iomanip>
#include <iostream>

int main()
{
    // Şu anki tohum
    unsigned int InitialSeed = sf::Randomizer::GetSeed();
    std::cout << "İlk tohum: " << InitialSeed << std::endl << std::endl;

    // 0 ve 100 arasında tam sayılar üret
    std::cout << "0 ile 100 arası rastgele tam sayılar oluşturuluyor:" << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << sf::Randomizer::Random(0, 100) << " ";
    std::cout << std::endl << std::endl;

    // 0 ve 100 arasında tam sayılar üret
    std::cout << "0 ile 100 arası rastgele başka tam sayılar oluşturuluyor:" << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << sf::Randomizer::Random(0, 100) << " ";
    std::cout << std::endl << std::endl;

    // -1 ile 1 arasında kayan nokta sayılar oluştur
    std::cout << "-1 ile 1 arasında kayan nokta sayılar oluşturuluyor:" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < 10; ++i)
        std::cout << sf::Randomizer::Random(-1.f, 1.f) << " ";
    std::cout << std::endl << std::endl;

    // İlk tohumu kullan, aynı diziyi elde edeceğiz
    std::cout << "İlk tohuma dönülüyor..." << std::endl
              << "(oluşturulan sayılar, daha öncekileriyle aynı olacaklar)" << std::endl << std::endl;
    sf::Randomizer::SetSeed(InitialSeed);

    // 0 ve 100 arasında tam sayılar üret
    std::cout << "0 ile 100 arasında 10 rastgele sayı oluşturuluyor:" << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << sf::Randomizer::Random(0, 100) << " ";
    std::cout << std::endl << std::endl;

    // Giriş tuşuna basılana kadar bekle
    std::cout << "Çıkmak için giriş tuşuna basın...";
    std::cin.ignore(10000, '\n');

    return EXIT_SUCCESS;
}
