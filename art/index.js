var scale = 50;
var boarderWidth = .1*scale;

$(document).ready(function () {
    // create svg drawing
    var draw = SVG('drawing').size(16*scale, 28*scale);
    
    // create text
    piece(draw, 4, 0, 0, 'red', 'pink');
    piece(draw, 4, 4, 1, 'red', 'pink');
    piece(draw, 4, 8, 2, 'red', 'pink');
    piece(draw, 4, 12, 3, 'red', 'pink');

    piece(draw, 0, 0, 4, 'red', 'pink');
    piece(draw, 0, 4, 5, 'red', 'pink');
    piece(draw, 0, 8, 6, 'red', 'pink');
    piece(draw, 0, 12, 7, 'red', 'pink');

    piece(draw, 8, 0, 8, 'red', 'pink');
    piece(draw, 8, 4, 9, 'red', 'pink');
    piece(draw, 8, 8, 10, 'red', 'pink');
    piece(draw, 8, 12, 11, 'red', 'pink');

    piece(draw, 12, 0, 12, 'red', 'pink');
    piece(draw, 12, 4, 13, 'red', 'pink');

    piece(draw, 16, 0, 14, 'red', 'pink');
    piece(draw, 16, 4, 15, 'red', 'pink');

    piece(draw, 20, 0, 16, 'red', 'pink');
    piece(draw, 20, 4, 17, 'red', 'pink');

    piece(draw, 24, 0, 18, 'red', 'pink');
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
