package main

import "fmt"

const (
	LIVE_CELL	= '*'
	DEAD_CELL	= '.'
	WALL		= "X"
	MAX_GENS	= 99
)

func main() {
	rows, cols, gen := 0, 0, 0
	var row string
	var board []string
	fmt.Scanf("%d %d", &rows, &cols)
	fmt.Scanln(&row)
	board = add_wall_row(cols + 2, board)
	for i := 0; i < rows; i++ {
		fmt.Scanln(&row)
		row = WALL + row + WALL
		board = append(board, row)
	}
	board = add_wall_row(cols + 2, board)
	for {
		gen += 1
		fmt.Printf("Generation %d:\n", gen)
		print(board)
		new_board := generation(board)
		if compare_boards(board, new_board) || gen >= MAX_GENS {
			gen += 1
			fmt.Printf("Generation %d:\n", gen)
			print(new_board)
			return
		}
		board = new_board
	}
}

func add_wall_row(length int, board []string) []string {
	row := ""
	for i := 0; i < length; i++ {
		row += WALL
	}
	board = append(board, row)
	return board
}

func compare_boards(board1 []string, board2 []string) bool {
	if len(board1) != len(board2) {
		return false;
	}
	for i := 0; i < len(board1); i++ {
		if board1[i] != board2[i] {
			return false
		}
	}
	return true
}

func generation(board []string) []string {
	rows, cols := len(board) - 2, len(board[0]) - 2
	var numboard [][]int
	for r := 1; r <= rows; r++ {
		var numrow []int
		numboard = append(numboard, numrow)
		for c := 1; c <= cols; c++ {
			alive := 0
			living_neighbors := 0
			for a := -1; a <= 1; a++ {
				for b := -1; b <= 1; b++ {
					if board[r+a][c+b] == LIVE_CELL && (a != 0 || b != 0) {
						living_neighbors += 1
					}					
				}
			}
			if board[r][c] == DEAD_CELL && living_neighbors == 3 || (board[r][c] == LIVE_CELL && living_neighbors == 2 || living_neighbors == 3) {
				alive = 1
			}
			numboard[r-1] = append(numboard[r-1], alive)
		}
	}
	return convert(numboard)
}

func convert(numboard [][]int) []string {
	var board []string
	var row string
	rows, cols := len(numboard), len(numboard[0])
	board = add_wall_row(cols + 2, board)
	for i := 0; i < rows; i ++ {
		row = WALL
		for j := 0; j < cols; j++ {
			if numboard[i][j] == 0 {
				row += "."
			} else {
				row += "*"
			}
		}
		row += WALL
		board = append(board, row)
	}
	board = add_wall_row(cols + 2, board)
	return board
}

func print(board []string) {
	for i := 1; i < len(board) - 1; i++ {
		fmt.Println(board[i][1:len(board[i])-1])
	}
	fmt.Println("")
}