#ifndef VERTEX_H
#define VERTEX_H

template <typename T>
class Vertex
{
public:
    T get_value() { return value; }
    void update_value(T new_val) { value = new_val; }
private:
    T value;
};

#endif