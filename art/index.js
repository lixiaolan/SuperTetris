var scale = 50;
var boarderWidth = 5;

$(document).ready(function () {
    // create svg drawing
    var draw = SVG('drawing').size(10*scale, 10*scale);
    
    // create text
    tee(draw, 3, 3);
    tee(draw, 5, 4);
});

// Function to draw a tetris piece
var tee = function (draw, row, col) {
    draw.rect(scale, 3*scale).move(col*scale, row*scale).fill({ color: 'pink' });
    draw.rect(2*scale, scale).move(col*scale, row*scale).fill({ color: 'pink' });

    draw.rect(scale - 2*boarderWidth, 3*scale - 2*boarderWidth).move(col*scale + boarderWidth, row*scale + boarderWidth).fill({ color: 'red' });
    draw.rect(2*scale - 2*boarderWidth, scale - 2*boarderWidth).move(col*scale + boarderWidth, row*scale + boarderWidth).fill({ color: 'red' });
}


