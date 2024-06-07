#include <iostream>
#include <cmath>

// Структура для представления точки
struct Point {
    double x;
    double y;
};

// Функция для проверки принадлежности точки параболе
bool isPointOnParabola(double a, double b, double c, Point p) {
    return p.y == a * p.x * p.x + b * p.x + c;
}

// Функция для нахождения координат фокуса параболы
Point focusOfParabola(double a, double b, double c) {
    Point vertex;
    vertex.x = -b / (2 * a);
    vertex.y = a * vertex.x * vertex.x + b * vertex.x + c;

    Point focus;
    focus.x = vertex.x;
    focus.y = vertex.y + 1 / (4 * a);
    return focus;
}

// Функция для нахождения расстояния от точки до директрисы параболы
double distanceToDirectrix(double a, double b, double c, Point p) {
    Point vertex;
    vertex.x = -b / (2 * a);
    vertex.y = a * vertex.x * vertex.x + b * vertex.x + c;

    double yDirectrix = vertex.y - 1 / (4 * a);

    return std::abs(p.y - yDirectrix);
}

int main() {
    // Коэффициенты уравнения параболы
    double a = 1, b = -3, c = 2;

    // Заданная точка
    Point p = { 1, 0 };

    // Проверка принадлежности точки параболе
    if (isPointOnParabola(a, b, c, p)) {
        std::cout << "Точка (" << p.x << ", " << p.y << ") принадлежит параболе." << std::endl;
    }
    else {
        std::cout << "Точка (" << p.x << ", " << p.y << ") не принадлежит параболе." << std::endl;
    }

    // Нахождение координат фокуса параболы
    Point focus = focusOfParabola(a, b, c);
    std::cout << "Координаты фокуса параболы: (" << focus.x << ", " << focus.y << ")" << std::endl;

    // Нахождение расстояния от точки до директрисы параболы
    double distanceDirectrix = distanceToDirectrix(a, b, c, p);
    std::cout << "Расстояние от точки до директрисы параболы = " << distanceDirectrix << std::endl;

    return 0;
}
