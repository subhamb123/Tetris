#pragma once

#include "header.hpp"

class shape {
public:
    shape() {

    }

    shape(RectangleShape s1, RectangleShape s2, RectangleShape s3, RectangleShape s4) {
        square1 = s1;
        square2 = s2;
        square3 = s3;
        square4 = s4;
    }

    RectangleShape square1, square2, square3, square4;
};

//Current block formations. There is a formation for every rotation.

void lineBlock1(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Cyan);
    square1.setPosition(200.f, 15.f);
    square2.setFillColor(Color::Cyan);
    square2.setPosition(250.f, 15.f);
    square3.setFillColor(Color::Cyan);
    square3.setPosition(300.f, 15.f);
    square4.setFillColor(Color::Cyan);
    square4.setPosition(350.f, 15.f);
}

void lineBlock2(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Cyan);
    square1.setPosition(250.f, 15.f);
    square2.setFillColor(Color::Cyan);
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color::Cyan);
    square3.setPosition(250.f, 115.f);
    square4.setFillColor(Color::Cyan);
    square4.setPosition(250.f, 165.f);
}

void lBlock1(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Blue);
    square1.setPosition(200.f, 15.f);
    square2.setFillColor(Color::Blue);
    square2.setPosition(200.f, 65.f);
    square3.setFillColor(Color::Blue);
    square3.setPosition(250.f, 65.f);
    square4.setFillColor(Color::Blue);
    square4.setPosition(300.f, 65.f);
}

void lBlock2(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Blue);
    square1.setPosition(250.f, 115.f);
    square2.setFillColor(Color::Blue);
    square2.setPosition(300.f, 15.f);
    square3.setFillColor(Color::Blue);
    square3.setPosition(300.f, 65.f);
    square4.setFillColor(Color::Blue);
    square4.setPosition(300.f, 115.f);
}

void lBlock3(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Blue);
    square1.setPosition(200.f, 15.f);
    square2.setFillColor(Color::Blue);
    square2.setPosition(250.f, 15.f);
    square3.setFillColor(Color::Blue);
    square3.setPosition(300.f, 15.f);
    square4.setFillColor(Color::Blue);
    square4.setPosition(300.f, 65.f);
}

void lBlock4(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Blue);
    square1.setPosition(250.f, 15.f);
    square2.setFillColor(Color::Blue);
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color::Blue);
    square3.setPosition(250.f, 115.f);
    square4.setFillColor(Color::Blue);
    square4.setPosition(300.f, 15.f);
}

void lBlock5(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(255, 165, 0));
    square1.setPosition(250.f, 15.f);
    square2.setFillColor(Color(255, 165, 0));
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color(255, 165, 0));
    square3.setPosition(250.f, 115.f);
    square4.setFillColor(Color(255, 165, 0));
    square4.setPosition(300.f, 115.f);
}

void lBlock6(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(255, 165, 0));
    square1.setPosition(200.f, 65.f);
    square2.setFillColor(Color(255, 165, 0));
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color(255, 165, 0));
    square3.setPosition(300.f, 65.f);
    square4.setFillColor(Color(255, 165, 0));
    square4.setPosition(300.f, 15.f);
}

void lBlock7(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(255, 165, 0));
    square1.setPosition(250.f, 15.f);
    square2.setFillColor(Color(255, 165, 0));
    square2.setPosition(300.f, 15.f);
    square3.setFillColor(Color(255, 165, 0));
    square3.setPosition(300.f, 65.f);
    square4.setFillColor(Color(255, 165, 0));
    square4.setPosition(300.f, 115.f);
}

void lBlock8(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(255, 165, 0));
    square1.setPosition(200.f, 15.f);
    square2.setFillColor(Color(255, 165, 0));
    square2.setPosition(200.f, 65.f);
    square3.setFillColor(Color(255, 165, 0));
    square3.setPosition(250.f, 15.f);
    square4.setFillColor(Color(255, 165, 0));
    square4.setPosition(300.f, 15.f);
}

void squareBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Yellow);
    square1.setPosition(250.f, 15.f);
    square2.setFillColor(Color::Yellow);
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color::Yellow);
    square3.setPosition(300.f, 15.f);
    square4.setFillColor(Color::Yellow);
    square4.setPosition(300.f, 65.f);
}

