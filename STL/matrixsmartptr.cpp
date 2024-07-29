#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>

template <typename T>
class Matrix
{
private:
    int rows, cols;
    std::unique_ptr<T[]> data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(std::make_unique<T[]>(r * c)) {}

    T& at(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[r * cols + c];
    }

    const T& at(int r, int c) const
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[r * cols + c];
    }

    int getRows() const
    {
        return rows;
    }

    int getCols() const
    {
        return cols;
    }

    void print() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                std::cout << at(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

template <typename T>
void addMatrixes(Matrix<T>& result, const Matrix<T>& mat1, const Matrix<T>& mat2, int startRow, int endRow, std::mutex& mtx)
{
    for (int i = startRow; i < endRow; ++i)
    {
        for (int j = 0; j < mat1.getCols(); ++j)
        {
            std::lock_guard<std::mutex> lock(mtx);
            result.at(i, j) = mat1.at(i, j) + mat2.at(i, j);
        }
    }
}

int main()
{
    const int numRows = 3;
    const int numCols = 3;
    Matrix<int> mat1(numRows, numCols);
    Matrix<int> mat2(numRows, numCols);
    Matrix<int> result(numRows, numCols);

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            mat1.at(i, j) = i * numCols + j;
            mat2.at(i, j) = (i + 1) * numCols + j;
        }
    }

    std::cout << "Matrix 1 before adding:" << std::endl;
    mat1.print();
    std::cout << std::endl;

    std::cout << "Matrix 2 before adding:" << std::endl;
    mat2.print();
    std::cout << std::endl;

    int numThreads = 3; 
    std::vector<std::thread> threads;
    std::mutex mtx;
    int rowsPerThread = numRows / numThreads;
    
    for (int t = 0; t < numThreads; ++t)
    {
        int startRow = t * rowsPerThread;
        
        int endRow;
        if (t == numThreads - 1)
        {
            endRow = numRows;
        } else{
            endRow = startRow + rowsPerThread;
        }
        
        threads.emplace_back(addMatrixes<int>, std::ref(result), std::cref(mat1), std::cref(mat2), startRow, endRow, std::ref(mtx));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    std::cout << "Matrixes after adding:" << std::endl;
    result.print();

    return 0;
}
