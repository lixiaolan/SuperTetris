var scale = 20;
var boarderWidth = .1*scale;

$(document).ready(function () {
    // create svg drawing
    var draw = SVG('drawing').size(62*scale, 22*scale);

    // Boarder
    piece(draw, 2, 60, 15, 'red', 'white');
    piece(draw, 0, 60, 11, 'red', 'white');
    piece(draw, 0, 57, 17, 'red', 'white');
    piece(draw, 1, 58, 11, 'red', 'white');
    piece(draw, 4, 57, 17, 'red', 'white');
    piece(draw, 2, 56, 7, 'red', 'white');
    piece(draw, 1, 56, 8, 'red', 'white');
    piece(draw, 1, 53, 8, 'red', 'white');
    piece(draw, 0, 53, 17, 'red', 'white');
    piece(draw, 0, 51, 18, 'red', 'white');
    piece(draw, 14, 27, 18, 'red', 'white');
    piece(draw, 12, 27, 18, 'red', 'white');
    piece(draw, 9, 27, 0, 'red', 'white');
    piece(draw, 1, 47, 18, 'red', 'white');
    piece(draw, 15, 45, 18, 'red', 'white');
    piece(draw, 15, 44, 0, 'red', 'white');
    piece(draw, 14, 42, 2, 'red', 'white');
    piece(draw, 12, 42, 14, 'red', 'white');
    piece(draw, 12, 44, 13, 'red', 'white');
    piece(draw, 12, 45, 4, 'red', 'white');
    piece(draw, 14, 51, 6, 'red', 'white');
    piece(draw, 13, 50, 16, 'red', 'white');
    piece(draw, 11, 50, 18, 'red', 'white');
    piece(draw, 11, 51, 4, 'red', 'white');
    piece(draw, 6, 59, 4, 'red', 'white');
    piece(draw, 7, 57, 8, 'red', 'white');
    piece(draw, 5, 53, 18, 'red', 'white');
    piece(draw, 6, 55, 8, 'red', 'white');
    piece(draw, 8, 55, 8, 'red', 'white');
    piece(draw, 8, 54, 15, 'red', 'white');
    piece(draw, 7, 53, 3, 'red', 'white');
    piece(draw, 8, 51, 2, 'red', 'white');
    piece(draw, 9, 49, 5, 'red', 'white');
    piece(draw, 10, 47, 17, 'red', 'white');
    piece(draw, 10, 46, 15, 'red', 'white');
    piece(draw, 10, 44, 18, 'red', 'white');
    piece(draw, 8, 45, 1, 'red', 'white');
    piece(draw, 6, 48, 16, 'red', 'white');
    piece(draw, 6, 49, 0, 'red', 'white');
    piece(draw, 5, 50, 13, 'red', 'white');
    piece(draw, 5, 51, 4, 'red', 'white');
    piece(draw, 3, 51, 12, 'red', 'white');
    piece(draw, 4, 49, 8, 'red', 'white');
    piece(draw, 3, 48, 3, 'red', 'white');
    piece(draw, 4, 47, 7, 'red', 'white');
    piece(draw, 6, 46, 13, 'red', 'white');
    piece(draw, 5, 45, 16, 'red', 'white');
    piece(draw, 4, 45, 2, 'red', 'white');
    piece(draw, 3, 44, 17, 'red', 'white');
    piece(draw, 2, 43, 17, 'red', 'white');
    piece(draw, 1, 43, 17, 'red', 'white');
    piece(draw, 1, 39, 17, 'red', 'white');
    piece(draw, 1, 37, 10, 'red', 'white');
    piece(draw, 3, 36, 14, 'red', 'white');
    piece(draw, 15, 34, 4, 'red', 'white');
    piece(draw, 14, 36, 9, 'red', 'white');
    piece(draw, 13, 37, 18, 'red', 'white');
    piece(draw, 9, 37, 16, 'red', 'white');
    piece(draw, 10, 36, 16, 'red', 'white');
    piece(draw, 6, 36, 16, 'red', 'white');
    piece(draw, 5, 35, 3, 'red', 'white');
    piece(draw, 6, 32, 14, 'red', 'white');
    piece(draw, 4, 32, 1, 'red', 'white');
    piece(draw, 3, 34, 8, 'red', 'white');
    piece(draw, 1, 33, 5, 'red', 'white');
    piece(draw, 2, 33, 6, 'red', 'white');
    piece(draw, 1, 28, 11, 'red', 'white');
    piece(draw, 2, 30, 10, 'red', 'white');
    piece(draw, 4, 30, 3, 'red', 'white');
    piece(draw, 5, 31, 9, 'red', 'white');
    piece(draw, 7, 29, 12, 'red', 'white');
    piece(draw, 6, 28, 3, 'red', 'white');
    piece(draw, 6, 26, 4, 'red', 'white');
    piece(draw, 4, 27, 1, 'red', 'white');
    piece(draw, 3, 26, 7, 'red', 'white');
    piece(draw, 2, 26, 12, 'red', 'white');
    piece(draw, 1, 23, 10, 'red', 'white');
    piece(draw, 3, 23, 14, 'red', 'white');
    piece(draw, 4, 25, 15, 'red', 'white');
    piece(draw, 6, 24, 12, 'red', 'white');
    piece(draw, 6, 22, 7, 'red', 'white');
    piece(draw, 5, 22, 8, 'red', 'white');
    piece(draw, 4, 19, 4, 'red', 'white');
    piece(draw, 3, 18, 11, 'red', 'white');
    piece(draw, 1, 19, 3, 'red', 'white');
    piece(draw, 2, 20, 18, 'red', 'white');
    piece(draw, 4, 21, 6, 'red', 'white');
    piece(draw, 7, 20, 13, 'red', 'white');
    piece(draw, 7, 18, 14, 'red', 'white');
    piece(draw, 9, 18, 18, 'red', 'white');
    piece(draw, 12, 16, 13, 'red', 'white');
    piece(draw, 12, 15, 6, 'red', 'white');
    piece(draw, 11, 15, 17, 'red', 'white');
    piece(draw, 9, 15, 10, 'red', 'white');
    piece(draw, 7, 16, 11, 'red', 'white');
    piece(draw, 5, 16, 9, 'red', 'white');
    piece(draw, 5, 17, 2, 'red', 'white');
    piece(draw, 1, 17, 16, 'red', 'white');
    piece(draw, 2, 15, 2, 'red', 'white');
    piece(draw, 1, 11, 9, 'red', 'white');
    piece(draw, 6, 8, 6, 'red', 'white');
    piece(draw, 5, 6, 15, 'red', 'white');
    piece(draw, 4, 7, 1, 'red', 'white');
    piece(draw, 3, 8, 5, 'red', 'white');
    piece(draw, 1, 8, 1, 'red', 'white');
    piece(draw, 1, 6, 4, 'red', 'white');
    piece(draw, 4, 5, 17, 'red', 'white');
    piece(draw, 1, 4, 15, 'red', 'white');
    piece(draw, 0, 3, 5, 'red', 'white');
    piece(draw, 0, 6, 6, 'red', 'white');
    piece(draw, 0, 8, 18, 'red', 'white');
    piece(draw, 0, 10, 5, 'red', 'white');
    piece(draw, 0, 13, 3, 'red', 'white');
    piece(draw, 0, 15, 14, 'red', 'white');
    piece(draw, 0, 18, 16, 'red', 'white');
    piece(draw, 0, 19, 17, 'red', 'white');
    piece(draw, 1, 22, 0, 'red', 'white');
    piece(draw, 0, 23, 3, 'red', 'white');
    piece(draw, 0, 25, 14, 'red', 'white');
    piece(draw, 0, 27, 14, 'red', 'white');
    piece(draw, 0, 30, 6, 'red', 'white');
    piece(draw, 0, 31, 11, 'red', 'white');
    piece(draw, 0, 33, 17, 'red', 'white');
    piece(draw, 0, 36, 13, 'red', 'white');
    piece(draw, 0, 38, 17, 'red', 'white');
    piece(draw, 0, 42, 17, 'red', 'white');
    piece(draw, 0, 46, 17, 'red', 'white');
    piece(draw, 0, 49, 13, 'red', 'white');
    piece(draw, 2, 50, 17, 'red', 'white');
    piece(draw, 2, 53, 1, 'red', 'white');
    piece(draw, 4, 54, 8, 'red', 'white');
    piece(draw, 5, 56, 5, 'red', 'white');
    piece(draw, 5, 59, 3, 'red', 'white');
    piece(draw, 6, 61, 16, 'red', 'white');
    piece(draw, 10, 60, 4, 'red', 'white');
    piece(draw, 13, 60, 18, 'red', 'white');
    piece(draw, 15, 60, 18, 'red', 'white');
    piece(draw, 17, 61, 16, 'red', 'white');
    piece(draw, 20, 59, 12, 'red', 'white');
    piece(draw, 21, 56, 17, 'red', 'white');
    piece(draw, 19, 57, 18, 'red', 'white');
    piece(draw, 14, 57, 16, 'red', 'white');
    piece(draw, 10, 57, 11, 'red', 'white');
    piece(draw, 12, 56, 18, 'red', 'white');
    piece(draw, 14, 56, 16, 'red', 'white');
    piece(draw, 18, 56, 6, 'red', 'white');
    piece(draw, 19, 54, 15, 'red', 'white');
    piece(draw, 17, 52, 4, 'red', 'white');
    piece(draw, 20, 52, 12, 'red', 'white');
    piece(draw, 21, 49, 17, 'red', 'white');
    piece(draw, 19, 49, 7, 'red', 'white');
    piece(draw, 18, 47, 11, 'red', 'white');
    piece(draw, 20, 46, 12, 'red', 'white');
    piece(draw, 20, 44, 7, 'red', 'white');
    piece(draw, 20, 42, 18, 'red', 'white');
    piece(draw, 21, 38, 17, 'red', 'white');
    piece(draw, 18, 41, 9, 'red', 'white');
    piece(draw, 16, 39, 11, 'red', 'white');
    piece(draw, 18, 38, 12, 'red', 'white');
    piece(draw, 19, 38, 7, 'red', 'white');
    piece(draw, 20, 35, 5, 'red', 'white');
    piece(draw, 21, 33, 17, 'red', 'white');
    piece(draw, 20, 28, 8, 'red', 'white');
    piece(draw, 20, 30, 10, 'red', 'white');
    piece(draw, 19, 32, 7, 'red', 'white');
    piece(draw, 10, 33, 6, 'red', 'white');
    piece(draw, 11, 31, 16, 'red', 'white');
    piece(draw, 11, 32, 0, 'red', 'white');
    piece(draw, 14, 31, 13, 'red', 'white');
    piece(draw, 16, 31, 11, 'red', 'white');
    piece(draw, 17, 30, 15, 'red', 'white');
    piece(draw, 18, 28, 10, 'red', 'white');
    piece(draw, 17, 22, 14, 'red', 'white');
    piece(draw, 18, 24, 18, 'red', 'white');
    piece(draw, 19, 26, 18, 'red', 'white');
    piece(draw, 21, 25, 17, 'red', 'white');
    piece(draw, 20, 23, 14, 'red', 'white');
    piece(draw, 20, 21, 18, 'red', 'white');
    piece(draw, 19, 21, 5, 'red', 'white');
    piece(draw, 19, 19, 11, 'red', 'white');
    piece(draw, 18, 17, 12, 'red', 'white');
    piece(draw, 20, 17, 12, 'red', 'white');
    piece(draw, 19, 15, 14, 'red', 'white');
    piece(draw, 21, 14, 17, 'red', 'white');
    piece(draw, 20, 12, 14, 'red', 'white');
    piece(draw, 6, 12, 11, 'red', 'white');
    piece(draw, 8, 11, 2, 'red', 'white');
    piece(draw, 9, 10, 13, 'red', 'white');
    piece(draw, 11, 11, 6, 'red', 'white');
    piece(draw, 14, 10, 18, 'red', 'white');
    piece(draw, 16, 10, 6, 'red', 'white');
    piece(draw, 17, 11, 15, 'red', 'white');
    piece(draw, 19, 11, 9, 'red', 'white');
    piece(draw, 21, 7, 17, 'red', 'white');
    piece(draw, 19, 8, 7, 'red', 'white');
    piece(draw, 18, 8, 12, 'red', 'white');
    piece(draw, 16, 7, 13, 'red', 'white');
    piece(draw, 15, 8, 2, 'red', 'white');
    piece(draw, 13, 8, 18, 'red', 'white');
    piece(draw, 12, 8, 5, 'red', 'white');
    piece(draw, 10, 6, 9, 'red', 'white');
    piece(draw, 12, 6, 13, 'red', 'white');
    piece(draw, 14, 6, 11, 'red', 'white');
    piece(draw, 16, 5, 6, 'red', 'white');
    piece(draw, 17, 6, 0, 'red', 'white');
    piece(draw, 20, 5, 8, 'red', 'white');
    piece(draw, 19, 3, 14, 'red', 'white');
    piece(draw, 21, 2, 17, 'red', 'white');
    piece(draw, 18, 1, 0, 'red', 'white');
    piece(draw, 19, 0, 0, 'red', 'white');
    piece(draw, 16, 0, 9, 'red', 'white');
    piece(draw, 15, 2, 6, 'red', 'white');
    piece(draw, 14, 1, 6, 'red', 'white');
    piece(draw, 12, 0, 16, 'red', 'white');
    piece(draw, 12, 1, 18, 'red', 'white');
    piece(draw, 11, 3, 16, 'red', 'white');
    piece(draw, 8, 2, 4, 'red', 'white');
    piece(draw, 10, 0, 10, 'red', 'white');
    piece(draw, 8, 0, 9, 'red', 'white');
    piece(draw, 7, 1, 15, 'red', 'white');
    piece(draw, 4, 2, 16, 'red', 'white');
    piece(draw, 5, 0, 13, 'red', 'white');
    piece(draw, 1, 1, 16, 'red', 'white');
    piece(draw, 2, 0, 16, 'red', 'white');
    piece(draw, 0, 0, 3, 'red', 'white');

    // Hole one
    piece(draw, 15, 19, 7, 'red', 'white');
    piece(draw, 13, 22, 6, 'red', 'white');
    piece(draw, 11, 23, 18, 'red', 'white');
    piece(draw, 11, 21, 13, 'red', 'white');
    piece(draw, 14, 20, 18, 'red', 'white');

    // hole two
    piece(draw, 7, 41, 11, 'red', 'white');
    piece(draw, 9, 40, 18, 'red', 'white');
    piece(draw, 6, 39, 0, 'red', 'white');
    piece(draw, 5, 40, 3, 'red', 'white');
    piece(draw, 6, 40, 14, 'red', 'white');

    // words
    piece(draw, 18, 13, 7, 'white', 'red');
    piece(draw, 17, 16, 3, 'white', 'red');
    piece(draw, 17, 19, 7, 'white', 'red');
    piece(draw, 16, 20, 1, 'white', 'red');
    piece(draw, 17, 54, 11, 'white', 'red');
    piece(draw, 15, 53, 11, 'white', 'red');
    piece(draw, 14, 54, 2, 'white', 'red');
    piece(draw, 18, 58, 12, 'white', 'red');
    piece(draw, 17, 58, 5, 'white', 'red');
    piece(draw, 13, 58, 16, 'white', 'red');
    piece(draw, 13, 59, 16, 'white', 'red');
    piece(draw, 10, 59, 9, 'white', 'red');
    piece(draw, 9, 58, 5, 'white', 'red');
    piece(draw, 9, 56, 13, 'white', 'red');
    piece(draw, 11, 54, 4, 'white', 'red');
    piece(draw, 9, 53, 9, 'white', 'red');
    piece(draw, 11, 53, 13, 'white', 'red');
    piece(draw, 14, 52, 13, 'white', 'red');
    piece(draw, 18, 50, 14, 'white', 'red');
    piece(draw, 17, 50, 3, 'white', 'red');
    piece(draw, 15, 49, 16, 'white', 'red');
    piece(draw, 13, 47, 16, 'white', 'red');
    piece(draw, 11, 48, 18, 'white', 'red');
    piece(draw, 13, 48, 18, 'white', 'red');
    piece(draw, 15, 47, 4, 'white', 'red');
    piece(draw, 17, 46, 9, 'white', 'red');
    piece(draw, 19, 43, 5, 'white', 'red');
    piece(draw, 18, 42, 17, 'white', 'red');
    piece(draw, 15, 42, 0, 'white', 'red');
    piece(draw, 15, 40, 2, 'white', 'red');
    piece(draw, 12, 40, 4, 'white', 'red');
    piece(draw, 11, 41, 8, 'white', 'red');
    piece(draw, 8, 42, 4, 'white', 'red');
    piece(draw, 7, 43, 2, 'white', 'red');
    piece(draw, 4, 43, 4, 'white', 'red');
    piece(draw, 3, 42, 11, 'white', 'red');
    piece(draw, 2, 40, 5, 'white', 'red');
    piece(draw, 3, 40, 18, 'white', 'red');
    piece(draw, 3, 38, 11, 'white', 'red');
    piece(draw, 5, 37, 13, 'white', 'red');
    piece(draw, 7, 37, 11, 'white', 'red');
    piece(draw, 9, 38, 13, 'white', 'red');
    piece(draw, 11, 38, 14, 'white', 'red');
    piece(draw, 12, 39, 13, 'white', 'red');
    piece(draw, 15, 38, 18, 'white', 'red');
    piece(draw, 16, 37, 9, 'white', 'red');
    piece(draw, 17, 36, 0, 'white', 'red');
    piece(draw, 18, 33, 1, 'white', 'red');
    piece(draw, 16, 33, 0, 'white', 'red');
    piece(draw, 14, 33, 15, 'white', 'red');
    piece(draw, 12, 34, 0, 'white', 'red');
    piece(draw, 11, 34, 2, 'white', 'red');
    piece(draw, 7, 35, 16, 'white', 'red');
    piece(draw, 7, 32, 1, 'white', 'red');
    piece(draw, 9, 31, 17, 'white', 'red');
    piece(draw, 9, 30, 7, 'white', 'red');
    piece(draw, 8, 28, 6, 'white', 'red');
    piece(draw, 9, 29, 0, 'white', 'red');
    piece(draw, 12, 29, 18, 'white', 'red');
    piece(draw, 14, 29, 18, 'white', 'red');
    piece(draw, 17, 27, 14, 'white', 'red');
    piece(draw, 16, 27, 17, 'white', 'red');
    piece(draw, 17, 25, 8, 'white', 'red');
    piece(draw, 14, 25, 11, 'white', 'red');
    piece(draw, 15, 23, 10, 'white', 'red');
    piece(draw, 13, 23, 13, 'white', 'red');
    piece(draw, 11, 25, 16, 'white', 'red');
    piece(draw, 10, 26, 16, 'white', 'red');
    piece(draw, 8, 24, 10, 'white', 'red');
    piece(draw, 8, 22, 8, 'white', 'red');
    piece(draw, 10, 22, 17, 'white', 'red');
    piece(draw, 9, 20, 14, 'white', 'red');
    piece(draw, 11, 19, 8, 'white', 'red');
    piece(draw, 12, 18, 12, 'white', 'red');
    piece(draw, 13, 18, 9, 'white', 'red');
    piece(draw, 14, 17, 0, 'white', 'red');
    piece(draw, 15, 15, 13, 'white', 'red');
    piece(draw, 16, 14, 0, 'white', 'red');
    piece(draw, 16, 12, 18, 'white', 'red');
    piece(draw, 14, 13, 7, 'white', 'red');
    piece(draw, 12, 13, 11, 'white', 'red');
    piece(draw, 12, 12, 16, 'white', 'red');
    piece(draw, 10, 13, 9, 'white', 'red');
    piece(draw, 8, 13, 11, 'white', 'red');
    piece(draw, 7, 14, 2, 'white', 'red');
    piece(draw, 5, 13, 12, 'white', 'red');
    piece(draw, 4, 13, 5, 'white', 'red');
    piece(draw, 1, 14, 0, 'white', 'red');
    piece(draw, 2, 12, 13, 'white', 'red');
    piece(draw, 4, 10, 10, 'white', 'red');
    piece(draw, 6, 10, 8, 'white', 'red');
    piece(draw, 7, 9, 18, 'white', 'red');
    piece(draw, 9, 9, 6, 'white', 'red');
    piece(draw, 9, 7, 11, 'white', 'red');
    piece(draw, 18, 2, 18, 'white', 'red');
    piece(draw, 16, 3, 15, 'white', 'red');
    piece(draw, 14, 4, 13, 'white', 'red');
    piece(draw, 12, 4, 9, 'white', 'red');
    piece(draw, 10, 4, 15, 'white', 'red');
    piece(draw, 9, 4, 8, 'white', 'red');
    piece(draw, 7, 6, 15, 'white', 'red');
    piece(draw, 5, 5, 16, 'white', 'red');
    piece(draw, 6, 3, 11, 'white', 'red');
    piece(draw, 4, 3, 13, 'white', 'red');
    piece(draw, 2, 3, 9, 'white', 'red');
    piece(draw, 1, 2, 6, 'white', 'red');
});