void zBlock1(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Red);
    square1.setPosition(200.f, 15.f);
    square2.setFillColor(Color::Red);
    square2.setPosition(250.f, 15.f);
    square3.setFillColor(Color::Red);
    square3.setPosition(250.f, 65.f);
    square4.setFillColor(Color::Red);
    square4.setPosition(300.f, 65.f);
}

void zBlock2(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Red);
    square1.setPosition(250.f, 65.f);
    square2.setFillColor(Color::Red);
    square2.setPosition(250.f, 115.f);
    square3.setFillColor(Color::Red);
    square3.setPosition(300.f, 15.f);
    square4.setFillColor(Color::Red);
    square4.setPosition(300.f, 65.f);
}

void invZBlock1(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Green);
    square1.setPosition(200.f, 65.f);
    square2.setFillColor(Color::Green);
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color::Green);
    square3.setPosition(250.f, 15.f);
    square4.setFillColor(Color::Green);
    square4.setPosition(300.f, 15.f);
}

void invZBlock2(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Green);
    square1.setPosition(250.f, 15.f);
    square2.setFillColor(Color::Green);
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color::Green);
    square3.setPosition(300.f, 65.f);
    square4.setFillColor(Color::Green);
    square4.setPosition(300.f, 115.f);
}

void tBlock1(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(75, 0, 130));
    square1.setPosition(200.f, 15.f);
    square2.setFillColor(Color(75, 0, 130));
    square2.setPosition(250.f, 15.f);
    square3.setFillColor(Color(75, 0, 130));
    square3.setPosition(250.f, 65.f);
    square4.setFillColor(Color(75, 0, 130));
    square4.setPosition(300.f, 15.f);
}

void tBlock2(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(75, 0, 130));
    square1.setPosition(250.f, 65.f);
    square2.setFillColor(Color(75, 0, 130));
    square2.setPosition(300.f, 15.f);
    square3.setFillColor(Color(75, 0, 130));
    square3.setPosition(300.f, 65.f);
    square4.setFillColor(Color(75, 0, 130));
    square4.setPosition(300.f, 115.f);
}

void tBlock3(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(75, 0, 130));
    square1.setPosition(250.f, 15.f);
    square2.setFillColor(Color(75, 0, 130));
    square2.setPosition(250.f, 65.f);
    square3.setFillColor(Color(75, 0, 130));
    square3.setPosition(250.f, 115.f);
    square4.setFillColor(Color(75, 0, 130));
    square4.setPosition(300.f, 65.f);
}

void tBlock4(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(75, 0, 130));
    square1.setPosition(200.f, 65.f);
    square2.setFillColor(Color(75, 0, 130));
    square2.setPosition(250.f, 15.f);
    square3.setFillColor(Color(75, 0, 130));
    square3.setPosition(250.f, 65.f);
    square4.setFillColor(Color(75, 0, 130));
    square4.setPosition(300.f, 65.f);
}

//Next block formations. Only one form is required to display.

void lineBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Cyan);
    square1.setPosition(675.f, 200.f);
    square2.setFillColor(Color::Cyan);
    square2.setPosition(725.f, 200.f);
    square3.setFillColor(Color::Cyan);
    square3.setPosition(775.f, 200.f);
    square4.setFillColor(Color::Cyan);
    square4.setPosition(825.f, 200.f);
}

void lBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Blue);
    square1.setPosition(700.f, 150.f);
    square2.setFillColor(Color::Blue);
    square2.setPosition(700.f, 200.f);
    square3.setFillColor(Color::Blue);
    square3.setPosition(750.f, 200.f);
    square4.setFillColor(Color::Blue);
    square4.setPosition(800.f, 200.f);
}

void LBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(255, 165, 0));
    square1.setPosition(700.f, 200.f);
    square2.setFillColor(Color(255, 165, 0));
    square2.setPosition(750.f, 200.f);
    square3.setFillColor(Color(255, 165, 0));
    square3.setPosition(800.f, 200.f);
    square4.setFillColor(Color(255, 165, 0));
    square4.setPosition(800.f, 150.f);
}

void sqBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Yellow);
    square1.setPosition(725.f, 150.f);
    square2.setFillColor(Color::Yellow);
    square2.setPosition(725.f, 200.f);
    square3.setFillColor(Color::Yellow);
    square3.setPosition(775.f, 150.f);
    square4.setFillColor(Color::Yellow);
    square4.setPosition(775.f, 200.f);
}

void zBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Red);
    square1.setPosition(700.f, 150.f);
    square2.setFillColor(Color::Red);
    square2.setPosition(750.f, 150.f);
    square3.setFillColor(Color::Red);
    square3.setPosition(750.f, 200.f);
    square4.setFillColor(Color::Red);
    square4.setPosition(800.f, 200.f);
}

void ZBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Green);
    square1.setPosition(700.f, 200.f);
    square2.setFillColor(Color::Green);
    square2.setPosition(750.f, 200.f);
    square3.setFillColor(Color::Green);
    square3.setPosition(750.f, 150.f);
    square4.setFillColor(Color::Green);
    square4.setPosition(800.f, 150.f);
}

void tBlock(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(75, 0, 130));
    square1.setPosition(700.f, 150.f);
    square2.setFillColor(Color(75, 0, 130));
    square2.setPosition(750.f, 150.f);
    square3.setFillColor(Color(75, 0, 130));
    square3.setPosition(750.f, 200.f);
    square4.setFillColor(Color(75, 0, 130));
    square4.setPosition(800.f, 150.f);
}

//Hold block formations. Only one form is required to display.

void lb(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Cyan);
    square1.setPosition(675.f, 550.f);
    square2.setFillColor(Color::Cyan);
    square2.setPosition(725.f, 550.f);
    square3.setFillColor(Color::Cyan);
    square3.setPosition(775.f, 550.f);
    square4.setFillColor(Color::Cyan);
    square4.setPosition(825.f, 550.f);
}

void lB(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Blue);
    square1.setPosition(700.f, 500.f);
    square2.setFillColor(Color::Blue);
    square2.setPosition(700.f, 550.f);
    square3.setFillColor(Color::Blue);
    square3.setPosition(750.f, 550.f);
    square4.setFillColor(Color::Blue);
    square4.setPosition(800.f, 550.f);
}

void LB(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(255, 165, 0));
    square1.setPosition(700.f, 550.f);
    square2.setFillColor(Color(255, 165, 0));
    square2.setPosition(750.f, 550.f);
    square3.setFillColor(Color(255, 165, 0));
    square3.setPosition(800.f, 550.f);
    square4.setFillColor(Color(255, 165, 0));
    square4.setPosition(800.f, 500.f);
}

void sqB(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Yellow);
    square1.setPosition(725.f, 500.f);
    square2.setFillColor(Color::Yellow);
    square2.setPosition(725.f, 550.f);
    square3.setFillColor(Color::Yellow);
    square3.setPosition(775.f, 500.f);
    square4.setFillColor(Color::Yellow);
    square4.setPosition(775.f, 550.f);
}

void zB(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Red);
    square1.setPosition(700.f, 500.f);
    square2.setFillColor(Color::Red);
    square2.setPosition(750.f, 500.f);
    square3.setFillColor(Color::Red);
    square3.setPosition(750.f, 550.f);
    square4.setFillColor(Color::Red);
    square4.setPosition(800.f, 550.f);
}

void ZB(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color::Green);
    square1.setPosition(700.f, 550.f);
    square2.setFillColor(Color::Green);
    square2.setPosition(750.f, 550.f);
    square3.setFillColor(Color::Green);
    square3.setPosition(750.f, 500.f);
    square4.setFillColor(Color::Green);
    square4.setPosition(800.f, 500.f);
}

void tB(RectangleShape& square1, RectangleShape& square2, RectangleShape& square3, RectangleShape& square4) {
    square1.setFillColor(Color(75, 0, 130));
    square1.setPosition(700.f, 500.f);
    square2.setFillColor(Color(75, 0, 130));
    square2.setPosition(750.f, 500.f);
    square3.setFillColor(Color(75, 0, 130));
    square3.setPosition(750.f, 550.f);
    square4.setFillColor(Color(75, 0, 130));
    square4.setPosition(800.f, 500.f);
}