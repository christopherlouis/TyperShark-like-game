#include "Game.h"



void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	// do nothing until the elapsed time has passed.
	while (clock() < startClock + secondsAhead);
	return;
}


void gamerun() {
	sf::RenderWindow window(sf::VideoMode(windowwidth, windowheight), "WTZ", sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close);
	/*window.setFramerateLimit(144);*/

	loadDefaultGameArg();

	runtime.restart();
	while (window.isOpen()) {
		//clearing canvas
		window.clear(sf::Color(0, 0, 0, 255));
		window.draw(background_sprite);
		//time needed per cycle (sorta FPS)
		deltaTime = cycle.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::KeyPressed)//get input from keyboard 
			{
				if (evnt.key.code >= 0 && evnt.key.code < 26)//get alphabet a-z
					inputkeylog = (char)(evnt.key.code + 'a');
				//if (evnt.key.code >= 26 && evnt.key.code < 36)
				//{
				//	int inputtemp = evnt.key.code - 26;
				//	sizereq = inputtemp >= 3 ? (inputtemp <= 7 ? inputtemp : 7) : 3;

				//}//get nums
				//if (evnt.key.code >= 75 && evnt.key.code < 85)//set string length
				//{
				//	int inputtemp = evnt.key.code - 75;
				//	sizereq = inputtemp >= 3 ? (inputtemp <= 7 ? inputtemp : 7) : 3;
				//}
				//if (evnt.key.code >= 87 && evnt.key.code < 93 && !spawnenemies)//set enemy amount
				//{
				//	int inputtemp = evnt.key.code - 84;
				//	maxenemy = inputtemp;
				//	ReinitMovingText();
				//}
			}
			if (evnt.type == sf::Event::Closed) {
				window.close();
			} //window closed
			if (evnt.type == sf::Event::Resized) {
				float defaultaspectRatio = windowwidth * 1.0f / windowheight * 1.0f;
				float aspectRatio1 = window.getSize().x * 1.0f / window.getSize().y * 1.0f;
				float height1 = windowwidth * 1.0f / aspectRatio1;
				float width1 = windowheight * 1.0f * aspectRatio1;
				if (aspectRatio1 >= defaultaspectRatio)
					view1.setSize(width1, windowheight);
				else
					view1.setSize(windowwidth, height1);
				window.setView(view1);
			} //window resized
		}







		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && cmdcooldown > 1.0f) { //toggle enemy spawner
		//	spawnenemies = !spawnenemies;
		//	cmdcooldown = 0;
		//}

		if (inputkeylog != '\0')
			letters++;


		//================================================================================== Transition stage 0 >> 1
		if (score == 0 && enemytext.size() == 0 && stagecooldown < roundcooldown && waveC == 0) { //delay
			spawnenemies = false;
			stagecooldown += deltaTime;

			wavetrans.setString("Wave " + std::to_string(waveC + 1));
			if (stagecooldown <= 1.0f)
				wavetrans.setFillColor(sf::Color(0, 0, 255, (stagecooldown * 1.0f / 1.0f) * 255));
			else if (stagecooldown >= (roundcooldown - 1.0f))
				wavetrans.setFillColor(sf::Color(0, 0, 255, ((1.0f - (stagecooldown - roundcooldown - 1.0f) * 1.0f / 1.0f)) * 255));
		}
		else if (score == 0 && stagecooldown >= roundcooldown && waveC == 0) { //ganti param
			wavetrans.setFillColor(sf::Color(0, 0, 255, 0));
			spawnenemies = true;
			waveC++;
			stagecooldown = 0;
		}
		//==================================================================================

		//================================================================================== Transition stage 1 >> 2
		if (score > 50 && enemytext.size() > 0 && waveC == 1) {
			spawnenemies = false;
		}
		else if (score > 50 && enemytext.size() == 0 && stagecooldown < roundcooldown && waveC == 1) { //delay
			spawnenemies = false;
			stagecooldown += deltaTime;

			wavetrans.setString("Wave " + std::to_string(waveC + 1));
			if (stagecooldown <= 1.0f)
				wavetrans.setFillColor(sf::Color(0, 0, 255, (stagecooldown*1.0f / 1.0f) * 255));
			else if (stagecooldown >= (roundcooldown - 1.0f))
				wavetrans.setFillColor(sf::Color(0, 0, 255, ((1.0f - (stagecooldown - roundcooldown - 1.0f) * 1.0f / 1.0f)) * 255));
		}
		else if (score > 50 && stagecooldown >= roundcooldown && waveC == 1) { //ganti param
			wavetrans.setFillColor(sf::Color(0, 0, 255, 0));
			spawnenemies = true;
			maxenemy = 4;
			waveC++;
			ReinitMovingText();
		}
		else if (score > 50 && score < 90 && waveC == 2) { //random
			sizereq = rand() % (5 - 3) + 3;
			stagecooldown = 0;
		}
		//==================================================================================

		//================================================================================== Transition stage 2 >> 3
		if (score > 100 && enemytext.size() > 0 && waveC == 2) {
			spawnenemies = false;
		}
		else if (score > 100 && enemytext.size() == 0 && stagecooldown < roundcooldown && waveC == 2) { //delay
			stagecooldown += deltaTime;

			wavetrans.setString("Wave " + std::to_string(waveC + 1));
			if (stagecooldown <= 1.0f)
				wavetrans.setFillColor(sf::Color(0, 0, 255, (stagecooldown * 1.0f / 1.0f) * 255));
			else if (stagecooldown >= (roundcooldown - 1.0f))
				wavetrans.setFillColor(sf::Color(0, 0, 255, ((1.0f - (stagecooldown - roundcooldown - 1.0f) * 1.0f / 1.0f)) * 255));
		}
		else if (score > 100 && stagecooldown >= roundcooldown && waveC == 2) { //ganti param
			wavetrans.setFillColor(sf::Color(0, 0, 255, 0));
			spawnenemies = true;
			maxenemy = 4;
			waveC++;
			enemytimelength = 15.0f;
			ReinitMovingText();
		}
		else if (score > 100 && score < 240 && waveC == 3) { //random
			sizereq = rand() % (6 - 3) + 3;
			stagecooldown = 0;
		}
		//==================================================================================

		//================================================================================== Transition stage 3 >> 4
		if (score > 250 && enemytext.size() > 0 && waveC == 3) {
			spawnenemies = false;
		}
		else if (score > 250 && enemytext.size() == 0 && stagecooldown < roundcooldown && waveC == 3) { //delay
			stagecooldown += deltaTime;

			wavetrans.setString("Wave " + std::to_string(waveC + 1));
			if (stagecooldown <= 1.0f)
				wavetrans.setFillColor(sf::Color(0, 0, 255, (stagecooldown * 1.0f / 1.0f) * 255));
			else if (stagecooldown >= (roundcooldown - 1.0f))
				wavetrans.setFillColor(sf::Color(0, 0, 255, ((1.0f - (stagecooldown - roundcooldown - 1.0f) * 1.0f / 1.0f)) * 255));
		}
		else if (score > 250 && stagecooldown >= roundcooldown && waveC == 3) { //ganti param
			wavetrans.setFillColor(sf::Color(0, 0, 255, 0));
			spawnenemies = true;
			maxenemy = 5;
			waveC++;
			enemytimelength = 13.0f;
			ReinitMovingText();
		}
		else if (score > 250 && score < 390 && waveC == 4) { //random
			sizereq = rand() % (7 - 3) + 3;
			stagecooldown = 0;
		}
		//==================================================================================

		//================================================================================== Transition stage 4 >> 5
		if (score > 400 && enemytext.size() > 0 && waveC == 4) {
			spawnenemies = false;
		}
		else if (score > 400 && enemytext.size() == 0 && stagecooldown < roundcooldown && waveC == 4) { //delay
			stagecooldown += deltaTime;

			wavetrans.setString("Wave " + std::to_string(waveC + 1));
			if (stagecooldown <= 1.0f)
				wavetrans.setFillColor(sf::Color(0, 0, 255, (stagecooldown * 1.0f / 1.0f) * 255));
			else if (stagecooldown >= (roundcooldown - 1.0f))
				wavetrans.setFillColor(sf::Color(0, 0, 255, ((1.0f - (stagecooldown - roundcooldown - 1.0f) * 1.0f / 1.0f)) * 255));
		}
		else if (score > 400 && stagecooldown >= roundcooldown && waveC == 4) { //ganti param
			wavetrans.setFillColor(sf::Color(0, 0, 255, 0));
			spawnenemies = true;
			maxenemy = 5;
			waveC++;
			enemytimelength = 10.0f;
			ReinitMovingText();
		}
		else if (score > 400 && score < 590 && waveC == 5) { //random
			sizereq = rand() % (8 - 5) + 5;
			stagecooldown = 0;
		}
		//==================================================================================



		//================================================================================== Transition stage 5 >> 6
		if (score > 600 && enemytext.size() > 0 && waveC == 5) {
			spawnenemies = false;
		}
		else if (score > 600 && enemytext.size() == 0 && stagecooldown < roundcooldown && waveC == 5) { //delay
			stagecooldown += deltaTime;

			wavetrans.setString("Final Wave");
			if (stagecooldown <= 1.0f)
				wavetrans.setFillColor(sf::Color(0, 0, 255, (stagecooldown * 1.0f / 1.0f) * 255));
			else if (stagecooldown >= (roundcooldown - 1.0f))
				wavetrans.setFillColor(sf::Color(0, 0, 255, ((1.0f - (stagecooldown - roundcooldown - 1.0f) * 1.0f / 1.0f)) * 255));
		}
		else if (score > 600 && stagecooldown >= roundcooldown && waveC == 5) { //ganti param
			wavetrans.setFillColor(sf::Color(0, 0, 255, 0));
			sizereq = 10;
			spawnenemies = true;
			maxenemy = 1;
			waveC++;
			enemytimelength = 7.0f;
			ReinitMovingText();

		}
		else if (score > 600 && waveC == 6) { //random
			//boss hp

			window.draw(bossHpBarBack);
			window.draw(bossHpBar);


			sizereq = 10;
			stagecooldown = 0;
			if (enemytext.size() > 0) {
				tempmovecount += deltaTime;
				if (tempmovecount < 2.0f)
					enemytext[0].getPos().y = (windowheight - 150)* (tempmovecount*1.0f / 2.0f);
				else if (tempmovecount >= 2.0f && tempmovecount < 4.0f)
					enemytext[0].getPos().y = (windowheight - 150)* (1.0f - ((tempmovecount*1.0f - 2.0f) / 2.0f));
				else if (tempmovecount >= 4.0f)
					tempmovecount = 0;
			}
			
		}

		//bossend
		if (bosshp == 6) {
			enemytimelength = 5.0f;
		}
		else if (bosshp == 1 && score > 690) {
			spawnenemies = false;
		}
		else if (bosshp == 0 && enemytext.size() == 0 && waveC == 6) {
			waveC++;
			stagecooldown = 0;
		}
		else if (bosshp == 0 && waveC == 7 && stagecooldown < roundcooldown) {
			stagecooldown += deltaTime;
			std::cout << stagecooldown << std::endl;

			wavetrans.setString("You Win");
			if (stagecooldown <= 1.0f)
				wavetrans.setFillColor(sf::Color(0, 0, 255, (stagecooldown * 1.0f / 1.0f) * 255));
			else if (stagecooldown >= (roundcooldown - 1.0f) && stagecooldown <= 4.9f) {
				wavetrans.setFillColor(sf::Color(0, 0, 255, ((1.0f - (stagecooldown - roundcooldown - 1.0f) * 1.0f / 1.0f)) * 255));
			}
			else if (stagecooldown  >= 5.0f){
				std::fstream myfile("score.txt", std::ios::out | std::ios::trunc);
				if (myfile.is_open())
				{
					myfile << "Last Played\n";
					myfile << "=============STATS==============\n";
					myfile << "Words Solved: " << wordsolved << " word(s)\n";
					myfile << "Letter(s) Typed: " << letters << " letter(s)\n";
					myfile << "Scores: " << score << " pt\n";
					myfile << "Misses: " << misses << " misses\n";
					myfile << "Accuracy: " << ((letters - misses) * 1.0f / letters * 1.0f) * 100 << "%\n";
					myfile << "===============================\n";
					myfile.close();
				}
				else
				{
					std::cout << "error";
				}
				letters = 0, misses = 0, wordsolved = 0, score = 0, waveC = 1, sizereq = 3, enemytimelength = 17.0f, maxenemy = 3;
				health = 3;
				bg.stop();
				window.close();
				main();
			}
		}
		//==================================================================================


		if (firstletter) { // if firstletter matched before
			if (tempinput == tempcheck) { // if input is correct
				if (waveC == 6) {
					bosshp = bosshp - 1;
					bossHpBar.setSize(sf::Vector2f(bossHpBar.getSize().x - 30, bossHpBar.getSize().y));
				}
				score += tempcheck.size();
				wordsolved++;
				death.play();
				for (sf::Text& each : slots) {
					if (each.getString() == tempcheck) {
						each.setString("");//clear the container
						break;
					}
				}
				int index = 0;
				for (TextEnemy& each : enemytext) {
					if (each.getText() == tempcheck) {
						enemytext.erase(enemytext.begin() + index);//delete from array
						entitytext.erase(entitytext.begin() + index);
						break;
					}
					index++;
				}
				tempinput = "";//reset temps
				tempcheck = "";
				firstletter = false;//reset indicator
			}
			else {//if answer not correct
				if (tempcheck[tempinput.size()] == toupper(inputkeylog)) {//check if input is correct for that word
					tempinput += toupper(inputkeylog);//add to temp
				}
				else {
					if (inputkeylog != '\0') {
						misses++;
					}
				}
			}
			target.setString(tempinput);//set string for target
			target.setOrigin(target.getOrigin().x, target.getLocalBounds().height / 2.0f); //re align center pos
			if (pointer < enemytext.size()) //prevents accesses to memory outside array
				target.setPosition(enemytext[pointer].getPos()); //set pos according to specific answer

		}
		else { //if firstletter is absent
			pointer = 0;
			for (TextEnemy& each : enemytext) {
				if (each.getText()[0] == toupper(inputkeylog)) { //check if firstletter available
					firstletter = true;//set indicator
					tempinput += toupper(inputkeylog);//add letter to temp
					tempcheck = each.getText();//set the correct one to temp
					break;
				}
				pointer++;
			}
			if (inputkeylog != '\0' && !firstletter) {
				misses++;
			}
		}

		for (int j = 0; j < slots.size(); j++) {
			window.draw(slots[j]);//draw each text
			if (slots[j].getString() == "" && spawnenemies) { //if string empty and spawn enabled
				enemytext.push_back(TextEnemy(sf::Vector2f(windowwidth, slots[j].getPosition().y), sizereq, enemytimelength, runtime, enemytext)); //spawn new enemy

				if (waveC == 1) {
					entitytext.push_back(new Deer()); // spawn new character
				}
				else if (waveC == 6) {
					entitytext.push_back(new Spider()); // spawn new character boss "Spider"
				}
				else {
					int anim = rand() % (7 - 1) + 1;
					switch (anim)
					{
					case 1:
						entitytext.push_back(new Penguin()); // spawn new character
						break;
					case 2:
						entitytext.push_back(new Seal()); // spawn new character
						break;
					case 3:
						entitytext.push_back(new Bird()); // spawn new character
						break;
					case 4:
						entitytext.push_back(new Deer()); // spawn new character
						break;
					case 5:
						entitytext.push_back(new Sheep()); // spawn new character
						break;
					case 6:
						entitytext.push_back(new Horse()); // spawn new character
						break;
					}
				}

				slots[j].setString(enemytext.back().getText());//set the string
				slots[j].setOrigin(slots[j].getOrigin().x, slots[j].getLocalBounds().height / 2.0f);
				slots[j].setPosition(enemytext.back().getPos());//set the pos

																//player.setOrigin(each.getOrigin().x, each.getLocalBounds().height / 2.0f);

			}
			else { //else
				for (int i = 0; i < enemytext.size(); i++) {//search for same string
					if (slots[j].getString() == enemytext[i].getText()) {
						if (!enemytext[i].Update(runtime)) {//check if player too slow
							health--;
							if (tempcheck == enemytext[i].getText()) { //check if string was targeted
								enemytext.erase(enemytext.begin() + pointer);
								entitytext.erase(entitytext.begin() + pointer);
								tempinput = "";
								tempcheck = "";
								firstletter = false;
								target.setString("");
							}
							else {
								enemytext.erase(enemytext.begin() + i);
								entitytext.erase(entitytext.begin() + i);
							}
							slots[j].setString("");
						}
						else {
							slots[j].setPosition(enemytext[i].getPos());//set the pos
						}
						break;
					}
				}
			}
		}

		for (int i = 0; i < entitytext.size(); i++)
		{
			entitytext[i]->setPos(enemytext[i].getPos());
			entitytext[i]->Update(deltaTime);
			window.draw(entitytext[i]->getRectangleShape());
		}

		inputkeylog = '\0'; //reset input
		if (health <= 0) {//check health
			bg.stop();
			std::fstream myfile("score.txt", std::ios::out | std::ios::trunc);
			if (myfile.is_open())
			{
				myfile << "Last Played\n";
				myfile << "=============STATS==============\n";
				myfile << "Words Solved: " << wordsolved << " word(s)\n";
				myfile << "Letter(s) Typed: " << letters << " letter(s)\n";
				myfile << "Scores: " << score << " pt\n";
				myfile << "Misses: " << misses << " misses\n";
				myfile << "Accuracy: " << ((letters - misses) * 1.0f / letters * 1.0f) * 100 << "%\n";
				myfile << "===============================\n";
				myfile.close();
			}
			else
			{
				std::cout << "error";
			}
			letters = 0, misses = 0, wordsolved = 0, score = 0, waveC = 1, sizereq = 3, enemytimelength = 17.0f, maxenemy = 3;
			health = 3;
			window.close();
			main();
		}

		lives.setString("Lives: " + std::to_string(health));//update text health
		scores.setString("Score: " + std::to_string(score));//update score text
		if (waveC == 1) {
			wavecount.setString("Wave: " + std::to_string(waveC));//update wavecount
			window.setTitle("WTZ | Wave - " + std::to_string(waveC) + " | Lives: " + std::to_string(health) + " | Score: " + std::to_string(score) + " | Typing: " + tempinput);
		}
		if (waveC < 6 && waveC >= 2) {
			wavecount.setString("Wave: " + std::to_string(waveC));//update wavecount
			window.setTitle("WTZ | Wave - " + std::to_string(waveC + 1) + " | Lives: " + std::to_string(health) + " | Score: " + std::to_string(score) + " | Typing: " + tempinput);
		}
		if (waveC == 6) {
			wavecount.setString("Final Wave");//update wavecount
			window.setTitle("WTZ | Wave - " + std::to_string(waveC + 1) + " | Lives: " + std::to_string(health) + " | Score: " + std::to_string(score) + " | Typing: " + tempinput + " | Boss: " + std::to_string(bosshp));
		}
		if (waveC == 7) {
			wavecount.setString("Wave END");//update wavecount
			window.setTitle("WTZ | Wave - " + std::to_string(waveC + 1) + " | Lives: " + std::to_string(health) + " | Score: " + std::to_string(score));
		}

		window.draw(lives); //draw health;
		window.draw(scores); //draw score
		window.draw(wavecount); //draw wavecount
		window.draw(target); //display the typing status
		window.draw(wavetrans); //display the typing status

		window.display(); //display
	}
}