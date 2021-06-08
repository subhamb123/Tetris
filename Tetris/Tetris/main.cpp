/*
Version 1:
    -If a line isn't formed at the bottom, it doesn't count. 
    -There is a glitch where sometimes parts of blocks go out of playable area. 
*/

#include "blocks.hpp"

int main() {
    srand((unsigned)time(nullptr));

    RenderWindow window(VideoMode(1000, 1100), "Tetris");
    window.setPosition(Vector2i(500, -35));

    int score = 0, level = 0, lines = 0, currentBlock = 0, nextBlock = 0, holdBlock = 0, holdTemp = 0, rotation = 0, counter = 0;
    bool lock = false, first = true, first2 = true, nextB = false, indicator1 = false, indicator2 = false, left = true, right = true, holdCheck = true, stop = true, rotationCheck = true, menu = true, end = true;

    Clock c1, c2, c3, c4, c5, c6, c7;

    Music music;
    music.openFromFile("music.ogg");
    music.setLoop(true);
    music.play();
    music.setVolume(30.f);

    RectangleShape border1, border2, border3, blackBox1, blackBox2, blackBox3;
    border1.setOutlineThickness(5.f);
    border1.setSize(Vector2f(500.f, 1000.f));
    border1.setFillColor(Color::Transparent);
    border1.setPosition(50.f, 15.f);

    border2.setOutlineThickness(5.f);
    border2.setSize(Vector2f(350.f, 300.f));
    border2.setFillColor(Color::Transparent);
    border2.setPosition(600.f, 50.f);

    border3.setOutlineThickness(5.f);
    border3.setSize(Vector2f(350.f, 300.f));
    border3.setFillColor(Color::Transparent);
    border3.setPosition(600.f, 400.f);

    blackBox1.setSize(Vector2f(1000.f, 80.f));
    blackBox1.setFillColor(Color::Black);
    blackBox1.setPosition(0.f, 1020.f);

    blackBox2.setSize(Vector2f(45.f, 1100.f));
    blackBox2.setFillColor(Color::Black);

    blackBox3.setSize(Vector2f(445.f, 1100.f));
    blackBox3.setFillColor(Color::Black);
    blackBox3.setPosition(555.f, 0.f);

    Font font;
    font.loadFromFile("font.ttf");

    Text next, hold, scoreT, levelT, linesT, menuText;
    next.setString("Next");
    next.setPosition(625.f, 75.f);
    next.setFont(font);

    hold.setString("Hold");
    hold.setPosition(625.f, 425.f);
    hold.setFont(font);

    scoreT.setPosition(600.f, 750.f);
    scoreT.setFont(font);

    levelT.setPosition(600.f, 850.f);
    levelT.setFont(font);

    linesT.setPosition(600.f, 950.f);
    linesT.setFont(font);

    menuText.setPosition(150.f, 400.f);
    menuText.setFont(font);

    RectangleShape square1, square2, square3, square4, square5, square6, square7, square8, temp1, temp2, temp3, temp4;
    square1.setSize(Vector2f(50.f, 50.f));
    square2.setSize(Vector2f(50.f, 50.f));
    square3.setSize(Vector2f(50.f, 50.f));
    square4.setSize(Vector2f(50.f, 50.f));
    square5.setSize(Vector2f(50.f, 50.f));
    square6.setSize(Vector2f(50.f, 50.f));
    square7.setSize(Vector2f(50.f, 50.f));
    square8.setSize(Vector2f(50.f, 50.f));
    temp1.setSize(Vector2f(50.f, 50.f));
    temp2.setSize(Vector2f(50.f, 50.f));
    temp3.setSize(Vector2f(50.f, 50.f));
    temp4.setSize(Vector2f(50.f, 50.f));

    vector<shape*> blocks, current;
    shape* newBlock = new shape;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

    menuLoop:
        while (menu) {
            menuText.setString("\t\tTetris\n\nPlay Game: Press Enter\n  Exit: Press Escape\n\nUse up and down arrow\n  keys to select level\n\t\tLevel: " + to_string(level + 1));
            window.clear(); 
            window.draw(menuText);
            window.display();

            if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                square5.setPosition(-100.f, -100.f);
                square6.setPosition(-100.f, -100.f);
                square7.setPosition(-100.f, -100.f);
                square8.setPosition(-100.f, -100.f);
                menu = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            if (c7.getElapsedTime().asMilliseconds() > 100 && Keyboard::isKeyPressed(Keyboard::Up) && level <= 23) {
                c7.restart();
                level++;
            }
            if (c7.getElapsedTime().asMilliseconds() > 100 && Keyboard::isKeyPressed(Keyboard::Down) && level >= 1) {
                c7.restart();
                level--;
            }
        }

        if (!lock) {
        holdFirst:
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks.at(i)->square1.getPosition() == Vector2f(200.f, 15.f) ||
                    blocks.at(i)->square1.getPosition() == Vector2f(250.f, 15.f) ||
                    blocks.at(i)->square1.getPosition() == Vector2f(300.f, 15.f) ||
                    blocks.at(i)->square1.getPosition() == Vector2f(350.f, 15.f) ||
                    blocks.at(i)->square2.getPosition() == Vector2f(200.f, 15.f) ||
                    blocks.at(i)->square2.getPosition() == Vector2f(250.f, 15.f) ||
                    blocks.at(i)->square2.getPosition() == Vector2f(300.f, 15.f) ||
                    blocks.at(i)->square2.getPosition() == Vector2f(350.f, 15.f) ||
                    blocks.at(i)->square3.getPosition() == Vector2f(200.f, 15.f) ||
                    blocks.at(i)->square3.getPosition() == Vector2f(250.f, 15.f) ||
                    blocks.at(i)->square3.getPosition() == Vector2f(300.f, 15.f) ||
                    blocks.at(i)->square3.getPosition() == Vector2f(350.f, 15.f) ||
                    blocks.at(i)->square4.getPosition() == Vector2f(200.f, 15.f) ||
                    blocks.at(i)->square4.getPosition() == Vector2f(250.f, 15.f) ||
                    blocks.at(i)->square4.getPosition() == Vector2f(300.f, 15.f) ||
                    blocks.at(i)->square4.getPosition() == Vector2f(350.f, 15.f)) {

                    while (end) {
                        menuText.setString("\t\tGame Over!\n\n\t\tScore: " + to_string(score) + "\n\t\tLevel: " + to_string(level) + "\n\t\tLines: " + to_string(lines) + "\n\nPress home to continue...");
                        window.clear();
                        window.draw(menuText);
                        window.display();

                        if (Keyboard::isKeyPressed(Keyboard::Home))
                            end = false;
                    }

                    end = true;
                    menu = true;
                    stop = true;
                    first = true;
                    first2 = true;
                    score = 0;
                    level = 0;
                    lines = 0;
                    counter = 0;
                    current.clear();
                    blocks.clear();

                    goto menuLoop;
                }
            }

            lock = true;
            rotation = 0;

            if (first) {
                currentBlock = rand() % 7;
                first = !first;
            }
            else
                currentBlock = nextBlock;

            nextBlock = rand() % 7;

            switch (currentBlock) {
            case 0:
                lineBlock1(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                lineBlock2(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                break;
            case 1:
                lBlock1(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                lBlock2(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock); 
                lBlock3(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                lBlock4(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                break;
            case 2:
                lBlock5(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                lBlock6(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock); 
                lBlock7(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                lBlock8(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                break;
            case 3:
                squareBlock(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                break;
            case 4:
                zBlock1(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                zBlock2(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                break;
            case 5:
                invZBlock1(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                invZBlock2(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                break;
            case 6:
                tBlock1(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                tBlock2(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                tBlock3(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                tBlock4(square1, square2, square3, square4);
                newBlock = new shape(square1, square2, square3, square4);
                current.push_back(newBlock);
                break;
            }

            switch (nextBlock) {
            case 0:
                lineBlock(square1, square2, square3, square4);
                break;
            case 1:
                lBlock(square1, square2, square3, square4);
                break;
            case 2:
                LBlock(square1, square2, square3, square4);
                break;
            case 3:
                sqBlock(square1, square2, square3, square4);
                break;
            case 4:
                zBlock(square1, square2, square3, square4);
                break;
            case 5:
                ZBlock(square1, square2, square3, square4);
                break;
            case 6:
                tBlock(square1, square2, square3, square4);
                break;
            }
        }

        if (c1.getElapsedTime().asMilliseconds() > 1000 - (level * 30)) {
            c1.restart();

            indicator1 = true;
            goto blockCheck;

        down1:
            for (int i = 0; i < current.size(); i++) {
                current.at(i)->square1.move(0.f, 50.f);
                current.at(i)->square2.move(0.f, 50.f);
                current.at(i)->square3.move(0.f, 50.f);
                current.at(i)->square4.move(0.f, 50.f);
            }

            indicator1 = false;
        }

        if (current.at(rotation)->square1.getPosition().x < border1.getPosition().x || (c2.getElapsedTime().asMilliseconds() > 50 && (Keyboard::isKeyPressed(Keyboard::Right) || 
            Keyboard::isKeyPressed(Keyboard::D)))) {
            c2.restart();

            if (current.at(rotation)->square4.getPosition().x != border1.getSize().x || current.at(rotation)->square1.getPosition().x < border1.getPosition().x) {
                for (int i = 0; i < blocks.size(); i++) {
                    if ((current.at(rotation)->square1.getPosition().x + 50 == blocks.at(i)->square1.getPosition().x && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square1.getPosition().x + 50 == blocks.at(i)->square2.getPosition().x && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square1.getPosition().x + 50 == blocks.at(i)->square3.getPosition().x && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square1.getPosition().x + 50 == blocks.at(i)->square4.getPosition().x && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square4.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x + 50 == blocks.at(i)->square1.getPosition().x && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x + 50 == blocks.at(i)->square2.getPosition().x && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x + 50 == blocks.at(i)->square3.getPosition().x && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x + 50 == blocks.at(i)->square4.getPosition().x && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square4.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x + 50 == blocks.at(i)->square1.getPosition().x && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x + 50 == blocks.at(i)->square2.getPosition().x && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x + 50 == blocks.at(i)->square3.getPosition().x && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x + 50 == blocks.at(i)->square4.getPosition().x && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square4.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x + 50 == blocks.at(i)->square1.getPosition().x && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x + 50 == blocks.at(i)->square2.getPosition().x && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x + 50 == blocks.at(i)->square3.getPosition().x && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x + 50 == blocks.at(i)->square4.getPosition().x && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square4.getPosition().y)) {
                        
                        right = false;
                        break;
                    }
                }

                if (right) {
                    for (int j = 0; j < current.size(); j++) {
                        current.at(j)->square1.move(50.f, 0.f);
                        current.at(j)->square2.move(50.f, 0.f);
                        current.at(j)->square3.move(50.f, 0.f);
                        current.at(j)->square4.move(50.f, 0.f);
                    }
                }
            }

            right = true;
        }

        if (current.at(rotation)->square4.getPosition().x > border1.getSize().x || (c3.getElapsedTime().asMilliseconds() > 50 && (Keyboard::isKeyPressed(Keyboard::Left) ||
            Keyboard::isKeyPressed(Keyboard::A)))) {
            c3.restart();

            if (current.at(rotation)->square1.getPosition().x != border1.getPosition().x || current.at(rotation)->square4.getPosition().x > border1.getSize().x) {
                for (int i = 0; i < blocks.size(); i++) {
                    if ((current.at(rotation)->square1.getPosition().x == blocks.at(i)->square1.getPosition().x + 50 && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square1.getPosition().x == blocks.at(i)->square2.getPosition().x + 50 && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square1.getPosition().x == blocks.at(i)->square3.getPosition().x + 50 && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square1.getPosition().x == blocks.at(i)->square4.getPosition().x + 50 && current.at(rotation)->square1.getPosition().y == blocks.at(i)->square4.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x == blocks.at(i)->square1.getPosition().x + 50 && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x == blocks.at(i)->square2.getPosition().x + 50 && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x == blocks.at(i)->square3.getPosition().x + 50 && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square2.getPosition().x == blocks.at(i)->square4.getPosition().x + 50 && current.at(rotation)->square2.getPosition().y == blocks.at(i)->square4.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x == blocks.at(i)->square1.getPosition().x + 50 && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x == blocks.at(i)->square2.getPosition().x + 50 && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x == blocks.at(i)->square3.getPosition().x + 50 && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square3.getPosition().x == blocks.at(i)->square4.getPosition().x + 50 && current.at(rotation)->square3.getPosition().y == blocks.at(i)->square4.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x == blocks.at(i)->square1.getPosition().x + 50 && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square1.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x == blocks.at(i)->square2.getPosition().x + 50 && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square2.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x == blocks.at(i)->square3.getPosition().x + 50 && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square3.getPosition().y) ||
                        (current.at(rotation)->square4.getPosition().x == blocks.at(i)->square4.getPosition().x + 50 && current.at(rotation)->square4.getPosition().y == blocks.at(i)->square4.getPosition().y)) {

                        left = false;
                        break;
                    }
                }

                if (left) {
                    for (int i = 0; i < current.size(); i++) {
                        current.at(i)->square1.move(-50.f, 0.f);
                        current.at(i)->square2.move(-50.f, 0.f);
                        current.at(i)->square3.move(-50.f, 0.f);
                        current.at(i)->square4.move(-50.f, 0.f);
                    }
                }
            }

            left = true;
        }

        if (c4.getElapsedTime().asMilliseconds() > 150 && (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))) {
            c4.restart();

            if (((currentBlock == 0 || currentBlock == 4 || currentBlock == 5) && rotation == 1) || ((currentBlock == 1 || currentBlock == 2 || currentBlock == 6) && rotation == 3)) {
                for (int i = 0; i < blocks.size(); i++) {
                    if (current.at(0)->square1.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(0)->square1.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(0)->square1.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(0)->square1.getPosition() == blocks.at(i)->square4.getPosition() ||
                        current.at(0)->square2.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(0)->square2.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(0)->square2.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(0)->square2.getPosition() == blocks.at(i)->square4.getPosition() ||
                        current.at(0)->square3.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(0)->square3.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(0)->square3.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(0)->square3.getPosition() == blocks.at(i)->square4.getPosition() ||
                        current.at(0)->square4.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(0)->square4.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(0)->square4.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(0)->square4.getPosition() == blocks.at(i)->square4.getPosition())
                        rotationCheck = false;
                }

                if(rotationCheck)
                    rotation = 0;

                rotationCheck = true;
            }

            else if (currentBlock != 3) {
                for (int i = 0; i < blocks.size(); i++) {
                    if (current.at(rotation + 1)->square1.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(rotation + 1)->square1.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(rotation + 1)->square1.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(rotation + 1)->square1.getPosition() == blocks.at(i)->square4.getPosition() ||
                        current.at(rotation + 1)->square2.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(rotation + 1)->square2.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(rotation + 1)->square2.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(rotation + 1)->square2.getPosition() == blocks.at(i)->square4.getPosition() ||
                        current.at(rotation + 1)->square3.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(rotation + 1)->square3.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(rotation + 1)->square3.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(rotation + 1)->square3.getPosition() == blocks.at(i)->square4.getPosition() ||
                        current.at(rotation + 1)->square4.getPosition() == blocks.at(i)->square1.getPosition() ||
                        current.at(rotation + 1)->square4.getPosition() == blocks.at(i)->square2.getPosition() ||
                        current.at(rotation + 1)->square4.getPosition() == blocks.at(i)->square3.getPosition() ||
                        current.at(rotation + 1)->square4.getPosition() == blocks.at(i)->square4.getPosition())
                        rotationCheck = false;
                }

                if (rotationCheck)
                    rotation++;

                rotationCheck = true;
            }
        }

        if (c5.getElapsedTime().asMilliseconds() > 150 && (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))) {
            c5.restart();

            indicator2 = true;
            goto blockCheck;

        down2:
            for (int i = 0; i < current.size(); i++) {
                current.at(i)->square1.move(0.f, 50.f);
                current.at(i)->square2.move(0.f, 50.f);
                current.at(i)->square3.move(0.f, 50.f);
                current.at(i)->square4.move(0.f, 50.f);
            }
            indicator2 = false;

            score += 10;
        }

        if (c6.getElapsedTime().asMilliseconds() > 150 && Keyboard::isKeyPressed(Keyboard::Space)) {
            c6.restart();

            while (((currentBlock == 0 && rotation == 0 && current.at(rotation)->square1.getPosition().y < 965 && current.at(rotation)->square2.getPosition().y < 965 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 0 && rotation == 1 && current.at(rotation)->square1.getPosition().y < 815 && current.at(rotation)->square2.getPosition().y < 865 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 1 && rotation == 0 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 965 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 1 && rotation == 1 && current.at(rotation)->square1.getPosition().y < 965 && current.at(rotation)->square2.getPosition().y < 865 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 1 && rotation == 2 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 1 && rotation == 3 && current.at(rotation)->square1.getPosition().y < 865 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 865) ||
                    (currentBlock == 2 && rotation == 0 && current.at(rotation)->square1.getPosition().y < 865 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 2 && rotation == 1 && current.at(rotation)->square1.getPosition().y < 965 && current.at(rotation)->square2.getPosition().y < 965 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 915) ||
                    (currentBlock == 2 && rotation == 2 && current.at(rotation)->square1.getPosition().y < 865 && current.at(rotation)->square2.getPosition().y < 865 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 2 && rotation == 3 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 965 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 915) ||
                    (currentBlock == 3 && rotation == 0 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 965 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 4 && rotation == 0 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 4 && rotation == 1 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 965 && current.at(rotation)->square3.getPosition().y < 865 && current.at(rotation)->square4.getPosition().y < 915) ||
                    (currentBlock == 5 && rotation == 0 && current.at(rotation)->square1.getPosition().y < 965 && current.at(rotation)->square2.getPosition().y < 965 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 915) ||
                    (currentBlock == 5 && rotation == 1 && current.at(rotation)->square1.getPosition().y < 865 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 6 && rotation == 0 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 915) ||
                    (currentBlock == 6 && rotation == 1 && current.at(rotation)->square1.getPosition().y < 915 && current.at(rotation)->square2.getPosition().y < 865 && current.at(rotation)->square3.getPosition().y < 915 && current.at(rotation)->square4.getPosition().y < 965) ||
                    (currentBlock == 6 && rotation == 2 && current.at(rotation)->square1.getPosition().y < 865 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 915) ||
                    (currentBlock == 6 && rotation == 3 && current.at(rotation)->square1.getPosition().y < 965 && current.at(rotation)->square2.getPosition().y < 915 && current.at(rotation)->square3.getPosition().y < 965 && current.at(rotation)->square4.getPosition().y < 965)) &&
                    nextB == false) {

            blockCheck:
                for (int i = 0; i < blocks.size(); i++) {
                    if ((current.at(rotation)->square1.getPosition().y + 50 == blocks.at(i)->square1.getPosition().y && current.at(rotation)->square1.getPosition().x == blocks.at(i)->square1.getPosition().x) ||
                        (current.at(rotation)->square1.getPosition().y + 50 == blocks.at(i)->square2.getPosition().y && current.at(rotation)->square1.getPosition().x == blocks.at(i)->square2.getPosition().x) ||
                        (current.at(rotation)->square1.getPosition().y + 50 == blocks.at(i)->square3.getPosition().y && current.at(rotation)->square1.getPosition().x == blocks.at(i)->square3.getPosition().x) ||
                        (current.at(rotation)->square1.getPosition().y + 50 == blocks.at(i)->square4.getPosition().y && current.at(rotation)->square1.getPosition().x == blocks.at(i)->square4.getPosition().x) ||
                        (current.at(rotation)->square2.getPosition().y + 50 == blocks.at(i)->square1.getPosition().y && current.at(rotation)->square2.getPosition().x == blocks.at(i)->square1.getPosition().x) ||
                        (current.at(rotation)->square2.getPosition().y + 50 == blocks.at(i)->square2.getPosition().y && current.at(rotation)->square2.getPosition().x == blocks.at(i)->square2.getPosition().x) ||
                        (current.at(rotation)->square2.getPosition().y + 50 == blocks.at(i)->square3.getPosition().y && current.at(rotation)->square2.getPosition().x == blocks.at(i)->square3.getPosition().x) ||
                        (current.at(rotation)->square2.getPosition().y + 50 == blocks.at(i)->square4.getPosition().y && current.at(rotation)->square2.getPosition().x == blocks.at(i)->square4.getPosition().x) ||
                        (current.at(rotation)->square3.getPosition().y + 50 == blocks.at(i)->square1.getPosition().y && current.at(rotation)->square3.getPosition().x == blocks.at(i)->square1.getPosition().x) ||
                        (current.at(rotation)->square3.getPosition().y + 50 == blocks.at(i)->square2.getPosition().y && current.at(rotation)->square3.getPosition().x == blocks.at(i)->square2.getPosition().x) ||
                        (current.at(rotation)->square3.getPosition().y + 50 == blocks.at(i)->square3.getPosition().y && current.at(rotation)->square3.getPosition().x == blocks.at(i)->square3.getPosition().x) ||
                        (current.at(rotation)->square3.getPosition().y + 50 == blocks.at(i)->square4.getPosition().y && current.at(rotation)->square3.getPosition().x == blocks.at(i)->square4.getPosition().x) ||
                        (current.at(rotation)->square4.getPosition().y + 50 == blocks.at(i)->square1.getPosition().y && current.at(rotation)->square4.getPosition().x == blocks.at(i)->square1.getPosition().x) ||
                        (current.at(rotation)->square4.getPosition().y + 50 == blocks.at(i)->square2.getPosition().y && current.at(rotation)->square4.getPosition().x == blocks.at(i)->square2.getPosition().x) ||
                        (current.at(rotation)->square4.getPosition().y + 50 == blocks.at(i)->square3.getPosition().y && current.at(rotation)->square4.getPosition().x == blocks.at(i)->square3.getPosition().x) ||
                        (current.at(rotation)->square4.getPosition().y + 50 == blocks.at(i)->square4.getPosition().y && current.at(rotation)->square4.getPosition().x == blocks.at(i)->square4.getPosition().x)) {
                        nextB = true;
                        break;
                    }
                }

                if (((currentBlock == 0 && rotation == 0 && current.at(rotation)->square1.getPosition().y == 965 && current.at(rotation)->square2.getPosition().y == 965 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 0 && rotation == 1 && current.at(rotation)->square1.getPosition().y == 815 && current.at(rotation)->square2.getPosition().y == 865 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 1 && rotation == 0 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 965 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 1 && rotation == 1 && current.at(rotation)->square1.getPosition().y == 965 && current.at(rotation)->square2.getPosition().y == 865 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 1 && rotation == 2 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 1 && rotation == 3 && current.at(rotation)->square1.getPosition().y == 865 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 865) ||
                    (currentBlock == 2 && rotation == 0 && current.at(rotation)->square1.getPosition().y == 865 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 2 && rotation == 1 && current.at(rotation)->square1.getPosition().y == 965 && current.at(rotation)->square2.getPosition().y == 965 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 915) ||
                    (currentBlock == 2 && rotation == 2 && current.at(rotation)->square1.getPosition().y == 865 && current.at(rotation)->square2.getPosition().y == 865 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 2 && rotation == 3 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 965 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 915) ||
                    (currentBlock == 3 && rotation == 0 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 965 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 4 && rotation == 0 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 4 && rotation == 1 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 965 && current.at(rotation)->square3.getPosition().y == 865 && current.at(rotation)->square4.getPosition().y == 915) ||
                    (currentBlock == 5 && rotation == 0 && current.at(rotation)->square1.getPosition().y == 965 && current.at(rotation)->square2.getPosition().y == 965 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 915) ||
                    (currentBlock == 5 && rotation == 1 && current.at(rotation)->square1.getPosition().y == 865 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 6 && rotation == 0 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 915) ||
                    (currentBlock == 6 && rotation == 1 && current.at(rotation)->square1.getPosition().y == 915 && current.at(rotation)->square2.getPosition().y == 865 && current.at(rotation)->square3.getPosition().y == 915 && current.at(rotation)->square4.getPosition().y == 965) ||
                    (currentBlock == 6 && rotation == 2 && current.at(rotation)->square1.getPosition().y == 865 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 915) ||
                    (currentBlock == 6 && rotation == 3 && current.at(rotation)->square1.getPosition().y == 965 && current.at(rotation)->square2.getPosition().y == 915 && current.at(rotation)->square3.getPosition().y == 965 && current.at(rotation)->square4.getPosition().y == 965))) {
                    nextB = true;
                }

                if (nextB == false && indicator1)
                    goto down1;
                
                if (nextB == false && indicator2)
                    goto down2;

                if (nextB == false) {
                    current.at(rotation)->square1.move(0.f, 50.f);
                    current.at(rotation)->square2.move(0.f, 50.f);
                    current.at(rotation)->square3.move(0.f, 50.f);
                    current.at(rotation)->square4.move(0.f, 50.f);
                    score += 10;
                }
            }
        }

        if (holdCheck && Keyboard::isKeyPressed(Keyboard::C)) {
            holdCheck = false;
            rotation = 0;
            current.clear();

            holdBlock = holdTemp;

            switch (currentBlock) {
            case 0:
                lb(square5, square6, square7, square8);
                holdTemp = 0;
                break;
            case 1:
                lB(square5, square6, square7, square8);
                holdTemp = 1;
                break;
            case 2:
                LB(square5, square6, square7, square8);
                holdTemp = 2;
                break;
            case 3:
                sqB(square5, square6, square7, square8);
                holdTemp = 3;
                break;
            case 4:
                zB(square5, square6, square7, square8);
                holdTemp = 4;
                break;
            case 5:
                ZB(square5, square6, square7, square8);
                holdTemp = 5;
                break;
            case 6:
                tB(square5, square6, square7, square8);
                holdTemp = 6;
                break;
            }

            if (first2) {
                first2 = !first2;
                goto holdFirst;
            }

            else {
                currentBlock = holdBlock;
                switch (holdBlock) {
                case 0:
                    lineBlock1(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    lineBlock2(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    break;
                case 1:
                    lBlock1(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    lBlock2(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    lBlock3(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    lBlock4(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    break;
                case 2:
                    lBlock5(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    lBlock6(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    lBlock7(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    lBlock8(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    break;
                case 3:
                    squareBlock(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    break;
                case 4:
                    zBlock1(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    zBlock2(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    break;
                case 5:
                    invZBlock1(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    invZBlock2(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    break;
                case 6:
                    tBlock1(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    tBlock2(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    tBlock3(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    tBlock4(temp1, temp2, temp3, temp4);
                    newBlock = new shape(temp1, temp2, temp3, temp4);
                    current.push_back(newBlock);
                    break;
                }
            }
        }

        if (counter == 10) {
            counter = 0;
            lines++;

            for (int i = 0; i < blocks.size(); i++) {
                blocks.at(i)->square1.move(0.f, 50.f);
                blocks.at(i)->square2.move(0.f, 50.f);
                blocks.at(i)->square3.move(0.f, 50.f);
                blocks.at(i)->square4.move(0.f, 50.f);
            }

            for (int i = 0; i < blocks.size(); i++) {
                if (blocks.at(i)->square1.getPosition().y == 965)
                    counter++;
                if (blocks.at(i)->square2.getPosition().y == 965)
                    counter++;
                if (blocks.at(i)->square3.getPosition().y == 965)
                    counter++;
                if (blocks.at(i)->square4.getPosition().y == 965)
                    counter++;
            }

            score += 40 * (level + 1);
        }

        if (stop && lines % 3 == 0) {
            stop = false;
            level++;
        }

        if (lines % 3 != 0)
            stop = true;

        scoreT.setString("Score: " + to_string(score));
        levelT.setString("Level: " + to_string(level));
        linesT.setString("Lines: " + to_string(lines));

        window.clear();

        for (int i = 0; i < blocks.size(); i++) {
            window.draw(blocks.at(i)->square1);
            window.draw(blocks.at(i)->square2);
            window.draw(blocks.at(i)->square3);
            window.draw(blocks.at(i)->square4);
        }

        window.draw(current.at(rotation)->square1);
        window.draw(current.at(rotation)->square2);
        window.draw(current.at(rotation)->square3);
        window.draw(current.at(rotation)->square4);

        window.draw(blackBox1);
        window.draw(blackBox2);
        window.draw(blackBox3);
        window.draw(border1);
        window.draw(border2);
        window.draw(border3);
        window.draw(next);
        window.draw(hold);
        window.draw(scoreT);
        window.draw(levelT);
        window.draw(linesT);
        window.draw(square1);
        window.draw(square2);
        window.draw(square3);
        window.draw(square4);
        window.draw(square5);
        window.draw(square6);
        window.draw(square7);
        window.draw(square8);

        window.display();

        if (nextB) {
            nextB = !nextB;
            blocks.push_back(current.at(rotation));

            if (current.at(rotation)->square1.getPosition().y == 965)
                counter++;
            if (current.at(rotation)->square2.getPosition().y == 965)
                counter++;
            if (current.at(rotation)->square3.getPosition().y == 965)
                counter++;
            if (current.at(rotation)->square4.getPosition().y == 965)
                counter++;

            current.clear();
            lock = !lock;
            holdCheck = true;
        }
    }

    return 0;
}