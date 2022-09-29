#include <iostream>
#include <fstream>

const int LINES_COUNT = 2;
const char * IN_FILE = "in.txt";
const char * OUT_FILE = "out.txt";

int main()
{
    int ** array = new int * [LINES_COUNT];
    int num_count = 0;
    //int num_val = 0;


    std::ifstream in_file (IN_FILE);
    if(!in_file.is_open()) std::exit(-1);
    for (int lines_cnt = 0; lines_cnt < LINES_COUNT; ++lines_cnt) {
        if (in_file >> num_count) {
            array[lines_cnt] = new int [num_count+1];
            array[lines_cnt][0] = num_count;
            for (int num_cnt = 1; num_cnt <= num_count; ++num_cnt) {
                in_file >> array[lines_cnt][num_cnt];
            }
        }
    }    
    in_file.close();

    for (int x_cnt = 1; x_cnt < array[0][0]; ++x_cnt) {
       std::swap(array[0][x_cnt], array[0][x_cnt+1]);
    }
    for (int x_cnt = array[1][0]; x_cnt > 1; --x_cnt) {
       std::swap(array[1][x_cnt], array[1][x_cnt-1]);
    }

    std::ofstream out_file (OUT_FILE);
    if(!out_file.is_open()) std::exit(-1);
    for (int rows = LINES_COUNT-1; rows >= 0; --rows) {
        out_file << array[rows][0] << std::endl;
        for (int cols = 1; cols <= array[rows][0]; ++cols) {
            out_file << array[rows][cols] << (cols == array[rows][0] ? "" : " ");
        }
        out_file << (rows == 0 ? "" : "\n");
    }
    out_file.close();

}

