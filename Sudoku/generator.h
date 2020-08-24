#ifndef GENERATOR_H
#define GENERATOR_H


namespace Sudoku {

    void generate(int difficulty,bool mut_map[10][10],int now_map[10][10]);
    bool check(int now_map[10][10]);
    
}// namespace Sudoku

#endif