var piece = function(draw, row, col, type, color, boarderColor)
{
    type = type % 19;
    var fun;
    if (type < 4)
    {
        fun = L;
    }
    else if (type < 8)
    {
        fun = J;
    }
    else if (type < 12)
    {
        fun = T;
    }
    else if (type < 14)
    {
        fun = Z;
    }
    else if (type < 16)
    {
        fun = S;
    }
    else if (type < 18)
    {
        fun = I;
    }
    else
    {
        fun = O;
    }
    
    fun(draw, row, col, type, color, boarderColor);
}

// Function to draw a tetris piece
var J = function (draw, row, col, orientation, color, boarderColor) {
    orientation = orientation % 4;

    switch (orientation) {
    case 0:
        rectangle(draw, 3, 1, row, col+1, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+2, col, false).fill({color: boarderColor});

        rectangle(draw, 3, 1, row, col+1, true).fill({color: color});
        rectangle(draw, 1, 2, row+2, col, true).fill({color: color});
        break;
    case 1:
        rectangle(draw, 2, 1, row, col+2, false).fill({color: boarderColor});
        rectangle(draw, 1, 3, row, col, false).fill({color: boarderColor});

        rectangle(draw, 2, 1, row, col+2, true).fill({color: color});
        rectangle(draw, 1, 3, row, col, true).fill({color: color});
        break;
    case 2:
        rectangle(draw, 3, 1, row, col, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row, col, false).fill({color: boarderColor});

        rectangle(draw, 3, 1, row, col, true).fill({color: color});
        rectangle(draw, 1, 2, row, col, true).fill({color: color});
        break;
    case 3:
        rectangle(draw, 2, 1, row, col, false).fill({color: boarderColor});
        rectangle(draw, 1, 3, row+1, col, false).fill({color: boarderColor});

        rectangle(draw, 2, 1, row, col, true).fill({color: color});
        rectangle(draw, 1, 3, row+1, col, true).fill({color: color});
        break;
    }
}

