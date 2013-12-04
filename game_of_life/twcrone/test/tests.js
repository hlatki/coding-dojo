test("Initialize game", function() {
    var game = new Game("...\n...\n...");
    var rows = game.rows;
    equal(rows.length, 3);
    equal(rows[0].length, 3)
});

test("Get next generation", function(){
    var gen = "........\n....*...\n...**...\n........";
    var next_gen = "........\n...**...\n...**...\n........";
    var game = new Game(gen)
    game.runNextGeneration();
    equal(game.getNextGenerationOutput(), next_gen);
});

test("Check if a cell is alive", function(){
    var game = new Game(".*.\n...\n...");
    ok(!game.isCellAliveAt(0, 0));
    ok(game.isCellAliveAt(0, 1));

    ok(!game.isCellAliveAt(100, 100));
    ok(!game.isCellAliveAt(0, 100));
    ok(!game.isCellAliveAt(100, 0));

    ok(!game.isCellAliveAt(-1, -1));
    ok(!game.isCellAliveAt(0, -1));
    ok(!game.isCellAliveAt(-1, 0));
});

test("Count alive neighbors", function(){
    var game = new Game("......*.\n....*.**\n...**...\n........\n...***..\n..*.**..");
    equal(game.countAliveNeighbors(1, 3), 3);
    equal(game.countAliveNeighbors(0, 0), 0);
    equal(game.countAliveNeighbors(2, 3), 2);
    equal(game.countAliveNeighbors(2, 4), 2);
    equal(game.countAliveNeighbors(1, 4), 2);
});

test("Test alive for next generation", function(){
    var game = new Game("......*.\n....*.**\n...**...\n........\n...***..\n..*.**..");
    ok(game.isAliveNextGeneration(1, 3));

    ok(!game.isAliveNextGeneration(0, 0));
    ok(game.isAliveNextGeneration(1, 4));
    ok(!game.isAliveNextGeneration(2, 2));
    ok(!game.isAliveNextGeneration(4, 4));
    ok(!game.isAliveNextGeneration(5, 3));
    ok(!game.isAliveNextGeneration(5, 4));
    ok(game.isAliveNextGeneration(5, 5));
    ok(!game.isAliveNextGeneration(5, 6));
    ok(!game.isAliveNextGeneration(5, 7));
});