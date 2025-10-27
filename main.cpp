#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <limits> 

using namespace std;

const int MAX_SIZE = 10;       
const double DEFAULT_RETURN = 10000.0; 
class NumberArray {
private:
    double *arrayPtr;
    int size;    

    void fillArrayWithRandom() {
        random_device rd; 
        default_random_engine myEngine(rd());
        uniform_real_distribution<double> dist(0.0, 100.0); 

        for (int i = 0; i < size; ++i) {
            arrayPtr[i] = dist(myEngine);
        }
    }

public:
    
    NumberArray(int initialSize = MAX_SIZE) {
        size = initialSize;
        arrayPtr = new (nothrow) double[size];

        if (arrayPtr == nullptr) {
            cerr << "Error: Memory allocation failed for array size " << size << ". Setting size to 0.\n";
            size = 0;
            return;
        }

        for (int i = 0; i < size; ++i) {
            arrayPtr[i] = 0.0;
        }
    }

    ~NumberArray() {
        if (arrayPtr != nullptr) {
            delete[] arrayPtr;
            arrayPtr = nullptr;
        }
        cout << "\nThe destructor is running for NumberArray object (size " << size << ").\n";
    }

    void setNumber(int index, double value) {
        if (index >= 0 && index < size) {
            arrayPtr[index] = value;
        } else {
            cout << "Warning: Index " << index << " is out of bounds (0-" << size - 1 << "). Value not stored.\n";
        }
    }

    double getNumber(int index) const {
        if (index >= 0 && index < size) {
            return arrayPtr[index];
        } else {
            cout << "Warning: Index " << index << " is out of bounds. Returning default value (" 
                 << fixed << setprecision(1) << DEFAULT_RETURN << ").\n";
            return DEFAULT_RETURN;
        }
    }

    double getMinimumValue() const {
        if (size == 0) return 0.0;

        double minVal = arrayPtr[0];
        for (int i = 1; i < size; ++i) {
            if (arrayPtr[i] < minVal) {
                minVal = arrayPtr[i];
            }
        }
        return minVal;
    }

    double getMaximumValue() const {
        if (size == 0) return 0.0;

        double maxVal = arrayPtr[0];
        for (int i = 1; i < size; ++i) {
            if (arrayPtr[i] > maxVal) {
                maxVal = arrayPtr[i];
            }
        }
        return maxVal;
    }

    double getAverage() const {
        if (size == 0) return 0.0;

        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += arrayPtr[i];
        }
        return sum / size;
    }

    void print() const {
        cout << fixed << setprecision(1); 
        for (int i = 0; i < size; ++i) {
            cout << arrayPtr[i] << " ";
        }
        cout << endl;
    }

    void loadTestNumbers(const double numbers[], int count) {
        if (count > size) {
            cout << "Error: Test numbers count exceeds array capacity. Loading first " << size << " elements.\n";
            count = size;
        }
        for (int i = 0; i < count; ++i) {
            arrayPtr[i] = numbers[i];
        }
    }
};

void runTests();

int main() {
    cout << fixed << setprecision(1);

    runTests();
    return 0; 
}

void runTests() {
    cout << "======================================================\n";
    cout << "              Number Array Class Test Program\n";
    cout << "======================================================\n";

    cout << "--- Test constructors ---\n";

    NumberArray arr1;
    cout << "From default constructor: Array of size " << MAX_SIZE << "\n";
    arr1.print(); 

    NumberArray arr2(15);
    cout << "From constructor with parameters: Array of size 15\n";
    arr2.print(); 

    cout << "\n";

    cout << "--- Test mutator ---\n";

    const int TEST_COUNT = 14;
    double testNumbers[TEST_COUNT] = {11.1, 55.0, 4.8, 47.8, 62.6, 11.9, 62.9, 88.5, 6.2, 3.5, 41.3, 91.9, 24.1, 73.5};

    arr1.loadTestNumbers(testNumbers, 10); 

    cout << "Array filled with numbers (first 10 from test data):\n";
    arr1.print();

    cout << "Trying to set a number with an out of bounds index (10):\n";
    arr1.setNumber(10, 999.9);

    cout << "\n";

    cout << "--- Test accessors ---\n";

    cout << "Access item at index 5: " << arr1.getNumber(5) << endl; 

    cout << "Access item at index 20 (out of bounds): " << arr1.getNumber(20) << endl; 

    cout << "\n";

    cout << "The minimum value in the array is: " << arr1.getMinimumValue() << endl;
    cout << "The maximum value in the array is: " << arr1.getMaximumValue() << endl;
    cout << "The average of the values in the array is: " << arr1.getAverage() << endl; 

    cout << "\n======================================================\n";
    cout << "Test program finished. Destructors should run now.\n";
}