// Function to draw a tetris piece
var L = function (draw, row, col, orientation, color, boarderColor) {
    orientation = orientation % 4;

    switch (orientation) {
    case 0:
        rectangle(draw, 3, 1, row, col, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+2, col, false).fill({color: boarderColor});

        rectangle(draw, 3, 1, row, col, true).fill({color: color});
        rectangle(draw, 1, 2, row+2, col, true).fill({color: color});
        break;
    case 1:
        rectangle(draw, 2, 1, row, col+2, false).fill({color: boarderColor});
        rectangle(draw, 1, 3, row+1, col, false).fill({color: boarderColor});

        rectangle(draw, 2, 1, row, col+2, true).fill({color: color});
        rectangle(draw, 1, 3, row+1, col, true).fill({color: color});
        break;
    case 2:
        rectangle(draw, 3, 1, row, col+1, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row, col, false).fill({color: boarderColor});

        rectangle(draw, 3, 1, row, col+1, true).fill({color: color});
        rectangle(draw, 1, 2, row, col, true).fill({color: color});
        break;
    case 3:
        rectangle(draw, 2, 1, row, col, false).fill({color: boarderColor});
        rectangle(draw, 1, 3, row, col, false).fill({color: boarderColor});

        rectangle(draw, 2, 1, row, col, true).fill({color: color});
        rectangle(draw, 1, 3, row, col, true).fill({color: color});
        break;
    }
}

