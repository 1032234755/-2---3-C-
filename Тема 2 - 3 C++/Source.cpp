#include <iostream>
#include <cmath>

// ��������� ��� ������������� �����
struct Point {
    double x;
    double y;
};

// ������� ��� �������� �������������� ����� ��������
bool isPointOnParabola(double a, double b, double c, Point p) {
    return p.y == a * p.x * p.x + b * p.x + c;
}

// ������� ��� ���������� ��������� ������ ��������
Point focusOfParabola(double a, double b, double c) {
    Point vertex;
    vertex.x = -b / (2 * a);
    vertex.y = a * vertex.x * vertex.x + b * vertex.x + c;

    Point focus;
    focus.x = vertex.x;
    focus.y = vertex.y + 1 / (4 * a);
    return focus;
}

// ������� ��� ���������� ���������� �� ����� �� ���������� ��������
double distanceToDirectrix(double a, double b, double c, Point p) {
    Point vertex;
    vertex.x = -b / (2 * a);
    vertex.y = a * vertex.x * vertex.x + b * vertex.x + c;

    double yDirectrix = vertex.y - 1 / (4 * a);

    return std::abs(p.y - yDirectrix);
}

int main() {
    // ������������ ��������� ��������
    double a = 1, b = -3, c = 2;

    // �������� �����
    Point p = { 1, 0 };

    // �������� �������������� ����� ��������
    if (isPointOnParabola(a, b, c, p)) {
        std::cout << "����� (" << p.x << ", " << p.y << ") ����������� ��������." << std::endl;
    }
    else {
        std::cout << "����� (" << p.x << ", " << p.y << ") �� ����������� ��������." << std::endl;
    }

    // ���������� ��������� ������ ��������
    Point focus = focusOfParabola(a, b, c);
    std::cout << "���������� ������ ��������: (" << focus.x << ", " << focus.y << ")" << std::endl;

    // ���������� ���������� �� ����� �� ���������� ��������
    double distanceDirectrix = distanceToDirectrix(a, b, c, p);
    std::cout << "���������� �� ����� �� ���������� �������� = " << distanceDirectrix << std::endl;

    return 0;
}
