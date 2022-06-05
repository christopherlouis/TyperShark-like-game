#include "Main.h"

void main() {
	loadDefaultAssets();

	sf::RenderWindow window(sf::VideoMode(512, 512), "Welcome To Zoo", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize); //untuk memunculkan window baru
																																	//sf::RectangleShape player(sf::Vector2f(150.0f, 100.0f));// untuk membuat player
																																	//sf::RectangleShape background(sf::Vector2f(512.0f, 512.0f));
																																	//sf::RectangleShape tombol1(sf::Vector2f(150.0f, 50.0f));
	int mode = 0;
	//menu
	main_menu menu(512, 512);

	//setting
	setting set(512, 512);

	//audio

	music_town.setVolume(20);
	music_town.play();
	music_town.setLoop(true);

	//score
	menu.loadscore();
	menu.tampil();

	//sf::Music music;
	//music.openFromFile("01Town0.wav");
	//music.setVolume(30);
	//music.play();

	//player.setFillColor(sf::Color::Cyan);
	//sf::Sprite player;
	//player.setPosition(206.0f, 206.0f);
	//tombol1.setPosition(180.0f, 206.0f);

	//sf::Texture playertexture;
	//playertexture.loadFromFile("sfml.png");
	//player.setTexture(&playertexture);

	//sf::Texture back;
	//back.loadFromFile("zoo.png");
	//background.setTexture(&back);

	//sf::Texture tb1;
	//tb1.loadFromFile("Menu Buttons sprite (BnW).png");
	//tombol1.setTexture(&tb1);

	//sf::Vector2u texturesize = tb1.getSize();
	//texturesize.x /= 4;
	//texturesize.y /= 5;
	//tombol1.setTextureRect(sf::IntRect(texturesize.x * 0, texturesize.y * 0, texturesize.x, texturesize.y));

	/*sf::Vector2u texturesize = playertexture.getSize();
	texturesize.x /= 4;
	texturesize.y /= 1;
	player.setTextureRect(sf::IntRect(texturesize.x*2, texturesize.y*0, texturesize.x, texturesize.y));*/

	while (window.isOpen()) {
		sf::Event evnt;//untuk apa saja yang kita lakukan.
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;

				//case sf::Event::Resized: //untuk resized.
				//    //std::cout << "NEW WINDOW HEIGHT : " << evnt.size.height << " NEW WINDOW WIDTH : " << evnt.size.width << std::endl;
				//    printf("NEW WINDOW HEIGHT : %i NEW WINDOW WIDTH : %i \n", evnt.size.height, evnt.size.width);
				//    break;
				//case sf:: Event::TextEntered: //untuk ngetik text.
				//    if (evnt.text.unicode < 128) {
				//        printf("%c",evnt.text.unicode);
				//    }
			}
		}

		//untuk jalan
		//pertanyaan f itu buat apa ?

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		player.move(0.0f, 0.1f);
		}*/
		//untuk fungsi klik kiri di mouse
		//static_cast<float>(mousepos.y) beda (float)mousepos.y bedanya apa ?

		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousepos = sf::Mouse::getPosition(window);
		player.setPosition((float)mousepos.x, (float)mousepos.y);
		}*/
		//menu.mouse_klik(window);
		set.mouse_klik(window);
		menu.mouse_klik(window);
		//player.setTexture(&playertexture);



		window.clear(); //untuk biar kegambar e mek 1.

		if (mode == 0) {

			menu.draw(window);

			mode = menu.get_mode();

			if (mode == 1) {
				set.set_mode();
			}

			if (mode == 2) {
				music_town.stop();
				window.close();
				gamerun();
			}
			if (mode == 3) {

			}
			if (mode == 4) {
				window.close();
			}

			window.display();

			/* std::cout << mode << " \n";*/
		}

		else if (mode == 1) {

			set.draw(window);

			mode = set.get_mode2();

			if (mode == 0) {
				menu.set_mode();
			}

			window.display();

			/*std::cout << mode << " \n";*/

		}

		//window.display();
		//window.draw(background);
		//window.draw(tombol1); //untuk gambar.
		//window.display(); //untuk display gambar.

	}
}
