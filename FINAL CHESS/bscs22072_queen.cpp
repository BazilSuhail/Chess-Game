#include "bscs22072_queen.h"
#include<windows.h>
#include <fstream>
#include<iostream>
#include"bscs22072_piece.h"

#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
queen::queen(int _r, int _c, color _col, board* _b) :piece(_r, _c, _col, _b) {

}
bool queen::get_type(int r, int c) {
    return false;
}
bool queen::move_legality(board Box, board* b, int sr, int sc, int dr, int dc) {
    return	(((hor_chk(sr, sc, dr, dc) && hor_path_clear(sr, sc, dr, dc, b))
        || (ver_chk(sr, sc, dr, dc) && ver_path_clear(sr, sc, dr, dc, b)))) || //diagnol conditions
        ((diagnol_chk(sr, sc, dr, dc) && ((diagnol_L2R(sr, sc, dr, dc, b)
            || diagnol_R2L(sr, sc, dr, dc, b)))));
}
char queen::get_symbol() const {
    return (C == BLACK) ? 'q' : 'Q';
}
// board_dis function
void queen::board_dis(RenderWindow& w, int x, int y, int squareSize, float scale) {
    Texture tex;
    if (C == WHITE) {
        if (!tex.loadFromFile("qwhite.png")) {
            std::cout << "Failed to load texture!" << std::endl;
            return;
        }
    }
    else {
        if (!tex.loadFromFile("qblack.png")) {
            std::cout << "Failed to load texture!" << std::endl;
            return;
        }
    }
    Sprite sp(tex);
    float centerX = x * squareSize * scale + squareSize * scale / 2.0;
    float centerY = y * squareSize * scale + squareSize * scale / 2.0;
    sp.setPosition(centerX, centerY);
    sp.setScale(scale, scale);
    sp.setOrigin(sp.getLocalBounds().width / 2.0, sp.getLocalBounds().height / 2.0);
    w.draw(sp);
}