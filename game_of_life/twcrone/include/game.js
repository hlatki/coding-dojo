function Game (gen) {
    this.rows = gen.split('\n');
    this.rowCount = this.rows.length;
}

Game.prototype.getNextGenerationOutput = function() {
    return this.nextGeneration.join('\n');
};

Game.prototype.runNextGeneration = function () {
    this.nextGeneration = [];
    for(var row = 0; row < this.rows.length; ++row) {
        var nextRow = '';
        for(var col = 0; col < this.rows[row].length; ++col) {
            nextRow += this.isAliveNextGeneration(row, col) ? '*' : '.';
        }
        this.nextGeneration[row] = nextRow;
    }
    this.rows = this.nextGeneration;
};

Game.prototype.isCellAliveAt = function (row, column) {
    if(row < 0 || column < 0) {
        return false;
    }
    if(row >= this.rowCount || column >= this.rows[row].length) {
        return false;
    }
    var cell = this.rows[row][column];
    return cell == '*';
};

Game.prototype.countAliveNeighborAt = function(row, column) {
    return (this.isCellAliveAt(row, column) ? 1 : 0);
};

Game.prototype.countAliveNeighbors = function(row, column) {
    var count = this.countAliveNeighborAt(row - 1, column - 1)
    count += this.countAliveNeighborAt(row - 1, column)
    count += this.countAliveNeighborAt(row - 1, column + 1)
    count += this.countAliveNeighborAt(row, column - 1)
    count += this.countAliveNeighborAt(row, column + 1)
    count += this.countAliveNeighborAt(row + 1, column - 1)
    count += this.countAliveNeighborAt(row + 1, column)
    count += this.countAliveNeighborAt(row + 1, column + 1)
    return count
};

Game.prototype.isAliveNextGeneration = function(row, column) {
    var neighborCount = this.countAliveNeighbors(row, column)
    if(neighborCount == 3) {
        return true;
    }
    else if(this.isCellAliveAt(row, column) && neighborCount == 2) {
        return true;
    }
    else {
        return false;
    }
};
