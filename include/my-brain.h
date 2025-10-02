#ifndef MY_BRAIN_H
#define MY_BRAIN_H

#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "vex.h"

class MyBrain;
void callbackPressed();

class Label {
  protected:
    int x, y, width, height;
    std::string text;
    vex::color text_color = vex::color::white;
    vex::color border_color = vex::color::black;
    vex::color fill_color = vex::color::black;
    MyBrain* brain = nullptr;
    friend class MyBrain;

    void render();

  public:
    Label(int _x, int _y, int _width, int _height, std::string _text, MyBrain* _brain)
        : x(_x), y(_y), width(_width), height(_height), text(_text), brain(_brain) {};
    void setText(std::string _text);
};

class Button : public Label {
  private:
    vex::color text_color = vex::color::white;
    vex::color border_color = vex::color::white;
    vex::color fill_color = vex::color::blue;
    bool callback_set = false;
    std::function<void()> callback;
    friend void callbackPressed();
    friend class MyBrain;

    bool isCoordInside(int _x, int _y);
    void press();
    void render();

  public:
    Button(int _x, int _y, int _width, int _height, std::string _text, MyBrain* _brain)
        : Label(_x, _y, _width, _height, _text, _brain) {};

    void setCallback(std::function<void()> _callback);
    void setText(std::string _text);
    void setFillColor(vex::color _color);
};

class MyBrain : public vex::brain {
  private:
    std::vector<Label*> labels;
    std::vector<Button*> buttons;
    friend void callbackPressed();

  public:
    static MyBrain* getInstance() {
        static MyBrain* p = nullptr;
        if (p == nullptr) {
            p = new MyBrain();
        }

        return p;
    }
    static void deleteInstance() {
        MyBrain* p = MyBrain::getInstance();
        if (p != nullptr) {
            delete p;
            p = nullptr;
        }
    }

    MyBrain();
    ~MyBrain();

    Label* addLabel(int x, int y, int width, int height, std::string text,
                    vex::color border_color = vex::color::black,
                    vex::color fill_color = vex::color::black,
                    vex::color text_color = vex::color::white);
    Button* addButton(int x, int y, int width, int height, std::string text,
                      vex::color border_color = vex::color::white,
                      vex::color fill_color = vex::color::blue,
                      vex::color text_color = vex::color::white);

    void clearBrainScreen();
};

// 字符处理函数
namespace my_string_utils {
    std::string to_string(int num);
    std::string to_string(double num);
} // namespace my_string_utils

#endif // MY_BRAIN_H