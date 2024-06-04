#ifndef OLDAL_HPP
#define OLDAL_HPP

class Oldal {
private:
    int x, y, szel, mag, meret;

public:
    Oldal(int x_, int y_);
    void rajzol(int oszto, int poz);
    bool felsofelett(int egerx, int egery);
    bool alsofelett(int egerx, int egery);
};

#endif // OLDAL_HPP
