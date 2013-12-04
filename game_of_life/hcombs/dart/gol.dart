import 'dart:io';
import 'dart:convert';
import 'dart:async';

void main(List<String> args) {
  
  var input = new File(args.first);
  input.readAsLines().then( (List<String> lines) => executeGame( lines ) );
  
}

void executeGame( List<String> lines ) {
  var board = new Board.fronLines(lines);
  board.run();
  print(board.toString());
}

class Cell {
  bool alive = false;
  int  neighborCount = 0;
  
  static const ALIVE = '*';
  static const DEAD = '.';
  
  Cell( String c ) {
    alive = ( c == ALIVE );
  }
  
  String toString() {
    return alive ? ALIVE : DEAD;
  }
}

typedef void CellVisitor( Cell c, int i, int j );

class Board { 
  int length;
  int width;
  List<List<Cell>> _board; 
  
  final List< List<int> > _visitOrder = [
    [-1,-1], [-1,0], [-1,1],
    [0, -1],          [0,1],
    [1, -1], [1, 0],  [1,1]
  ];
  
  Board.fronLines( List<String> lines ) {
    //dimensions on first line
    var header = lines.first.split(' ');
    length = int.parse( header[0].trim() );
    width = int.parse( header[1].trim() );
    
    _board = new List<List<Cell>>(length);
    
    int j = 0;
    lines.sublist(1).forEach( (String s) {
      List<Cell> row = new List<Cell>(width);
      for ( var i=0; i < s.length; i++ ) {
        row [i] = new Cell( s[i] );
      }
      _board[j++] = row;
    });    
  }
  
  // Allow clients to 'clock' the game one iteration
  void run() {
    _eachCell( _markNeighbors );
    _eachCell( _enforceRules );
  }
  
  void _eachCell( CellVisitor visitor ) {
    for (int i=0; i < length ; i++) {
      for (int j=0; j < width; j++ ) {
        visitor( _board[i][j], i, j );
      }
    }
  }
  
  void _markNeighbors( Cell c, int i, int j ) {
    int neighbors = 0;
    _visitOrder.forEach( (List<int> offsets) {
      int dy = offsets[0];
      int dx = offsets[1];
      Cell neighbor = _itemAt( i + dx, j + dy );
      if (null != neighbor) {
        neighbors += neighbor.alive ? 1 : 0;
      }
    }); 
    c.neighborCount = neighbors;
  }
  
  Cell _itemAt( int i, int j ) {
    if ( (i < 0) || (i > length-1)) {
      return null;
    }
    if ( (j < 0) || (j > width-1 ) ) {
      return null;
    }
    
    return _board[i][j];
  }
  
  void _enforceRules( Cell c, int i, int j) {
    if (c.alive) {
      if (c.neighborCount < 2) {
        c.alive = false; // dead, rule #1
      }
      if (c.neighborCount > 3) {
        c.alive = false; // dead, rule #2
      }
      //2 or 3, you're still alive!
    } else {
      if (c.neighborCount == 3) {
        c.alive = true;
      }
    }
    
    //reset our neighbor count
    c.neighborCount = 0;
  }
  
  String toString() {
    StringBuffer sb = new StringBuffer("$length $width\n");
    _board.forEach( (List<Cell> row) {
      sb.writeAll(row);
      sb.write("\n");
    });
    return sb.toString();
  }
}

