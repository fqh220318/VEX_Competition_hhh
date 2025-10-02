#include "my-brain.h"

#include <cstdio>
using namespace std;

bool Button::isCoordInside(int _x, int _y) { return x <= _x && _x <= x + width && y <= _y && _y <= y + height; }

void Label::render() {
    brain->Screen.setPenColor(border_color);
    brain->Screen.setFillColor(fill_color);
    brain->Screen.drawRectangle(x, y, width, height, fill_color);
    brain->Screen.setPenColor(text_color);
    brain->Screen.printAt(x + width / 2 - text.length() * 5, y + height / 2 + 4, text.c_str());
}

void Button::render() {
    brain->Screen.setPenColor(border_color);
    brain->Screen.setFillColor(fill_color);
    brain->Screen.drawRectangle(x, y, width, height, fill_color);
    brain->Screen.setPenColor(text_color);
    brain->Screen.printAt(x + width / 2 - text.length() * 5, y + height / 2 + 4, text.c_str());
}

void Button::press() {
    if (this->callback_set) {
        callback();
    }
}

void Button::setCallback(std::function<void()> _callback) {
    callback = _callback;
    this->callback_set = true;
}

void Label::setText(std::string _text) {
    text = _text;
    render();
}

void Button::setText(std::string _text) {
    text = _text;
    render();
}

MyBrain::MyBrain() : vex::brain() {
    Screen.released(callbackPressed);
    Screen.setFont(vex::fontType::mono12);
}

MyBrain::~MyBrain() { clearBrainScreen(); }

void MyBrain::clearBrainScreen() {
    for (auto label : labels) {
        delete label;
    }
    labels.clear();
    for (auto button : buttons) {
        delete button;
    }
    buttons.clear();
    Screen.clearScreen();
}

Label *MyBrain::addLabel(int x, int y, int width, int height, std::string text, vex::color border_color,
                         vex::color fill_color, vex::color text_color) {
    labels.push_back(new Label(x, y, width, height, text, this));
    labels.back()->text_color = text_color;
    labels.back()->border_color = border_color;
    labels.back()->fill_color = fill_color;
    labels.back()->render();
    return labels.back();
}

Button *MyBrain::addButton(int x, int y, int width, int height, std::string text, vex::color border_color,
                           vex::color fill_color, vex::color text_color) {
    buttons.push_back(new Button(x, y, width, height, text, this));
    buttons.back()->text_color = text_color;
    buttons.back()->border_color = border_color;
    buttons.back()->fill_color = fill_color;
    buttons.back()->render();
    return buttons.back();
}

void Button::setFillColor(vex::color _color) {
    fill_color = _color;
    render();
}

void callbackPressed() {
    MyBrain *brain = MyBrain::getInstance();
    int x = brain->Screen.xPosition();
    int y = brain->Screen.yPosition();
    for (Button *button : brain->buttons) {
        if (button->isCoordInside(x, y)) {
            button->press();
            break;
        }
    }
}

std::string my_string_utils::to_string(int num) {
    char buf[20];
    sprintf(buf, "%d", num);
    return string(buf);
}

std::string my_string_utils::to_string(double num) {
    char buf[20];
    sprintf(buf, "%.2f", num);
    return string(buf);
}