var scale = 20;
var boarderWidth = .1*scale;

$(document).ready(function () {
    // create svg drawing
    var draw = SVG('drawing').size(40*scale, 40*scale);
    
    // create text
    // piece(draw, 4, 0, 0, 'red', 'pink');
    // piece(draw, 4, 4, 1, 'red', 'pink');
    // piece(draw, 4, 8, 2, 'red', 'pink');
    // piece(draw, 4, 12, 3, 'red', 'pink');

    // piece(draw, 0, 0, 4, 'red', 'pink');
    // piece(draw, 0, 4, 5, 'red', 'pink');
    // piece(draw, 0, 8, 6, 'red', 'pink');
    // piece(draw, 0, 12, 7, 'red', 'pink');

    // piece(draw, 8, 0, 8, 'red', 'pink');
    // piece(draw, 8, 4, 9, 'red', 'pink');
    // piece(draw, 8, 8, 10, 'red', 'pink');
    // piece(draw, 8, 12, 11, 'red', 'pink');

    // piece(draw, 12, 0, 12, 'red', 'pink');
    // piece(draw, 12, 4, 13, 'red', 'pink');

    // piece(draw, 16, 0, 14, 'red', 'pink');
    // piece(draw, 16, 4, 15, 'red', 'pink');

    // piece(draw, 20, 0, 16, 'red', 'pink');
    // piece(draw, 20, 4, 17, 'red', 'pink');

    // piece(draw, 24, 0, 18, 'red', 'pink');

    // piece(draw, 17, 7, 11, 'red', 'pink');
    // piece(draw, 5, 8, 8, 'red', 'pink');
    // piece(draw, 2, 6, 18, 'red', 'pink');
    // piece(draw, 3, 7, 10, 'red', 'pink');
    // piece(draw, 2, 11, 1, 'red', 'pink');
    // piece(draw, 2, 10, 0, 'red', 'pink');
    // piece(draw, 1, 11, 18, 'red', 'pink');
    // piece(draw, 7, 16, 13, 'red', 'pink');
    // piece(draw, 5, 17, 11, 'red', 'pink');
    // piece(draw, 3, 18, 15, 'red', 'pink');
    // piece(draw, 3, 16, 4, 'red', 'pink');
    // piece(draw, 1, 16, 12, 'red', 'pink');
    // piece(draw, 2, 15, 18, 'red', 'pink');
    // piece(draw, 0, 13, 5, 'red', 'pink');
    // piece(draw, 1, 13, 2, 'red', 'pink');
    // piece(draw, 4, 14, 8, 'red', 'pink');
    // piece(draw, 6, 15, 18, 'red', 'pink');
    // piece(draw, 8, 14, 18, 'red', 'pink');
    // piece(draw, 9, 13, 9, 'red', 'pink');
    // piece(draw, 9, 11, 11, 'red', 'pink');
    // piece(draw, 11, 11, 9, 'red', 'pink');
    // piece(draw, 11, 9, 4, 'red', 'pink');
    // piece(draw, 14, 9, 8, 'red', 'pink');
    // piece(draw, 15, 8, 18, 'red', 'pink');
    // piece(draw, 16, 6, 18, 'red', 'pink');
    // piece(draw, 14, 5, 13, 'red', 'pink');
    // piece(draw, 13, 4, 18, 'red', 'pink');
    // piece(draw, 11, 3, 13, 'red', 'pink');
    // piece(draw, 10, 2, 13, 'red', 'pink');
    // piece(draw, 9, 1, 9, 'red', 'pink');
    // piece(draw, 8, 1, 12, 'red', 'pink');
    // piece(draw, 5, 1, 14, 'red', 'pink');
    // piece(draw, 6, 0, 7, 'red', 'pink');
    // piece(draw, 4, 0, 14, 'red', 'pink');
    // piece(draw, 2, 1, 7, 'red', 'pink');
    // piece(draw, 2, 3, 4, 'red', 'pink');
    // piece(draw, 1, 4, 2, 'red', 'pink');
    // piece(draw, 1, 2, 18, 'red', 'pink');

    // Marlin
    // piece(draw, 17, 12, 10, 'red', 'pink');
    // piece(draw, 16, 53, 11, 'red', 'pink');
    // piece(draw, 16, 58, 4, 'red', 'pink');
    // piece(draw, 16, 57, 18, 'red', 'pink');
    // piece(draw, 13, 57, 0, 'red', 'pink');
    // piece(draw, 12, 57, 2, 'red', 'pink');
    // piece(draw, 9, 58, 13, 'red', 'pink');
    // piece(draw, 8, 57, 8, 'red', 'pink');
    // piece(draw, 8, 55, 13, 'red', 'pink');
    // piece(draw, 11, 52, 0, 'red', 'pink');
    // piece(draw, 8, 52, 9, 'red', 'pink');
    // piece(draw, 10, 53, 18, 'red', 'pink');
    // piece(draw, 12, 53, 2, 'red', 'pink');
    // piece(draw, 15, 52, 8, 'red', 'pink');
    // piece(draw, 14, 51, 3, 'red', 'pink');
    // piece(draw, 16, 50, 18, 'red', 'pink');
    // piece(draw, 17, 48, 12, 'red', 'pink');
    // piece(draw, 14, 48, 0, 'red', 'pink');
    // piece(draw, 10, 47, 15, 'red', 'pink');
    // piece(draw, 12, 46, 12, 'red', 'pink');
    // piece(draw, 13, 46, 9, 'red', 'pink');
    // piece(draw, 15, 45, 1, 'red', 'pink');
    // piece(draw, 18, 43, 8, 'red', 'pink');
    // piece(draw, 17, 43, 17, 'red', 'pink');
    // piece(draw, 16, 41, 11, 'red', 'pink');
    // piece(draw, 15, 40, 18, 'red', 'pink');
    // piece(draw, 13, 39, 7, 'red', 'pink');
    // piece(draw, 10, 40, 16, 'red', 'pink');
    // piece(draw, 9, 41, 9, 'red', 'pink');
    // piece(draw, 5, 43, 16, 'red', 'pink');
    // piece(draw, 6, 42, 16, 'red', 'pink');
    // piece(draw, 2, 42, 16, 'red', 'pink');
    // piece(draw, 1, 40, 2, 'red', 'pink');
    // piece(draw, 1, 39, 9, 'red', 'pink');
    // piece(draw, 2, 37, 11, 'red', 'pink');
    // piece(draw, 4, 36, 11, 'red', 'pink');
    // piece(draw, 6, 36, 15, 'red', 'pink');
    // piece(draw, 8, 37, 13, 'red', 'pink');
    // piece(draw, 10, 37, 14, 'red', 'pink');
    // piece(draw, 11, 38, 13, 'red', 'pink');
    // piece(draw, 14, 37, 18, 'red', 'pink');
    // piece(draw, 15, 35, 10, 'red', 'pink');
    // piece(draw, 17, 34, 5, 'red', 'pink');
    // piece(draw, 18, 32, 17, 'red', 'pink');
    // piece(draw, 15, 32, 0, 'red', 'pink');
    // piece(draw, 13, 32, 15, 'red', 'pink');
    // piece(draw, 12, 33, 18, 'red', 'pink');
    // piece(draw, 10, 33, 18, 'red', 'pink');
    // piece(draw, 6, 34, 16, 'red', 'pink');
    // piece(draw, 6, 32, 11, 'red', 'pink');
    // piece(draw, 7, 31, 9, 'red', 'pink');
    // piece(draw, 8, 29, 13, 'red', 'pink');
    // piece(draw, 7, 27, 12, 'red', 'pink');
    // piece(draw, 8, 27, 15, 'red', 'pink');
    // piece(draw, 11, 28, 2, 'red', 'pink');
    // piece(draw, 12, 28, 0, 'red', 'pink');
    // piece(draw, 16, 26, 14, 'red', 'pink');
    // piece(draw, 15, 26, 17, 'red', 'pink');
    // piece(draw, 16, 24, 8, 'red', 'pink');
    // piece(draw, 11, 16, 4, 'red', 'pink');
    // piece(draw, 10, 18, 16, 'red', 'pink');
    // piece(draw, 10, 19, 13, 'red', 'pink');
    // piece(draw, 8, 19, 13, 'red', 'pink');
    // piece(draw, 7, 23, 18, 'red', 'pink');
    // piece(draw, 7, 21, 18, 'red', 'pink');
    // piece(draw, 9, 21, 17, 'red', 'pink');
    // piece(draw, 9, 24, 13, 'red', 'pink');
    // piece(draw, 11, 24, 4, 'red', 'pink');
    // piece(draw, 12, 22, 14, 'red', 'pink');
    // piece(draw, 14, 22, 17, 'red', 'pink');
    // piece(draw, 15, 22, 17, 'red', 'pink');
    // piece(draw, 15, 20, 13, 'red', 'pink');
    // piece(draw, 16, 18, 18, 'red', 'pink');
    // piece(draw, 15, 16, 18, 'red', 'pink');
    // piece(draw, 15, 14, 4, 'red', 'pink');
    // piece(draw, 14, 14, 17, 'red', 'pink');
    // piece(draw, 15, 12, 5, 'red', 'pink');
    // piece(draw, 16, 11, 8, 'red', 'pink');
    // piece(draw, 14, 11, 3, 'red', 'pink');
    // piece(draw, 12, 11, 1, 'red', 'pink');
    // piece(draw, 11, 11, 18, 'red', 'pink');
    // piece(draw, 9, 12, 15, 'red', 'pink');
    // piece(draw, 8, 12, 8, 'red', 'pink');
    // piece(draw, 5, 13, 0, 'red', 'pink');
    // piece(draw, 3, 14, 16, 'red', 'pink');
    // piece(draw, 0, 13, 0, 'red', 'pink');
    // piece(draw, 1, 11, 11, 'red', 'pink');
    // piece(draw, 3, 11, 1, 'red', 'pink');
    // piece(draw, 3, 9, 14, 'red', 'pink');
    // piece(draw, 5, 9, 8, 'red', 'pink');
    // piece(draw, 6, 8, 2, 'red', 'pink');
    // piece(draw, 7, 8, 16, 'red', 'pink');
    // piece(draw, 8, 6, 11, 'red', 'pink');
    // piece(draw, 7, 4, 5, 'red', 'pink');
    // piece(draw, 17, 1, 18, 'red', 'pink');
    // piece(draw, 15, 2, 15, 'red', 'pink');
    // piece(draw, 13, 3, 13, 'red', 'pink');
    // piece(draw, 11, 3, 9, 'red', 'pink');
    // piece(draw, 9, 3, 15, 'red', 'pink');
    // piece(draw, 8, 3, 8, 'red', 'pink');
    // piece(draw, 5, 2, 15, 'red', 'pink');
    // piece(draw, 4, 4, 0, 'red', 'pink');
    // piece(draw, 2, 3, 16, 'red', 'pink');
    // piece(draw, 2, 1, 2, 'red', 'pink');
    // piece(draw, 0, 1, 18, 'red', 'pink');

    piece(draw, 23, 26, 4, 'red', 'pink');
    piece(draw, 21, 24, 0, 'red', 'pink');
    piece(draw, 21, 25, 15, 'red', 'pink');
    piece(draw, 15, 29, 0, 'red', 'pink');
    piece(draw, 35, 26, 18, 'red', 'pink');
    piece(draw, 36, 25, 9, 'red', 'pink');
    piece(draw, 36, 23, 4, 'red', 'pink');
    piece(draw, 38, 21, 10, 'red', 'pink');
    piece(draw, 36, 20, 12, 'red', 'pink');
    piece(draw, 36, 19, 9, 'red', 'pink');
    piece(draw, 38, 19, 14, 'red', 'pink');
    piece(draw, 38, 16, 10, 'red', 'pink');
    piece(draw, 36, 17, 11, 'red', 'pink');
    piece(draw, 35, 15, 10, 'red', 'pink');
    piece(draw, 34, 17, 18, 'red', 'pink');
    piece(draw, 33, 19, 10, 'red', 'pink');
    piece(draw, 35, 19, 17, 'red', 'pink');
    piece(draw, 35, 22, 11, 'red', 'pink');
    piece(draw, 33, 23, 18, 'red', 'pink');
    piece(draw, 33, 24, 4, 'red', 'pink');
    piece(draw, 33, 26, 7, 'red', 'pink');
    piece(draw, 32, 27, 7, 'red', 'pink');
    piece(draw, 29, 29, 16, 'red', 'pink');
    piece(draw, 28, 27, 4, 'red', 'pink');
    piece(draw, 27, 29, 11, 'red', 'pink');
    piece(draw, 24, 30, 13, 'red', 'pink');
    piece(draw, 24, 29, 16, 'red', 'pink');
    piece(draw, 22, 29, 15, 'red', 'pink');
    piece(draw, 21, 30, 11, 'red', 'pink');
    piece(draw, 19, 29, 11, 'red', 'pink');
    piece(draw, 18, 28, 14, 'red', 'pink');
    piece(draw, 20, 27, 12, 'red', 'pink');
    piece(draw, 21, 27, 15, 'red', 'pink');
    piece(draw, 24, 28, 16, 'red', 'pink');
    piece(draw, 28, 23, 7, 'red', 'pink');
    piece(draw, 27, 25, 14, 'red', 'pink');
    piece(draw, 28, 26, 13, 'red', 'pink');
    piece(draw, 31, 26, 5, 'red', 'pink');
    piece(draw, 31, 24, 12, 'red', 'pink');
    piece(draw, 30, 23, 3, 'red', 'pink');
    piece(draw, 31, 22, 7, 'red', 'pink');
    piece(draw, 32, 21, 15, 'red', 'pink');
    piece(draw, 29, 20, 15, 'red', 'pink');
    piece(draw, 31, 19, 18, 'red', 'pink');
    piece(draw, 31, 18, 0, 'red', 'pink');
    piece(draw, 30, 16, 17, 'red', 'pink');
    piece(draw, 31, 15, 14, 'red', 'pink');
    piece(draw, 32, 16, 13, 'red', 'pink');
    piece(draw, 34, 14, 13, 'red', 'pink');
    piece(draw, 37, 14, 5, 'red', 'pink');
    piece(draw, 38, 13, 5, 'red', 'pink');
    piece(draw, 36, 11, 12, 'red', 'pink');
    piece(draw, 35, 11, 5, 'red', 'pink');
    piece(draw, 33, 13, 14, 'red', 'pink');
    piece(draw, 33, 11, 8, 'red', 'pink');
    piece(draw, 33, 10, 9, 'red', 'pink');
    piece(draw, 29, 9, 1, 'red', 'pink');
    piece(draw, 31, 9, 3, 'red', 'pink');
    piece(draw, 32, 10, 17, 'red', 'pink');
    piece(draw, 31, 13, 8, 'red', 'pink');
    piece(draw, 29, 12, 13, 'red', 'pink');
    piece(draw, 29, 14, 18, 'red', 'pink');
    piece(draw, 28, 16, 1, 'red', 'pink');
    piece(draw, 28, 19, 3, 'red', 'pink');
    piece(draw, 28, 21, 11, 'red', 'pink');
    piece(draw, 27, 22, 5, 'red', 'pink');
    piece(draw, 26, 25, 3, 'red', 'pink');
    piece(draw, 25, 23, 8, 'red', 'pink');
    piece(draw, 24, 23, 17, 'red', 'pink');
    piece(draw, 22, 22, 9, 'red', 'pink');
    piece(draw, 25, 21, 10, 'red', 'pink');
    piece(draw, 26, 19, 10, 'red', 'pink');
    piece(draw, 24, 19, 1, 'red', 'pink');
    piece(draw, 21, 20, 16, 'red', 'pink');
    piece(draw, 20, 21, 16, 'red', 'pink');
    piece(draw, 20, 22, 15, 'red', 'pink');
    piece(draw, 19, 23, 14, 'red', 'pink');
    piece(draw, 19, 25, 11, 'red', 'pink');
    piece(draw, 17, 27, 9, 'red', 'pink');
    piece(draw, 16, 26, 5, 'red', 'pink');
    piece(draw, 14, 26, 5, 'red', 'pink');
    piece(draw, 13, 24, 17, 'red', 'pink');
    piece(draw, 14, 22, 17, 'red', 'pink');
    piece(draw, 15, 24, 17, 'red', 'pink');
    piece(draw, 16, 24, 12, 'red', 'pink');
    piece(draw, 17, 24, 7, 'red', 'pink');
    piece(draw, 17, 22, 15, 'red', 'pink');
    piece(draw, 17, 19, 4, 'red', 'pink');
    piece(draw, 17, 21, 0, 'red', 'pink');
    piece(draw, 16, 21, 5, 'red', 'pink');
    piece(draw, 15, 20, 17, 'red', 'pink');
    piece(draw, 13, 21, 3, 'red', 'pink');
    piece(draw, 8, 17, 15, 'red', 'pink');
    piece(draw, 10, 19, 15, 'red', 'pink');
    piece(draw, 13, 18, 5, 'red', 'pink');
    piece(draw, 13, 14, 17, 'red', 'pink');
    piece(draw, 14, 15, 8, 'red', 'pink');
    piece(draw, 14, 17, 14, 'red', 'pink');
    piece(draw, 15, 18, 10, 'red', 'pink');
    piece(draw, 24, 16, 18, 'red', 'pink');
    piece(draw, 21, 17, 4, 'red', 'pink');
    piece(draw, 18, 16, 9, 'red', 'pink');
    piece(draw, 20, 16, 11, 'red', 'pink');
    piece(draw, 22, 14, 5, 'red', 'pink');
    piece(draw, 23, 14, 11, 'red', 'pink');
    piece(draw, 23, 12, 14, 'red', 'pink');
    piece(draw, 22, 11, 8, 'red', 'pink');
    piece(draw, 21, 11, 17, 'red', 'pink');
    piece(draw, 20, 10, 17, 'red', 'pink');
    piece(draw, 19, 14, 11, 'red', 'pink');
    piece(draw, 17, 14, 13, 'red', 'pink');
    piece(draw, 17, 16, 17, 'red', 'pink');
    piece(draw, 18, 17, 8, 'red', 'pink');
    piece(draw, 20, 18, 8, 'red', 'pink');
    piece(draw, 22, 18, 4, 'red', 'pink');
    piece(draw, 25, 18, 9, 'red', 'pink');
    piece(draw, 27, 15, 5, 'red', 'pink');
    piece(draw, 27, 14, 7, 'red', 'pink');
    piece(draw, 26, 14, 17, 'red', 'pink');
    piece(draw, 25, 12, 14, 'red', 'pink');
    piece(draw, 27, 11, 5, 'red', 'pink');
    piece(draw, 28, 10, 5, 'red', 'pink');
    piece(draw, 28, 8, 12, 'red', 'pink');
    piece(draw, 26, 8, 7, 'red', 'pink');
    piece(draw, 25, 9, 7, 'red', 'pink');
    piece(draw, 24, 10, 7, 'red', 'pink');
    piece(draw, 23, 9, 5, 'red', 'pink');
    piece(draw, 23, 8, 9, 'red', 'pink');
    piece(draw, 20, 8, 0, 'red', 'pink');
    piece(draw, 20, 9, 15, 'red', 'pink');
    piece(draw, 16, 10, 9, 'red', 'pink');
    piece(draw, 17, 9, 0, 'red', 'pink');
    piece(draw, 18, 11, 1, 'red', 'pink');
    piece(draw, 15, 13, 0, 'red', 'pink');
    piece(draw, 16, 11, 4, 'red', 'pink');
    piece(draw, 14, 11, 13, 'red', 'pink');
    piece(draw, 14, 13, 12, 'red', 'pink');
    piece(draw, 16, 14, 17, 'red', 'pink');

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