// Function to draw a tetris piece
var T = function (draw, row, col, orientation, color, boarderColor) {
    orientation = orientation % 4;

    switch (orientation) {
    case 0:
        rectangle(draw, 1, 3, row, col, false).fill({color: boarderColor});
        rectangle(draw, 2, 1, row, col+1, false).fill({color: boarderColor});

        rectangle(draw, 1, 3, row, col, true).fill({color: color});
        rectangle(draw, 2, 1, row, col+1, true).fill({color: color});
        break;
    case 1:
        rectangle(draw, 3, 1, row, col, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+1, col, false).fill({color: boarderColor});

        rectangle(draw, 3, 1, row, col, true).fill({color: color});
        rectangle(draw, 1, 2, row+1, col, true).fill({color: color});
        break;
    case 2:
        rectangle(draw, 1, 3, row+1, col, false).fill({color: boarderColor});
        rectangle(draw, 2, 1, row, col+1, false).fill({color: boarderColor});

        rectangle(draw, 1, 3, row+1, col, true).fill({color: color});
        rectangle(draw, 2, 1, row, col+1, true).fill({color: color});
        break;
    case 3:
        rectangle(draw, 3, 1, row, col+1, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+1, col, false).fill({color: boarderColor});

        rectangle(draw, 3, 1, row, col+1, true).fill({color: color});
        rectangle(draw, 1, 2, row+1, col, true).fill({color: color});
        break;
    }
}

