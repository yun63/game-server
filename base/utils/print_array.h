// =====================================================================================
// 
//       Filename:  print_array.h
// 
//    Description:  打印array
// 
//        Version:  1.0
//        Created:  2016/10/13 18时20分54秒
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  lyf (leiyunfei), towardstheway@gmail.com
//        Company:  
// 
// =====================================================================================

#include <string>
#include <iomanip>

template <typename T,
          unsigned width,
          unsigned precision>
void print_array(T *array,              // array to print_array
                 int n,                 // number of elements to precision
                 int row,               // number of elements per row
                 std::string array_name // array namespace
                 ) {
    using std::cout;
    using std::endl;
    std::string line(" index | content\n ------+-");
    cout << "\n\n array \"" << array_name << "\", length " << n << endl << endl;
    cout << line.append(width * row, '-');

    for (int i = 0; i < n; i++) {
        if (i % row == 0) {
            cout << endl << std::setw(6) << i << " | ";
        }
        cout << std::setw(width) << std::fixed << std::setprecision(precision) << array[i];
    }
    cout << endl << endl;
}
