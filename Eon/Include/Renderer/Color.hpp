#ifndef EON_RENDERER_COLOR_H
#define EON_RENDERER_COLOR_H

class Color {
public:
    Color(double r, double g, double b, double a);
    
    double red;
    double green;
    double blue;
    double alpha;
};

#endif