// Function to draw a tetris piece
var Z = function (draw, row, col, orientation, color, boarderColor) {
    orientation = orientation % 2;

    switch (orientation) {
    case 0:
        rectangle(draw, 1, 2, row, col, false).fill({color: boarderColor});
        rectangle(draw, 2, 1, row, col+1, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+1, col+1, false).fill({color: boarderColor});

        rectangle(draw, 1, 2, row, col, true).fill({color: color});
        rectangle(draw, 2, 1, row, col+1, true).fill({color: color});
        rectangle(draw, 1, 2, row+1, col+1, true).fill({color: color});        
        break;
    case 1:
        rectangle(draw, 2, 1, row+1, col, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+1, col, false).fill({color: boarderColor});
        rectangle(draw, 2, 1, row, col+1, false).fill({color: boarderColor});

        rectangle(draw, 2, 1, row+1, col, true).fill({color: color});
        rectangle(draw, 1, 2, row+1, col, true).fill({color: color});
        rectangle(draw, 2, 1, row, col+1, true).fill({color: color});
        break;
    }
}

// Function to draw a tetris piece
var S = function (draw, row, col, orientation, color, boarderColor) {
    orientation = orientation % 2;

    switch (orientation) {
    case 0:
        rectangle(draw, 1, 2, row, col+1, false).fill({color: boarderColor});
        rectangle(draw, 2, 1, row, col+1, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+1, col, false).fill({color: boarderColor});

        rectangle(draw, 1, 2, row, col+1, true).fill({color: color});
        rectangle(draw, 2, 1, row, col+1, true).fill({color: color});
        rectangle(draw, 1, 2, row+1, col, true).fill({color: color});        
        break;
    case 1:
        rectangle(draw, 2, 1, row, col, false).fill({color: boarderColor});
        rectangle(draw, 1, 2, row+1, col, false).fill({color: boarderColor});
        rectangle(draw, 2, 1, row+1, col+1, false).fill({color: boarderColor});

        rectangle(draw, 2, 1, row, col, true).fill({color: color});
        rectangle(draw, 1, 2, row+1, col, true).fill({color: color});
        rectangle(draw, 2, 1, row+1, col+1, true).fill({color: color});
        break;
    }
}

// Function to draw a tetris piece
var I = function (draw, row, col, orientation, color, boarderColor) {
    orientation = orientation % 2;

    switch (orientation) {
    case 0:
        rectangle(draw, 4, 1, row, col, false).fill({color: boarderColor});

        rectangle(draw, 4, 1, row, col, true).fill({color: color});
        break;
    case 1:
        rectangle(draw, 1, 4, row, col, false).fill({color: boarderColor});

        rectangle(draw, 1, 4, row, col, true).fill({color: color});
        break;
    }
}

var O = function (draw, row, col, orientation, color, boarderColor) {
    rectangle(draw, 2, 2, row, col, false).fill({color: boarderColor});
    
    rectangle(draw, 2, 2, row, col, true).fill({color: color});
}

// boarderReduction is a boolean
var rectangle = function(draw, rowSize, colSize, rowOffset, colOffset, boarderReduction) {
    return draw.rect(scale*colSize - 2*boarderWidth*boarderReduction, scale*rowSize - 2*boarderWidth*boarderReduction)
        .move(colOffset*scale + boarderWidth*boarderReduction, rowOffset*scale + boarderWidth*boarderReduction);
}
