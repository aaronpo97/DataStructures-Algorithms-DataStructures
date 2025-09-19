#pragma once

#include <sstream>

struct Polygon {
    virtual double area() const           = 0;
    virtual ~Polygon()                    = default;
    virtual std::string to_string() const = 0;
};

struct Triangle : Polygon {
    double base{}, height{};

    double area() const override {
        return (base * height) / 2;
    }

    Triangle() = default;
    Triangle(double _base, double _height) : base(_base), height(_height) {
    }

    std::string to_string() const override {
        std::stringstream os;
        os << "Triangle(" << base << ", " << height << ")";
        return os.str();
    }
};

struct Rectangle : Polygon {
    double width{}, height{};

    double area() const override {
        return width * height;
    }

    Rectangle() = default;
    Rectangle(double _width, double _height) : width(_width), height(_height) {
    }

    std::string to_string() const override {
        std::stringstream os;
        os << "Rectangle(" << width << ", " << height << ")";
        return os.str();
    }
};

std::ostream &operator<<(std::ostream &os, Polygon const &p) {
    os << p.to_string();

    return os;
}