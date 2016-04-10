var scale = 20;
var boarderWidth = .1*scale;

$(document).ready(function () {
    // create svg drawing
    var draw = SVG('drawing').size(60*scale, 20*scale);
    
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

    piece(draw, 17, 12, 10, 'red', 'pink');
    piece(draw, 16, 53, 11, 'red', 'pink');
    piece(draw, 16, 58, 4, 'red', 'pink');
    piece(draw, 16, 57, 18, 'red', 'pink');
    piece(draw, 13, 57, 0, 'red', 'pink');
    piece(draw, 12, 57, 2, 'red', 'pink');
    piece(draw, 9, 58, 13, 'red', 'pink');
    piece(draw, 8, 57, 8, 'red', 'pink');
    piece(draw, 8, 55, 13, 'red', 'pink');
    piece(draw, 11, 52, 0, 'red', 'pink');
    piece(draw, 8, 52, 9, 'red', 'pink');
    piece(draw, 10, 53, 18, 'red', 'pink');
    piece(draw, 12, 53, 2, 'red', 'pink');
    piece(draw, 15, 52, 8, 'red', 'pink');
    piece(draw, 14, 51, 3, 'red', 'pink');
    piece(draw, 16, 50, 18, 'red', 'pink');
    piece(draw, 17, 48, 12, 'red', 'pink');
    piece(draw, 14, 48, 0, 'red', 'pink');
    piece(draw, 10, 47, 15, 'red', 'pink');
    piece(draw, 12, 46, 12, 'red', 'pink');
    piece(draw, 13, 46, 9, 'red', 'pink');
    piece(draw, 15, 45, 1, 'red', 'pink');
    piece(draw, 18, 43, 8, 'red', 'pink');
    piece(draw, 17, 43, 17, 'red', 'pink');
    piece(draw, 16, 41, 11, 'red', 'pink');
    piece(draw, 15, 40, 18, 'red', 'pink');
    piece(draw, 13, 39, 7, 'red', 'pink');
    piece(draw, 10, 40, 16, 'red', 'pink');
    piece(draw, 9, 41, 9, 'red', 'pink');
    piece(draw, 5, 43, 16, 'red', 'pink');
    piece(draw, 6, 42, 16, 'red', 'pink');
    piece(draw, 2, 42, 16, 'red', 'pink');
    piece(draw, 1, 40, 2, 'red', 'pink');
    piece(draw, 1, 39, 9, 'red', 'pink');
    piece(draw, 2, 37, 11, 'red', 'pink');
    piece(draw, 4, 36, 11, 'red', 'pink');
    piece(draw, 6, 36, 15, 'red', 'pink');
    piece(draw, 8, 37, 13, 'red', 'pink');
    piece(draw, 10, 37, 14, 'red', 'pink');
    piece(draw, 11, 38, 13, 'red', 'pink');
    piece(draw, 14, 37, 18, 'red', 'pink');
    piece(draw, 15, 35, 10, 'red', 'pink');
    piece(draw, 17, 34, 5, 'red', 'pink');
    piece(draw, 18, 32, 17, 'red', 'pink');
    piece(draw, 15, 32, 0, 'red', 'pink');
    piece(draw, 13, 32, 15, 'red', 'pink');
    piece(draw, 12, 33, 18, 'red', 'pink');
    piece(draw, 10, 33, 18, 'red', 'pink');
    piece(draw, 6, 34, 16, 'red', 'pink');
    piece(draw, 6, 32, 11, 'red', 'pink');
    piece(draw, 7, 31, 9, 'red', 'pink');
    piece(draw, 8, 29, 13, 'red', 'pink');
    piece(draw, 7, 27, 12, 'red', 'pink');
    piece(draw, 8, 27, 15, 'red', 'pink');
    piece(draw, 11, 28, 2, 'red', 'pink');
    piece(draw, 12, 28, 0, 'red', 'pink');
    piece(draw, 16, 26, 14, 'red', 'pink');
    piece(draw, 15, 26, 17, 'red', 'pink');
    piece(draw, 16, 24, 8, 'red', 'pink');
    piece(draw, 11, 16, 4, 'red', 'pink');
    piece(draw, 10, 18, 16, 'red', 'pink');
    piece(draw, 10, 19, 13, 'red', 'pink');
    piece(draw, 8, 19, 13, 'red', 'pink');
    piece(draw, 7, 23, 18, 'red', 'pink');
    piece(draw, 7, 21, 18, 'red', 'pink');
    piece(draw, 9, 21, 17, 'red', 'pink');
    piece(draw, 9, 24, 13, 'red', 'pink');
    piece(draw, 11, 24, 4, 'red', 'pink');
    piece(draw, 12, 22, 14, 'red', 'pink');
    piece(draw, 14, 22, 17, 'red', 'pink');
    piece(draw, 15, 22, 17, 'red', 'pink');
    piece(draw, 15, 20, 13, 'red', 'pink');
    piece(draw, 16, 18, 18, 'red', 'pink');
    piece(draw, 15, 16, 18, 'red', 'pink');
    piece(draw, 15, 14, 4, 'red', 'pink');
    piece(draw, 14, 14, 17, 'red', 'pink');
    piece(draw, 15, 12, 5, 'red', 'pink');
    piece(draw, 16, 11, 8, 'red', 'pink');
    piece(draw, 14, 11, 3, 'red', 'pink');
    piece(draw, 12, 11, 1, 'red', 'pink');
    piece(draw, 11, 11, 18, 'red', 'pink');
    piece(draw, 9, 12, 15, 'red', 'pink');
    piece(draw, 8, 12, 8, 'red', 'pink');
    piece(draw, 5, 13, 0, 'red', 'pink');
    piece(draw, 3, 14, 16, 'red', 'pink');
    piece(draw, 0, 13, 0, 'red', 'pink');
    piece(draw, 1, 11, 11, 'red', 'pink');
    piece(draw, 3, 11, 1, 'red', 'pink');
    piece(draw, 3, 9, 14, 'red', 'pink');
    piece(draw, 5, 9, 8, 'red', 'pink');
    piece(draw, 6, 8, 2, 'red', 'pink');
    piece(draw, 7, 8, 16, 'red', 'pink');
    piece(draw, 8, 6, 11, 'red', 'pink');
    piece(draw, 7, 4, 5, 'red', 'pink');
    piece(draw, 17, 1, 18, 'red', 'pink');
    piece(draw, 15, 2, 15, 'red', 'pink');
    piece(draw, 13, 3, 13, 'red', 'pink');
    piece(draw, 11, 3, 9, 'red', 'pink');
    piece(draw, 9, 3, 15, 'red', 'pink');
    piece(draw, 8, 3, 8, 'red', 'pink');
    piece(draw, 5, 2, 15, 'red', 'pink');
    piece(draw, 4, 4, 0, 'red', 'pink');
    piece(draw, 2, 3, 16, 'red', 'pink');
    piece(draw, 2, 1, 2, 'red', 'pink');
    piece(draw, 0, 1, 18, 'red', 'pink');
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
